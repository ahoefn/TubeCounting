A small script that counts the number of tubings for an arbitrary diagram, based on a counting problem from [this paper](https://arxiv.org/pdf/2503.05866). (Specifically, see the table on p. 58 where this script computes N_f.) 

### Compiling

The code here can be compiled using the makefile (see dependencies), in particular simply run

  make

while in the TubeCounting directory, tben run

  ./.build/main.exe

to run the actual program. Alternatively, see the [release]() for a downloadable .exe version.

### Dependicies

[GNU make](https://www.gnu.org/software/make/) for building.
