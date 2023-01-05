#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define DEFAULT_BUFLEN 512
#define PORT 2121



int main (int argc, char argv[]){
    int sock = socket (AF_INET, SOCK_STREAM,0);
    if (sock<0){
        perror("Socket");
        exit(1);
    }

    struct sockaddr_in server_adder;
    memset(&server_adder, 0, sizeof(server_adder));
    server_adder.sin_family = AF_INET;
    server_adder.sin_addr.s_addr = inet_addr (INADDR_ANY);
    server_adder.sin_port = htons(PORT);

    if (connect(sock,(struct sockaddr *)&server_adder, sizeof(server_adder))< 0){
        port_error("Connect");
        exit(1);
    }
    
    char buffer [1024];
    int bytes_recevied = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_recevied < 0 ){
        port_error("recv");
        exit(1);
    }

    printf("Data: %s\n", buffer);

    close(sock);

    return 0;





}