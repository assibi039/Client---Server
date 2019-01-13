#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(){




	
	int clientSocket;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	

	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(4444);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int status=connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(status == -1)
	printf("error");
else{
	
	while(1){
	recv(clientSocket, buffer, 1024, 0);
	printf("%s",buffer);
	scanf("%s",&buffer);
	send(clientSocket, buffer, sizeof(buffer),0);
}
	


}
}
