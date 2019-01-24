cmake_minimum_required(VERSION 3.13)
project(02_Pthread_wrapper)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 14 pthread)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -pthread -lm")

find_package(Threads)

set (
        SOURCE_FILES
        main.cpp

        sem.h
        sem.cpp

        workerbase.h
        workerbase.cpp

        testthread.h
        testthread.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
