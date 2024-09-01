project('chess960', 'c')

sources = [
  'src/asset.c',
  'src/board.c',
  'src/logging.c',
  'src/main.c',
  'src/piece.c',
  'src/position.c',
  'src/util.c',
]

sdl2_dep = dependency('sdl2')
sdl2_image_dep = dependency('SDL2_image')

executable('chess960', sources,
  dependencies: [sdl2_dep, sdl2_image_dep],
  install: true,
)

images = [
  'assets/black-bishop.png',
  'assets/black-king.png',
  'assets/black-knight.png',
  'assets/black-pawn.png',
  'assets/black-queen.png',
  'assets/black-rook.png',
  'assets/white-bishop.png',
  'assets/white-king.png',
  'assets/white-knight.png',
  'assets/white-pawn.png',
  'assets/white-queen.png',
  'assets/white-rook.png',
]

install_data(images)
