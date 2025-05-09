// General int array functions, not actually used here but useful to have on hand

#include <stdlib.h>
#include <assert.h>

#include "ArenaArrayFloat.h"

float ArenaArrayFloatGet(int index, ArenaArrayFloat array)
{
    assert((0 <= index) & (index < array.size));
    return ((float *)array.memory)[index];
}
void ArenaArrayFloatSet(int index, float value, ArenaArrayFloat array)
{
    assert((0 <= index) & (index < array.size));
    ((float *)array.memory)[index] = value;
}

ArenaArrayFloat ArenaArrayFloatCreate(int size, Arena *arenaPtr)
{
    ArenaArrayFloat array;
    array.memory = ArenaAlloc(size * sizeof(float), arenaPtr);
    array.size = size;
    return array;
}