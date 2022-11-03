Integrantes: Jorge Ruip�rez Escalera (100472783), y Emilio Jos� Manchado Barquero (100472764)

Resumen de funcionalidad:

	- int printmenu(): Funci�n b�sica que imprime el men� de elecciones por pantalla y pide input al usuario para ejecutar la funci�n que desee.

	- bool wificollector_quit(): La funci�n que cierra el programa. Pide al usuario que escriba s o n, s para salir; n para permanecer. Al elegir salir, se termina el programa a trav�s de un return 0 en el main.

	- int** wificollector_collect(): Es una funci�n que pide al usuario que introduzca el n�mero de la celda cuya informaci�n quiere almacenar en el sistema (a trav�s de una matriz en la que las filas representan los archivos y las columnas, el texto en s�). Tras almacenar, pide al usuario si quiere repetir la operaci�n. La matriz la declaramos como un array de punteros, para los que reservamos espacio en memoria suficiente como para que quepan todos sus elementos a trav�s de la funci�n malloc().

	- void wificollector_display(int** celdas): con este m�todo imprimimos la celda pedida por el usuario, �nicamente si la celda esta contenida en nuestra matriz "celdas", por ello, lo primero que hacemos es comprobar si la celda que nos ha pedido el usuario est� almacenada en nuestra matriz (a trav�s de la primera fila de la matriz, la cual est� inutilizada y guarda un 1 en la columna correspondiente al archivo que representa en caso de que no est� vac�a; si lo est�, habr� un 0).

	- void wificollector_display_all(int** celdas): esta funci�n imprime todo lo que tengamos contenido en nuestra matriz, para ello utilizamos un for que se recorre las 21 posiciones de los diferentes ficheros que puede contener la matriz y comprueba si esa posici�n est� vac�a, y de estarlo, pasar a la siguiente fila para seguir comprobando e imprimiendo.

	- void wificollector_select_best(int** source): a trav�s de dos funciones con tareas m�s espec�ficas (splitstring(), y returnquality()) dividimos en l�neas el texto de los archivos guardados usando wificollector_collect(), en la matriz a la que apunta source. Una vez dividido en l�neas, podemos extraer el valor de quality para cada subcelda dentro de cada archivo, encontrar el mayor valor, y compararlo con los mayores valores de los dem�s archivos. As�, encontramos la mayor calidad, y teniendo una referencia de d�nde se ubica, imprimir detalles sobre la red que hay detr�s.

	- void selectworst(int** source): misma funcionalidad que wificollector_select_best(), con la �nica diferencia de que aqu� se busca la calidad m�s baja, se encuentra la m�s baja por archivo, y se compara entre todas para encontrar la peor e imprimir los detalles.
	 
