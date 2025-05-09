// General int array functions, not actually used here but useful to have on hand

#include <stdlib.h>
#include <assert.h>

#include "ArenaArrayInt.h"

int ArenaArrayIntGet(int index, ArenaArrayInt array)
{
    assert((0 <= index) & (index < array.size));
    return ((int *)array.memory)[index];
}
void ArenaArrayIntSet(int index, int value, ArenaArrayInt array)
{
    assert((0 <= index) & (index < array.size));
    ((int *)array.memory)[index] = value;
}

ArenaArrayInt ArenaArrayIntCreate(int size, Arena *arenaPtr)
{
    ArenaArrayInt array;
    array.memory = ArenaAlloc(size * sizeof(int), arenaPtr);
    array.size = size;
    return array;
}