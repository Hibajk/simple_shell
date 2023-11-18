#include "shell.h"

/**
 * shell_exit - a function that exits the shell
 * @cmd: the given command
 * @argv: arguments
 * @sts: exit status
 * @idx: index of the command
 */

void shell_exit(char **cmd, char **argv, int *sts, int idx)
{
int exit_value = *sts;
char *index, mssg[] = ": exit: Illegal number: ";
char idx_str[20];

if (cmd[1])
{
if (!positive_int(cmd[1]))
{
snprintf(idx_str, sizeof(idx_str), "%d", idx);
index = _intoa(idx);

write(STDERR_FILENO, argv[0], _strlen(argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index, _strlen(index));
write(STDERR_FILENO, mssg, _strlen(mssg));
write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
write(STDERR_FILENO, "\n", 1);
free(index);
free(cmd);
free2DArray(cmd);
(*sts) = 2;
return;

}
free(cmd);
free2DArray(cmd);
exit(exit_value)
}
