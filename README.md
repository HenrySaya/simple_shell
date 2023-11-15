0x16. C - Simple Shell
Shell programs are applications that allows users to interact with computers.
In this project I undertook a simple shell project that will do and run commands juz like shell would.
Various files whereby each file handles a particulars task

### FILES
## shell.c
This file did the following and also followed he below structure
#structure
Displays a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word, therefore no arguments should be passed to programs.
If an executable cannot be found, it prints an error message and display the prompt again.
Handle errors.
handles the “end of file” condition (Ctrl+D)
