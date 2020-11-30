cmake_minimum_required(VERSION 3.17)
project(RPOPhone C)

set(CMAKE_C_STANDARD 99)

add_executable(RPOPhone main.c db/fakeBaseEmulator.c phoneProfile/phoneProfile.c
        utilites/dynamicString.c utilites/file.c)