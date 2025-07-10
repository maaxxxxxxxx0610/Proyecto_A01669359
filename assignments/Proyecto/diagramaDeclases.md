classDiagram
    class Unidad {
        - int vida
        - int salud
        - int ataque
        - int nivel
        + Unidad(vida, salud, ataque, nivel)
        + void Atacar(Unidad&)
        + void RecibeAtaque(int)
        + void Imprimir() const
        + int GetVida() const
        + void SetVida(int)
    }

    class Max {
        - int fuerza
        + Max(vida, salud, ataque, nivel, fuerza)
        + void Atacar(Unidad&) override
        + void RecibeAtaque(int) override
        + void Imprimir() const override
    }

    class Fudz {
        - int Hafudzzz
        + Fudz(vida, salud, ataque, nivel, Hafudzzz)
        + void Atacar(Unidad&) override
        + void RecibeAtaque(int) override
        + void Imprimir() const override
    }

    class Noob {
        + Noob(vida, salud, ataque, nivel)
        + void CareToMuch(Unidad&, int)
        + void RecibeAtaque(int) override
        + void Imprimir() const override
    }

    Unidad <|-- Max
    Unidad <|-- Fudz
    Unidad <|-- Noob
