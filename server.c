#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(){

	
	
	int client2Socket;
	struct sockaddr_in serverAddr;
	char buffer[1024]="hello";

	client2Socket = socket(AF_INET, SOCK_STREAM, 0);
	

	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(4444);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bind(client2Socket, (struct sockaddr*) &serverAddr, sizeof(serverAddr));
	listen(client2Socket,5);

	int client_socket=accept(client2Socket,NULL,NULL);
	while(1){
	send(client_socket, buffer, sizeof(buffer),0);
	recv(client_socket, buffer, 1024, 0);
	printf("%s",buffer);
	scanf("%s",&buffer);
}
	
	}



