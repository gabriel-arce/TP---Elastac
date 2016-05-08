/*
 * ProcesarUMC.c
 *
 *  Created on: 29/4/2016
 *      Author: utnso
 */

#include <UMC.h>

int main() {

	printf("***Proceso UMC***\n");
	new_line();

	archivo_log  = "umc.log";
	contador_hilos = 0;

	//creo estructuras
	inicializar_memoria();
	crear_archivo_reporte();
	crear_archivo_log();

	//carga archivo de configuracion y sus parametros
	cargar_config();
	imprimir_config();

	cpu_conectadas = list_create();
	lista_frames = list_create();
	tabla_de_paginas = list_create();

	if (tlb_habilitada())
		tlb = list_create();

	//inicializo semaforos
	pthread_mutex_init(&mutex_hilos, 0);
	pthread_mutex_init(&mutex_lista_cpu, 0);


	pthread_create(&hilo_server, NULL, escucha_conexiones, NULL);
	pthread_join(hilo_server, NULL);

	pthread_create(&hiloConsola, NULL, lanzar_consola, NULL);
	pthread_join(hiloConsola, NULL);

	pthread_detach(hiloConsola);
	pthread_detach(hilo_server);

	list_destroy(cpu_conectadas);
	free(memoria_principal);
	free(umc_config);

	return EXIT_SUCCESS;
}
