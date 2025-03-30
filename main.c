#include "main.h"

int main()
{
    Arena arena = ArenaCreate(90000000 * sizeof(Tube));
    int countingResult;
    int memoryUsed;
    Tubing generatedTubes;
    for (int n = 1; n < 20; n++)
    {
        // printf("Starting count:\n");
        generatedTubes = GenConnectedTubes(n, &arena);
        countingResult = CountValidTubes(generatedTubes, &arena);
        memoryUsed = (arena.nextLocation - arena.memoryPtr);
        printf("Counting done, total count: %d, memory used %d\n", countingResult, memoryUsed);
        ArenaReset(&arena);
    }
    return 0;
}