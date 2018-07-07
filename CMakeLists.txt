project(LOG_ANALYZER)

set(SRC src/main.cc
        src/logs.cc
        src/timestamp.cc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

include_directories(src)

add_executable(log_analyzer ${SRC})

cmake_minimum_required(VERSION 3.5)

#add_custom_target(check COMMAND ../tests/testsuite.sh)
