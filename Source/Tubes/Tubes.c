// Useful functions that allow us to work with arrays of tubes within a memory arena

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Tubes.h"

Tube TubeCreate(int start_in, int end_in)
{
    if (start_in > end_in)
    {
        printf("Invalid input for CreateTube.");
        exit(EXIT_FAILURE);
    }
    Tube output;
    output.start = start_in;
    output.end = end_in;
    return output;
}

Tube TubeArrayGet(int index, TubeArenaArray array)
{
    assert((0 <= index) & (index < array.size));
    return array.memory[index];
}
void TubeArraySet(int index, Tube value, TubeArenaArray array)
{
    assert((0 <= index) & (index < array.size));
    (array.memory)[index] = value;
}

TubeArenaArray TubeArrayCreate(int size, Arena *arenaPtr)
{
    TubeArenaArray array;
    array.memory = ArenaAlloc(size * sizeof(Tube), arenaPtr);
    array.size = size;
    return array;
}

// Creates a subarray within another array, note that these point to the same memory location
// so if one is changed the other will as well
TubeArenaArray TubeArraySubCreate(int start, int end, TubeArenaArray array)
{
    assert(start >= 0);
    assert(start < end);
    assert(end <= array.size);

    TubeArenaArray output;
    output.memory = array.memory + start;
    output.size = end - start;
    return output;
}