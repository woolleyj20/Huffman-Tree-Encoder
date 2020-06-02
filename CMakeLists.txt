cmake_minimum_required(VERSION 3.10)
project(huffman_woolleyj20)

set(CMAKE_CXX_STANDARD 14)

add_executable(huffman
        main.cpp
        FrequencyElement.cpp FrequencyElement.h
        FrequencyTable.cpp FrequencyTable.h
        HuffmanTree.cpp HuffmanTree.h)
