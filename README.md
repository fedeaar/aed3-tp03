## TP3: Camino Mínimo y Flujo Máximo

Arienti, Zaid


<br>

### Estructura del repo

El repositorio cuenta con los siguientes archivos y carpetas:

- 'ej-1' - Los archivos correspondientes a la implementación del ejercicio 1, el informe y los archivos fuente de la experimentación.

- 'ej-2' - Los archivos correspondientes a la implementación del ejercicio 2.


<br>

### Cómo crear los archivos ejecutables de los ejercicios

Para este procedimiento se asume que trabajaremos en bash. Desde la raiz del repo procederemos de la siguiente forma.

1. Para crear el ejecutable de cada ejercicio (reemplazar `i` por el numero del ejercicio. Por ejemplo: ej-1)

```bash
$ cd ej-i

$ mkdir build

$ cd build

$ cmake ..

$ make
```

2. Para ejecutarlo (desde la carpeta ./ej-`i`/build/, reemplazar `i` por el numero del ejercicio)

```bash
$ ./ej-i
```


<br>

### Cómo crear los archivos ejecutables de la experimentación

Para este procedimiento se asume que trabajaremos en bash. Desde la raiz del repo procederemos de la siguiente forma.

1. Para crear los ejecutables de la experimentación

```bash
$ cd ej-1/experimentacion/

$ mkdir build

$ cd build

$ cmake ..

$ make
```

2. Para ejecutar cada experimento (desde la carpeta ./ej-3/experimentacion/)

```bash
# generamos los casos de test y directorios

$ python generar_instancias.py

$ python generar_instancias_ralas.py

# ejecutamos

$ ./build/exp-dijkstra-fast # heap
$ ./build/exp-dijkstra-slow # ingenuo
$ ./build/exp-dijkstra-queue

$ ./build/exp-dijkstra-fast-ralo 
$ ./build/exp-dijkstra-slow-ralo 
$ ./build/exp-dijkstra-queue-ralo

$ ./build/exp-dijkstra-fast-ralo-small 
$ ./build/exp-dijkstra-slow-ralo-small
$ ./build/exp-dijkstra-queue-ralo-small
```
