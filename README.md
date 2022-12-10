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
($)_ls
Hello_World.c README.md simple_shell.h hsh etc...
($)_
($)_echo chicken nuggets
chicken nuggets
($)_
```
>"_" is a representation of the built in space in the above example
## Description

#### Syntax
```
($)[program/command name] [options] [argumemts]
```
When you run the `simple_shell` / `hsh` is run, a command line is written just as any other line interpreter.
`hsh` will attempt to execute the program name (searching into the PATH environment variable) with the given arguments specified by [options] you give it. There is a 100* character limit per line, including the new line character. All tab characters that are found should be ignored/removed in the code.
>*this could be wrong

## Files For hsh

The files needed for `hsh` to function correctly and their description below.

| File  | Description |
| ------------- |:-------------:|
| simple_shell.h      | This is the primary .h file containing most if not all prototypes and structs + more     |
| main.c      | This summons the different main functions together to make the shell     |
| SimpleShell.c      | This is the bulk of the shell, gets the pid, env, and parser.      |
| take_input.c      | This is an important component in actually using the shell as the name implies     |
| find_command_path.c      | This function finds command path/creates it     |
| errors.c      | This is what houses our main error checking function(s) and allows them to be displayed    |




## Process Walkthrough

### hsh:
1. Initialize: create_shell, assess if hsh will be interactive or running a script.
2. Invoke either:
    1. launch_repl if interactive mode
    2. read_script if not interactive
3. Once in interactive mode or not, parse_line will activate and access builtins and more.
4. parse_line calls on find_command_path to setup os_command_path to then pass to
5. create_new_process (self explanatory) but this takes the os*cp* command_args and env together
6. command_args uses take_input.c to do various things like splitting strings, making token buffers, and handling spaces and more.
7. Now of course once that is all done and you exit the program the memory will(should) be free'd up.

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

https://github.com/jorbian/holbertonschool-simple_shell
> you should already be here if you are viewing this


# End of README.md
