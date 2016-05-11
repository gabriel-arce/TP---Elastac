/*
 * elestac_paquetes.h
 *
 *  Created on: 10/5/2016
 *      Author: utnso
 */

#ifndef ELESTAC_PAQUETES_H_
#define ELESTAC_PAQUETES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef struct {
	uint8_t identificador;
	uint32_t tamanio;
}__attribute__((packed)) t_header;

typedef struct {
	void * data;
	int size;
}__attribute__((packed)) t_stream;

t_stream * serializar_header(t_header * unHeader);
t_header * deserializar_header(t_stream * unStream);
int recibir_handshake(int sock_fd, t_header * handshake_in);
int enviar_handshake(int sock_fd, uint8_t id_proc, uint32_t size);


#endif /* ELESTAC_PAQUETES_H_ */