# <p align="center">C - Simple Shell</p>

## Table of Contents

-   [Objective](#Objective)
-   [Description](#Descritpion)
-   [Requirements](#Requirements)
-   [Compilation command](#Compilation-command)
-   [Mandatory Tasks](#Mandatory-tasks)
-   [Flowchart](#Flowchart)
-   [MAN page](#MAN-page)
-   [Installation](#Installation)
-   [Thanks](#Thanks)
-   [Authors](#Authors)

## Objective

Write a simple UNIX command language interpreter.

## Description
The "C - Simple Shell" project is about creating our own simplified version of the [shell]. Shell is a program taking commands from the keyboard and giving them to the operating system to perform.

It consists of a *command line interface* (CLI) (as opposed to a *graphical user interface*(GUI) available on most computer nowadays). Most Linux systems provide a program call *bash* (standing for Bourne Again SHell) an enhanced version of the original Unix shell program, *sh*, written by Steve Bourne, and acting a the shell program.

## Requirements

-   Allowed editors: `vi`, `vim`, `emacs`
-   All files will be compiled on Ubuntu 20.04 LTS
-   Code must follow the `Betty` style
-   All your files should end with a new line
-   A `README.md` file, at the root of the folder of the project is mandatory
-   Your shell should not have any memory leaks
-   No more than 5 functions per file
-   No more than functions per file
-   All your header files should be include guarded

## Compilation command

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Mandatory Tasks

### Task 0. README, man, AUTHORS

- Write a README
- Write a man for your shell.
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.

```
julien@ubuntu:~/shell$ ./shell 
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
julien@ubuntu:~/shell$
```

### Task 1. Betty would be proud

- Write a beautiful code that passes the Betty checks

### Task 2. Simple shell 0.1

- Write a UNIX command line interpreter.

    - Usage: ./hsh

- Your Shell should:

    - Display a prompt and wait for the user to type a command. A command line always ends with a new line.
    - The prompt is displayed again each time a command has been executed.
    - The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
    - The command lines are made only of one word. No arguments will be passed to programs.
    - If an executable cannot be found, print an error message and display the prompt again.
    - Handle errors.
    - You have to handle the “end of file” condition (Ctrl+D)

- You don’t have to:

    - use the PATH
    - implement built-ins
    - handle special characters : ", ', `, \, *, &, #
    - be able to move the cursor
    - handle commands with arguments

execve will be the core part of your Shell, don’t forget to pass the environ to it…

```
julien@ubuntu:~/shell$ ./shell
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
julien@ubuntu:~/shell$
```

### Task 3. Simple shell 0.2

- Simple shell 0.1 +
	
	- Handle command lines with arguments

### Task 4. Simple shell 0.3

- Simple shell 0.2 +

	- Handle the `PATH`
	- `fork` must not be called if the command doesn’t exist

```
julien@ubuntu:~/shell$ ./shell_0.3
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls -l /tmp 
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
:) ^C
julien@ubuntu:~/shell$
```

### Task 5. Simple shell 0.4

- Simple shell 0.3 +

    - Implement the `exit` built-in, that exits the shell
    - Usage: `exit`
    - You don’t have to handle any argument to the built-in `exit`

### Task 6. Simple shell 1.0

- Simple shell 0.4 +

    - Implement the `env` built-in, that prints the current environment

```
julien@ubuntu:~/shell$ ./simple_shell
$ env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ exit
julien@ubuntu:~/shell$
```

## Man page

```
Run man ./man_1_simple_shell
```

## Installation

### Install and run:

To install and run Simple Shell, follow these steps:

Clone the repository using the following command:

`
git clone https://github.com/mistWil/holbertonschool-simple_shell.git
`


Navigate to the directory where the repository was cloned.

Compile the program by running the following command:

`
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o .hsh
`

Run the program by typing the following command:

`
./hsh
`

### Using the Simple Shell:

To use our Simple Shell, type a command and press Enter.

The program will execute the command and display the output on the screen.

Here are some examples of commands that you can run:

- `ls`: list the contents of the current directory.
- `pwd`: print the path of the current working directory.
- `echo`: display a message on the screen.
- `mkdir`: create a new directory.
- `exit`: exit the shell.

## Thanks

Many warm thanks to all the Holberton School peers who helped and brought joy throughout the many challenges of this project.

## Authors

Julie Dedieu julie.dedieu1@gmail.com
Wilfried Leroulier <7448@holbertonstudents.com>
