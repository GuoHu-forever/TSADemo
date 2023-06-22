#define MIINPUT_EXPORTS
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
