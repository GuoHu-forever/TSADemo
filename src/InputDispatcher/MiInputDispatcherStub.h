#ifndef MIINPUTDISPATCHERSTUB_H
#define MIINPUTDISPATCHERSTUB_H
#include"IMiInputdispatcherstub.h"
#include<mutex>
class MiInputDispatcherStub
{
private:
    static void* sLibMiInputDispatcherImpl;
    static IMiInputDispatcherStub* sStubImplInstance;
    static std::mutex sLock;
    static bool inited;
    static IMiInputDispatcherStub* getImplInstance();
    static void destroyImplInstance();
    static constexpr const char* LIBPATH = "MiInputDispatcherStubImpl.dll";
public:
    MiInputDispatcherStub();
    ~MiInputDispatcherStub();
    static void beforeTransferTouchFocusLocked();
};

#endif // MIINPUTDISPATCHERSTUB_H
