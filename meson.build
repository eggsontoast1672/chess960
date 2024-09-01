project('chess960', 'c')

sources = [
  'src/board.c',
  'src/logging.c',
  'src/main.c',
  'src/piece.c',
  'src/position.c',
]

sdl2_dep = dependency('sdl2')
sdl2_image_dep = dependency('SDL2_image')

executable('chess960', sources, dependencies: [sdl2_dep, sdl2_image_dep])
