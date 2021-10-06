#include "cliente_tcp.h"
#include "setagem.h"
#include "default.h"


int enviar_parametros(const void *params) {

	if((client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		printf("Erro no socket.\n");
	}

	memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados

	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = inet_addr(DISTRIBUTED_SERVER_IP);
	// servidorAddr.sin_port = htons(DISTRIBUTED_SERVER_1_PORT);
	// servidorAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servidorAddr.sin_port = htons(8080);

	if(connect(client_socket, (struct sockaddr *) &servidorAddr, sizeof(servidorAddr)) < 0) {
		printf("Erro no connect.\n");
	}

	size = sizeof(state);

	bytes_sent = send(client_socket, params, size, 0);

	if(bytes_sent != size) {
		printf("Erro no envio: numero de bytes enviados %d diferente do esperado %d\n", bytes_sent, size);
		return 0;
	}

	close(client_socket);

	return 1;
}
