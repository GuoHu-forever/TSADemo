#pragma once

#include<memory>
#include<iostream>
#include"amutex.h"

#ifdef _WIN32
    #ifdef INPUT_EXPORTS
        #define INPUT_LIB_API  _declspec(dllexport)
    #else
        #define INPUT_LIB_API _declspec(dllimport)
    #endif
#else
    #define INPUT_LIB_API
#endif

using namespace std;
class EventEntry {
public:
    int mX = 0;
};

class INPUT_LIB_API InputDispatcher {
    amutex mLock;
public:
    shared_ptr<EventEntry> mPendingEvent GUARDED_BY(mLock);
    void transferTouchFocus();
    void getWindowHandleLocked() REQUIRES(mLock);
    void getWindowHandleForStubLocked() REQUIRES(mLock){
           cout<< typeid(*this).name()<<"::"<<__FUNCTION__<<endl;
        getWindowHandleLocked();
    }
};
