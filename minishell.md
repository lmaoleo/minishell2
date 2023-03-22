# Minishell1

**Binaty name:** mysh</br>
**language:** C</br>
**compilation:** via Makefile, including re, clean and fclean rules

You have to program a UNIX command interpreter.
This is one of the first step to be able to do 42sh project.

The interpreter is expected to display a prompt ($> for example) and then wait for you to write a command
line, which must be validated by a newline.

The prompt must be displayed again only after the command execution.
Only basic command lines are expected to executed; no pipes, redirections or any other advanced features.
The executables should be those found in the path, as indicated in the PATH variable.

If the executable cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.

You must correctly handle the PATH and the environment (by copying and restoring the initial env).
You must implement the following builtins: cd, setenv, unsetenv, env, exit.

Your env builtin hasrit to take any argument. Your unsetenv builtin hasnt to support the “*” wildcard.


## Authorized Functions

* malloc, free, exit, opendir, readdir, closedir, getcwd, chdir
* fork, stat, lstat, fstat, open, close, getline, strtok, strtok_r
* read, write, execve, access, isatty, wait, waitpid
* wait3, wait4, signal, kill, getpid, strerror, perror, strsignal
