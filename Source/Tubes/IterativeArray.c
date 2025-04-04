#include "Tubes.h"

TubeIterativeArray TubeIterativeCreate(Arena *arenaPtr)
{
    TubeIterativeArray array;
    array.memory = ArenaAlloc(0, arenaPtr);
    array.size = 0;
    return array;
}
Tube TubeIterativeGet(int index, TubeIterativeArray array)
{
    assert((0 <= index) & (index < array.size));
    return ((Tube *)array.memory)[index];
}

void TubeIterativeSet(int index, Tube value, TubeIterativeArray array)
{
    assert((0 <= index) & (index < array.size));
    ((Tube *)array.memory)[index] = value;
}

// Appends an element from the array and increments the arena location.
void TubeIterativeAppend(Tube tube, TubeIterativeArray *arrayPtr, Arena *arenaPtr)
{
    int lastIndex = arrayPtr->size;
    ArenaAlloc(sizeof(tube), arenaPtr);
    arrayPtr->size += 1;
    TubeIterativeSet(lastIndex, tube, *arrayPtr);
}

// Removes the last element from the list and updates this in the arena
void TubeIterativeChop(TubeIterativeArray *arrayPtr, Arena *arenaPtr)
{
    assert(arenaPtr->memoryPtr != NULL);
    assert(arenaPtr->end != NULL);
    assert(arenaPtr->nextLocation != NULL);
    assert(arenaPtr->memoryPtr <= arenaPtr->nextLocation - sizeof(Tube));

    arenaPtr->nextLocation = arenaPtr->nextLocation + sizeof(Tube);
    arrayPtr->size -= 1;
}

// Stops the iterative construction and outputs an ordinary array
TubeArenaArray TubeIterativeFinalize(TubeIterativeArray *arrayPtr)
{
    TubeArenaArray output;
    output.memory = arrayPtr->memory;
    output.size = arrayPtr->size;
    arrayPtr->memory = NULL;
    arrayPtr->size = 0;
    return output;
}