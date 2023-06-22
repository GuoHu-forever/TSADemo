#include "MiInputDispatcherStub.h"
#include <Windows.h>
void* MiInputDispatcherStub::sLibMiInputDispatcherImpl = nullptr;
IMiInputDispatcherStub* MiInputDispatcherStub::sStubImplInstance = nullptr;
std::mutex MiInputDispatcherStub::sLock;
bool MiInputDispatcherStub::inited = false;

IMiInputDispatcherStub* MiInputDispatcherStub::getImplInstance() {
    std::lock_guard<std::mutex> lock(sLock);
    if (!sLibMiInputDispatcherImpl && !inited) {
        sLibMiInputDispatcherImpl =  LoadLibrary(TEXT(LIBPATH));
        if (sLibMiInputDispatcherImpl) {
            // typedef function pointer
            typedef IMiInputDispatcherStub* (*Create)();
            // get the createInputDispatcherStub function pointer
            Create create = (Create)GetProcAddress((HINSTANCE )sLibMiInputDispatcherImpl, "createInputDispatcherStubImpl");
            if (create) {
                // invoke
                sStubImplInstance = create();
            } else {
                printf("dlsym is fail InputDispatcher.");
            }
        } else {
            printf("inputflinger open %s failed! dlopen - ", LIBPATH);
        }
        inited = true;
    }
    return sStubImplInstance;
}

void MiInputDispatcherStub::destroyImplInstance() {
    std::lock_guard<std::mutex> lock(sLock);
    if (!sLibMiInputDispatcherImpl) {
        return;
    }
    // typedef function pointer
    typedef void (*Destroy)(IMiInputDispatcherStub*);
    // get the destroyInputDispatcherStub function
    Destroy destroy = (Destroy)GetProcAddress((HINSTANCE )sLibMiInputDispatcherImpl, "destroyInputDispatcherStubImpl");
    // destroy sStubImplInstance
    destroy(sStubImplInstance);
    FreeLibrary((HINSTANCE )sLibMiInputDispatcherImpl);
    sLibMiInputDispatcherImpl = nullptr;
    sStubImplInstance = nullptr;
}


MiInputDispatcherStub::MiInputDispatcherStub()
{

}
MiInputDispatcherStub::~MiInputDispatcherStub(){
    destroyImplInstance();
}

void MiInputDispatcherStub::beforeTransferTouchFocusLocked(){
    IMiInputDispatcherStub* stub = getImplInstance();
     if (stub) {
         stub->beforeTransferTouchFocusLocked();
     }
}

