#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

#define SERVER_IP "127.0.0.1"	// Local host
#define PORT 5555
#define BUFFER_SIZE 1024

int main(void)
{
	WSADATA wsaData;
	SOCKET clientSocket;
	struct sockaddr_in server;
	char buffer[BUFFER_SIZE] = { 0 };
	int receivedBytes;

	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("[ERROR %d] WSAStartup failed.\n", WSAGetLastError());
		return 1;
	}

	// Create socket
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET)
	{
		printf("[ERROR: %d] Socket creation failed.\n", WSAGetLastError());
		return 1;
	}

	// Setip server address structure
	server.sin_family = AF_INET;
	inet_pton(AF_INET, SERVER_IP, &server.sin_addr);
	server.sin_port = htons(PORT);

	// Connet to server
	if (connect(clientSocket, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		printf("[ERROR: %d] Connection to server failed.\n", WSAGetLastError());
		closesocket(clientSocket);
		return 1;
	}

	printf("Connected to server.\n");

	// Interaction Loop
	while (1)
	{
		printf("Enter message (type 'exit' to quit): ");
		fgets(buffer, BUFFER_SIZE, stdin);

		// Remove new line character
		buffer[strcspn(buffer, "\n")] = '\0';

		// Exit condition
		if (strcmp(buffer, "exit") == 0)
			break;

		// Send message to server
		send(clientSocket, buffer, (int)strlen(buffer), 0);

		// Recieve echoed message from server
		receivedBytes = recv(clientSocket, buffer, BUFFER_SIZE, 0);
		if (receivedBytes > 0)
		{
			buffer[receivedBytes] = '\0';
			printf("Echoed from server: %s\n", buffer);
		}
	}

	// Cleanup
	closesocket(clientSocket);
	WSACleanup();
	return 0;
}