#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[argc])
{
  // Buffer
  int size = 2048;
  char input[size];
  char exitMesg[] = "quit\n";

  /* Print Version and Exit Information */
  puts("LiCp Version 0.0.0.0.1");
  puts("Type \"quit\" to exit.\n");

  bool cont = true;
  while(cont){
    printf("licp >> ");
    fgets(input, size, stdin);
    if(strcmp(exitMesg, input) == 0){
      cont = false;
    }
    else{
      printf("What is %s", input);
    }
  }
  printf("Quitting\n");
  return 0;
}
