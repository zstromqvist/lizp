#include <stdio.h>
#include <stdlib.h>

// make win possible, sigh
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// fake functions
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = '\n';
  return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {
  
  // basic info
  puts("Lizp version 0.0.1");
  puts("Press Ctrl+c to exit\n");

  // the meat
  while(1) {
    
    // output prompt
    char* input = readline("lizp> ");

    // add input to history
    add_history(input);

    // answer
    printf("No you are a %s\n", input);
    
    // free the input from memory
    free(input);
  }

  return 0;

}
