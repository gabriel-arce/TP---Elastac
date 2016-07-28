/*
 * ProcesarCPU.c
 *
 *  Created on: 28/4/2016
 *      Author: utnso
 */

#include "CPU.h"


int main(int argc, char * argv[]){

	signal(SIGUSR1,rutina);		//HotPlug
	signal(SIGINT, rutina);

	if (!chequear_argumentos(argc, 2))
			return EXIT_FAILURE;

	cargar_archivo_config(argv, (void *) cargarConfiguracion);


	conectarConNucleo();		//Conectar al nucleo


	conectarConUMC();			//Conectar al UMC


	while(!hotPlugActivado){

		escucharAlNucleo();								//Escuchar al nucleo a la espera de nuevos PCBs
		cambiar_proceso_activo(pcbActual->pcb_pid);		//envio a umc nuevo PID

		//Modifico
		enviar_header(21,sizeof(pcbActual),socketNucleo);
		enviarPCB();

		while( (getQuantumPcb() <= getQuantum())  &&  (pcbCorriendo)){

			quantumSleep();
			ejecutarProximaInstruccion();
			actualizarQuantum();

		}

		if(getQuantumPcb() == getQuantum()){

			restaurarQuantum();
		}

		enviarPCB();

		borrarPCBActual();

	}

	desconectarCPU();



 	return EXIT_SUCCESS;
}
