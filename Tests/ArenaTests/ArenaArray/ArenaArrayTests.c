#include <stdio.h>
#include <assert.h>

#include "../../../Source/MemoryArena/ArenaArray/ArenaArrayInt.h"
#include "../../../Source/MemoryArena/ArenaArray/ArenaArrayFloat.h"

void ArenaArrayIntCreateTest();
void ArenaArrayIntGetSetTest();
void ArenaArrayFloatCreateTest();
void ArenaArrayFloatGetSetTest();

void ArenaArrayTests()
{
    printf("Starting ArenaArrayTests.\n");
    ArenaArrayIntCreateTest();
    ArenaArrayIntGetSetTest();
    ArenaArrayFloatCreateTest();
    ArenaArrayFloatGetSetTest();
    printf("ArenaArrayTests completed.\n");
}
void ArenaArrayIntCreateTest()
{
    int size = 10;
    Arena arena = ArenaCreate(size * sizeof(int));
    ArenaArrayInt array = ArenaArrayIntCreate(size, &arena);
    assert(array.memory != NULL);
    assert(array.size == size);
    assert(arena.nextLocation == (arena.memoryPtr + size * sizeof(int)));
    printf("ArenaArrayIntCreateTest completed.\n");
}
void ArenaArrayIntGetSetTest()
{
    int sizeTotal = 20;
    int size1 = 8;
    int size2 = 12;
    Arena arena = ArenaCreate(sizeTotal * sizeof(int));
    ArenaArrayInt array1 = ArenaArrayIntCreate(size1, &arena);
    ArenaArrayInt array2 = ArenaArrayIntCreate(size2, &arena);

    for (int i = 0; i < size1; i++)
    {
        ArenaArrayIntSet(i, 5 - i, array1);
    }
    for (int i = 0; i < size2; i++)
    {
        ArenaArrayIntSet(i, 100 - 50 * i, array2);
    }
    for (int i = 0; i < size1; i++)
    {
        assert(ArenaArrayIntGet(i, array1) == 5 - i);
    }
    for (int i = 0; i < size2; i++)
    {
        assert(ArenaArrayIntGet(i, array2) == 100 - 50 * i);
    }
    printf("ArenaArrayIntGetSetTest completed.\n");
}

void ArenaArrayFloatCreateTest()
{
    int size = 10;
    Arena arena = ArenaCreate(size * sizeof(float));
    ArenaArrayFloat array = ArenaArrayFloatCreate(size, &arena);
    assert(array.memory != NULL);
    assert(array.size == size);
    assert(arena.nextLocation == (arena.memoryPtr + size * sizeof(float)));
    printf("ArenaArrayFloatCreateTest completed.\n");
}
void ArenaArrayFloatGetSetTest()
{
    int sizeTotal = 20;
    int size1 = 8;
    int size2 = 12;
    Arena arena = ArenaCreate(sizeTotal * sizeof(float));
    ArenaArrayFloat array1 = ArenaArrayFloatCreate(size1, &arena);
    ArenaArrayFloat array2 = ArenaArrayFloatCreate(size2, &arena);

    for (int i = 0; i < size1; i++)
    {
        ArenaArrayFloatSet(i, 5 - i, array1);
    }
    for (int i = 0; i < size2; i++)
    {
        ArenaArrayFloatSet(i, 100 - 50 * i, array2);
    }
    for (int i = 0; i < size1; i++)
    {
        assert(ArenaArrayFloatGet(i, array1) == 5 - i);
    }
    for (int i = 0; i < size2; i++)
    {
        assert(ArenaArrayFloatGet(i, array2) == 100 - 50 * i);
    }
    printf("ArenaArrayFloatGetSetTest completed.\n");
}