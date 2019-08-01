#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "temp/Dsocket"
#define BUFFER_SIZE 128

int main()
{
	struct sockaddr_un addr;
	int i;
	int ret;
	int data_socket;
	char buffer[BUFFER_SIZE];
	//SOCKET
	data_socket = socket(AF_UNIX, SOCK_STREAM, 0);
	if(data_socket == -1){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	memset(&addr, 0, sizeof(struct sockaddr_un));
	
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);
	//CONNECT
	ret = connect(data_socket, (const struct sockaddr *)&addr, sizeof(struct sockaddr_un));
	if(ret == -1){
		fprintf(stderr, "The server is down\n");
		exit(EXIT_FAILURE);
	}

	do{
		printf("Enter the number to send to server\n");
		scanf("%d", &i);	
		ret = write(data_socket, &i, sizeof(int));
		if(ret == -1){
			perror("write");
			break;
		}
		printf("No of bytes sent = %d, data sent = %d\n", ret, i);	
	} while(i);

	//Request result
	memset(buffer, 0, BUFFER_SIZE);
	strncpy(buffer, "RES", strlen("RES"));
	buffer[strlen(buffer)] = '\0';
	printf("buffer = %s\n", buffer);
	//WRITE
	ret = write(data_socket, buffer, strlen(buffer));
	if(ret == -1){
		perror("write");
		exit(EXIT_FAILURE);
	}
	
	//Receive result
	memset(buffer, 0, BUFFER_SIZE);
	//READ
	ret = read(data_socket, buffer, BUFFER_SIZE);
	if(ret == -1){
		perror("read");
		exit(EXIT_FAILURE);
	}
	//ensure last element is zero
	buffer[BUFFER_SIZE -1] = 0;
	printf("Result = %s\n", buffer);
	//CLOSE
	close(data_socket);
	exit(EXIT_SUCCESS);
}
