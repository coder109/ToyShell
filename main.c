#include "include/ToyShell.h"
#include "include/utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char* command = (char*)SafeMalloc(BUFFER_SIZE * sizeof(char));
  while(1) {
    printf("\x1b[31mToyShell> \x1b[0m");
    int status = ReadLine(command);
    if(status > 0) {
      char** token_list = ProcessLine(command);
      ExecuteCommand(token_list);
    } else if(status == INPUT_EOF) {
      printf("Exit!\n");
      break;
    } else if(status == ERR_EXPR_TOO_LONG) {
      FlushStdin();
    }
  }
  free(command);
  return 0;
}
