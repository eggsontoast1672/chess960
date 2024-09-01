# Chess960

## Overview

Chess960 is a position generator for the Chess variant of the same name. In this
variant, the starting positions of the pieces on the back rank are randomized,
following a few rules. First, the bishops must be on opposite colors, and
second, the king must be between the rooks.

This variant is called Chess 960 because due to the rules governing the
starting positions of pieces, it turns out that there are 960 possible starting
positions.

## Compiling

Chess960 is written in pure C using the SDL2 library for graphics. In order
to compile the program, you need a C compiler, the SDL2 development files, the
SDL2-image development files, and `meson`.

Compiling is really easy. Simply set up meson in some directory, preferably
named `build`, and then compile the program. That can be done with the following
commands:

```bash
meson setup build
meson compile -C build
```

The resulting executable will be available in the build directory.

## Usage

This is not a difficult piece of software to use. Once you run the executable,
it will automatically generate the first position. After that, you can press
`g` to generate a new position. That's all there is to it.

## License

The code for this project is 100% public domain.

The images are licensed under CC BY-SA 3.0, see the license
[here](https://creativecommons.org/licenses/by-sa/3.0/). The images were
retrieved from
[greenchess.net](https://greenchess.net/info.php?item=downloads).
