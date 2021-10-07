#include "cliente_tcp.h"
#include "config.h"
#include "constants.h"

int enviar_dados_tcp(const void *message) {

	if((client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		printf("Socket erro\n");
	}

	memset(&servidorAddr, 0, sizeof(servidorAddr));
	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = inet_addr("192.168.0.22");
	
	servidorAddr.sin_port = htons(8080);

	if(connect(client_socket, (struct sockaddr *) &servidorAddr, sizeof(servidorAddr)) < 0) {
		printf("Connect\n");
	}

	size = sizeof(setagem);

	bytes_sent = send(client_socket, message, size, 0);

	if(bytes_sent != size) {
		return 0;
	}

	close(client_socket);

	return 1;
}
