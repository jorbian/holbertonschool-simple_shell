# Jon Boller and Evan Richardson's Simple Shell

## Welcome to our Simple Shell Project!
I will try and give a decent explanation/overview of our project for you all to enjoy.

## How to use the Simple Shell
You must first compile all the .c files in the repository. Then execute the resulting file.
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 $filename -o hsh
```
When the hsh executable is run, the hsh prompt will be shown. It should look like this
```
$./hsh
($)_ /* You can type commands here */
```
After you have entered into the hsh prompt you can enter commands such as ls to make a list of files and display them:
```
($)ls
Hello_World.c
README.md
simple_shell.h
hsh
etc...
($)_
```
## Description

#### Syntax
```
($)[program/command name] [options]
```
When you run the `simple_shell` / `hsh` is run, a command line is written just as any other line interpreter.
`hsh` will attempt to execute the program name (searching into the PATH environment variable) with the given arguments specified by [options] you give it. There is a 100 character limit per line, including the new line character. All tab characters that are found should be ignored/removed in the code.


## Files

The files needed for `hsh` to function correctly and their description below.

| File  | Description |
| ------------- |:-------------:|
| simple_shell.h      | This is the primary .h file containing most if not all prototypes and structs + more     |
| main.c      | This will of course be the main file that lets everything connect together and run     |
| SimpleShell.c      | This will house all the functions related to interpreting commands     |
| UserInterface.c      | This is the main component to making and using the UI     |
| ScriptReader.c      | This reads the scripts and makes sure to check for errors     |
| left baz      | right baz     |
| left foo      | right foo     |
| left bar      | right bar     |
| left baz      | right baz     |



## Low or High Level Description //placeholdernameidk

### Main.c:
1. Initialize the CommandParser
2. Assess if hsh will be interactive or running a script
3. Invoke either:
    1. int execute_script(&parser, filename);
    2. int open_repl(&parser);
4. For either: return an error message or not.
5. Free the parser and exit.

## Allowed Functions List:
* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `getpid` (man 2 getpid)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror` (man 3 perror)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__xstat)(man 2 stat)
* `lstat` (__lxstat)(man 2 lstat)
* `fstat` (__fxstat)(man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)



## Links

You may be using [Markdown Live Preview](https://markdownlivepreview.com/).

## Blockquotes

> Markdown is a lightweight markup language with plain-text-formatting syntax, created in 2004 by John Gruber with Aaron Swartz.
>
>> Markdown is often used to format readme files, for writing messages in online discussion forums, and to create rich text using a plain text editor.

## Formatting

| Left columns  | Right columns |
| ------------- |:-------------:|
| left foo      | right foo     |
| left bar      | right bar     |
| left baz      | right baz     |

# End of README.md