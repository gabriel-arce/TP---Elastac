/*
 * elestac_config.c
 *
 *  Created on: 22 de abr. de 2016
 *      Author: gabriel
 */

#include "elestac_config.h"

bool chequearProperty(t_config* config, char* property) {
	return (config_has_property(config, property));
}

char* getStringProperty(t_config* config, char* property) {
	chequearProperty(config, property);
	return string_duplicate(config_get_string_value(config, property));
}

int getIntProperty(t_config* config, char* property) {
	if (chequearProperty(config, property))
		return config_get_int_value(config, property);
	return EXIT_FAILURE;
}

t_list *getListProperty(t_config *config, char *property) {
	char **items = config_get_array_value(config, property);
	t_list *ret = list_create();
	int cant = string_count(config_get_string_value(config, property), ",") + 1;

	int i;
	for (i = 0; i < cant; i++)
		list_add(ret, (void *) string_duplicate(items[i]));

	return ret;
}

int string_count(char *text, char *pattern) {
	char **chunks = string_split(text, pattern);
	int ret;
	for (ret = 0; chunks[ret]; ret++)
		;
	return ret - 1;
}

void cargar_archivo_config(char ** ruta_config, void (*funcion_de_carga)(void**)) {

	funcion_de_carga((void **) ruta_config);

}

int chequear_argumentos(int argc, int shouldc) {
	if (argc == 1) {
		printf("Debe ingresar un archivo de configuracion\n");
		return -1;
	}

	if (argc != shouldc) {
		printf("Cantidad incorrecta de argumentos\n");
		return -1;
	}

	return 1;
}
