#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

#define SERVER_IP "127.0.0.1"	// Local host
#define PORT 6013
#define BUFFER_SIZE 1024

int main(void)
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("[ERROR: %d] WSAStartup failed.\n", WSAGetLastError());
		return 1;
	}

	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET)
	{
		printf("[ERROR: %d] Socket creation failed.\n", WSAGetLastError());
		return 1;
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	inet_pton(AF_INET, SERVER_IP, &server.sin_addr);
	server.sin_port = htons(PORT);

	if (connect(clientSocket, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		printf("[ERROR: %d] Connection to server failed.\n", WSAGetLastError());
		closesocket(clientSocket);
		return 1;
	}

	printf("Connected to server.\n");

	while (1)
	{
		char buffer[BUFFER_SIZE] = { 0 };

		int receivedBytes = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
		if (receivedBytes > 0)
		{
			buffer[receivedBytes] = '\0';
			printf("Date from server: %s\n", buffer);
			break;
		}
	}

	closesocket(clientSocket);
	WSACleanup();
	return 0;
}