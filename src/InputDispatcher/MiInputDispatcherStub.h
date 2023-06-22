#ifndef MIINPUTDISPATCHERSTUB_H
#define MIINPUTDISPATCHERSTUB_H
#include"IMiInputdispatcherstub.h"
#include<mutex>
#ifdef _WIN32
    #include <windows.h>
    #define LIB_HANDLE HMODULE
    #define LIB_LOAD(libname) LoadLibrary(libname)
    #define LIB_SYMBOL(libhandle, symbolname) GetProcAddress(libhandle, symbolname)
    #define LIB_CLOSE(libhandle) FreeLibrary(libhandle)
    #define LIBPATH "MiInputDispatcherStubImpl.dll"
#else
    #include <dlfcn.h>
    #define LIB_HANDLE void*
    #define LIB_LOAD(libname) dlopen(libname, RTLD_LAZY)
    #define LIB_SYMBOL(libhandle, symbolname) dlsym(libhandle, symbolname)
    #define LIB_CLOSE(libhandle) dlclose(libhandle)
    #define LIBPATH "libMiInputDispatcherStubImpl.so"
#endif
class MiInputDispatcherStub
{
private:
    static LIB_HANDLE sLibMiInputDispatcherImpl;
    static IMiInputDispatcherStub* sStubImplInstance;
    static std::mutex sLock;
    static bool inited;
    static IMiInputDispatcherStub* getImplInstance();
    static void destroyImplInstance();
public:
    MiInputDispatcherStub();
    ~MiInputDispatcherStub();
    static void beforeTransferTouchFocusLocked();
};

#endif // MIINPUTDISPATCHERSTUB_H
