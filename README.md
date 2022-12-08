Integrantes: Jorge Ruipérez Escalera y Emilio José Manchado

Funciones: 

	int printmenu(): Función básica que imprime el menú de elecciones por pantalla y pide input al usuario para ejecutar la función que desee.

	bool wificollector_quit(): La función que cierra el programa. Pide al usuario que escriba s o n, s para salir; n para no. Al elegir salir, se termina el programa a través de un return 0 en el main.

	lista* wificollector_collect(): Es una función que pide al usuario que introduzca el número del archivo cuya información quiere almacenar en la cadena de nodos. Al introducir un número, se crea un nodo nuevo al que se le asigna un número (el del archivo), el texto, y el tamaño de este. Al introducir otro número más se crea otro nodo que se sitúa detras del anterior.

	void wificollector_display(lista* nodos): Con este método conseguimos imprimir la celda pedida por el usuario pero solo si está celda esta contenida en nuestra aplicación, es decir, en la cadena de nodos. Se nos pedirá un número, correspondiente al número de archivo que queremos mostrar, y si este se encuentra entre alguno de nuestros nodos, se mostrará; si no, te dará la opción de probar con otro.

	void wificollector_display_all(int** celdas): Esta función imprime todo lo que tengamos contenido en nuestros nodos, para ello utilizamos un for sobre las 21 posiciones posibles, combinado con un while que busca el archivo concreto para cada posición dentro de nuestra cadena de nodos.

	void wificollector_select_best(lista nodos): Esta función coge los valores de calidad las distintas celdas de red dentro de cada archivo, y elige la más alta. Para ello, hacemos uso de dos funciones propias con las que desgranamos el texto y sacamos el valor de la calidad. Con char** splitstring() introducimos un string como input, y se devuelve un array de strings; es decir, un array en el que cada posición está ocupada por una línea del texto original. A partir de este array de strings, con int returnquality() llegamos a las líneas de texto donde se encuentra escrita la calidad de cada conexión, y, al situarse siempre tras un '=', podemos conseguir un puntero a los caracteres de dicha calidad y convertirlos a ints para poder así comparar su valor con el de resto de calidades. Después, imprimimos por pantalla la información de la red con mejor calidad.
	
	void wificollector_select_worst(lista nodos): Igual funcionamiento que wificollector_select_best(), con la diferencia de que, a la hora de filtrar las calidades, en vez de hacerlo buscando la más alta, se queda con la más pequeña. Imprime también por pantalla los detalles de la peor red encontrada entre los archivos en nodos.
	
El main(int main()):

	La función main nos sirve como punto de partida para la ejecución del programa. Su estructura central consta de un switch que según la elección del usuario, redirige el flujo del programa hacia las funciones asignadas para cada posición de este.

