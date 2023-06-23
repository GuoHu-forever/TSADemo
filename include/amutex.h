#ifndef AMUTEX_H
#define AMUTEX_H
#include<mutex>
using namespace std;

// Enable thread safety attributes only with clang.
// The attributes can be safely erased when compiling with other compilers.
#if defined(__clang__) && (!defined(SWIG))
#define THREAD_ANNOTATION_ATTRIBUTE__(x) __attribute__((x))
#else
#define THREAD_ANNOTATION_ATTRIBUTE__(x)  // no-op
#endif
#define GUARDED_BY(x) THREAD_ANNOTATION_ATTRIBUTE__(guarded_by(x))
#define REQUIRES(...) THREAD_ANNOTATION_ATTRIBUTE__(requires_capability(__VA_ARGS__))



#ifndef _LIBCPP_THREAD_SAFETY_ANNOTATION
#  ifdef _LIBCPP_HAS_THREAD_SAFETY_ANNOTATIONS
#    define _LIBCPP_THREAD_SAFETY_ANNOTATION(x) __attribute__((x))
#  else
#    define _LIBCPP_THREAD_SAFETY_ANNOTATION(x)
#  endif
#endif  // _LIBCPP_THREAD_SAFETY_ANNOTATION

class  _LIBCPP_THREAD_SAFETY_ANNOTATION(capability("mutex")) amutex :public mutex
{
public:
    void lock() _LIBCPP_THREAD_SAFETY_ANNOTATION(acquire_capability()){
        mutex::lock();
    }
    bool try_lock()   _LIBCPP_THREAD_SAFETY_ANNOTATION(try_acquire_capability(true))  {
        return mutex::try_lock();
    }
    void unlock()   _LIBCPP_THREAD_SAFETY_ANNOTATION(release_capability()) {
        mutex::unlock();
    }
};



#endif // AMUTEX_H
