cmake_minimum_required (VERSION 2.8)

project (Tetris)

aux_source_directory(. SRC_LIST)

add_executable(main ${SRC_LIST})