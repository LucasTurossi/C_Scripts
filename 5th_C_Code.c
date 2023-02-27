#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(void){

    int sock;
    int connection;

    struct sockaddr_in target;

    sock = socket (AF_INET, SOCK_STREAM, 0);
    target.sin_family = AF_INET;
    target.sin_port = htons (8058);
    target.sin_addr.s_addr = inet_addr("192.168.0.1");

    connection = connect(sock, (struct sockaddr *)&target, sizeof target);

    if (connection == 0){

        printf ("Porta Aberta \n");
        close(sock);
        close(connection);
    }

    else{

        printf("Porta fechada \n");

    }
}