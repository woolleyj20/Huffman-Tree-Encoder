
##  Introduction
This lab was the final lab of of my Data Structures II class at Seattle Pacific University.  Through this class we studied many fundamental data structures,
and concluded with Huffman Tree encoding.  Our final lab project was to implement from scratch a program that can take a text file and encode by creating a Huffman Tree.  The file creates an encoded version and a file detailing the code created for each character in a table.  

##  Instructions
The executable `huffman` is already included in the project, and a test file of A Christmas Carol.  
Use the command `./huffman -encode dickens.txt dickens_encode.txt > dickens_table.txt`.  
This will create two files in the project directory.  The `dickens_encode.txt` file is the full text encoded and `dickens_table.txt` shows the table with the code per character

##  Project Files
- `main.cpp`:  Handles I/O operations with files, and starting the encoding process
- `FrequencyElement.cpp`: Custom object for characters that contains their count in the file and eventually their code from encoding
- `FrequencyTable.cpp`: Custom table with FrequencyElements with functions for printing the table and using the table to write an encoded file
- `HuffmanTree.cpp`: Logic and instructions for building a tree structure out of a FrequencyTable

##  Original Instructions
For documentation, you can see the original Readme below given by my instuctor that fueled the projct

~~~
# Encoding Text Files using Huffman Trees

## Purpose
The goal of this lab is to implement the Huffman Tree Encoding.

## Design
You are free to create the design to solve this problem. The general steps
for this program are:
1. Open the file for input and create the Frequency table.
1. Sort the Frequency Table on frequency.
1. Using the Frequency Table start creating the Huffman Tree from bottom up.
1. Once the tree is created, traverse it to create the code for each of the
symbols (character) found in the file. This will result in a Encoding Table.
1. Using the Encoding Table read the input file, and for each character use the table
to get the encoding and write the encoding into the output file.

## What is given?
You are given eight files:
- `test-file-0.txt` the first input file
- `test-file-0.table` the output to screen of the first input file
- `test-file-0.encoded` the output file of the first input file
- `test-file-1.txt` the second input file
- `test-file-1.table` the output to screen of the second input file
- `test-file-1.encoded` the output file of the second input file
- `test-file-2.txt` the third input file
- `test-file-2.table` the output to screen of the third input file
- `test-file-2.encoded` the output file of the third input file
- `test-file-3.txt` the fourth input file
- `test-file-3.table` the output to screen of the fourth input file
- `test-file-3.encoded` the output file of the fourth input file

## How the program is supposed to work

Ideally you should write a makefile, but you can compile the following way:
```
g++ yoursource1.cpp yoursource2.cpp -o huffman -std=c++11 -Wall
```
This will result in an executable name `huffman`, remember to specify the name of the exacutable in case you make your own `makefile`. The program should work with command line parameters the following way:
- `./huffman -encode inputfile outputfile`       
  - It will encode the file `inpufile` and create a file `outputfile` with the huffman encoding of the first file       

### Examples:
To encode a file named `mybook.txt` and put the encoding into a file named `myencodedbook.txt`:
```
./huffman -encode mybook.txt myencodedbook.txt
```

### Output to Screen
Your program should output the Coding Table in the screen using JSON-like format, as follows:
```
{key:   , code: 11}
{key:  a, code: 010}
{key:  e, code: 0010}
{key:  o, code: 0110}
{key:  u, code: 0111}
{key:  r, code: 1000}
{key:  n, code: 1010}
{key:  i, code: 1011}
{key:  l, code: 00001}
{key:  s, code: 00010}
{key:  d, code: 00110}
{key:  m, code: 10011}
{key:  p, code: 000000}
{key:  c, code: 000001}
{key: CR, code: 000110}
{key:  t, code: 000111}
{key:  g, code: 001111}
{key:  q, code: 100100}
{key:  b, code: 100101}
{key:  h, code: 0011100}
{key:  f, code: 00111010}
{key:  z, code: 00111011}
```
This is the output of the program when ran using `test-file-0.txt`. Things to notice:
- The file is sorted by encoding, shorter encodings first
- For certain characters, they are changed to be able to display:
  - CR for displaying charater `'\n'`
  - LF for displaying character `'\r'`

The encoded file (without extra challenge) will be a single line with 0 and 1 only.

## What is expected?
- Your code ***must*** compile.
- Your code ***must not*** compile with warnings.
- Your program ***must not*** crash.
- Your program is expected to implement a Tree Data Structure, there will be a code inspection to verify this.
- Every source file must contain header comments with the following format:
 ```
 /*
  Filename: huffmantree.h
  Description: Declaration of the class HuffmanTree to represent the binary Huffman Tree
  Author: McDonald Berger
  Date: 05/29/2019
  Course: Data Structures II
 */
 ```
- The program will be tested with the given files, and with additional files. Your grade will be calculated based on the screen output and file output. These outputs must be identical to the given outputs.
- Your code needs to show good programming practices: appropriate amount of
comments for your methods, indentation, meaningful
variable names, identifiers convention (CamelCase for functions, camelCase
for variables, _camelCase for data members, SNAKE_CASE for constants),
header comments, correct file names, etc. Failure to code appropriate will
result in strong points penalization.

## How to Test your Lab
Once you finished coding your lab you may want to test it to check it is correctly working. The steps would be:
1. Compile your program, make sure the executable name is `huffman`
1. Run the program using the first input file: `./huffman -enconde test-file-0.txt my-0.encoded > my.table`
1. Previous step will create files:
   1. `my-0.encoded` contains the encoded file `test-file-0.txt`
   1. `my-0.table` contains the output to screen that shows the Huffman Code Table
1. Compare the files, if there is no output, it means the files are identical and your program is working as expected.
   1. `diff test-file-0.encoded my-0.encoded` This will check if your encoded file is identical to the given file.
   1. `diff test-file-0.table my-0.table` This will check if your encoding table is identical to the given encoding table.

NOTE: If you are using the Windows command line, you will need to use `fc` instead of `diff`.
~~~
