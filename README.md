# simple_shell
A custom implementation of the sh (bourne shell) in C.

```
 ____   _                    _           ____   _            _  _ 
/ ___| (_) _ __ ___   _ __  | |  ___    / ___| | |__    ___ | || |      
\___ \ | || '_ ` _ \ | '_ \ | | / _ \   \___ \ | '_ \  / _ \| || |      
 ___) || || | | | | || |_) || ||  __/    ___) || | | ||  __/| || |      
|____/ |_||_| |_| |_|| .__/ |_| \___|   |____/ |_| |_| \___||_||_|      
                     |_|                                                                         

```
## Description
This is a simple implementation of a Unix shell, which is a command-line interface allowing users to interact with the operating system by entering and executing commands. The project aims to replicate some basic functionalities of the Unix shell.

## Getting Started
### Prerequisites
- A Unix-like operating system (Linux, macOS, etc.)
- GCC (GNU Compiler Collection) or any compatible C compiler

### Installation
1. Clone the repo
`git clone https://github.com/geoffreylgv/simple_shell.git`
2. Move to the directory
Run: `cd simple_shell`
3. Compilation
3.1. Compilation with Makefile
Type `root@laptop$ make`  
Run the program with `root@laptop$ make run`  
To clean it, run `root@laptop$ make clean`, it will remove the hsh program file in the directory.  
3.2. Traditional compilation
Type this command : `root@laptop$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`  
Then, run `./hsh` to execute the simple shell program

### Features
#### UNIX command line interpreter
##### Step 1
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition `(Ctrl+D)`
- `execve` will be the core part of your Shell, don’t forget to pass the environ to it…
##### Step 2
- Handle command lines with arguments
##### Step 3
- Handle the `PATH`
- `fork` must not be called if the command doesn’t exist
##### Step 4
- Implement the `exit` built-in, that exits the shell
- Usage: `exit`
- You don’t have to handle any argument to the built-in `exit`
##### Step 5
- Implement the `env` built-in, that prints the current environment

> ###  More information about `bourne shell`  
[Bourne Shell](https://en.wikipedia.org/wiki/Bourne_shell)

## Authors
[Geoffrey Logovi](https://github.com/geoffreylgv) | [Soufyane Halloumi](https://github.com/soofyane)
