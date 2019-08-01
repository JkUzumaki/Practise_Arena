#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
	// open a file to server
	FILE *html_data;
	html_data = fopen("index.html", "r");

	char response_data[1024];
	fgets(response_data, 1024, html_data);

	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	strcat(http_header, response_data);
	
	//Create socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	//define address
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(8001);
	address.sin_addr.s_addr = INADDR_ANY;

	bind(server_socket, (struct sockaddr*) &address, sizeof(address));

	listen(server_socket, 5);
	
	int client_socket;
	while(1){
		client_socket = accept(server_socket, NULL, NULL);
		send(client_socket, http_header, sizeof(http_header), NULL);
	}
	close(client_socket);
	return 0;
}
