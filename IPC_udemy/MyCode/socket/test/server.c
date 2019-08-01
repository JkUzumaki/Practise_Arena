#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/un.h>

#include<stdlib.h>
#include<string.h>

#define SOCKET_NAME "Test"
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

	unlink(SOCKET_NAME);
	//SOCKET
	connection_socket = socket(AF_UNIX, SOCK_STREAM, 0);
	if(connection_socket == -1){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	printf("Master socket created\n");

	//initialize
	memset(&name, 0, sizeof(struct sockaddr_un));
	//assign
	name.sun_family = AF_UNIX;
	strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);
	
	//BIND
	ret = bind(connection_socket, (const struct sockaddr*)&name, sizeof(struct sockaddr_un));
	if(ret == -1){
		perror("Bind");
		exit(EXIT_FAILURE);
	}
	printf("Bind call completed\n");

	//LISTEN
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
		printf("Connection accepted at client\n");
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
		printf("Sending the final result to client\n");
		ret = write(data_socket, buffer, BUFFER_SIZE);
		if(ret == -1){
			perror("write");
			exit(EXIT_FAILURE);
		}
		close(data_socket);
	}
	close(connection_socket);
	printf("connection closed..\n");
	unlink(SOCKET_NAME);
	exit(EXIT_SUCCESS);
}
