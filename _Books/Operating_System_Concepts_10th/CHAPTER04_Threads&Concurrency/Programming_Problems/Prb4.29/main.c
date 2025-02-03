#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 5555
#define BUFFER_SIZE 1024

DWORD WINAPI Echo(LPVOID Param);


int main(void)
{
	WSADATA wsaData;
	SOCKET serverSocket, clientSocket;
	DWORD ThreadId;
	HANDLE ThreadHandle;
	struct sockaddr_in server, client;
	int clientSize;

	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("[ERROR: %d] WSAStartup failed.\n", WSAGetLastError());
		return 1;
	}

	// Create socket
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET)
	{
		printf("[ERROR: %d] Socket creation failed.\n", WSAGetLastError());
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}

	// Setup server address
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	// Bind socket
	if (bind(serverSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("[ERROR: %d] Bind failed.\n", WSAGetLastError());
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}

	// Listen for connections
	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		printf("[ERROR: %d] Listen failed.\n", WSAGetLastError());
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}

	printf("Server is listening on port %d\n", PORT);

	clientSize = sizeof(client);
	while (1)
	{
		clientSocket = accept(serverSocket, (struct sockaddr*)&client, &clientSize);
		if (clientSocket == INVALID_SOCKET)
		{
			printf("[ERROR: %d] Accept failed.\n", WSAGetLastError());
			closesocket(serverSocket);
			closesocket(clientSocket);
			WSACleanup();
			return 1;
		}

		// Create thread
		SOCKET* clientSocketPtr = malloc(sizeof(SOCKET));
		*clientSocketPtr = clientSocket;
		ThreadHandle = CreateThread(NULL, 0, Echo, clientSocketPtr, 0, &ThreadId);
		if (ThreadHandle == NULL)
		{
			printf("[ERROR: %d] Create thread failed.\n", GetLastError());
			closesocket(serverSocket);
			closesocket(clientSocket);
			WSACleanup();
			return 1;
		}

		printf("Client '%d' accepted.\n", ThreadId);
	}

	// Cleanup
	closesocket(serverSocket);
	closesocket(clientSocket);
	WSACleanup();
	CloseHandle(ThreadHandle);
	return 0;
}

DWORD WINAPI Echo(LPVOID Param)
{
	SOCKET clientSocket = *(SOCKET*)Param;
	char buffer[BUFFER_SIZE] = { 0 };
	DWORD curThreadId = GetCurrentThreadId();

	while (1)
	{
		int receivedBytes = recv(clientSocket, buffer, BUFFER_SIZE, 0);
		if (receivedBytes > 0)
		{
			buffer[receivedBytes] = '\0';
			printf("Client '%d' sent: %s\n", curThreadId, buffer);

			// Send the message back to the client
			send(clientSocket, buffer, receivedBytes, 0);
		}
		else if (receivedBytes == 0)
		{
			// Client closed the connection
			printf("Client '%d' disconnected.\n", curThreadId);
			break;
		}
		else
		{
			// Error occured
			printf("[ERROR: %d] recv failed.\n", GetLastError());
			break;
		}
	}
	free(Param);
	return 0;
}