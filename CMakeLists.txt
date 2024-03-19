cmake_minimum_required(VERSION 3.0)
project(tetris_mbg)

file(GLOB SRC_FILES "src/*.c")

add_executable(tetris_mbg ${SRC_FILES})
target_include_directories(tetris_mbg PUBLIC include)

install(TARGETS tetris_mbg DESTINATION /usr/local/bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION /usr/local/include)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/ DESTINATION /usr/local/src)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "mbg")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Tetris game")
include(CPack)

