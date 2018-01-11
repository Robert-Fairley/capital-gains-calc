cmake_minimum_required(VERSION 3.9)
project(capital_gains_calc C)

set(CMAKE_C_STANDARD 99)

add_executable(capital_gains_calc main.c CRA.h CRA.c)