#include "lista.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>

/* Pruebas sobre lista recien creada */
void pruebas_lista_vacia(){
	printf("INICIO DE PRUEBAS CON LISTA VACIA\n");

	/* Declaro las variables a utilizar */
	lista_t *lista = lista_crear();
	 /* Pruebo que la lista fue creada*/
	print_test("la lista fue creada", lista != NULL);
	print_test("largo de lista igual a 0 es true", lista_largo(lista) == 0);
	print_test("la lista esta vacia", lista_esta_vacia(lista));

	/* Pruebo que lista borrar primero, lista ver primero y ver último
	   sobre lista vacía es inválido */
	print_test("lista ver primero es invalido", lista_ver_primero(lista) == NULL);
	print_test("lista ver ultimo es invalido", lista_ver_ultimo(lista) == NULL);
	print_test("lista borrar primero es invalido", lista_borrar_primero(lista) == NULL);
	
	/* Destruyo la lista */
	lista_destruir(lista, NULL);
	print_test("la lista fue destruida", true);
}

/* Pruebas de guardar correctamente sobre la lista */
void pruebas_lista_algunos_elementos(){
	printf("INICIO DE PRUEBAS CON ALGUNOS ELEMENTOS\n");

	/* Declaro las variables a utilizar */
	lista_t *lista = lista_crear();

	/* Declaro las variables para insertar primero */
	int num1 = 1, num2 = 2, num3 = 3;
	char *cad1 = "perro", *cad2 = "gato", *cad3 = "loro";

	/* Pruebo que guardar primero funciona correctamente */
	print_test("guardar primero num1 es true", lista_insertar_primero(lista, &num1));
	print_test("guardar primero num2 es true", lista_insertar_primero(lista, &num2));
	print_test("guardar primero num3 es true", lista_insertar_primero(lista, &num3));
	print_test("guardar primero cad1 es true", lista_insertar_primero(lista, cad1));
	print_test("guardar primero cad2 es true", lista_insertar_primero(lista, cad2));
	print_test("guardar primero cad3 es true", lista_insertar_primero(lista, cad3));

	/* Declaro las variables para insertar último */
	int num4 = 4, num5 =5, num6 = 6;
	char *cad4 = "linux", *cad5 = "valgrind", *cad6 = "gdb";

	/* Pruebo que guardar ultimo funciona correctamente */
	print_test("guardar ultimo num4 es true", lista_insertar_ultimo(lista, &num4));
	print_test("guardar ultimo num5 es true", lista_insertar_ultimo(lista, &num5));
	print_test("guardar ultimo num6 es true", lista_insertar_ultimo(lista, &num6));
	print_test("guardar ultimo cad4 es true", lista_insertar_ultimo(lista, cad4));
	print_test("guardar ultimo cad5 es true", lista_insertar_ultimo(lista, cad5));
	print_test("guardar ultimo cad6 es true", lista_insertar_ultimo(lista, cad6));

	/* Destruyo la lista */
	lista_destruir(lista, NULL);
	print_test("la lista fue destruida", true);
}

/* Pruebas de guardado con un cantidad grande de elementos */
void pruebas_lista_volumen(){
	printf("INICIO DE PRUEBAS DE VOLUMEN\n");

	/* Creo la lista */
	lista_t *lista = lista_crear();

	/* Defino la cantidad de elementos para guardar */
	size_t tam = 10000;
	int vector[tam];
	bool ok = true;

	for(size_t i = 0; i < tam; i++){
		// Si no se guarda correctamente, ok será false
		ok &= lista_insertar_primero(lista, &vector[i]);
	}

	print_test("se insertaron todos los elementos", ok);

	/* Pruebo que se eliminaron correctamente todos los elementos */
	for(size_t i = 0; i < tam; i++){
		// Si el elemento no es el correcto, ok será false
		ok &= (lista_borrar_primero(lista) == &vector[tam - i - 1]);
	}

	print_test("se eliminaron todos los elementos", ok);

	/* Destruyo la lista */
	lista_destruir(lista, NULL);
	print_test("la lista fue destruida", true);
}

/* Pruebas del invariante de la lista */
void pruebas_lista_invariante(){
	printf("INICIO DE PRUEBAS DEL INVARIANTE\n");

	/* Declaro las variables a utilizar */
	lista_t *lista = lista_crear();

	print_test("la lista fue creada", lista != NULL);
	print_test("la lista esta vacia", lista_esta_vacia(lista));

	int num1 = 1, num2 = 2, num3 = 3;
	char *cad1 = "perro", *cad2 = "gato", *cad3 = "loro";

	/* Inserto enteros en la lista */
	print_test("insertar ultimo num1 es true", lista_insertar_ultimo(lista, &num1));
	print_test("ver primero igual a num1 es true", lista_ver_primero(lista) == &num1);

	/* Pruebo que num1 es el primer elemento*/
	print_test("insertar ultimo num2 es true", lista_insertar_ultimo(lista, &num2));
	print_test("insertar ultimo num3 es true", lista_insertar_ultimo(lista, &num3));
	print_test("ver primero igual a num1 es true",lista_ver_primero(lista) == &num1);

	/* Pruebo que num3 es el último elemento */
	print_test("insertar primero cad1 es true", lista_insertar_primero(lista, cad1));
	print_test("insertar primero cad2 es true", lista_insertar_primero(lista, cad2));
	print_test("insertar primero cad3 es true", lista_insertar_primero(lista, cad3));
	print_test("ver ultimo igual a num3 es true", lista_ver_ultimo(lista) == &num3);

	/* Pruebo que borrar los primeros elementos no cambia el último (num3) */
	print_test("borrar primero igual a cad3 es true", lista_borrar_primero(lista) == cad3);
	print_test("borrar primero igual a cad2 es true", lista_borrar_primero(lista) == cad2);
	print_test("borrar primero igual a cad1 es true", lista_borrar_primero(lista) == cad1);
	print_test("ver ultimo igual a num3 es true", lista_ver_ultimo(lista) == &num3);

	/* Pruebo que al borrar todos los elementos de la lista, se comporta
		como lista recien creada */
	print_test("borrar primero igual a num1 es true", lista_borrar_primero(lista) == &num1);
	print_test("borrar primero igual a num2 es true", lista_borrar_primero(lista) == &num2);
	print_test("borrar primero igual a num3 es true", lista_borrar_primero(lista) == &num3);

	print_test("largo de lista igual a 0 es true", lista_largo(lista) == 0);
	print_test("lista esta vacia es true", lista_esta_vacia(lista));
	print_test("borrar primero en lista vacia es invalido", lista_borrar_primero(lista) == NULL);
	print_test("ver primero y ver ultimo en lista vacia son invalidos", lista_ver_primero(lista) == NULL
				&& lista_ver_ultimo(lista) == NULL);

	/* Destruyo la lista */
	lista_destruir(lista, NULL);
	print_test("la lista fue destruida", true);
}

/* Pruebas con funciones pasadas como parámetro */
void pruebas_lista_destruir(){
	printf("INICIO DE PRUEBAS CON FUNCIONES PASADAS COMO PARAMETRO\n");

	/* Declaro las variables a utilizar */
	lista_t *lista = lista_crear();
	char *valor1, *valor2, *valor3;
	valor1 = malloc(sizeof(char));
	valor2 = malloc(sizeof(char));
	valor3 = malloc(sizeof(char));

	/* Inserto los elementos en la lista */
	print_test("insertar primero cad1 es true", lista_insertar_primero(lista, valor1));
	print_test("insertar primero cad2 es true", lista_insertar_primero(lista, valor2));
	print_test("insertar primero cad3 es true", lista_insertar_primero(lista, valor3));

	/* Paso como argumento, una función definida por el usuario */
	lista_destruir(lista, free);
	print_test("la lista fue destruida", true);
}

/* Inicio de pruebas con iterador interno */
size_t factorial(size_t n){
	if(n == 0 || n == 1) return 1;
	return n*factorial(n - 1);
}

bool simular_factorial(void *dato, void *extra){
	*(size_t *)extra *= *(size_t *)dato;
	return true;
}

// EL k será 83
bool sumar_k_pares(void *dato, void *extra){
	if(*(size_t *)dato % 2 == 0)
		*(size_t *)extra += *(size_t *)dato;
	return *(size_t *)dato < 83;
}

size_t suma_k_pares(size_t k){
	size_t acum = 0;
	for(size_t i = 0; i < k; i++){
		if(i % 2 == 0) acum += i;
	}
	return acum;
}

void pruebas_iterador_interno(){
	printf("INICIO DE PRUEBAS CON ITERADOR INTERNO\n");

	/* Creo la lista*/
	lista_t *lista = lista_crear();
	print_test("la lista fue creada", lista);

	/* Declaro las variables a utilizar */
	size_t n = 100;
	size_t vector[n];
	bool ok = true;
	size_t extra = 1;
	for(size_t i = 0; i < n; i++){
		vector[i] = i + 1;
		// Si no se inserta correctamente, ok será false
		ok &= lista_insertar_ultimo(lista, &vector[i]);
	}
	print_test("los elementos fueron insertados correctamente", ok);

	/* Pruebo que simular_factorial calcula el factorial de n */
	lista_iterar(lista, simular_factorial, &extra);
	print_test("simular factorial se comporta como el factorial de n", extra == factorial(n));

	/* Pruebo que se acumula la suma de los primeros k pares */
	extra = 0;
	lista_iterar(lista, sumar_k_pares, &extra);
	print_test("se acumularon los primeros k nros pares", extra == suma_k_pares(83));

	/* Destruyo la lista */
	lista_destruir(lista, NULL);
	print_test("la lista fue destruida", true);
}

/* Pruebas con iterador externo */
bool buscar_eliminado(void *dato, void *extra){
	bool ok = (dato != extra);
	print_test("num2 no se encuentra en la lista", ok);
	return ok;
}

void pruebas_iterador_externo(){
	printf("INICIO DE PRUEBAS CON ITERADOR EXTERNO\n");

	/* Declaro las variables a utilizar */
	lista_t *lista = lista_crear();
	int num1 = 1, num2 = 2, num3 = 3, num4 = 4;
	lista_insertar_ultimo(lista, &num2);
	lista_insertar_ultimo(lista, &num3);

	/* Creo el iterador */
	lista_iter_t *iter = lista_iter_crear(lista);
	print_test("el iterador fue creado", iter != NULL);

	/* Pruebo que remover un elemento al crear el iterador, 
	   se cambia el primer elemento de la lista*/
	print_test("iter borrar igual a num2 es true", lista_iter_borrar(iter) == &num2);
	print_test("lista ver primero igua a num3 es true", lista_ver_primero(lista) == &num3);

	/* Pruebo que insertar con iter recien creado equivale a lista insertar primero */
	print_test("iter insertar num1 es true", lista_iter_insertar(iter, &num1));
	print_test("lista ver primero igual a num1 es true", lista_ver_primero(lista) == &num1);

	/* Pruebo que insertar un elemento en el medio se hace en la posición correcta */
	print_test("iter avanzar es true", lista_iter_avanzar(iter));
	print_test("iter insertar num2 es true", lista_iter_insertar(iter, &num2));
	print_test("lista ver primero igual a num1 es true", lista_ver_primero(lista) == &num1);
	print_test("lista ver ultimo igual a num3 es true", lista_ver_ultimo(lista) == &num3);

	/* Pruebo que remover al remover un elemento del medio, este no está */
	print_test("iter borrar igual a num2 es true", lista_iter_borrar(iter) == &num2);
	lista_iterar(lista, buscar_eliminado, &num2);

	/* Pruebo que avanzar con iter al final es invalido */
	print_test("iter avanzar es true", lista_iter_avanzar(iter));
	print_test("iter al final es true", lista_iter_al_final(iter));
	print_test("iter avanzar con iterador al final es invalido", !lista_iter_avanzar(iter));

	/* Pruebo que insertar un elemento con el iterador al final, equivale a lista insertar último */
	print_test("iter insertar num4 es true", lista_iter_insertar(iter, &num4));
	print_test("lista ver ultimo igual a num4 es true", lista_ver_ultimo(lista) == &num4);

	/* Pruebo que remover un elemento con el iterador al final, 
	   cambia el último elemento de la lista*/
	print_test("iter borrar igual a num4 es true", lista_iter_borrar(iter) == &num4);
	print_test("lista ver ultimo igual a num3 es true", lista_ver_ultimo(lista) == &num3);

	/* Destruyo el iterador */
	lista_iter_destruir(iter);
	print_test("el iterador fue destruido", true);

	/* Destruyo la lista */
	lista_destruir(lista, NULL);
	print_test("la lista fue destruida", true);
}

void pruebas_lista_alumno(){
	pruebas_lista_vacia();
	pruebas_lista_algunos_elementos();
	pruebas_lista_volumen();
	pruebas_lista_invariante();
	pruebas_lista_destruir();
	pruebas_iterador_interno();
	pruebas_iterador_externo();
}