#include "Utilities.h"

int GetNextPowerOfTwo(int input)
{
    // Not very optimized, let's see if it's necessary.
    int output = 1;
    while (output < input)
    {
        output *= 2;
    }
    return output;
}