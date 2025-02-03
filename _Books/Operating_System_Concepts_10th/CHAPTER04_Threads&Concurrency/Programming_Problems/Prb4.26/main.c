#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include <time.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 6013

DWORD WINAPI HandleClient(LPVOID clientSocket);

int main(void)
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("[ERROR: %d] WSAStartup failed.\n", WSAGetLastError());
		return 1;
	}

	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET)
	{
		printf("[ERROR: %d] Socket creation failed.\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(PORT);

	if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		printf("[ERROR: %d] Bind failed.\n", WSAGetLastError());
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}

	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		printf("[ERROR: %d] Listen failed.\n", WSAGetLastError());
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}

	printf("Server listening on port %d\n", PORT);

	while (1)
	{
		SOCKET clientSocket = accept(serverSocket, NULL, NULL);
		if (clientSocket == INVALID_SOCKET)
		{
			printf("[ERROR: %d] Accept failed.\n", WSAGetLastError());
			break;
		}

		SOCKET* clientPtr = (SOCKET*)malloc(sizeof(SOCKET));
		if (clientPtr == NULL)
		{
			printf("[ERROR: %d] Memory allocation failed.\n", WSAGetLastError());
			closesocket(clientSocket);
			break;
		}
		*clientPtr = clientSocket;

		HANDLE threadHandle = CreateThread(NULL, 0, HandleClient, clientPtr, 0, NULL);
		if (threadHandle == NULL)
		{
			printf("[ERROR: %d] Thread creation failed.\n", WSAGetLastError());
			closesocket(clientSocket);
			free(clientPtr);
			break;
		}
			
		CloseHandle(threadHandle);
	}

	closesocket(serverSocket);
	WSACleanup();
	return 0;
}

DWORD WINAPI HandleClient(LPVOID clientSocket)
{
	SOCKET client = *(SOCKET*)clientSocket;
	free(clientSocket);

	time_t now = time(NULL);
	char* date = ctime(&now);

	send(client, date, (int)strlen(date), 0);
	closesocket(client);

	return 0;
}