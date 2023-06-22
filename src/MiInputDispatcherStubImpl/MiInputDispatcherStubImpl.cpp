#define MIINPUT_EXPORTS
#include "MiInputDispatcherStubImpl.h"
#include<iostream>
using namespace std;

void MiInputDispatcherStubImpl::beforeTransferTouchFocusLocked(){
      cout<< typeid(*this).name()<<"::"<<__FUNCTION__<<endl;
            mInputDispatcher->getWindowHandleForStubLocked();
}
extern "C"  _declspec(dllexport) IMiInputDispatcherStub* createInputDispatcherStubImpl() {
    return new MiInputDispatcherStubImpl;
}

extern "C"  _declspec(dllexport)  void destroyInputDispatcherStubImpl(IMiInputDispatcherStub* instance) {
    delete instance;
}
