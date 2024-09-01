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
compile the program, you need the following programs:

- A C compiler
- SDL2 development files
- SDL2 image development files
- A POSIX compliant shell
- GNU Make
- `pkg-config`

All of that is pretty standard. The reason why you need a POSIX compliant shell
is that the `configure` script expects it. Fish users: you are free to try your
luck, but there are no promises here that it will work.

Building from source is easy as pie, just perform the classic GNU incantation
(provided below). Bear in mind that if you are attempting to install to a
directory that requires root permissions to modify, you will need to run `sudo
make install`.

```bash
$ ./configure && make && make install
```

If you'd like to install into a different directory such as `~/.local`, you
can pass the `--prefix` flag to the configure script, supplying it the install
prefix. For instance, if you wanted to install to `~/.local`, you would run the
following command:

```bash
$ ./configure --prefix ${HOME}/.local && make && make install
```

For more information regarding the GNU build system, refer to their
documentation
[here](https://www.gnu.org/software/automake/manual/html_node/index.html).

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
