#include <iostream>
#include "InputDispatcher.h"
#include "MiInputDispatcherStubImpl.h"
using namespace std;

int main()
{
    InputDispatcher inputDispatcher;
    inputDispatcher.transferTouchFocus();

    return 0;
}
