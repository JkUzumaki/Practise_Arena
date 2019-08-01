#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>
int main()
{
	// Create a socket
	int nw_socket;
	nw_socket = socket(AF_INET, SOCK_STREAM, 0);
	// Specify an address to socket
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(9002);
	address.sin_addr.s_addr = INADDR_ANY;
	// Establish connection
	int connect_status = connect(nw_socket, (struct sockaddr*) &address, sizeof(address));
	if(connect_status == -1)
		printf("Error in making connection to the remote server\n\n");
	// Received data from server	
	char response[256];
	recv(nw_socket, &response, sizeof(response), 0);
	// Response data from server
	printf("The server sent the data: %s\n", response);
	close(nw_socket);
	return 0;
}
