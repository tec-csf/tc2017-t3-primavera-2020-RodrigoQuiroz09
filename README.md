# Tarea *TAREA 3*. *Técnicas de diseño de algoritmos*

---

##### Integrantes:
1. *Rodrigo Quiroz Reyes* - *A01026546* - *CSF*

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

PROBLEMA 1: COLOREADO DE UN GRAFO
Para este problema se planteó el siguiente problema:

"Dado un grafo conexo y un número m > 0, llamamos colorear el grafo a asignar un número i (1 ≤ i ≤ m) a cada vértice, de forma que dos vértices adyacentes nunca tengan asignados números iguales. Deseamos implementar un algoritmo que coloree un grafo dado."

Entonces la solución dada es que al grafo que hemos considerado como raiz se le asigna el primer color, después por cada vértice restante considera el vértice seleccionado actualmente y coloréelo con el color con el número más bajo que no se haya utilizado anteriormente
vértices de colores adyacentes a él. Si todos los colores utilizados anteriormente aparecer en vértices adyacentes a v, asignarle un nuevo color.

A la hora de colorear los vértices, estos se guardan en una estructura auxiliar para mantener un registrosobre qué nodos ya han sido visitados volviéndolo un algoritmo ávido. De esa manera nos aseguramos de que cada vértice obtenga un color diferente al de sus adyacentes, además de que busca la combinación con menor número de colores posibles.

La siguiente imagen es el grafo utilizado como ejemplo para la verificación del algoritmo


![Settings Window](https://raw.github.com/tec-csf/tc2017-t3-primavera-2020-RodrigoQuiroz09/master/examples/Grafo_ejemplo.png)

Como dentro del algoritmo de colorear se basa en 2 ciclos anidados para poder recorrer todas las opciones sin equivocarse la complejidad tiende a ser O(V^2), siendo V el número de vértices, pero como en los grafos las aristas dictan las adyacencias lo cual son una parte fundamental a la hora de asignar el color es tomado en cuenta su tiempo de procesamiento A es el número de aristas. Por consiguiente la complejidad temporal del algoritmo es de: O(V^2+A).

PROBLEMA 2: GATO
Para este problema se planteó el siguiente problema:

"Si se desea implementar un algoritmo para modelar el juego Gato ,  ¿qué técnica de diseño de algoritmo deberá usarse?"

Para este problema se utilizó el diseño de algritmo minimax el cual esun algoritmo recursivo que se utiliza para elegir un movimiento óptimo para un jugador, suponiendo que el oponente también está jugando de manera óptima. Como su nombre lo indica, su objetivo es minimizar la pérdida máxima (minimizar el peor de los casos).

Su comportamiento se basa en el puntaje que se obtiene a partir de una cierta serie de decisiones que se analizan de manera recursiva. De ahí vas regresando los resultado que más le brinden beneficio al algoritmo escogiendo esa ruta como opción. Y además como es un algoritmo que implementa el tipo de diseño de backtracking, siempre va a analizar todos los casos posibles, volviéndolo una de los algoritmos más fiables.

La siguiente imagen demuestra una pequeña fracción del recorrido recursivo del minimax y como este siempre busca la opción con mayor puntaje.

![Settings Window](https://raw.github.com/tec-csf/tc2017-t3-primavera-2020-RodrigoQuiroz09/master/examples/tic_tac_toe.jpg)

Por último como es un algoritmo recursivo este depende bastante tanto de la profundidad que obtenga el arbol de recursividad como todos los posibles movimientos en cada etapa de análisis. Por lo tanto se le es asignada una complejidad temporal de O(b^m), donde b es el número de movimientos legales en cada punto y m es la profundidad máxima del árbol.
### 2.1 Pasos a seguir para utilizar la aplicación

    1. Abrir la terminal del equipo donde se comprobarán la eficiencia de los algoritmos.
    2. Acceder al directorio donde se clonará el repositorio de github.
    3. Utilizar el siguiente comando para clonar el repositorio: https://github.com/tec-csf/tc2017-t3-primavera-2020-RodrigoQuiroz09.git
    4. Compilar los códigos a su preferencia usando el compilador de g++. Linea de compilaión recomendada: g++ Algoritmo.cpp -o nombre_ejecutable
    5. Ejecutar ambos código para confirmar la soluciones a los problemas
    6. Para el de Coloreado_Grafos.cpp el input del usuario es nulo ya que el coloreado está basado en un grafo ejemplo visto anteriormente en la explicación de la solución
    7. Para el código de Gato.cpp el usuario debe de interactuar con el algoritmo hasta que uno de los 2 gane

## 3. Referencias

*https://thecodingtrain.com/CodingChallenges/154-tic-tac-toe-minimax.html
https://cis.temple.edu/~vasilis/Courses/CIS603/Lectures/l7.html
https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/?ref=rp
https://www.geeksforgeeks.org/graph-coloring-applications/?ref=rp*
