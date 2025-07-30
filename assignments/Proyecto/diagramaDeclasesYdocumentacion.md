# Sistema de Combate Polimórfico en C++

Este proyecto implementa un sistema de combate simple utilizando **POO en C++**, con las siguientes características:

- Clases derivadas de una clase base abstracta (`Unidad`)
- Uso de **herencia**, **polimorfismo**, **sobrecarga de operadores**, y **vector de punteros**
- Modelado de 3 tipos de personajes: **Guerrero (Max)**, **Mago (Fudz)** y **Sanador (Noob)**

## Estructura de Clases

### 🧱 Clase Base: `Unidad` (abstracta)
- Atributos: `vida`, `salud`, `ataque`, `nivel`
- Métodos:
  - `virtual void Atacar(Unidad& objetivo)`
  - `virtual void RecibeAtaque(int valor)`
  - `virtual void Imprimir() const`
  - `virtual bool estaVivo() const = 0` ← Método puro
  - `void BarraDeVida()` ← Muestra la barra de vida
- Sobrecarga externa del operador `<<` para imprimir la unidad.

---

### ⚔️ Clase Derivada: `Max` (Guerrero)
- Atributo adicional: `fuerza`
- Ataca con `ataque + fuerza`
- Bloquea un 20% del daño recibido
- **Sólo está vivo si `vida > 0` y `fuerza > 10`**

---

### ✨ Clase Derivada: `Fudz` (Mago)
- Atributo adicional: `Hafudzzz` (maná mágico)
- Ataca con `ataque + Hafudzzz`
- Reduce daño en 10% de Hafudzzz
- Si `vida <= 0` y `Hafudzzz >= 20` revive con 10 de vida

---

### 💖 Clase Derivada: `Noob` (Sanador)
- Puede curar a otros con `CareToMuch()`
- Bloquea 5% del daño recibido
- **Sólo está vivo si `vida > 0` y `salud > 20`**

---

## 🧪 Funcionalidades Probadas en `main()`

- Se crea un **vector de punteros a `Unidad`**, cada uno apuntando a un objeto distinto (`Max`, `Fudz`, `Noob`)
- Se imprime el **estado inicial**
- El personaje 0 (`Max`) ataca a los personajes 1 y 2
- Se imprime el estado después del ataque
- Se libera la memoria

---

## 💡 Polimorfismo y Sobrecarga

- **Polimorfismo:** se usa `vector<Unidad*>` y se llama a métodos virtuales (`Atacar`, `RecibeAtaque`, `Imprimir`) según el tipo real del objeto.
- **Sobrecarga de operador `<<`:** se sobrecarga para imprimir cualquier objeto derivado de `Unidad`.

---

## 📦 Compilación

```bash
g++ combate.cpp -o combate
./combate
 
┌────────────────────────────┐
│        Unidad (abstracta)  │
├────────────────────────────┤
│ - vida: int                │
│ - salud: int               │
│ - ataque: int              │
│ - nivel: int               │
├────────────────────────────┤
│ + Unidad(int, int, int, int)     │
│ + Atacar(obj: Unidad&): void     │
│ + RecibeAtaque(valor: int): void│
│ + Imprimir(): void               │
│ + BarraDeVida(): void           │
│ + GetVida(): int                │
│ + SetVida(v: int): void         │
│ + estaVivo(): bool (abstracto)  │
│ + ~Unidad()                     │
│ <<friend>> operator<<(ostream&, │
│                 const Unidad&)  │
└────────▲───────────────────────┘
         │
         │
 ┌───────┼─────────────────────────────────────────────┐
 │       │                         │                   │
 ▼       ▼                         ▼                   ▼
┌────────────┐         ┌────────────────┐      ┌────────────────┐
│    Max     │         │     Fudz       │      │     Noob       │
├────────────┤         ├────────────────┤      ├────────────────┤
│ - fuerza: int│        │ - Hafudzzz: int│      │ (no atributos)│
├────────────┤         ├────────────────┤      ├────────────────┤
│ + Atacar() │         │ + Atacar()     │      │ + Atacar()     │
│ + RecibeAtaque() │   │ + RecibeAtaque()│      │ + RecibeAtaque()│
│ + Imprimir() │      │ + Imprimir()   │      │ + Imprimir()   │
│ + estaVivo(): bool │ │ + estaVivo(): bool│   │ + estaVivo(): bool│
└────────────┘         └────────────────┘      └────────────────┘


##EXPLIACION DEL PROYECTO 

# Sistema de Combate Polimórfico en C++

## Hoja de presentación

**Nombre del alumno:** Maximiliano Dirmau Pozos Moreno  
**Matrícula:** A01700000  
**Carrera:** Ingeniería en Tecnologías Computacionales (ITC)  
**Materia:** Programación Orientada a Objetos   
**Fecha:** 29 de julio de 2025  
**Tema:** Simulación de combate en C++ usando herencia, polimorfismo, clases abstractas y sobrecarga de operadores

---

## 🧩 Introducción

En este proyecto se desarrolla una simulación de combate por turnos en C++ donde tres personajes (Max el Guerrero, Fudz el Mago y Noob el Sanador) interactúan dentro de un sistema orientado a objetos. El objetivo principal es aplicar correctamente conceptos como **herencia**, **polimorfismo**, **clases abstractas**, **sobrecarga de operadores** y **manejo de excepciones**.

Este ejercicio no solo permite reforzar el conocimiento teórico sobre programación orientada a objetos (POO), sino también explorar buenas prácticas de diseño de software en C++. La modularidad, legibilidad y extensibilidad del código fueron prioridades en el desarrollo.

---

## Explicación 

### Herencia

Se utilizó herencia para crear una jerarquía de clases. La clase base `Unidad` encapsula atributos y comportamientos comunes como vida, ataque, salud, nivel y nombre. A partir de esta clase se heredan tres clases especializadas:

- `Max`: Guerrero con daño físico.  
- `Fudz`: Mago con habilidades mágicas y capacidad de revivir.  
- `Noob`: Sanador especializado en curaciones.  

Gracias a la herencia se evita duplicar código y se centraliza la lógica común en la clase padre.

---

### Polimorfismo

El polimorfismo se implementó a través de métodos virtuales como `atacar()`, `estaVivo()` y `imprimir()`, definidos en la clase abstracta `Unidad` y redefinidos en las clases hijas.

Esto permite que, al usar punteros del tipo `Unidad*`, los métodos llamados ejecuten la versión correspondiente a la clase real del objeto, logrando así un comportamiento dinámico.

```cpp
Unidad* u = new Fudz("Fudz el Mago", 100, 60, 20, 1);
u->atacar(...); // Se ejecuta la función de ataque específica del mago


## Clases abstractas
La clase Unidad se diseñó como clase abstracta al incluir al menos un método virtual puro:

virtual bool estaVivo() const = 0;
Esto impide la instanciación directa de objetos Unidad y obliga a todas las clases derivadas a implementar este método. Esto garantiza que todas las unidades del sistema tengan una lógica definida para determinar si están vivas.

## Sobrecarga de operadores
Se sobrecargó el operador << para permitir la impresión amigable de cualquier objeto que herede de Unidad, usando una función amiga que internamente llama al método virtual imprimir() de cada subclase.

ostream& operator<<(ostream& os, const Unidad& u) {
    u.imprimir(os);
    return os;
}
Esto permite hacer:

cout << *unidad;

Y se imprimen sus atributos dependiendo de si es guerrero, mago o sanador. Esta sobrecarga mejora mucho la legibilidad del código y es una muestra del poder de la POO en C++.

## Manejo de excepciones
Aunque el proyecto no utiliza excepciones de forma activa, se previó su uso para validaciones como evitar que un personaje muerto ataque o sea curado. Por ejemplo:

if (!objetivo->estaVivo()) {
    throw invalid_argument("No puedes interactuar con una unidad muerta.");
}
Este tipo de manejo es esencial en programas más robustos (como se comento en clase) y puedo implementarse fácilmente sobre la estructura actual del código.


Conclusión personal

Este proyecto me permitió aplicar de manera práctica los principios fundamentales de la programación orientada a objetos en C++. La construcción del sistema de combate me ayudó a entender cómo utilizar la herencia para organizar jerarquías de clases, el polimorfismo para cambiar comportamiento dinámicamente, las clases abstractas como contratos, la sobrecarga de operadores para hacer el código más legible y natural, y el valor de preparar el código para posibles excepciones.

Me pareció muy interesante y formativo el ejercicio, ya que también se asemeja a la arquitectura real que se usaría en videojuegos o simuladores, todo se baso en un videojuego que estoy haciendo y considero que reforzar estos conceptos es vital para ser un mejor desarrollador.

## Referencias consultadas

cppreference.com – C++ Standard Reference
Programiz – C++ OOP Concepts
StackOverflow
Notas de clase del curso POO (Tec de Monterrey)
Videos de YouTube sobre polimorfismo en C++