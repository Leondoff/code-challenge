cmake_minimum_required(VERSION 3.26)
project(Question_4 C)

set(CMAKE_C_STANDARD 11)

include(CheckIncludeFile)
check_include_file(Question_4 main.c regex.h HAVE_REGEX_H)

add_executable(regex_example main.c)

if (HAVE_REGEX_H)
    target_link_libraries(regex_example regex)
endif()
