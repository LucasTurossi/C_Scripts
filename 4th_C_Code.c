#include <stdio.h>

int main(int argc, char *argv[]){

  int host;
  if(argc<2){
  
    printf("Modo de uso: ./program 192.168.0. 443 \n");
  }
else{
  for(host=1;host<=254; host++) {
  printf("Varrendo o host %s.%i na porta %s \n", argv[1], host);
  
    }
  }  
}