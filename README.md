Integrantes: Jorge Ruip�rez Escalera y Emilio Jos� Manchado

Funciones: 

	int printmenu(): Funci�n b�sica que imprime el men� de elecciones por pantalla y pide input al usuario para ejecutar la funci�n que desee.

	bool wificollector_quit(): La funci�n que cierra el programa. Pide al usuario que escriba s o n, s para salir; n para no. Al elegir salir, se termina el programa a trav�s de un return 0 en el main.

	lista* wificollector_collect(): Es una funci�n que pide al usuario que introduzca el n�mero del archivo cuya informaci�n quiere almacenar en la cadena de nodos. Al introducir un n�mero, se crea un nodo nuevo al que se le asigna un n�mero (el del archivo), el texto, y el tama�o de este. Al introducir otro n�mero m�s se crea otro nodo que se sit�a detras del anterior.

	void wificollector_display(lista* nodos): Con este m�todo conseguimos imprimir la celda pedida por el usuario pero solo si est� celda esta contenida en nuestra aplicaci�n, es decir, en la cadena de nodos. Se nos pedir� un n�mero, correspondiente al n�mero de archivo que queremos mostrar, y si este se encuentra entre alguno de nuestros nodos, se mostrar�; si no, te dar� la opci�n de probar con otro.

	void wificollector_display_all(int** celdas): Esta funci�n imprime todo lo que tengamos contenido en nuestros nodos, para ello utilizamos un for sobre las 21 posiciones posibles, combinado con un while que busca el archivo concreto para cada posici�n dentro de nuestra cadena de nodos.

	void wificollector_select_best(lista nodos): Esta funci�n coge los valores de calidad las distintas celdas de red dentro de cada archivo, y elige la m�s alta. Para ello, hacemos uso de dos funciones propias con las que desgranamos el texto y sacamos el valor de la calidad. Con char** splitstring() introducimos un string como input, y se devuelve un array de strings; es decir, un array en el que cada posici�n est� ocupada por una l�nea del texto original. A partir de este array de strings, con int returnquality() llegamos a las l�neas de texto donde se encuentra escrita la calidad de cada conexi�n, y, al situarse siempre tras un '=', podemos conseguir un puntero a los caracteres de dicha calidad y convertirlos a ints para poder as� comparar su valor con el de resto de calidades. Despu�s, imprimimos por pantalla la informaci�n de la red con mejor calidad.
	
	void wificollector_select_worst(lista nodos): Igual funcionamiento que wificollector_select_best(), con la diferencia de que, a la hora de filtrar las calidades, en vez de hacerlo buscando la m�s alta, se queda con la m�s peque�a. Imprime tambi�n por pantalla los detalles de la peor red encontrada entre los archivos en nodos.
	
El main(int main()):

	La funci�n main nos sirve como punto de partida para la ejecuci�n del programa. Su estructura central consta de un switch que seg�n la elecci�n del usuario, redirige el flujo del programa hacia las funciones asignadas para cada posici�n de este.

