#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <string.h>
#include<readline/readline.h>
#include<readline/history.h>

#include "repl.h"
#include "parser.h"
#include "tree.h"

int repl() {
  char exitMesg[] = "quit";
  /* Print Version and Exit Information */
  printf("LiCp Version 0.0.3\n");
  printf("Type \"%s\" to exit.\n", exitMesg);

  bool cont = true;
  while(cont) {
    char* input = readline("licp >> ");

    add_history(input);

    if(strcmp(exitMesg, input) == 0) {
      cont = false;
    }
    else if(strcmp("print", input) == 0) {
      printf("printing \n");
      printf(printTestTree());
      printf("\ndone\n");
    }
    else {
      symbolLoop(input);
      printf("\n");
    }
    free(input);
  }
  printf("Goodbye :_)\n");
  return 0;
}
