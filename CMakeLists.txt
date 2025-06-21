cmake_minimum_required(VERSION 3.29)
project(LAB_PROG_TRANSAZIONI_FINANZIARIE)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_PROG_TRANSAZIONI_FINANZIARIE src/main.cpp
        src/transazione.cpp
        src/transazione.h
        src/conto.cpp
        src/conto.h
        test/test_transazione.cpp
        test/test_conto.cpp
)
