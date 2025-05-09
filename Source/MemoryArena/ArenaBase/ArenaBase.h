#ifndef MEMORYARENABASE
#define MEMORYARENABASE

typedef struct Arena
{
    char *memoryPtr;
    char *end;
    char *nextLocation;
} Arena;

Arena ArenaCreate(long long int size);
void ArenaDelete(Arena *arenaPtr);
void *ArenaAlloc(int size, Arena *arenaPtr);
void ArenaReset(Arena *arenaPtr);
#endif
