#include "ArenaBase.h"

Arena ArenaCreate(int size)
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

    // Allocate more dynamically:
    if (arenaPtr->nextLocation + size <= arenaPtr->end)
    {
        int maxSize = arenaPtr->end - arenaPtr->memoryPtr;
        arenaPtr->memoryPtr = realloc(arenaPtr->memoryPtr, 2 * maxSize);
        arenaPtr->end = arenaPtr->memoryPtr + 2 * maxSize;
    }

    void *outputLocation = arenaPtr->nextLocation;
    arenaPtr->nextLocation = arenaPtr->nextLocation + size;
    return outputLocation;
}
