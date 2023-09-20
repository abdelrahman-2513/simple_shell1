#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

/*
 *  functions descleration
 */

void _prompt(void);
void command_execution(char *comm);
char *cpy_str(char *command1);
int isEmpty(char *command1);
int str_cmp(char *str1, char *str2);
int str_count(char *str);
void print_env(void);
char *get_path(char *command);
void str_cpy(char *str1, char *str2);
void str_cat(char *str1, char *str2);
char *get_env(char *str);
int cmp_indexes(char *str1, char *str2, int i);

#endif
