#ifndef MEMORYARENAARRAYINT
#define MEMORYARENAARRAYINT

#include "../ArenaBase/ArenaBase.h"

// Note separate structs are for type safety:
typedef struct ArenaArrayInt
{
    void *memory;
    int size;
} ArenaArrayInt;

int ArenaArrayIntGet(int index, ArenaArrayInt array);
void ArenaArrayIntSet(int index, int value, ArenaArrayInt array);
ArenaArrayInt ArenaArrayIntCreate(int size, Arena *arenaPtr);

#endif
