cmake_minimum_required(VERSION 3.15)
project(sem2lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(sem2lab1 main.cpp DynamicArray.h Functions.h Sequence.h LinkedList.h ArraySequence.h LinkedListSequence.h QueueSequence.h ISorter.h Interface.h)