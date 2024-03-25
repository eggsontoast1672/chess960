# Chess960

## Overview

Chess960 is a position generator for the Chess variant of the same name. In
this variant, the starting positions of the pieces on the back rank are
randomized, following a few rules. First, the bishops must be on opposite
colors, and second, the king must be between the rooks.

This variant is called Chess 960 because due to the rules governing the
starting positions of pieces, it turns out that there are 960 possible starting
positions.

## Compiling

Chess960 is written in pure C using the SDL2 library for graphics. In order to
compile the program, you need a C compiler, the SDL2 development files,
`pkg-config` (sorry Windows users), and `CMake`.

One quick note about the `run.sh` script: it will check to see whether or not a
file called `compile_command.json` exists in a directory called `build`, and if
that is not the case, it will generate the build configuration. That means that
if you have not configured `CMake` to generate `compile_commands.json`, the run
script will not work.

### Method 1 (`compile_commands.json`)

If you have configured `CMake` to generate `compile_commands.json`, you're in
luck because this way is simpler. All you have to do is run the script `run.sh`
while you are in the root of the project, and everything will be taken care of.

```bash
$ ./run.sh
```

### Method 2 (no `compile_commands.json`)

If you haven't configured `CMake` to generate `compile_commands.json`, you can
still set it up manually. Just run the following command in the root of the
project to generate the build configuration:

```bash
$ cmake -S . -B build
```

Once the build configuration is generated, you can compile the code like so:

```bash
$ make -C build
```

And finally, to run the executable, you can execute this command:

```bash
$ build/chess960
```

## License

This is public domain software.
