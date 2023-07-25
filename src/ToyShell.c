#include "../include/ToyShell.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

int ReadLine(char* buffer) {
  int buffer_pivot = 0;
  int buffer_length = 0;

  while(1) {
    if(buffer_pivot == BUFFER_SIZE) {
      printf("The expression is too long to process.\n");
      return ERR_EXPR_TOO_LONG;
    }
    
    char current_char = getchar();
    if(current_char == '\n') {
      buffer[buffer_pivot++] = '\0';
      break;
    } else if(current_char == EOF){
      return INPUT_EOF;
    } else {
      buffer[buffer_pivot++] = current_char;
    }
  }

  buffer_length = strlen(buffer);
  return buffer_length;
}

char** ProcessLine(char* command) {
  char** command_tokens = (char**)SafeMalloc(sizeof(char) * BUFFER_SIZE);
  char* token;
  int command_tokens_index = 0;

  token = strtok(command, TOKEN_DELIMITER);
  while(token != NULL) {
    command_tokens[command_tokens_index++] = token;
    token = strtok(NULL, TOKEN_DELIMITER);
  }

  command_tokens[command_tokens_index] = NULL;
  return command_tokens;
}

int ExecuteCommand(char **token_list) {
  pid_t command_pid;
  int status = 0;
  if(token_list[0] == NULL) {
    return SUCCESS;
  } else {
    if(strcmp(token_list[0], "cd") == 0) {
      return Command_cd(token_list);
    } else if(strcmp(token_list[0], "exit") == 0) {
      return Command_exit(token_list);
    }
  }
  command_pid = fork();
  if(command_pid == 0) {
    if(execvp(token_list[0], token_list) == -1) {
      perror("Execute Error");
      exit(0);
      return ERR_FAILED_TO_EXEC;
    }
  } else if(command_pid > 0) {
    wait(&status);
  } else {
    perror("Fork Error");
    exit(0);
  }
  free(token_list);
  return SUCCESS;
}

int Command_cd(char **args) {
  if(args[1] == NULL) {
    printf("Change to home dir\n");
    chdir("~");
  } else {
    if(chdir(args[1]) != 0) {
      printf("Failed to change dir\n");
      return ERR_FAILED_TO_CHDIR;
    }
    printf("Changed to dir %s\n", args[1]);
  }
  return SUCCESS;
}

int Command_exit(char** args) { return SUCCESS; }
