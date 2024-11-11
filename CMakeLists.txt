cmake_minimum_required(VERSION 3.29)
project(all C)

set(CMAKE_C_STANDARD 99)


add_executable(leitores_escritores leitores_escritores.c)
add_executable(barreiras barreiras.c)
add_executable(sinais sinais.c)
add_executable(deadlock deadlock.c)


target_link_libraries(leitores_escritores pthread)
target_link_libraries(barreiras pthread)
target_link_libraries(sinais pthread)
target_link_libraries(deadlock pthread)
