
#define _LIBCPP_HAS_THREAD_SAFETY_ANNOTATIONS
#define INPUT_EXPORTS
#include "InputDispatcher.h"
#include "MiInputDispatcherStub.h"
#include<iostream>

using namespace std;

void InputDispatcher::transferTouchFocus(){
//    mLock.Lock();
       std::scoped_lock  _l(mLock);

       cout<< typeid(*this).name()<<"::"<<__FUNCTION__<<endl;
    MiInputDispatcherStub::beforeTransferTouchFocusLocked();
//    mLock.Unlock();
}
void InputDispatcher::getWindowHandleLocked(){
    cout<< typeid(*this).name()<<"::"<<__FUNCTION__<<endl;
}

