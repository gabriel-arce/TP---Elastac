/*
 * elestac_config.h
 *
 *  Created on: 22 de abr. de 2016
 *      Author: gabriel
 */

#ifndef ELESTAC_CONFIG_H_
#define ELESTAC_CONFIG_H_

#include <stdio.h>
#include <stdlib.h>
#include <commons/collections/list.h>
#include <commons/string.h>
#include <commons/config.h>

int chequear_argumentos(int argc, int shouldc);
void cargar_archivo_config(char ** ruta_config, void(*funcion_de_carga)(void**));

bool chequearProperty(t_config* config, char* property);		//Chequear propiedad
char* getStringProperty(t_config* config, char* property);	//Obtener valor de un string
int getIntProperty(t_config* config, char* property);		//Obtener valor de un int
t_list *getListProperty(t_config *config, char *property);	//Obtener valores de una lista
int string_count(char *text, char *pattern);				//Obtener cantidad de subcadenas

#endif /* ELESTAC_CONFIG_H_ */
