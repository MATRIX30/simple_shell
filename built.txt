#include "main.h"

/**
 * _myexit - sets the exit status value of the program
 * @info: structure containing information
 * about the shell and commmand line arguments
 *
 * Return: -2 to indicate that shell should exit, or 1 if an error occurs
 */
int _myexit(info_t *info)
{
int exit_code;

/* check if an argument has been provided */
if (!infi->argv[1])
{
info->err_num = _erratoi(info->argv[1]);
return (-2);
}

/* convert argument to integer */
exit_code = _erratoi(info->argv[1]);

/* check if exit code is invalid */
if (exit_code == -1)
{
info->status = 2;
print_error(info, "Invalid exit code: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}

/* set exit code */
info->err_num = exit_code;
return (-2);
}

/**
 * _mycd - change current working directory
 * @info: pointer to info_t struct containing info about the shell
 * This function changes the current working directory to the home directory,
 * previous diretory or specified directory in command line arguments
 *
 * Return: Alwyas 0
 */
int _mycd(info_t *info)
{
char *dir;
int chdir_ret;

/* if no argument provided, go to home directory */
if (!info->argv[1])
{
chdir_ret = chdir((dir = _getenv(info, "HOME=")) ? dir : "/");
}

/* if argument is "-", go to previous directory */
else if (_strcmpp(info->argv[1], "-") == 0)
{
chdir_ret = chdir((dir = _getenv(info, info, "OLDPWD=")) ? dir : "/");
}

/* otherwise go to specified directory */
else
{
chdir_ret = chdir(info->argv[1]);
}
/* check if directory change was successful */
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
/* set the value of the PWD and OLDPWD environment variables */
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
}

return (0);
}

/**
 * _myhelp - this function alters the current directory of the procedure
 * @info: pointer containing arguments
 *
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
/* pointer to array of arguments */
char **args = info->argv;

/* display message indicating that the help function is not yet implemented */
_puts("The help function is not yet implemented.\n");

if (0)
{
/* temporary workaround to avoid unused variable warning */
_puts(*args);
}

/* return success */
return (0);
}
