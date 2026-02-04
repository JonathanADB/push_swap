*This project has been created as part of the 42 curriculum by jonadomi*

<h1 align="center">🧩 Push_swap — Lógica de Ordenación Eficiente</h1>

<p align="center">
  <b>Un motor de optimización basado en el Turk Algorithm para la ordenación de stacks.</b>
</p>

---

## 📖 Description

**Push_swap** es un proyecto de algoritmos en el que debemos ordenar un conjunto de datos en una pila (Stack A), utilizando una pila auxiliar (Stack B) y un conjunto limitado de instrucciones. El objetivo principal es minimizar el número de operaciones para lograr una ordenación perfecta.

Mi implementación utiliza una versión mejorada del **Turk Algorithm**, que destaca por su enfoque "Greedy" (voraz): en cada paso, calcula el coste exacto de mover cada nodo y selecciona la opción más barata. Gracias a la **pre-partición por mediana**, este programa logra resultados significativamente mejores que los requeridos por los estándares de la escuela.

---

## 📚 Índice

1. 	[Instructions](#instructions)
2. 	[Objetivo del proyecto](#objetivo)
3. 	[Arquitectura general](#arquitectura)
4. 	[1. Pre‑partición por mediana](#prepartición)
5. 	[2. Ordenación de 3 elementos](#ordenación-de-3-elementos)
6. 	[3. Asignación de posiciones y objetivos](#asignación-de-posiciones-y-objetivos)
7. 	[4. Cálculo de costes](#cálculo-de-costes)
8. 	[5. Selección del nodo más barato](#selección-del-nodo-más-barato)
9. 	[6. Ejecución optimizada de movimientos](#ejecución-optimizada-de-movimientos)
10.	[7. Inserción completa desde B](#inserción-completa-desde-b)
11. [8. Rotación final](#rotación-final)
12.	[Rendimiento](#rendimiento)
13.	[Decisiones de diseño](#decisiones-de-diseño)
14. [Resources & AI Disclosure](#recursos)

---
<h2 id="instructions">🛠️ Instructions</h2>

### Compilación
El proyecto se compila mediante un `Makefile` que gestiona las dependencias y la `libft`.
```bash
make        # Genera el ejecutable push_swap
make clean  # Elimina los archivos objeto (.o)
make fclean # Elimina objetos y el ejecutable
make re     # Recompila todo el proyecto
```
## 🚀 Ejecución y Testing

### Ejecución básica

- Puedes validar que la salida es correcta utilizando el checker proporcionado y contar el número de instrucciones generadas:
```bash
# Verificar si el stack queda ordenado (debe devolver OK)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

# Contar el número de movimientos realizados
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
- Para garantizar que no existen fugas de memoria (leaks), ejecuta el programa a través de Valgrind:
```bash
ARG="4 67 3 87 23"; valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG
```
---

## 🚀 Introducción

Este proyecto implementa un algoritmo altamente eficiente para ordenar una pila de números utilizando un conjunto limitado de operaciones. Mi solución combina el **Turk Algorithm** con una fase inicial de **pre‑partición por mediana**, optimizando el flujo de datos entre stacks.

### 📊 Rendimiento Obtenido
Mis resultados superan con creces los límites de la evaluación (100%):

| Cantidad | Límite 42 (100%) | Mi Resultado | Calificación |
| :--- | :--- | :--- | :--- |
| **100 números** | < 700 movimientos | **~550 – 650** | 🏆 Excelente |
| **500 números** | < 5500 movimientos | **~2900** | 🏆 Excelente |

---

## 🛠️ El Algoritmo en un Vistazo

A diferencia de algoritmos básicos como *Bubble Sort* o *Selection Sort*, mi implementación se centra en el **cálculo proactivo de costes**. En lugar de buscar el número más pequeño, buscamos el **nodo más eficiente de mover**.

1.  **División Inteligente:** Usamos la mediana para no saturar el Stack B de forma desordenada.
2.  **Estrategia Greedy:** Calculamos el coste total de cada elemento (movimientos en A + movimientos en B).
3.  **Optimización de Instrucciones:** Aprovechamos `rr` y `rrr` para realizar rotaciones dobles siempre que sea posible.



---

<h2 id="objetivo">🎯 Objetivo del Proyecto</h2>

El reto consiste en ordenar una secuencia de números enteros en el **Stack A** utilizando el menor número posible de operaciones, apoyándose en un **Stack B** auxiliar.

### 🛠️ El Set de Instrucciones

Para lograrlo, solo disponemos de las siguientes operaciones atómicas:

| Movimiento | Descripción |
| :--- | :--- |
| `sa`, `sb`, `ss` | **Swap:** Intercambia los dos primeros elementos en el tope de la pila. |
| `pa`, `pb` | **Push:** Pasa el elemento del tope de una pila a la otra. |
| `ra`, `rb`, `rr` | **Rotate:** Desplaza todos los elementos una posición hacia arriba (el primero pasa a ser el último). |
| `rra`, `rrb`, `rrr` | **Reverse Rotate:** Desplaza todos los elementos hacia abajo (el último pasa a ser el primero). |

> **Nota de eficiencia:** El éxito en **42** no es solo que el programa funcione (que dé `OK`), sino lograr que el algoritmo "piense" el camino más corto, reduciendo la complejidad de movimientos al mínimo.

---

<h2 id="arquitectura">🏗️ Arquitectura General</h2>

Mi implementación sigue una estructura de **Pipeline de Optimización**, dividida en tres fases principales: Inicialización, Ciclo de Costes y Cierre.

### 🔄 Flujo del Algoritmo

| Fase | Acción | Descripción |
| :--- | :--- | :--- |
| **I. Preparación** | `Pre-partición` | Se utiliza la **mediana** para mover números pequeños a B, manteniendo la pila A manejable. |
| | `Sort 3` | Aplicamos una lógica específica para dejar solo 3 elementos ordenados en A. |
| **II. Bucle Turk** | `Análisis` | Se actualizan posiciones, se asignan nodos objetivo y se calculan costes de movimiento. |
| | `Optimización` | Se selecciona el **nodo más barato** y se ejecutan movimientos combinados (`rr`/`rrr`). |
| **III. Finalización** | `Inserción` | Se reinsertan los nodos de B en A en su posición exacta. |
| | `Ajuste` | Rotación final del Stack A para situar el valor mínimo en el tope. |

> **💡 Ventaja competitiva:** Este flujo permite alcanzar un rendimiento de **~2900 movimientos en 500 números** sin la sobrecarga de gestionar *chunks* o bloques fijos, adaptándose dinámicamente a la distribución de los datos.

---

<h2 id="prepartición">🔹 1. Pre‑partición por Mediana</h2>

En lugar de realizar una transferencia masiva y desordenada hacia el Stack B, el algoritmo aplica un filtro de **umbral estadístico** basado en la mediana de la pila original.

### 🧠 Estrategia de Selección
Calculamos la mediana de los valores en A y transferimos a B **únicamente** los elementos que cumplen con: 
$$valor < mediana_{stack\_A}$$



### 🏆 Ventajas del Filtrado
* **Reducción del Caos:** El Stack B se puebla con valores menores, creando un entorno más predecible para la búsqueda de objetivos.
* **A preserva su estructura:** Al dejar aproximadamente el 50% de los elementos (los más grandes) en A, la fase de ordenación de 3 elementos y la posterior re-inserción es mucho más limpia.
* **Eficiencia de Inserción:** Se minimizan las "inserciones caras" al evitar que números muy grandes crucen al Stack B y tengan que recorrer toda la pila de vuelta.

> **Impacto en el rendimiento:** En una prueba de 100 números, esta fase deja ambos stacks equilibrados (~50/50), sentando las bases para que el cálculo de costes posterior sea mucho más corto y preciso.

--- 

<h2 id="ordenación-de-3-elementos">🔹 2. Ordenación de 3 elementos (`sort_three`)</h2>

Cuando el **Stack A** se reduce a tres elementos, el algoritmo utiliza una lógica de decisión optimizada para dejarlos ordenados en el menor número de movimientos posibles (máximo 2). 

### ⚡ Lógica de Decisión (Hardcoded)
Para evitar cálculos costosos, mi función analiza directamente los valores del tope (**a**), el centro (**b**) y el fondo (**c**):

| Caso (a, b, c) | Condición | Operación | Movimientos |
| :--- | :--- | :--- | :---: |
| `[2, 1, 3]` | `a > b && b < c && a < c` | `sa` | 1 |
| `[3, 2, 1]` | `a > b && b > c` | `sa` + `rra` | 2 |
| `[3, 1, 2]` | `a > c && b < c` | `ra` | 1 |
| `[2, 3, 1]` | `a < b && a > c` | `rra` | 1 |
| `[1, 3, 2]` | `a < b && b > c && a < c` | `sa` + `ra` | 2 |



> **Reflexión técnica:** Implementar esta lógica mediante `if/else if` en lugar de un algoritmo genérico garantiza que la base de nuestra pila siempre esté ordenada con el **coste computacional mínimo**.

---

<h2 id="asignación-de-posiciones-y-objetivos">🔹 3. Asignación de Posiciones y Objetivos</h2>

Para que cada inserción sea quirúrgica, el algoritmo debe conocer la configuración exacta de ambas pilas en tiempo real. Esta fase prepara los datos necesarios para el cálculo de costes.

### 🎯 La Búsqueda del "Target Node"
Para cada nodo que reside en el **Stack B**, identificamos su posición ideal en el **Stack A** siguiendo esta jerarquía lógica:

1.  **El Superior Inmediato:** Buscamos el nodo en A que sea el número más pequeño entre todos los que son mayores que el número de B.
2.  **El Caso Límite (Circularidad):** Si el número en B es más grande que cualquier número en A, su "objetivo" será el **nodo con el valor mínimo** en A. Esto mantiene la propiedad circular de la pila.



### 🏗️ Actualización de Índices
Antes de buscar objetivos, el algoritmo recalcula la posición (`pos`) de cada nodo en ambas pilas (de `0` a `n-1`). 
* Esto es fundamental para determinar si un nodo está en la **mitad superior** o **inferior** de la pila.
* Determina si usaremos rotaciones normales (`ra`/`rb`) o inversas (`rra`/`rrb`).

> **Impacto en el Bot:** Esta fase de mapeo es equivalente a lo que un bot de navegación hace al recalcular su posición GPS antes de decidir el siguiente giro. Sin una asignación de objetivos precisa, el número de movimientos sería errático e ineficiente.

---

<h2 id="cálculo-de-costes">🔹 4. Cálculo de Costes</h2>

Una vez definidos los objetivos, el algoritmo cuantifica el esfuerzo necesario para mover cada pieza. No solo contamos pasos, sino que determinamos la **dirección óptima** para cada pila de forma independiente.

### 📉 La Métrica del Coste
Para cada nodo en **B**, calculamos dos variables distintas que representan la distancia al tope de sus respectivas pilas:

* **`cost_b`:** Cantidad de movimientos para llevar el nodo de B a la cima.
* **`cost_a`:** Cantidad de movimientos para llevar su `target_node` a la cima de A.



### 🔄 Dirección y Polaridad
Utilizamos un sistema de **números con signo** para codificar la dirección del movimiento, lo que simplificará la optimización posterior:

| Posición del Nodo | Tipo de Movimiento | Signo del Coste |
| :--- | :--- | :---: |
| Mitad Superior (`index <= size / 2`) | Rotación (`ra` / `rb`) | **+** (Positivo) |
| Mitad Inferior (`index > size / 2`) | Rotación Inversa (`rra` / `rrb`) | **-** (Negativo) |

> **💡 Inteligencia del Algoritmo:** Al calcular costes positivos y negativos, el programa puede identificar instantáneamente si ambas pilas deben rotar en el mismo sentido, permitiendo el uso de instrucciones dobles (`rr` o `rrr`) que reducen el coste total a la mitad.

---

<h3 id="selección-del-nodo-más-barato">🔹 5. Selección del nodo más barato</h3>

    Para maximizar la eficiencia, el algoritmo aplica una estrategia **Greedy** (voraz). De todos los nodos presentes en el **Stack B**, se calcula el coste individual y se selecciona aquel cuyo sumatorio de movimientos sea el mínimo:

$$coste\_total = |cost\_a| + |cost\_b|$$

> **Nota:** Se utilizan valores absolutos porque los costes pueden ser negativos (representando rotaciones inversas `rra`/`rrb`). El nodo con el `coste_total` más pequeño es el elegido para ser insertado inmediatamente en A.

---

<h3 id="ejecución-optimizada-de-movimientos">🔹 6. Ejecución optimizada de movimientos</h3>

La clave del rendimiento reside en la **sincronización de rotaciones**. En lugar de mover cada pila por separado, el algoritmo identifica cuándo ambos stacks deben rotar en la misma dirección para aprovechar las instrucciones dobles.

#### 🔄 Rotaciones Simultáneas
Si ambos costes tienen el mismo signo, optimizamos los movimientos:

* **Costes positivos (+, +):** Se ejecutan `rr` hasta que una de las pilas llega a su destino.
* **Costes negativos (-, -):** Se ejecutan `rrr` hasta que una de las pilas llega a su destino.

#### 🎯 Ajuste Final e Inserción
Una vez agotadas las rotaciones dobles, se procesan los movimientos restantes:

1.  **Ajuste individual:** Se ejecutan las rotaciones simples pendientes (`ra`/`rra` o `rb`/`rrb`).
2.  **Transferencia:** Se ejecuta `pa` para mover el nodo a su posición exacta en el Stack A.

> **Resultado:** Esta técnica reduce drásticamente el número de movimientos totales, permitiendo pasar los límites más estrictos de la evaluación (especialmente en el test de 500 números).
 ---

 <h2 id="inserción-completa-desde-b">🔹 7. Inserción completa desde B</h2>

El algoritmo entra en un bucle de **ejecución voraz (Greedy)**. No se conforma con mover un solo nodo, sino que recalcula el estado global del sistema tras cada operación para asegurar la máxima eficiencia.

### 🔄 El Bucle de Optimización
Este proceso se repite cíclicamente hasta que el **Stack B queda completamente vacío**:

1.  **Recalibración:** Se actualizan las posiciones de todos los nodos remanentes.
2.  **Mapeo:** Se vuelven a asignar los objetivos en A para cada nodo de B.
3.  **Evaluación:** Se recalculan los costes de desplazamiento.
4.  **Acción:** Se identifica y ejecuta el movimiento hacia el "nodo más barato".



> **Dato de rendimiento:** Gracias a que el algoritmo es dinámico y recalcula posiciones en cada paso, logra adaptarse a cualquier distribución de números, manteniendo la media por debajo de los **~2900 movimientos**.

---

<h2 id="rotación-final">🔹 8. Rotación Final</h2>

Una vez que todos los elementos han regresado al **Stack A**, la pila ya está técnicamente ordenada, pero es probable que no esté en su posición "natural" (con el número menor en el tope).

### 🎯 Alineación del Mínimo
Para finalizar el proceso de forma limpia:
* El algoritmo localiza el **nodo con el valor mínimo**.
* Se calcula si es más corto llevarlo al tope mediante rotaciones normales (`ra`) o inversas (`rra`).
* Se ejecuta la rotación final.



**¡Resultado!** La pila A queda perfectamente ordenada de menor a mayor, cumpliendo con todos los requisitos de la evaluación de 42.

---

<h2 id="rendimiento">🚀 Rendimiento (Benchmarks)</h2>

Gracias a la optimización del cálculo de costes y la pre-partición, los resultados obtenidos superan con creces los límites impuestos por la escuela (máximo 5 puntos):

| Tamaño de la Pila | Límite para 5 Puntos | Mi Resultado | Eficiencia |
| :--- | :--- | :--- | :---: |
| **5 números** | < 12 movimientos | **7 – 9** | ⚡ 100% |
| **100 números** | < 700 movimientos | **~550 – 650** | ⚡ 100% |
| **500 números** | < 5500 movimientos | **~2900** | ⚡ 100% |

---

<h2 id="decisiones-de-diseño">🧠 Decisiones de Diseño</h2>

La arquitectura del proyecto fue diseñada bajo tres pilares: **Eficiencia**, **Simplicidad** y **Robustez**.

* **Mediana vs. Chunks:** Optar por la pre-partición por mediana en lugar de bloques fijos (chunks) simplifica la lógica del código y evita que el Stack B se convierta en un sumidero de movimientos innecesarios.
* **Mantenimiento de Orden en A:** Al dejar siempre el Stack A parcialmente ordenado (mínimo 3 elementos), reducimos drásticamente la "resistencia" al reinsertar nodos desde B.
* **Estructura de Datos `t_node`:** Cada nodo de la lista circular lleva consigo su propia "inteligencia" (posición, coste, objetivo), lo que permite que el algoritmo Turk tome decisiones en tiempo real sin recorrer toda la lista repetidamente.
* **Modularidad:** El código está fracturado en módulos lógicos (costes, movimientos, inicialización), facilitando la depuración con **Valgrind** y cumpliendo con la normativa de la Norma de 42.

> **Nota final:** Esta implementación no solo busca pasar la evaluación, sino optimizar el uso de recursos, una habilidad crítica para el desarrollo de futuros bots y sistemas de alto rendimiento.

## 📂 Estructura del Proyecto

El código se ha organizado siguiendo una arquitectura modular. Cada directorio agrupa funciones con una responsabilidad única, facilitando la depuración y cumpliendo con la **Norma de 42**.

```text
push_swap/
├── 📁 include/
│   └── push_swap.c          # Header con estructuras y prototipos
├── 📁 libft/                # Librería de funciones auxiliares personalizada
├── 📁 src/                  # Código fuente del proyecto
│   ├── 📁 algorithm/        # Núcleo del algoritmo Turk
│   │   ├── cheapest.c       # Selección del nodo con menor coste
│   │   ├── costs.c          # Cálculo de movimientos necesarios
│   │   ├── execute_moves.c  # Orquestación de instrucciones
│   │   ├── find_smallest.c  # Localización del mínimo para rotación final
│   │   ├── median.c         # Cálculo de pivotes para pre-partición
│   │   ├── positions.c      # Actualización de índices en tiempo real
│   │   ├── sort_if_needed.c # Comprobaciones de estado
│   │   ├── sort_stacks.c    # Flujo principal del algoritmo
│   │   ├── sort_three.c     # Lógica optimizada para 3 elementos
│   │   └── target_positions.c # Mapeo de objetivos B -> A
│   ├── 📁 errors/           # Gestión de salidas y leaks
│   │   ├── error_exit.c     # Mensajes de error estándar
│   │   └── free_all.c       # Limpieza total de memoria
│   ├── 📁 init/             # Configuración inicial
│   │   ├── init_stack_a.c   # Carga de datos inicial
│   │   └── new_node.c       # Constructor de nodos
│   ├── 📁 operations/       # Set de instrucciones (sa, pa, ra, rra...)
│   │   ├── [sa, sb, ss].c   # Swaps
│   │   ├── [pa, pb].c       # Pushes
│   │   ├── [ra, rb, rr].c   # Rotations
│   │   └── [rra, rrb, rrr].c # Reverse Rotations
│   ├── 📁 parsing/          # Validación de entrada
│   │   ├── error_duplicate.c # Control de números repetidos
│   │   ├── error_syntax.c   # Validación de caracteres no numéricos
│   │   ├── ft_atol.c        # Conversión con control de overflow
│   │   └── parse_args.c     # Split y limpieza de argumentos
│   ├── 📁 stack/            # Utilidades de la lista enlazada
│   │   ├── free_stack.c     # Liberación selectiva
│   │   ├── stack_add_back.c # Inserción de nodos
│   │   └── stack_sorted.c   # Verificación de orden
│   └── main.c               # Punto de entrada y orquestador
├── Makefile                 # Script de compilación automatizada
```

---

<h2 id="recursos">📚 Resources & AI Disclosure</h2>

## Referencias Clásicas

- **The Turk Algorithm** — Conceptos fundamentales sobre asignación de objetivos y optimización de costes entre dos pilas.
- **Thuggonaut – push_swap TUTORIAL!** — Explicación práctica del sorting en C y estrategias de inserción.
- **Oceano’s Push_swap Tutorial** — Análisis detallado de la lógica de target nodes y rotaciones combinadas.
- **42 Docs** — Documentación oficial sobre gestión de memoria, normas de estilo y buenas prácticas en C.

---

### Uso de Inteligencia Artificial (AI)

En cumplimiento con el *Chapter VII* y siguiendo las normas de transparencia académica, se declara el uso de herramientas de IA durante el desarrollo del proyecto.  
La IA **no generó código del proyecto**, sino que se utilizó exclusivamente como apoyo conceptual y documental.

### Áreas donde se empleó IA

- **Estructuración de documentación**  
  Refinado del formato del README, organización de secciones y creación de tablas de rendimiento.

- **Clarificación conceptual**  
  Análisis del funcionamiento integral del algoritmo: flujo de inserción, cálculo de objetivos, gestión dinámica de nodos, rotaciones combinadas y coherencia entre los distintos módulos de operaciones.


- **Soporte en testing**  
  Ayuda en la sintaxis de comandos de Valgrind, pipes en Bash y estrategias de stress‑testing.

- **Revisión de arquitectura**  
  Análisis de la estructura global del proyecto, coherencia entre módulos, claridad en la separación de responsabilidades y consistencia en el flujo completo del algoritmo.

---

## Límites del uso de IA

Para mantener la integridad del proyecto:

- **No se generó código fuente mediante IA.**  
  Todo el código fue escrito, depurado y optimizado manualmente.

- **No se utilizaron soluciones externas completas.**  
  La IA se empleó únicamente para *explicar*, *analizar* o *reformular*, nunca para proporcionar implementaciones listas para usar.

- **El diseño del algoritmo, la arquitectura y las decisiones finales son completamente propias.**

---

## Reflexión Personal

El uso de IA permitió acelerar la comprensión de ciertos conceptos avanzados (como la interacción entre `cost_a`, `cost_b` y las rotaciones combinadas), pero el trabajo real —la implementación, la depuración y la optimización— fue realizado íntegramente a mano.

Este equilibrio garantiza que el proyecto cumple con los estándares de 42 y refleja un aprendizaje real y profundo.

---

## Aprendizajes Técnicos Relevantes

Durante el desarrollo del proyecto, hubo dos áreas clave que marcaron una diferencia significativa en la calidad y eficiencia de la solución:

### 📌 Cálculo de la Mediana y Pre‑partición Inteligente

La estrategia de calcular la **mediana** de la pila A y utilizarla como umbral para la pre‑partición fue un punto de inflexión.  
Esta técnica permitió:

- Reducir drásticamente el desorden inicial.
- Minimizar el número de elementos que requieren inserciones costosas.
- Mantener A en un estado más estable para el algoritmo Turk.
- Mejorar el rendimiento global sin necesidad de implementar *chunks* complejos.

Este enfoque no solo simplificó la arquitectura, sino que también permitió un comportamiento más predecible y eficiente durante la reinserción desde B.

### 🔧 Manipulación de Nodos y Listas Enlazadas

El proyecto también fue una oportunidad para profundizar en:

- Gestión de punteros en estructuras enlazadas.
- Actualización de posiciones (`pos`) y objetivos (`target_node`) en tiempo real.
- Cálculo de costes (`cost_a`, `cost_b`) basado en la estructura dinámica de las pilas.
- Comprensión de cómo las rotaciones afectan la topología de la lista.
- Diseño modular de funciones para mantener el código limpio y mantenible.

Estas lecciones fueron esenciales para implementar correctamente el algoritmo Turk y optimizar las rotaciones combinadas (`rr`, `rrr`), garantizando que cada inserción contribuyera al orden final de la pila A.

---

