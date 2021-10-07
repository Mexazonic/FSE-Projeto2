#include "socket.h"
#include "gpio.h"

void fechar_servidor_distribuido() {
    close(server_socket);
}

void *iniciar_servidor_distribuido() {

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
	char buffer[5000];
	void *buffer_tmp = &buffer[0];

	while(1){    

		client_socket = accept(server_socket, (struct sockaddr*)NULL ,NULL);
		if ((bytes_received = recv(client_socket, buffer_tmp, sizeof(setagem), 0)) < 0) {
			printf("Erro no recv.\n");
		}

		setagem *params = (setagem *) buffer_tmp;
		ligar_atuadores(params);
		sleep(1);
	} 
	return 0;
}
