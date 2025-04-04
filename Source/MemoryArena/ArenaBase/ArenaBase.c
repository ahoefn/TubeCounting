// Base initialzation and creation functions for the memoery arena

#include <stdlib.h>
#include <assert.h>

#include "../../Utilities/Utilities.h"
#include "ArenaBase.h"

Arena ArenaCreate(long long int size)
{
    assert(size > 0);
    Arena arena;
    arena.memoryPtr = malloc(size);
    arena.end = arena.memoryPtr + size;
    arena.nextLocation = arena.memoryPtr;
    return arena;
}
void ArenaDelete(Arena *arena)
{
    free(arena->memoryPtr);
    arena->memoryPtr = NULL;
    arena->end = NULL;
    arena->nextLocation = NULL;
}
void ArenaReset(Arena *arenaPtr)
{
    arenaPtr->nextLocation = arenaPtr->memoryPtr;
}

void *ArenaAlloc(int size, Arena *arenaPtr)
{
    assert(size >= 0);
    assert(arenaPtr->memoryPtr != NULL);
    assert(arenaPtr->end != NULL);
    assert(arenaPtr->nextLocation != NULL);
    assert(arenaPtr->nextLocation + size <= arenaPtr->end);

    void *outputLocation = arenaPtr->nextLocation;
    arenaPtr->nextLocation = arenaPtr->nextLocation + size;
    return outputLocation;
}
