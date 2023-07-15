cmake_minimum_required(VERSION 3.23)
project(maics)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(maics main.cpp TTarget.cpp TTarget.h functions.cpp functions.h TRLS.cpp TRLS.h)

set_target_properties(maics PROPERTIES LINK_FLAGS "-static")
