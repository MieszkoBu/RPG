#ifndef KLASA_HPP
#define KLASA_HPP

class Gracz {
public:
    std::string imie;
    std::string nazwisko;
    int max_pz;
    int max_pm;
    int pz;
    int pm;
    int sl;
    int zw;
    int in;
    int sz;
    Gracz(std::string imie, std::string nazwisko, int start_pz, int start_pm, int sila, int zwinnosc, int inteligencja, int szczescie);
     void wypisz_statystyki();
    virtual void opis_klasy() = 0;
    virtual ~Gracz() = default;
};

class Wojownik : public Gracz {
public:
    Wojownik(std::string imie, std::string nazwisko);
    void opis_klasy();
};

class Magik : public Gracz {
public:
    Magik(std::string imie, std::string nazwisko);
        void opis_klasy();

};

class Silacz : public Gracz {
public:
    Silacz(std::string imie, std::string nazwisko);
        void opis_klasy();

};

class Lotrzyk : public Gracz {
public:
    Lotrzyk(std::string imie, std::string nazwisko);
    void opis_klasy();

};
class Rasa{
public:
    virtual void dodaj_bonusy(Gracz*) = 0;
    virtual void opis_rasy() = 0;
};

class Czlowiek : public Rasa{
public:
    void dodaj_bonusy(Gracz* gracz);
    void opis_rasy();
};

class Elf : public Rasa{
public:
    void dodaj_bonusy(Gracz* gracz);
    void opis_rasy();
};

class Gnom : public Rasa{
public:
    void dodaj_bonusy(Gracz*);
    void opis_rasy();
};

class Krasnolud : public Rasa{
public:
    void dodaj_bonusy(Gracz* gracz);
    void opis_rasy();
};
class Bonusy{
public:
    virtual void dodatkowe_punkty(Gracz*) = 0;
};
class PZ : public Bonusy{
public:
    void dodatkowe_punkty(Gracz* gracz);
};

class PM : public Bonusy{
public:
    void dodatkowe_punkty(Gracz* gracz);
};
class Sila : public Bonusy{
public:
    void dodatkowe_punkty(Gracz* gracz);
};
class Zwinnosc : public Bonusy{
public:
    void dodatkowe_punkty(Gracz* gracz);
};
class Inteligencja : public Bonusy{
public:
    void dodatkowe_punkty(Gracz* gracz);
};
class Szczescie : public Bonusy{
public:
    void dodatkowe_punkty(Gracz* gracz);
};

enum plec{
    mezczyzna, kobieta
};
enum klasa {
    wojownik, silacz, magik, lotrzyk
};
enum rasa_g {
    czlowiek, elf, gnom, krasnolud
};

struct StanGry {
    // Cechy gracza
    std::string imie;
    std::string nazwisko;
    enum klasa klasa;
    enum rasa_g rasa_g;
    Rasa* rasa = NULL;
    enum plec plec;
    // stan gracza;
    Bonusy* bonus = NULL;
    Gracz* gracz = NULL;
    int poziom = 1;
    int pd = 0;
    int zloto = 0;
};
extern struct StanGry stan_gry;

void wypisz_plec(enum plec p);
void wypisz_klase(enum klasa k);
void wypisz_rase(enum rasa_g r);

#endif // KLASA_HPP
