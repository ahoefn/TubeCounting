#include "ArenaTests.h"
#include "ArenaBase/ArenaBaseTests.h"
#include "ArenaArray/ArenaArrayTests.h"

void ArenaTests()
{
    printf("Starting ArenaTests.\n");
    ArenaBaseTests();
    ArenaArrayTests();
    printf("ArenaTests completed.\n");
}