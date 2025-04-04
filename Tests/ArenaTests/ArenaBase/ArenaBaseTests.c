#include "../../../Source/MemoryArena/ArenaBase/ArenaBase.h"

void ArenaAllocTest();
void ArenaCreateDeleteTest();

void ArenaBaseTests()
{
    ArenaCreateDeleteTest();
    ArenaAllocTest();
    printf("Arena Base tests completed.\n");
}

void ArenaAllocTest()
{
    // Setup:
    int lengthTotal = 6;
    int lengthBuf1 = 4;
    int lengthBuf2 = 2;
    Arena arena = ArenaCreate(lengthTotal * sizeof(int));

    assert(arena.memoryPtr + lengthTotal * sizeof(int) == arena.end);
    assert(arena.nextLocation == arena.memoryPtr);

    int *buf11 = (int *)ArenaAlloc(lengthBuf1 * sizeof(int), &arena);

    assert(arena.memoryPtr + lengthBuf1 * sizeof(int) == arena.nextLocation);

    int *buf12 = (int *)ArenaAlloc(lengthBuf2 * sizeof(int), &arena);

    assert(arena.memoryPtr + (lengthBuf1 + lengthBuf2) * sizeof(int) == arena.nextLocation);
    // Initialize arrays
    for (int i = 0; i < lengthBuf1; i++)
    {
        buf11[i] = 1;
    }
    for (int i = 0; i < lengthBuf2; i++)
    {
        buf12[i] = 2;
    }

    // Check:
    int currentInt;
    for (int i = 0; i < lengthTotal; i++)
    {
        currentInt = *(arena.memoryPtr + i * sizeof(int));
        // printf("i is %d, currentInt is %d\n", i, currentInt);
        if (i < lengthBuf1)
        {
            assert(currentInt == 1);
        }

        if ((lengthBuf1 < i) & (i < lengthBuf1 + lengthBuf2))
        {
            assert(currentInt == 2);
        }
    }
    printf("ArenaAllocTest completed.\n");
}

void ArenaCreateDeleteTest()
{
    int size = 100;
    Arena arena = ArenaCreate(size);
    assert(arena.memoryPtr != NULL);
    assert(arena.nextLocation == arena.memoryPtr);
    assert(arena.end == arena.memoryPtr + size);

    ArenaDelete(&arena);
    assert(arena.memoryPtr == NULL);
    assert(arena.nextLocation == NULL);
    assert(arena.end == NULL);

    printf("ArenaCreateDeleteTest completed.\n");
}
