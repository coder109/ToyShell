#ifndef __TOYSHELL_H__
#define __TOYSHELL_H__

#pragma once

#define BUFFER_SIZE 1024
#define MAX_PARAMETER_NUM 30
#define TOKEN_DELIMITER " \t\r\n\a"

// Status Code
#define SUCCESS 1
#define INPUT_EOF 0
#define ERR_EXPR_TOO_LONG -1
#define ERR_FAILED_TO_EXEC -2
#define ERR_FAILED_TO_CHDIR -3
#define ERR_NO_SUCH_DIR -4
#define ERR_WRONG_PARAMETER_FORMAT -5

int ReadLine(char* buffer);

char **ProcessLine(char *command);

int ExecuteCommand(char **token_list);

int Command_cd(char **args);

int Command_exit(char **args);

#endif
