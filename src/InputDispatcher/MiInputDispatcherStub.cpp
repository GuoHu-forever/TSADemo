
#include "MiInputDispatcherStub.h"
LIB_HANDLE MiInputDispatcherStub::sLibMiInputDispatcherImpl = nullptr;
IMiInputDispatcherStub* MiInputDispatcherStub::sStubImplInstance = nullptr;
std::mutex MiInputDispatcherStub::sLock;
bool MiInputDispatcherStub::inited = false;

IMiInputDispatcherStub* MiInputDispatcherStub::getImplInstance() {
    std::lock_guard<std::mutex> lock(sLock);
    if (!sLibMiInputDispatcherImpl && !inited) {
        sLibMiInputDispatcherImpl =  LIB_LOAD(LIBPATH);
        if (sLibMiInputDispatcherImpl) {
            // typedef function pointer
            typedef IMiInputDispatcherStub* (*Create)();
            // get the createInputDispatcherStub function pointer
            Create create = (Create)LIB_SYMBOL(sLibMiInputDispatcherImpl, "createInputDispatcherStubImpl");
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
    Destroy destroy = (Destroy)LIB_SYMBOL(sLibMiInputDispatcherImpl, "destroyInputDispatcherStubImpl");
    // destroy sStubImplInstance
    destroy(sStubImplInstance);
    LIB_CLOSE(sLibMiInputDispatcherImpl);
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

