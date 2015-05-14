#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  //オプション解析部: -n:改行変換 -t:タブ変換
  int opt;
  int n_flag = 0;
  int t_flag = 0;
  while((opt = getopt(argc, argv, "nt")) != -1){
    switch(opt){
      case 'n':
        n_flag = 1;
        break;
      case 't':
        t_flag = 1;
        break;
      case '?':
        break;
    }
  }

  int i;
  for(i = 1; i < argc; i++){
    FILE *f;
    int c;

    f = fopen(argv[i], "r");
    if(!f){
      perror(argv[i]);
      exit(1);
    }
    //適当
    while((c = fgetc(f)) != EOF){
      if((c == '\t') && t_flag){
        putchar('\\');
        putchar('t');
      }
      else if(c == '\n' && n_flag){
        putchar('$');
        putchar('\n');
      }
      else if (putchar(c) < 0) exit(1);
    }
    fclose(f);
  }
  exit(0);
}
