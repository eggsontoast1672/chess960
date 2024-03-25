#!/bin/sh

if [ ! -f build/compile_commands.json ]; then
    cmake -S . -B build
fi

ninja -C build run
