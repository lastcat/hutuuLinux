#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048
int main(){
  int line_number = 0;
  char buf[BUFFER_SIZE];
  while(fgets(buf, BUFFER_SIZE, stdin) != NULL){
    line_number++;
  }
  printf("line:%d\n", line_number);
}
