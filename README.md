Integrantes: Jorge Ruipérez Escalera (100472783), y Emilio José Manchado Barquero (100472764)

Resumen de funcionalidad:

	- int printmenu(): Función básica que imprime el menú de elecciones por pantalla y pide input al usuario para ejecutar la función que desee.

	- bool wificollector_quit(): La función que cierra el programa. Pide al usuario que escriba s o n, s para salir; n para permanecer. Al elegir salir, se termina el programa a través de un return 0 en el main.

	- int** wificollector_collect(): Es una función que pide al usuario que introduzca el número de la celda cuya información quiere almacenar en el sistema (a través de una matriz en la que las filas representan los archivos y las columnas, el texto en sí). Tras almacenar, pide al usuario si quiere repetir la operación. La matriz la declaramos como un array de punteros, para los que reservamos espacio en memoria suficiente como para que quepan todos sus elementos a través de la función malloc().

	- void wificollector_display(int** celdas): con este método imprimimos la celda pedida por el usuario, únicamente si la celda esta contenida en nuestra matriz "celdas", por ello, lo primero que hacemos es comprobar si la celda que nos ha pedido el usuario está almacenada en nuestra matriz (a través de la primera fila de la matriz, la cual está inutilizada y guarda un 1 en la columna correspondiente al archivo que representa en caso de que no esté vacía; si lo está, habrá un 0).

	- void wificollector_display_all(int** celdas): esta función imprime todo lo que tengamos contenido en nuestra matriz, para ello utilizamos un for que se recorre las 21 posiciones de los diferentes ficheros que puede contener la matriz y comprueba si esa posición está vacía, y de estarlo, pasar a la siguiente fila para seguir comprobando e imprimiendo.

	- void wificollector_select_best(int** source): a través de dos funciones con tareas más específicas (splitstring(), y returnquality()) dividimos en líneas el texto de los archivos guardados usando wificollector_collect(), en la matriz a la que apunta source. Una vez dividido en líneas, podemos extraer el valor de quality para cada subcelda dentro de cada archivo, encontrar el mayor valor, y compararlo con los mayores valores de los demás archivos. Así, encontramos la mayor calidad, y teniendo una referencia de dónde se ubica, imprimir detalles sobre la red que hay detrás.

	- void selectworst(int** source): misma funcionalidad que wificollector_select_best(), con la única diferencia de que aquí se busca la calidad más baja, se encuentra la más baja por archivo, y se compara entre todas para encontrar la peor e imprimir los detalles.
	 
