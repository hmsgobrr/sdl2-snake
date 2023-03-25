cmake_minimum_required(VERSION 3.0.0)
project(sdl2project VERSION 0.1.0)

include_directories(include)

add_executable(sdl2project src/main.cpp src/RenderWindow.cpp src/Game.cpp src/Sprite.cpp)

if (WIN32)
  # target_link_options(sdl2project PRIVATE "LINKER:--subsystem,windows -municode")
  target_link_libraries(sdl2project mingw32)
endif(WIN32)

target_link_libraries(sdl2project SDL2main SDL2 SDL2_image)
if (UNIX)
    target_link_libraries(sdl2project GL)
endif (UNIX)
