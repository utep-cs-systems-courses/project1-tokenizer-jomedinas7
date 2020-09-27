Project 1: Tokenizer
====================
# Description

This project is a tokenizer for strings. Along with tokenizing a string, it
will add the string to a history that the user can recall. The tokenizer class
contains all of the methods for tokenizing, and the history class uses a
linked list(List) to maintain a history.

## How to compile

1. Inside the src directory, type "make" or "make Lab1". This will create a
Lab1 executable file.

2.Type "./Lab1" to run the executable.

3.Once finished, entering "make clean" will remove the executeable and any .o
files.

## Input commands

First the user will input strings or decide to move on to viewing the
history. When prompted:

* '&': will bring up another input field for the user to input a string.

* '@': will end the string input section and move on to the history viewing
  section.

The history will be printed once for the user, and then the user will be
allowed to recall a specific item from history.

* Entering any number within the length of the history list will recall that
 item in history.

* Any non-integer character will terminate the program.

