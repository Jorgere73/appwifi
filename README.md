Funciones: 
	int printmenu(): Función básica que imprime el menú de elecciones por pantalla y pide input al usuario para ejecutar la función que desee.

	bool wificollector_quit(): La función que cierra el programa. Pide al usuario que escriba s o n, s para salir; n para no. Al elegir salir, se termina el programa a través de un return 0 en el main.

	int** wificollector_collect(): Es una función que pide al usuario que introduzca el número de la celda cuya información quiere almacenar en el sistema (a través de una matriz en la que las filas representan los archivos y las columnas, el texto en sí). Tras almacenar, pide al usuario si quiere repetir la operación. La matriz la declaramos como un array de punteros, para los que reservamos espacio en memoria suficiente como para que quepan todos sus elementos a través de la función malloc().

	void wificollector_display(int** celdas): Con este método conseguimos imprimir la celda pedida por el usuario pero solo si está celda esta contenida en nuestra aplicación, es decir, en nuestra matriz(celdas), por ello, lo primero que hacemos es comprobar si la celda que nos ha pedido el usuario está almacenada en nuestra matriz (esto lo hacemos con el if y con el for imprimimos la celda pedida por el usuario).

	void wificollector_display_all(int** celdas):Está función imprime todo lo que tengamos contenido en nuestra matriz, para ello utilizamos un for que se recorre las 21 posiciones de los diferentes ficheros que puede 
contener la matriz y comprueba si esa posición está vacía, y de estarlo, pasar a la siguiente fila.

El main(int main()): La función main nos sirve como punto de partida para la ejecución del programa. Su estructura central consta de un switch que según la elección del usuario, redirige el flujo del programa hacia las funciones asignadas para cada posición de este.
