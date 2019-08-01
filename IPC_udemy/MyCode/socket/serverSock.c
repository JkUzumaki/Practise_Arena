#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_NAME "temp/Dsocket"
#define BUFFER_SIZE 128

int main()
{
	struct sockaddr_un name;
	
	int ret;
	int connection_socket;
	int data_socket;
	int result;
	int data;
	char buffer[BUFFER_SIZE];
	
	//Removes the existing socket of same name if found
	unlink(SOCKET_NAME);

	//Create new socket
	connection_socket = socket(AF_UNIX, SOCK_STREAM, 0);
	
	if(connection_socket == -1){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	printf("Master socket created\n");

	// Initialize
	memset(&name, 0, sizeof(struct sockaddr_un));
	
	// Specify socket values
	name.sun_family = AF_UNIX;
	strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);
	
	// Bind
	ret	= bind(connection_socket, (const struct sockaddr*) &name, sizeof(struct sockaddr_un));
	if(ret == -1){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	printf("bind call succeed\n");

	// Listen
	ret = listen(connection_socket, 20);
	if(ret == -1){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	for(;;){
		printf("Waiting for accept() call\n");
		data_socket = accept(connection_socket, NULL, NULL);
		if(data_socket == -1){
			perror("accept");
			exit(EXIT_FAILURE);
		}
		printf("Connection accepted from client\n");
		
		result = 0;
		for(;;){
			memset(buffer, 0, BUFFER_SIZE);
			printf("Waiting for data from client\n");
			ret = read(data_socket, buffer, BUFFER_SIZE);

			if(ret == -1){
				perror("read");
				exit(EXIT_FAILURE);
			}
			
			memcpy(&data, buffer, sizeof(int));
			if(data == 0) 
				break;
			result += data;
		}
		memset(buffer, 0, BUFFER_SIZE);
		sprintf(buffer, "Result = %d", result);
	
		printf("Sending the final result to the client\n");	
		ret = write(data_socket, buffer, BUFFER_SIZE);
		if(ret == -1){
			perror("write");
			exit(EXIT_FAILURE);
		}
		close(data_socket);
	}
	close(connection_socket);
	printf("connection closed...\n");
	
	unlink(SOCKET_NAME);
	exit(EXIT_SUCCESS);
}



