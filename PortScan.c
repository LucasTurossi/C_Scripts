#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc,char*argv[]){
    if (argc !=4){
        printf("Uso: %s <destino> <porta_inicial> <porta_final>\n", argv[0]);
        return 1;
    }
    char *destination = argv [1];
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    struct sockaddr_in target;
    int sock, connection;

    for (int port = start; port <= end; port++){
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1){
            perror("Erro ao criar socket");
            return 1;
        }

        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(destination);

        connection = connect(sock, (struct sockaddr *)&target, sizeof(target));
        if (connection == 0){
            printf("Porta %d aberta em %s\n", port, destination);
        }
        close(sock);

    }
    

}