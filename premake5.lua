workspace "chess960"
  language "C"
  configurations { "default" }

  project "chess960"
    kind "ConsoleApp"
    files { "**.c", "**.h" }
    includedirs { "include" }
    links { "SDL2", "SDL2_image" }
