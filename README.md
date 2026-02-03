# 🧩 push_swap — Explicación de la lógica de mi implementación

Este proyecto implementa un algoritmo eficiente para ordenar una pila de números utilizando únicamente un conjunto limitado de operaciones.
Mi solución se basa en una versión optimizada del algoritmo Turk, combinada con una fase inicial de pre‑partición por mediana, lo que reduce drásticamente el número total de movimientos.

El resultado es un push_swap capaz de:

    - Ordenar 100 números en ~550–650 movimientos

    - Ordenar 500 números en ~2900 movimientos

- Muy por encima de los requisitos del proyecto.

---

## 📚 Índice

1. [Objetivo del proyecto](#objetivo-del-proyecto)
2. [Arquitectura general](#arquitectura-general)
3. [1. Pre‑partición por mediana](#1-prepartición-por-mediana)
4. [2. Ordenación de 3 elementos](#2-ordenación-de-3-elementos)
5. [3. Asignación de posiciones y objetivos](#3-asignación-de-posiciones-y-objetivos)
6. [4. Cálculo de costes](#4-cálculo-de-costes)
7. [5. Selección del nodo más barato](#5-selección-del-nodo-más-barato)
8. [6. Ejecución optimizada de movimientos](#6-ejecución-optimizada-de-movimientos)
9. [7. Inserción completa desde B](#7-inserción-completa-desde-b)
10. [8. Rotación final](#8-rotación-final)
11. [Rendimiento](#rendimiento)
12. [Decisiones de diseño](#decisiones-de-diseño)

---

<h2 id="objetivo-del-proyecto">🎯 Objetivo del proyecto</h2>

Ordenar una lista de números utilizando dos pilas (**A** y **B**) y un conjunto limitado de operaciones:

	 **sa, sb, ss**: Intercambio (swap).
	 **pa, pb**: Empujar (push).
	 **ra, rb, rr**: Rotar (rotate).
	 **rra, rrb, rrr**: Rotación inversa (reverse rotate).

- El reto consiste en minimizar el número total de movimientos.

---

<h2 id="arquitectura-general">🏗 Arquitectura general</h2>

Mi implementación sigue esta estructura:

    Pre‑partición por mediana → empujar solo los números pequeños a B

    Ordenar 3 elementos en A

    Para cada nodo en B:

        actualizar posiciones

        asignar objetivo

        calcular costes

        elegir el nodo más barato

        ejecutar movimientos combinados

    Reinsertar todos los nodos en A

    Rotar A hasta dejar el mínimo arriba

- Este flujo permite un rendimiento muy alto sin necesidad de chunks complejos.

---

<h2 id="1-prepartición-por-mediana">🔹 1. Pre‑partición por mediana</h2>

En lugar de empujar todos los elementos a B, calculo la mediana de A y empujo solo los elementos menores que ella.

Ventajas:

    A queda más ordenado

    B contiene valores pequeños (más fáciles de insertar)

    Se reduce el caos inicial

    Se reduce el número total de inserciones caras

- Esto deja A con ~50 elementos y B con ~50 (en el caso de 100 números).

--- 

<h2 id="2-ordenación-de-3-elementos">🔹 2. Ordenación de 3 elementos</h2>

    Cuando A tiene solo 3 elementos, uso sort_three() para ordenarlos con un número mínimo de operaciones.

- Esto deja A en un estado estable para recibir elementos desde B.

---

<h2 id="3-asignación-de-posiciones-y-objetivos">🔹 3. Asignación de posiciones y objetivos</h2>

Antes de cada inserción:

    Actualizo pos de cada nodo

    Para cada nodo de B, busco su target_node en A:

        el primer número mayor que él

        si no existe, el número más pequeño de A

- Esto determina dónde debe insertarse cada nodo.


# 🔥 3. ¿Cómo funciona entonces el flujo completo?
Tu algoritmo Turk funciona así:

1. Calculas posiciones
update_positions(ps);

2. Calculas target positions
set_target_positions(ps);

3. Calculas costes
calculate_costs(ps);

4. Encuentras el nodo más barato
get_cheapest_node(ps);

5. Ejecutas los movimientos
execute_cheapest(ps);  
→ que internamente vuelve a llamar a get_cheapest_node(ps)  
→ y mueve ese nodo a A

6. Repetir hasta que B esté vacío

## 🧠 2. Qué debe hacer init_stack_a
✔ Recorrer ps->args
✔ Validar cada string
sintaxis → error_syntax

overflow → ft_atol(ps, str)

duplicados → error_duplicate

✔ Crear un nodo → new_node(ps, nbr)
✔ Insertarlo en A → stack_add_back(&ps->a, node)
✔ Actualizar ps->size_a
✔ Llamar a error_exit(ps) si algo falla

## 🧠 Objetivo de error_syntax
Comprobar si un string representa un número entero válido:

Permitir + o - al inicio

No permitir solo + o -

No permitir caracteres no numéricos

No permitir strings vacíos

No imprimir "Error"

No liberar memoria

No salir del programa

Si hay error → devuelve 1  
Si es válido → devuelve 0

## 🧠 Objetivo de error_duplicate
Comprobar si un número ya existe en el stack A.

No imprime "Error"

No libera memoria

No llama a exit

Solo devuelve:

1 si hay duplicado

0 si no lo hay

La decisión de abortar el programa la toma init_stack_a.

## 🧠 Objetivo de ft_atol
Convertir un string a long y:

detectar overflow

detectar underflow

detectar strings inválidos (aunque esto ya lo hace error_syntax)

llamar a error_exit(ps) si algo falla

devolver un long válido

## 🧠 Objetivo de new_node
Crear un nodo completamente inicializado:

asignar memoria

asignar el valor (nbr)

inicializar todos los campos auxiliares del algoritmo Turk

dejar punteros next y prev en NULL

si falla → error_exit(ps)
🎯 Cómo encaja en el flujo del main
parse_args → devuelve lista de strings

init_stack_a → recorre cada string

error_syntax → valida formato

ft_atol → convierte y valida overflow

error_duplicate → valida duplicados

new_node → crea nodo completo

stack_add_back → lo añade a A

Todo modular, limpio y profesional.

## 🧠 Objetivo de stack_add_back
Añadir un nodo al final de una lista doblemente enlazada.

Debe:

manejar el caso de lista vacía

enlazar correctamente prev y next

no modificar nada más

no liberar memoria

no imprimir errores

## 🧠 Explicación técnica
✔ Recorre la lista nodo por nodo
while (stack && stack->next) garantiza que siempre haya un siguiente elemento para comparar.

✔ Compara valores en orden ascendente
c
if (stack->nbr > stack->next->nbr)
    return (0);
Si encuentra un valor fuera de orden → no está ordenado.

✔ Si termina el bucle sin fallos
→ la lista está ordenada → devuelve 1.

✔ No modifica nada
Es una función pura de comprobación.

## 🧠 Explicación clara
Hay solo 5 casos posibles cuando tienes 3 números desordenados.

✔ Caso 1
a > b < c y a < c  
→ solo sa

✔ Caso 2
a > b > c  
→ sa + rra

✔ Caso 3
a > c y b < c  
→ ra

✔ Caso 4
a < b y a > c  
→ rra

✔ Caso 5
a < b > c  
→ sa + ra

## 🧠 ¿Qué hace sort_stacks?
Mueve todos los elementos excepto 3 desde A → B

Ordena los 3 elementos restantes en A con sort_three

Mientras haya elementos en B:

recalcula posiciones

asigna target nodes

calcula costes

encuentra el nodo más barato

ejecuta los movimientos óptimos

Cuando B está vacío, rota A hasta que el menor esté arriba

## 🧠 Que hace Position
✔ assign_positions
Recorre el stack y asigna:

Code
pos = 0, 1, 2, 3...
✔ assign_above_median
Divide el stack en dos mitades:

Si pos <= size/2 → está arriba

Si pos > size/2 → está abajo

Esto es crucial para saber si conviene:

ra o rra

rb o rrb

✔ update_positions
Actualiza ambos stacks en una sola llamada.

## 🧠 Explicación target_position
✔ find_smallest
Encuentra el nodo con el número más pequeño en A.
Se usa cuando no existe ningún número mayor que b->nbr.

Ejemplo:
Si B tiene un 98 y A tiene [1, 5, 20], no hay ningún número mayor que 98.
Entonces el target es el más pequeño (1).

✔ find_target_node
Encuentra el nodo de A donde debería insertarse el número de B.

Regla del algoritmo Turk:

El target es el número más pequeño de A que sea mayor que el número de B.

Ejemplo:
A = [2, 7, 12, 20]  
B = 9  
Target = 12

✔ set_target_positions
Para cada nodo de B:

Busca su target en A

Si no existe → usa el más pequeño

Guarda:

target_node

target_pos

Esto es lo que permite calcular los costes después.

## 🧠 Explicación breve
calc_cost devuelve un coste con signo:

positivo → número de rotate necesarios (ra / rb),

negativo → número de reverse rotate necesarios (rra / rrb).
La fórmula usa la mitad del tamaño para decidir la dirección óptima.

calculate_costs recorre la pila B y asigna a cada nodo:

cost_b según su pos y ps->size_b,

cost_a según su target_pos y ps->size_a.

Estos costes con signo permiten luego combinar movimientos (rotar ambos stacks simultáneamente) y elegir la estrategia más barata.



## 🧠 Breve explicación

get_cheapest_node recorre la pila B y devuelve el nodo con la suma mínima de costes absolutos |cost_a| + |cost_b|.

Devuelve NULL si ps o ps->b no existen.

## 🧠 Breve explicación execute_moves.c

Este archivo implementa la parte más importante del algoritmo Turk:

Mover el nodo de B que requiere menos movimientos totales para insertarse en A.

Y lo hace de forma óptima:

primero rotaciones conjuntas (rr, rrr)

luego rotaciones individuales (ra, rb, rra, rrb)

finalmente pa





push_swap/
│
├── Makefile
├── push_swap.h
├── libft/
│
└── src/
    │
    ├── main.c
    │
    ├── parsing/
    │   ├── parse_args.c
    │   ├── error_syntax.c
    │   ├── error_duplicate.c
    │   ├── ft_atol.c
    │
    ├── init/
    │   ├── init_stack_a.c
    │   ├── new_node.c
    │
    ├── stack/
    │   ├── stack_add_back.c
    │   ├── free_stack.c
    │   ├── stack_sorted.c
    │
    ├── errors/
    │   ├── error_exit.c
    │   ├── free_all.c
    │
    ├── operations/
    │   ├── sa.c
    │   ├── sb.c
    │   ├── ss.c
    │   ├── pa.c
    │   ├── pb.c
    │   ├── ra.c
    │   ├── rb.c
    │   ├── rr.c
    │   ├── rra.c
    │   ├── rrb.c
    │   ├── rrr.c
	|   ├── stack_ops_utils.c
    │
    ├──algorithm/
	|	├── cheapest.c
	|	├── sort_if_needed.c
	|	├── sort_three.c
	|	├── sort_stacks.c
	|	├── median.c
	|	├── positions.c
	|	├── target_positions.c
	|	├── costs.c
	|	├── find_smallest.c
	|	├── execute_moves.c
