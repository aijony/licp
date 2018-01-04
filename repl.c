#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <string.h>
#include <histedit.h>
#include <editline/readline.h>

int main(int argc, char *argv[argc])
{
  char exitMesg[] = "quit";
  /* Print Version and Exit Information */
  printf("LiCp Version 0.0.0.0.2");
  printf("Type \"%s\" to exit.\n", exitMesg);

  bool cont = true;
  while(cont){
    char* input = readline("licp >> ");

    add_history(input);

    if(strcmp(exitMesg, input) == 0){
      cont = false;
    }
    else{
      printf("What is %s", "quit\n");
    }
    free(input);
  }
  printf("Quitting\n");
  return 0;
}
