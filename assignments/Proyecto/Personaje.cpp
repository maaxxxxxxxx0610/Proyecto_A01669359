#include <iostream>
#include <string>
#include <algorithm> // Para std::max

using namespace std;

// Clase base: Unidad
class Unidad {
protected:
    int vida, salud, ataque, nivel;

public:
    Unidad(int vida = 100, int salud = 100, int ataque = 7, int nivel = 1)
        : vida(vida), salud(salud), ataque(ataque), nivel(nivel) {}

    virtual void Atacar(Unidad& objetivo) {
        int dano = ataque;
        objetivo.RecibeAtaque(dano);
    }

    virtual void RecibeAtaque(int valorDeAtaque) {
        vida = max(vida - valorDeAtaque, 0);
        cout << "Unidad recibió " << valorDeAtaque << " de daño. Vida restante: " << vida << endl;
        if (vida == 0)
            cout << "Unidad ha muerto.\n";
    }

    virtual void Imprimir() const {
        cout << "Vida: " << vida << ", Salud: " << salud << ", Ataque: " << ataque << ", Nivel: " << nivel << endl;
    }

    int GetVida() const { return vida; }
    void SetVida(int v) { vida = max(0, v); }
};

// Clase Max (Guerrero)
class Max : public Unidad {
private:
    int fuerza;

public:
    Max(int vida, int salud, int ataque, int nivel, int fuerza)
        : Unidad(vida, salud, ataque, nivel), fuerza(fuerza) {}

    void Atacar(Unidad& objetivo) override {
        int potencia = ataque + fuerza;
        cout << "Max ataca con fuerza extra: " << fuerza << " (daño total: " << potencia << ")\n";
        objetivo.RecibeAtaque(potencia);
    }

    void RecibeAtaque(int valor) override {
        int reduccion = valor * 0.2;
        int final = valor - reduccion;
        vida = max(vida - final, 0);
        cout << "Max bloqueó parte del daño y solo recibió " << final << ". Vida: " << vida << endl;
    }

    void Imprimir() const override {
        cout << "Soy Max (Guerrero). Fuerza extra: " << fuerza << endl;
        Unidad::Imprimir();
    }
};

// Clase Fudz (Mago)
class Fudz : public Unidad {
private:
    int Hafudzzz;

public:
    Fudz(int vida, int salud, int ataque, int nivel, int Hafudzzz)
        : Unidad(vida, salud, ataque, nivel), Hafudzzz(Hafudzzz) {}

    void Atacar(Unidad& objetivo) override {
        int dano = ataque + Hafudzzz;
        cout << "Fudz lanzó magia poderosa. Potencia: " << Hafudzzz << " (daño total: " << dano << ")\n";
        objetivo.RecibeAtaque(dano);
    }

    void RecibeAtaque(int valor) override {
        int reduccion = Hafudzzz * 0.1;
        int final = max(0, valor - reduccion);
        vida = max(vida - final, 0);
        cout << "Fudz usó magia defensiva. Recibió solo " << final << " de daño. Vida: " << vida << endl;
    }

    void Imprimir() const override {
        cout << "Soy Fudz (Mago). Hafudzzz mágico: " << Hafudzzz << endl;
        Unidad::Imprimir();
    }
};

// Clase Noob (Sanador)
class Noob : public Unidad {
public:
    Noob(int vida, int salud, int ataque, int nivel)
        : Unidad(vida, salud, ataque, nivel) {}

    void CareToMuch(Unidad& objetivo, int danoRecibido) {
        if (danoRecibido > 0) {
            int curacion = danoRecibido;
            objetivo.SetVida(objetivo.GetVida() + curacion);
            cout << "Noob curó a su compañero con " << curacion << " de vida 💖\n";
        }
    }

    void RecibeAtaque(int valor) override {
        int bloqueo = valor * 0.05;
        int final = valor - bloqueo;
        vida = max(vida - final, 0);
        cout << "Noob recibió " << final << " de daño tras bloquear un poco. Vida: " << vida << endl;
    }

    void Imprimir() const override {
        cout << "Soy Noob (Sanador). Solo quiero ayudarte 💖\n";
        Unidad::Imprimir();
    }
};

int main() {
    Max guerrero(100, 100, 10, 1, 20);
    Fudz mago(100, 100, 8, 1, 30);
    Noob sanador(100, 100, 5, 1);

    guerrero.Imprimir();
    mago.Imprimir();
    sanador.Imprimir();

    cout << "\n--- Batalla ---\n";

    guerrero.Atacar(mago);
    mago.Atacar(guerrero);

    sanador.CareToMuch(guerrero, 15);  // Noob cura a Max

    cout << "\n--- Estado final ---\n";
    guerrero.Imprimir();
    mago.Imprimir();
    sanador.Imprimir();

    return 0;
}

