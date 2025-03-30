#include "Counting.h"

bool DoesNotCross(Tube T1, Tube T2)
{
    bool T1IsSubset = (T2.start <= T1.start) & (T1.end <= T2.end);
    bool t2IsSubset = (T1.start <= T2.start) & (T2.end <= T1.end);
    bool areDisjoint = (T1.end < T2.start) | (T2.end < T1.start);
    return T1IsSubset | t2IsSubset | areDisjoint;
}

TubeArenaArray GenConnectedTubes(int n, Arena *arenaPtr)
{
    int size = n * (n + 1) / 2;
    TubeArenaArray output = TubeArrayCreate(size, arenaPtr);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            TubeArraySet(count, TubeCreate(i, j), output);
            count += 1;
        }
    }
    return output;
}

Tubing SelectValidTubes(Tube T, Tubing tubing, Arena *arenaPtr)
{
    TubeIterativeArray array = TubeIterativeCreate(arenaPtr);
    Tube currentTube;
    for (int i = 0; i < tubing.size; i++)
    {
        currentTube = TubeArrayGet(i, tubing);
        if (DoesNotCross(T, currentTube))
        {
            TubeIterativeAppend(currentTube, &array, arenaPtr);
        }
    }
    Tubing output = TubeIterativeFinalize(&array);
    return output;
}

int CountValidTubes(Tubing tubing, Arena *arenaPtr)
{
    if (tubing.size == 1)
    {
        return 1;
    }

    Tube firstTube = TubeArrayGet(0, tubing);
    Tubing firstRemoved = TubeArraySubCreate(1, tubing.size, tubing);
    Tubing validTubes = SelectValidTubes(firstTube, firstRemoved, arenaPtr);
    return CountValidTubes(firstRemoved, arenaPtr) + CountValidTubes(validTubes, arenaPtr);
}