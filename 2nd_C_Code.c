//Segundo programa em C!
#include <stdio.h>
int main (void) {

    int port;
    char ip[16];
    
    printf("Desec Security\n");
    printf("Digite o endereço IP:\n");
    scanf ("%s",&ip);

    printf("Digite a porta:\n");
    scanf ("%i",&port);
    printf("Varrendo o Host: %s na porta: %i \n",ip, port);

    return 0;
 



}