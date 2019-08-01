#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>

#include <unistd.h>
int main()
{
	char server_msg[256] = "You have reached the server!";
	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	// definer the server address
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(9002);
	address.sin_addr.s_addr = INADDR_ANY;

	// bind the IP and Port
	bind(server_socket, (struct sockaddr*) &address, sizeof(address));

	// Listen function to start listening for the function
	listen(server_socket, 3);

	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);		

	// send the message
	send(client_socket, server_msg, sizeof(server_msg), 0);

	//close the socket
	close(server_socket);
	return 0;	
}
