#pragma once



#include "InputDispatcher.h"
#include "IMiInputdispatcherstub.h"

#ifdef _WIN32
    #ifdef MIINPUT_EXPORTS
        #define MIINPUT_LIB_API  _declspec(dllexport)
    #else
        #define MIINPUT_LIB_API _declspec(dllimport)
    #endif
#else
    #define MIINPUT_LIB_API
#endif

class MIINPUT_LIB_API MiInputDispatcherStubImpl: public IMiInputDispatcherStub {
public:
    InputDispatcher*mInputDispatcher;
    void beforeTransferTouchFocusLocked() override;
};
extern "C"  MIINPUT_LIB_API IMiInputDispatcherStub* createInputDispatcherStubImpl();

extern "C"  MIINPUT_LIB_API void destroyInputDispatcherStubImpl(IMiInputDispatcherStub* instance) ;

