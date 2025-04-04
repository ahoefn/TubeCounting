#ifndef TUBECOUNTING
#define TUBECOUNTING

#include <stdbool.h>
#include "../Tubes/Tubes.h"

Tubing GenConnectedTubes(int n, Arena *arenaPtr);
bool DoesNotCross(Tube t1, Tube t2);
Tubing SelectValidTubes(Tube T, Tubing tubing, Arena *arenaPtr);
int CountValidTubes(Tubing tubing, Arena *arenaPtr);

#endif