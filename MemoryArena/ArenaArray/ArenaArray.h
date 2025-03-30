#ifndef MEMORYARENAARRAYINT
#define MEMORYARENAARRAYINT

#include "../../Utilities/Utilities.h"
#include "../ArenaBase/ArenaBase.h"

// Ints, note separate structs are for type safety:
typedef struct ArenaArrayInt
{
    void *memory;
    int size;
} ArenaArrayInt;
int ArenaArrayIntGet(int index, ArenaArrayInt array);
void ArenaArrayIntSet(int index, int value, ArenaArrayInt array);
ArenaArrayInt ArenaArrayIntCreate(int size, Arena *arenaPtr);

// Floats:
typedef struct ArenaArrayFloat
{
    void *memory;
    int size;
} ArenaArrayFloat;
float ArenaArrayFloatGet(int index, ArenaArrayFloat array);
void ArenaArrayFloatSet(int index, float value, ArenaArrayFloat array);
ArenaArrayFloat ArenaArrayFloatCreate(int size, Arena *arenaPtr);

#endif