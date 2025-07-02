# Crea una libreria chiamata conto_lib usando i file cpp indicati
add_library(conto_lib conto.cpp transazione.cpp)

# Rende disponibili gli header della directory corrente per chi include la libreria
target_include_directories(conto_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main_exec main.cpp)

# Collega l'eseguibile main_exec alla libreria conto_lib
target_link_libraries(main_exec conto_lib)

