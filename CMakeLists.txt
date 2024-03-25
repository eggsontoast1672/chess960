cmake_minimum_required(VERSION 3.5)
project(Chess960)

find_package(PkgConfig)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

add_executable(chess960 src/main.c src/piece.c)
target_compile_definitions(chess960 PRIVATE LOAD_SVG)
target_include_directories(chess960 PRIVATE include)
target_link_libraries(chess960 PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

add_custom_target(run COMMAND chess960 DEPENDS chess960)
