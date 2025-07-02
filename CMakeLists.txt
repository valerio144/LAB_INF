cmake_minimum_required(VERSION 3.14)

project(ContoTransazioni)

set(CMAKE_CXX_STANDARD 17)

# Abilita il supporto alla funzione "enable_testing()" (necessario per GoogleTest)
enable_testing()

# Aggiunge la sotto-directory "src" e "test"
add_subdirectory(src)
add_subdirectory(test)


