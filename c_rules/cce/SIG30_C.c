#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

char *foo;

void int_handler(int signum) {
  _Exit(0);
}

int main(void) {
  foo = malloc(sizeof("Hello World."));
  if (foo == NULL) {
    /* handle error condition */
  }
  signal(SIGINT, int_handler);
  strcpy(foo, "Hello World.");
  puts(foo);
  free(foo);
  foo = NULL;
  return 0;
}
