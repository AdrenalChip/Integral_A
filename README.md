# Integral_A

Este proyecto es un programa para el manejo de libros de una suppuesta libreria, en donde se pueden ordenar por número de paginas, se pueden agregar mas libros y eliminar dichos libros,dichos libros estan almacenados en un arreglo dentro de una clase. Tambien cada libro cuenta con sus tags, categorias a las que pertenece, que estan acomodados en ordenamientos lineales

# SICT0302B: Toma decisiones

Selecciona un algoritmo de ordenamiento adecuado al problema

Para este avance, presentacion opte por un acercamiento mas sencillo siendo este el bubble Sort por el hecho de que queria compararlo con todos y por que estoy manejando una base de datos pequeña y se me hizo mas sencillo de manejar por los valores y la forma en la que plantee mi programa

Selecciona y usa una estructura lineal adecuada al problema

Para este problema usa un ordenamiento de lista para almacenar las categorias de cada libro en diferentes nodos, para que cuando se seleccione buscar por categorias, se puede buscar facilmente los libros que contengan dicha categorias. Tambien se cuenta con la funcion para que cuando se agreguen nuevos libros se agreguen su respectiva lista de categorias. 

Usa un árbol adecuado para resolver un problema

Usando un arbol BST almacenamos la cantidad de libros que hay por libro, es decir que si Harry Potter tiene 10 copias y Los Juegos del Hmabre son 20,se van almacenando en este arbol por orden para poder saber cuales tienen mas copias y cuales estaran por terminarse 


# SICT0301B: Evalúa los componentes

* Existe un .cpp llamado casosdeprueba en donde estan presentes los casos de prueba, las funciones y procedimientos que hace el programa y nos muestra si cumple o no con dicha prueba. En dicho de caso prueba se ejecutan las siguientes funciones que estan en el programa principal y hacen que el programa funcione y cumpla con lo solicitado:

Algortimo de Ordenamiento:

* Bubble Sort() : Dos ciclos anidados por lo que O(n^2) es la complejidad.
  
Estructura de Datos:

* Link List : almacena las categorias de cada libro

  #insertion
  
O(n) siempre recorre hasta el ultimo link para agregarlo.

  #search
  
O(n) En el peor de los casos no está y habrá recorrido los n elementos de la lista.

     
* BST Tree : genera un arbol para el almacenamiento de la cantidad de paginas por libro

  #inorder
  
 Pasa por cada uno de los nodos, por lo que es O(n)
  #search
  
  Por la estrcutura de un BST, en donde el lado izquiero es menor y el lado derecho mayor, al buscar un numero siempre tomara un camino u otro por lo que no recorre todo los nodos y su complejidad es O(log(n))
  
  #insertion
  
  Por la estrcutra de un BST, al insertar un nuevo nodo analiza su el valor a agregar mayor o menor al nodo en el que esta consultando, y dependiendo se va a la izquierda o derecha por lo  que su complejidad es O(log(n)) pues no necesita recorrer todos los nodos,
  
Funciones 
* inicializar(): genera un numero preestablecido libros en el objeto Libro y con atributos ya definidos por el programa.

Su complejidad es grado O(1) pues siempre se generan los mismos libros al inicio del programa
* catalogo(): Se le presentan opciones al usuario y dependiendo de la opcion la funcion llama otras. Entre las funciones que llama se encuentra el bubblesort,arreglaarray,cantidadtree y categoria. 

Su complejidad es O(1) pues solo depende de una seleccion y no cambia

* arreglarray(): funcion que recibe un vector y con todos los datos almacenados, genera un nuevo string para imprimir los valores usando como referencia atributos de los Libros

Su complejidad es O(n) pues el tiempo que tardara en ejecutarse depende de la cantidad de valores almacenados en el vector

* cantidad_tree(): funcion que recibe objetos de tipo Libro y la cantidad de libros que haya registrados. Tomando los objetos de tipo libro recupera su atributo de cantidad de copias y con la funcion add() del bst genera el arbol. 
 Despues de generarlo realiza la funcion inorder() e imprime el orden de menor a mayor de cantidad de copias de libros
 
 Su complejidad es O(n) pues dependiendo de la cantidad de objetos Libro habra mas o menos nodos y los ciclos para recuperar datos son lineales 
 
* categoria(): recibe los objetos tipo Libro y su tamaño, deja al usuario ingresar una categoria por buscar entre todos los objetos,llama a la funcion searching().

Su complejidad es O(n) el ciclo con el que cuenta depende de la cantidad de objetos tipo Libro que existan

* agregar_libro(): Esta funcion permite generar al usuario nuevos objetos tipo Libro mediante inputs hechos por el, dichos input se van asginado a los atributos correspondientes dentro del objeto

Su complejidad es O(n) pues el usuario puede agregar n numeros de libros 

* eliminar_libro(): esta funcion permite al usuario eliminar un objeto tipo libro que el desee, recibe los objetos tipos de libro, y cantidad de. Despues de encontrar el libro a eliminar, reestrcutura la cantidad y el orden de los objetos, es decir reduce el tamaño de objetos

Su complejidad es O(n) pues depende de la cantidad de libros que haya en total y que hay que mover a posiciones diferentes

Clase Libro: genera objetos de tipo Libro con diversos atributos: Nombre del Libro, cantidad de copias,numero de paginas, categorias a las que pertenece 

* set_paginas(): funcion que recibe un numero de paginas y lo asigna al atributo correspondiente

Su complejidad es O(1) solo es una instruccion constante 

* set_cantidad(): funcion que recibe un numero de copias y lo asigna al atributo correspondiente

Su complejidad es O(1) solo es una instruccion constante 

* set_names(): funcion que recibe el nombre del libro y lo asigna al atributo correspondiente

Su complejidad es O(1) solo es una instruccion constante

* get_name():funcion que devuelve el atributo del nombre 

Su complejidad es O(1) solo es una instruccion constante 

* get_pages()funcion que devuelve el atributo de cuantas paginas hay

Su complejidad es O(1) solo es una instruccion constante 

* get_cantidad(): funcion que devuelve el atributo de cantidad de copias

Su complejidad es O(1) solo es una instruccion constante 

* get_categoria(): funcion que devuelve las categorias

Su complejidad es O(1) solo es una instruccion constante 

* set_categoria(): funcion que recibe un array tipo string con las categorias que se buscan registrar y el tamaño de dicho array. Cada categoria registrada en el array se inserta en una lista encadenada

Su complejidad es O(n) tiene un ciclo que depende de la cantidad de categorias a registrar en la lista encadenada

* searching(): funcion que recibe un string categoria y usando la funcion search() de las listas encadenadas busca que objetos de tipo Libro en su lista encadenada cuenta con dicha categoria alamcenada y lo imprime para el usuario 

Su complejidad es O(1) pues aqui solo se llama la funcion search().


# Correciones:

-El arbol ya funciona, estaba mal organizado en el main.cpp

-Se incluyo competencia SICT0301B
