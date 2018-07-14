project(LOG_ANALYZER)

set(SRC src/main.cc
        src/logs.cc
        src/toJson.cc
        src/timerange.cc
        src/timestamp.cc
        src/query_handler.cc)

set(CMAKE_C_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -g -pthread")

include_directories(src)

add_executable(log_analyzer ${SRC})

target_link_libraries(log_analyzer pistache)

cmake_minimum_required(VERSION 3.5)

#add_executable(speed_test
#               tests/test.cc
#               src/logs.cc
#               src/toJson.cc
#               src/timerange.cc
#               src/timestamp.cc)
