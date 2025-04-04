#include <stdio.h>

#include "MemoryArena/MemoryArena.h"
#include "Counting/Counting.h"
#include "Tubes/Tubes.h"

// Program start, iteratively generates the valid tubings for n=1 to 20, but will run out of memory around 11 or 12.
int main()
{
    // Allocate all memory at once, can be customized if required
    long long unsigned int memorySize = 3000000000 * sizeof(Tube);
    printf("memroysize : %lli\n", memorySize);

    // Arena for memory management
    Arena arena = ArenaCreate(memorySize);

    // Start iteration
    int countingResult;
    long long unsigned int memoryUsed;
    Tubing generatedTubes;
    for (int n = 1; n < 20; n++)
    {
        generatedTubes = GenConnectedTubes(n, &arena);
        countingResult = CountValidTubes(generatedTubes, &arena);
        memoryUsed = (arena.nextLocation - arena.memoryPtr);
        printf("n %d: Counting done, total count %d, memory used %llu\n", n, countingResult, memoryUsed);
        ArenaReset(&arena);
    }
    return 0;
}