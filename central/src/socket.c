#include "socket.h"

void close_server() {
    close(server_socket);
}

void *iniciar_servidor(void *central_setagem) {

	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, '0', sizeof(serv_addr));
		
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	serv_addr.sin_port = htons(8081);
	bind(server_socket, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
	if(listen(server_socket, 10) == -1){
		printf("Erro no listen\n");
		return 0;
	}

	int bytes_received;
		
	char buffer1[5000];

	void *buffer_tmp = &buffer1[0];

	while(1){ 

		client_socket = accept(server_socket, (struct sockaddr*)NULL ,NULL);

		if ((bytes_received = recv(client_socket, buffer_tmp, sizeof(setagem), 0)) < 0) {
			printf("Erro no recv.\n");
		}

		setagem *buffer = (setagem *) buffer_tmp;
		setagem *central = (setagem *) central_setagem;
 
		switch (buffer->codigo_sensor) {
			case TEMP_HUM:
				central->humidade = buffer->humidade;
				
				central->temperatura = buffer->temperatura;
				break;

			case PEOPLE_COUNT:
				central->pessoas = buffer->pessoas;
				break;

			case SP_T:
				central->SP_T_setagem = buffer->SP_T_setagem;
				break;

			case SF_T:
				central->SF_T_setagem = buffer->SF_T_setagem;
				break;

			case SJ_T01:
				central->SJ_T01_setagem = buffer->SJ_T01_setagem;
				break;

			case SJ_T02:
				central->SJ_T02_setagem = buffer->SJ_T02_setagem;
				break;

			case SPo_T:
				central->SPo_T_setagem = buffer->SPo_T_setagem;
				break;

			default:
				break;
		}

		sleep(1);
	} 

	return 0;
}
