cmake_minimum_required(VERSION 3.10)
project(huffman_woolleyj20)

set(CMAKE_CXX_STANDARD 14)

add_executable(huffman_woolleyj20
        main.cpp
        object.cpp object.h
        list.cpp list.h
        vsarray.cpp vsarray.h FrequencyElement.cpp FrequencyElement.h FrequencyTable.cpp FrequencyTable.h)
