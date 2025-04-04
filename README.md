A small script that counts the number of tubings for an arbitrary diagram, based on a counting problem from [this paper](https://arxiv.org/pdf/2503.05866). (Specifically, see the table on p. 58 where this script computes N_f.) 

### Compiling

If the 'gcc' compiler and 'GNU make' are installed, the project can be build simply using

    make

while in the TubeCounting directory, and then 

    ./.build/main.exe

to run the actual program. If make is not installed, build using

    [your compiler] Source/main.c Source/Tubes/IterativeArray.c Source/Tubes/SubTubings.c Source/Tubes/Tubes.c Source/Counting/Counting.c Source/Utilities/Utilities.c Source/MemoryArena/ArenaArray/ArenaArrayFloat.c Source/MemoryArena/ArenaArray/ArenaArrayInt.c Source/MemoryArena/ArenaBase/ArenaBase.c -o .build/TubeCounting.exe

Alternatively, see the [release]() for a downloadable .exe version.

### Dependencies

(optional) [GNU make](https://www.gnu.org/software/make/) for building.
