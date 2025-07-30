#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Clase base abstracta: Unidad
class Unidad {
protected:
    int vida, salud, ataque, nivel;

    virtual void ImprimirEnStream(ostream& os) const {
        os << "Vida: " << vida << ", Salud: " << salud << ", Ataque: " << ataque << ", Nivel: " << nivel << "\n";
        os << "Barra de vida: ";
        for (int i = 0; i < vida; ++i) os << "█";
        for (int i = 0; i < 100 - vida; ++i) os << "░";
        os << "\n";
    }

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
        if (!estaVivo()) cout << "Unidad ha muerto.\n";
    }

    virtual void Imprimir() const {
        cout << *this;
    }

    int GetVida() const { return vida; }
    void SetVida(int v) { vida = max(0, v); }

    virtual bool estaVivo() const = 0;
    virtual ~Unidad() {}

    friend ostream& operator<<(ostream& os, const Unidad& u);
};

// Sobrecarga del operador de flujo corregida
ostream& operator<<(ostream& os, const Unidad& u) {
    u.ImprimirEnStream(os);
    return os;
}

// Clase Max (Guerrero)
class Max : public Unidad {
private:
    int fuerza;

protected:
    void ImprimirEnStream(ostream& os) const override {
        os << "Soy Max (Guerrero). Fuerza extra: " << fuerza << "\n";
        Unidad::ImprimirEnStream(os);
    }

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
        if (!estaVivo()) cout << "Max ha muerto con honor.\n";
    }

    bool estaVivo() const override {
        return vida > 0 && fuerza > 10;
    }
};

// Clase Fudz (Mago)
class Fudz : public Unidad {
private:
    int Hafudzzz;

protected:
    void ImprimirEnStream(ostream& os) const override {
        os << "Soy Fudz (Mago). Hafudzzz mágico: " << Hafudzzz << "\n";
        Unidad::ImprimirEnStream(os);
    }

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
        if (!estaVivo()) cout << "Fudz se quedó sin maná y murió. ✨\n";
    }

    bool estaVivo() const override {
        if (vida <= 0 && Hafudzzz >= 20) {
            cout << "Fudz usó su último Hafudzzz para revivir con 10 de vida.\n";
            const_cast<Fudz*>(this)->vida = 10;
            const_cast<Fudz*>(this)->Hafudzzz -= 20;
            return true;
        }
        return vida > 0;
    }
};

// Clase Noob (Sanador)
class Noob : public Unidad {
protected:
    void ImprimirEnStream(ostream& os) const override {
        os << "Soy Noob (Sanador). Solo quiero ayudarte 💖\n";
        Unidad::ImprimirEnStream(os);
    }

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
        if (!estaVivo()) cout << "Noob murió ayudando a los demás 💀\n";
    }

    bool estaVivo() const override {
        return vida > 0 && salud > 20;
    }
};

int main() {
    vector<Unidad*> personajes;

    personajes.push_back(new Max(100, 100, 10, 1, 20));
    personajes.push_back(new Fudz(100, 100, 8, 1, 30));
    personajes.push_back(new Noob(100, 100, 5, 1));

    cout << "\n========== ESTADO INICIAL ==========\n";
    for (auto p : personajes)
        cout << *p << endl;

    cout << "\n========== ¡COMIENZA LA BATALLA! ==========\n";

    try {
        if (!personajes[1]->estaVivo()) throw runtime_error("Fudz ya está muerto. No puedes atacarlo.");
        personajes[0]->Atacar(*personajes[1]);
        cout << *personajes[1] << endl;

        if (!personajes[2]->estaVivo()) throw runtime_error("Noob ya está muerto. No puedes atacarlo.");
        personajes[0]->Atacar(*personajes[2]);
        cout << *personajes[2] << endl;

    } catch (const exception& e) {
        cerr << "⚠️ EXCEPCIÓN: " << e.what() << "\n";
    }

    cout << "\n========== ESTADO FINAL ==========\n";
    for (auto p : personajes)
        cout << *p << endl;

    for (auto p : personajes)
        delete p;

    cout << "\nFin de la simulación. Que ganen los mejores...\n";
    return 0;
}
