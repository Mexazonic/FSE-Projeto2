#include "socket.h"

void close_server() {
    close(server_socket);
}

void *iniciar_servidor(void *args) {

	setagem *estado_atual = (setagem *) args;

	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, '0', sizeof(serv_addr));
		
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	serv_addr.sin_port = htons(8080);

	bind(server_socket, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

	if(listen(server_socket, 10) == -1){
		printf("Failed to listen\n");
		return 0;
	}

	int bytes_received;
		
	char buffer1[5000];

	void *buffer_tmp = &buffer1[0];

	while(1) {

		client_socket = accept(server_socket, (struct sockaddr*)NULL ,NULL);

		if ((bytes_received = recv(client_socket, buffer_tmp, sizeof(setagem), 0)) < 0) {
			printf("Erro no recv.\n");
		}

		setagem *buffer = (setagem *) buffer_tmp;

		switch (buffer->codigo_atuador) {
			case LS_T01:
				estado_atual->LS_T01_setagem = buffer->LS_T01_setagem;
				estado_atual->codigo_atuador = buffer->codigo_atuador;
				break;
			case LS_T02:
				estado_atual->LS_T02_setagem = buffer->LS_T02_setagem;
				estado_atual->codigo_atuador = buffer->codigo_atuador;
				break;
			case LC_T:
				estado_atual->LC_T_setagem = buffer->LC_T_setagem;
				estado_atual->codigo_atuador = buffer->codigo_atuador;
				break;
			case AC_T:
				estado_atual->AC_T_setagem = buffer->AC_T_setagem;
				estado_atual->codigo_atuador = buffer->codigo_atuador;
				break;
			case ASP:
				estado_atual->ASP_setagem = buffer->ASP_setagem;
				estado_atual->codigo_atuador = buffer->codigo_atuador;
				break;
			
			default:
				break;
		}

		sleep(1);
	} 

	return 0;
}

