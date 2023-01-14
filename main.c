#include "lista.h"
#include "testing.h"
#include <stdio.h>

int main()
{
	/* Ejecuta todas las pruebas unitarias. */
    printf("~~~ PRUEBAS ALUMNO ~~~\n");

    pruebas_lista_alumno();

	return failure_count() > 0;
}