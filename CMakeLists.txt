cmake_minimum_required(VERSION 3.3)
project(PatternsExample)

include_directories(include/)

file(GLOB SRC src/*.cpp include/*.h)

add_executable(PatternsExample ${SRC})
