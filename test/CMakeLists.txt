# Include il modulo FetchContent, che serve per scaricare librerie esterne da URL (come GoogleTest)
include(FetchContent)

# Specifica dove scaricare GoogleTest: dalla versione più aggiornata su GitHub
FetchContent_Declare( googletest URL https://github.com/google/googletest/archive/refs/heads/main.zip)

# Scarica e rende disponibile GoogleTest nel progetto
FetchContent_MakeAvailable(googletest)

# Crea l'eseguibile di test chiamato "tests", compilando i file sorgente dei test
add_executable(tests test_conto.cpp test_transazione.cpp)

# Collega l'eseguibile "tests" alla libreria conto_lib e alla libreria GoogleTest (gtest_main)
target_link_libraries(tests conto_lib gtest_main)

# Include il modulo GoogleTest per registrare e scoprire i test
include(GoogleTest)

# Fa in modo che CTest possa eseguire automaticamente tutti i test trovati in "tests"
gtest_discover_tests(tests)

