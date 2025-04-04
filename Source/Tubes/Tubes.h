#ifndef TUBES
#define TUBES

#include "../MemoryArena/MemoryArena.h"
typedef struct Tube
{
    int start;
    int end;
} Tube;

// Arena Array's
typedef struct TubeArenaArray
{
    Tube *memory;
    int size;
} TubeArenaArray;
typedef TubeArenaArray Tubing;

// Starts from a list of tubes and has indices corresponding to the tubes that are in the subtubing.
typedef struct SubTubing
{
    ArenaArrayInt tubes;
    TubeArenaArray *tubing;
} SubTubing;

Tube TubeCreate(int start_in, int end_in);
Tube TubeArrayGet(int index, TubeArenaArray array);
void TubeArraySet(int index, Tube value, TubeArenaArray array);
TubeArenaArray TubeArrayCreate(int size, Arena *arenaPtr);
TubeArenaArray TubeArraySubCreate(int start, int end, TubeArenaArray array);

// Iterative array of tubes
typedef struct TubeIterativeArray
{
    Tube *memory;
    int size;
} TubeIterativeArray;

// A way to add elements consecutively to an array, adding
// and deletion operations must all be done immediately after
// creation, with no other calls to arena in between.
TubeIterativeArray TubeIterativeCreate(Arena *arenaPtr);
Tube TubeIterativeGet(int index, TubeIterativeArray array);
void TubeIterativeSet(int index, Tube value, TubeIterativeArray array);
void TubeIterativeAppend(Tube tube, TubeIterativeArray *arrayPtr, Arena *arenaPtr);
void TubeIterativeChop(TubeIterativeArray *arrayPtr, Arena *arenaPtr);
TubeArenaArray TubeIterativeFinalize(TubeIterativeArray *arrayPtr);
#endif