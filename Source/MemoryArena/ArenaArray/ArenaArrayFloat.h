#ifndef MEMORYARENAARRAYFLOAT
#define MEMORYARENAARRAYFLOAT

#include "../ArenaBase/ArenaBase.h"

// Note separate structs are for type safety:
typedef struct ArenaArrayFloat
{
    void *memory;
    int size;
} ArenaArrayFloat;

float ArenaArrayFloatGet(int index, ArenaArrayFloat array);
void ArenaArrayFloatSet(int index, float value, ArenaArrayFloat array);
ArenaArrayFloat ArenaArrayFloatCreate(int size, Arena *arenaPtr);

#endif
