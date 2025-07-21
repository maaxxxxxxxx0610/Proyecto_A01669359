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
