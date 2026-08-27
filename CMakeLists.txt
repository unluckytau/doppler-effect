cmake_minimum_required(VERSION 3.10) #cmake version.

project(doppler-effect) # project name.

add_executable(doppler doppler.c) # can add one more `.c` and `.h` files.

target_link_libraries(my_game PRIVATE raylib) # link external libraries.
