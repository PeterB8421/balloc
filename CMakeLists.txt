cmake_minimum_required(VERSION 3.17)
project(balloc C)

include_directories(include)

add_library(balloc SHARED src/balloc.c)

set_property(TARGET balloc PROPERTY C_STANDARD 99)


