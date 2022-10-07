Funciones: 
	int printmenu(): Funci�n b�sica que imprime el men� de elecciones por pantalla y pide input al usuario para ejecutar la funci�n que desee.

	bool wificollector_quit(): La funci�n que cierra el programa. Pide al usuario que escriba s o n, s para salir; n para no. Al elegir salir, se termina el programa a trav�s de un return 0 en el main.

	int** wificollector_collect(): Es una funci�n que pide al usuario que introduzca el n�mero de la celda cuya informaci�n quiere almacenar en el sistema (a trav�s de una matriz en la que las filas representan los archivos y las columnas, el texto en s�). Tras almacenar, pide al usuario si quiere repetir la operaci�n. La matriz la declaramos como un array de punteros, para los que reservamos espacio en memoria suficiente como para que quepan todos sus elementos a trav�s de la funci�n malloc().

	void wificollector_display(int** celdas): Con este m�todo conseguimos imprimir la celda pedida por el usuario pero solo si est� celda esta contenida en nuestra aplicaci�n, es decir, en nuestra matriz(celdas), por ello, lo primero que hacemos es comprobar si la celda que nos ha pedido el usuario est� almacenada en nuestra matriz (esto lo hacemos con el if y con el for imprimimos la celda pedida por el usuario).

	void wificollector_display_all(int** celdas):Est� funci�n imprime todo lo que tengamos contenido en nuestra matriz, para ello utilizamos un for que se recorre las 21 posiciones de los diferentes ficheros que puede 
contener la matriz y comprueba si esa posici�n est� vac�a, y de estarlo, pasar a la siguiente fila.

El main(int main()): La funci�n main nos sirve como punto de partida para la ejecuci�n del programa. Su estructura central consta de un switch que seg�n la elecci�n del usuario, redirige el flujo del programa hacia las funciones asignadas para cada posici�n de este.
