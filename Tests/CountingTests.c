#include "../Source/Counting/Counting.h"

void DoesNotCrossTest()
{
    Tube T1 = TubeCreate(2, 3);
    Tube T2 = TubeCreate(3, 3);
    assert(DoesNotCross(T1, T2));

    T2 = TubeCreate(2, 4);
    assert(DoesNotCross(T1, T2));

    T1 = TubeCreate(1, 3);

    assert(!DoesNotCross(T1, T2));
    printf("DoesnotCross test completed.\n");
}
void GenConnectedTubesTest()
{
    int n = 3;
    int size = n * (n + 1) / 2;
    Arena arena = ArenaCreate(size * sizeof(Tube));
    Tubing connectedTubes = GenConnectedTubes(n, &arena);

    // Generate counts for all possible values (such that we are free to permute)
    int T00count = 0;
    int T01count = 0;
    int T02count = 0;
    int T11count = 0;
    int T12count = 0;
    int T22count = 0;

    Tube tube;
    for (int i = 0; i < size; i++)
    {
        tube = TubeArrayGet(i, connectedTubes);
        assert(tube.start <= tube.end);
        // printf("tube %d, start: %d, end: %d\n", i, tube.start, tube.end);

        // Start counting of the different cases:
        switch (tube.start)
        {
        case 0:
            if (tube.end == 0)
            {
                T00count += 1;
            }
            if (tube.end == 1)
            {
                T01count += 1;
            }
            if (tube.end == 2)
            {
                T02count += 1;
            }
            break;
        case 1:
            if (tube.end == 1)
            {
                T11count += 1;
            }
            if (tube.end == 2)
            {
                T12count += 1;
            }
            break;
        case 2:
            if (tube.end == 2)
            {
                T22count += 1;
            }
            break;
        }
    }
    assert(T00count == 1);
    assert(T01count == 1);
    assert(T02count == 1);
    assert(T11count == 1);
    assert(T12count == 1);
    assert(T22count == 1);
    ArenaDelete(&arena);

    printf("GenConnectedTubes test completed.\n");
}

void SelectionTest()
{
    int n = 3;
    int size = n * (n + 1) / 2;
    Arena arena = ArenaCreate(2 * size * sizeof(Tube));
    Tubing connectedTubes = GenConnectedTubes(n, &arena);

    Tube testTube = TubeCreate(1, 1);
    Tubing output = SelectValidTubes(testTube, connectedTubes, &arena);

    int outputList[3 * 3] = {0};
    int expectedOutputList[3 * 3] = {0};

    Tube currentTube, expectedTube;
    for (int i = 0; i < output.size; i++)
    {
        currentTube = TubeArrayGet(i, output);
        expectedTube = TubeArrayGet(i, connectedTubes);
        outputList[currentTube.start + 3 * currentTube.end]++;
        expectedOutputList[expectedTube.start + 3 * expectedTube.end]++;
    }
    for (int i = 0; i < 3 * 3; i++)
    {
        assert(outputList[i] == expectedOutputList[i]);
    }
    ArenaDelete(&arena);
    printf("Selection test completed.\n");
}

void CountingTests()
{
    printf("Starting counting tests.\n");
    DoesNotCrossTest();
    GenConnectedTubesTest();
    SelectionTest();
    printf("Counting tests done.\n");
}
