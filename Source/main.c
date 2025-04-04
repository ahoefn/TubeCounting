#include "main.h"

int main()
{
    long long unsigned int memorySize = 3000000000 * sizeof(Tube);
    printf("memroysize : %lli\n", memorySize);
    Arena arena = ArenaCreate(memorySize);
    int countingResult;
    long long unsigned int memoryUsed;
    Tubing generatedTubes;
    for (int n = 1; n < 20; n++)
    {
        // printf("Starting count:\n");
        generatedTubes = GenConnectedTubes(n, &arena);
        countingResult = CountValidTubes(generatedTubes, &arena);
        memoryUsed = (arena.nextLocation - arena.memoryPtr);
        printf("n %d: Counting done, total count %d, memory used %llu\n", n, countingResult, memoryUsed);
        ArenaReset(&arena);
    }
    return 0;
}