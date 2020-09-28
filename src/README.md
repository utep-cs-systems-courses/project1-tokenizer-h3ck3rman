Project 1: Tokenizer
====================
## Summary

The program created allows the user to tokenize a sentence (separate words in
a sentence) and maintain a history of all the inputs throughout the execution of the program. Using
pointers to manipulate strings in the tokenizer class and a linked list in the
history class to store strings, various functions can be implemented together
into the UI and create a simple tokenizing program.

## Program Inputs

The program has the following input choices:
 - **'t'**: The user inputs a sentence and the tokenized words will be printed
 back to them, while also storing that sentence into the program's history.
 - **'h'**: Allows the user to view all previous inputs in a chronological
 list.
 - **'!'**: This input '!', followed by an id (number in the history) recalls
 the sentence with the matching id only.
 - **'q'**: Will quit the program, and clear the history that was stored while
 the program was running.

## How to Compile/Run

1. Open the file named 'src'.
2. Type 'make' in your computer, this will compile all the files and create an
executable file named 'token'.
3. Type './token' to run the program.
4. If the user wishes to remove the compiled files and the 'token' executable,
type 'make clean', which will clear those files from the source file.
