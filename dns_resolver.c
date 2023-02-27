#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){

    if (argc <= 1){
        printf("Modo de uso: ./dns_resolver domínio.com \n");
        return 0;
    }
    else{
        struct hostent *domain = gethostbyname (argv[1]);

        if (domain == NULL){
            printf ("Ocorreu um erro! \n");
    }
        else{
            printf ("IP: %s \n",inet_ntoa(*((struct in_addr *)domain->h_addr)));
    
    }
    }

}