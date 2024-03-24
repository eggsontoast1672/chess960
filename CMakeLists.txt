cmake_minimum_required(VERSION 3.5)
project(Occident)

find_package(PkgConfig)
pkg_check_modules(SDL2 REQUIRED sdl2)

add_executable(occident src/main.c)
target_link_libraries(occident PRIVATE ${SDL2_LIBRARIES})
