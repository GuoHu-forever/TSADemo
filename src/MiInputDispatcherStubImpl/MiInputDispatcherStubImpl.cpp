#define MIINPUT_EXPORTS
#define _LIBCPP_HAS_THREAD_SAFETY_ANNOTATIONS
#include "MiInputDispatcherStubImpl.h"
#include<iostream>
using namespace std;

void MiInputDispatcherStubImpl::beforeTransferTouchFocusLocked(){
      cout<< typeid(*this).name()<<"::"<<__FUNCTION__<<endl;
            mInputDispatcher->getWindowHandleForStubLocked();
}
 IMiInputDispatcherStub* createInputDispatcherStubImpl() {
    return new MiInputDispatcherStubImpl;
}

 void destroyInputDispatcherStubImpl(IMiInputDispatcherStub* instance) {
    delete instance;
}
