#include <iostream>
#include <string>
#include <fstream>
class Gracz {
public:
    std::string imie;
    std::string nazwisko;

    int max_hp;
    int max_mp;
    int hp;
    int mp;
    int sl;
    int zw;
    int in;
    int sz;

    Gracz(std::string imie, std::string nazwisko, int start_hp, int start_mp, int sila, int zwinnosc, int inteligencja, int szczescie) {
        this->imie = imie;
        this->nazwisko = nazwisko;

        hp = start_hp;
        mp = start_mp;
        sl = sila;
        zw = zwinnosc;
        in = inteligencja;
        sz = szczescie;
        max_hp = start_hp;
        max_mp = start_mp;
    }

     void wypisz_statystyki() {
        std::cout << imie << " " << nazwisko << " Mam " << hp << " HP, " << mp << " MP, " << sl << " Sily, " << zw << " zwinnosci, " << in << " inteligencji i " << sz << " szczescia." << std::endl;
    }

    virtual void opis_klasy() = 0;
};

class Wojownik : public Gracz {
public:
    Wojownik(std::string imie, std::string nazwisko) : Gracz(imie, nazwisko, 40, 0, 24, 8, 2, 1) {}

    virtual void opis_klasy() {
        std::fstream wojownik;
        std::string opis_wojownika;
        wojownik.open("wojownik.txt");
        if(!wojownik) std::cout<<"Wybacz, ale wojownik zostal zabity"<<std::endl;
        else while(!wojownik.eof()){
            getline(wojownik,opis_wojownika);
            std::cout<<opis_wojownika<<std::endl;
        }
        wojownik.close();
    }
};

class Magik : public Gracz {
public:
    Magik(std::string imie, std::string nazwisko) : Gracz(imie, nazwisko, 20, 50, 5, 9, 30, 3) {}

    virtual void opis_klasy() {
        std::fstream magik;
        std::string opis_magika;
        magik.open("magik.txt");
        if(!magik) std::cout<<"Wybacz, ale magik zostal zabity"<<std::endl;
        else while(!magik.eof()){
            getline(magik,opis_magika);
            std::cout<<opis_magika<<std::endl;
        }
        magik.close();
    }

};

class Silacz : public Gracz {
public:
    Silacz(std::string imie, std::string nazwisko) : Gracz(imie, nazwisko, 15, 0, 40, 15, 0, 0) {}

    virtual void opis_klasy() {
        std::fstream silacz;
        std::string opis_silacza;
        silacz.open("silacz.txt");
        if(!silacz) std::cout<<"Wybacz, ale silacz zostal zabity"<<std::endl;
        else while(!silacz.eof()){
            getline(silacz,opis_silacza);
            std::cout<<opis_silacza<<std::endl;
        }
        silacz.close();
    }
};

class Lotrzyk : public Gracz {
public:
    Lotrzyk(std::string imie, std::string nazwisko) : Gracz(imie, nazwisko, 25, 10, 15, 28, 7, 15) {}

    virtual void opis_klasy() {
        std::fstream lotrzyk;
        std::string opis_lotrzyka;
        lotrzyk.open("lotrzyk.txt");
        if(!lotrzyk) std::cout<<"Wybacz, ale lotrzyk zostal zabity"<<std::endl;
        else while(!lotrzyk.eof()){
            getline(lotrzyk,opis_lotrzyka);
            std::cout<<opis_lotrzyka<<std::endl;
        }
        lotrzyk.close();
    }
};
class Rasa{
public:
    virtual void dodaj_bonusy(Gracz*) = 0;
    virtual void opis_klasy() = 0;
};

class Czlowiek : public Rasa{
public:
    virtual void dodaj_bonusy(Gracz* gracz){
        gracz->hp+=4;
        gracz->mp+=4;
        gracz->sl+=4;
        gracz->in+=4;
        gracz->zw+=4;
        gracz->sz+=4;
    }
    virtual void opis_rasy() {
        std::fstream czlowiek;
        std::string opis_czlowieka;
        czlowiek.open("czlowiek.txt");
        if(!czlowiek) std::cout<<"Wybacz, ale ludzie wygineli"<<std::endl;
        else while(!czlowiek.eof()){
            getline(czlowiek,opis_czlowieka);
            std::cout<<opis_czlowieka<<std::endl;
        }
        czlowiek.close();
    }
};

class Elf : public Rasa{
public:
    virtual void dodaj_bonusy(Gracz* gracz){
        gracz->hp+=1;
        gracz->mp+=3;
        gracz->sl+=5;
        gracz->in+=3;
        gracz->zw+=11;
        gracz->sz+=5;

    }
    virtual void opis_rasy() {
        std::fstream elf;
        std::string opis_elfa;
        elf.open("elf.txt");
        if(!elf) std::cout<<"Wybacz, ale elfowie wygineli"<<std::endl;
        else while(!elf.eof()){
            getline(elf,opis_elfa);
            std::cout<<opis_elfa<<std::endl;
        }
        elf.close();
    }
};

class Gnom : public Rasa{
public:
    virtual void dodaj_bonusy(Gracz* gracz){
        gracz->hp-=5;
        gracz->mp+=7;
        gracz->in+=10;
        gracz->zw+=7;
        gracz->sz+=9;

    }
    virtual void opis_rasy() {
        std::fstream gnom;
        std::string opis_gnoma;
        gnom.open("gnom.txt");
        if(!gnom) std::cout<<"Wybacz, ale gnomy wygineli"<<std::endl;
        else while(!gnom.eof()){
            getline(gnom,opis_gnoma);
            std::cout<<opis_gnoma<<std::endl;
        }
        gnom.close();
    }
};

class Krasnolud : public Rasa{
public:
    virtual void dodaj_bonusy(Gracz* gracz){
        gracz->hp+=9;
        gracz->sl+=10;
        gracz->zw+=3;
        gracz->sz+=6;
    }
    virtual void opis_rasy() {
        std::fstream krasnolud;
        std::string opis_krasnoluda;
        krasnolud.open("krasnolud.txt");
        if(!krasnolud) std::cout<<"Wybacz, ale krasnoludy wygineli"<<std::endl;
        else while(!krasnolud.eof()){
            getline(krasnolud,opis_krasnoluda);
            std::cout<<opis_krasnoluda<<std::endl;
        }
        krasnolud.close();
    }
};

enum klasa {
    wojownik, silacz, magik, lotrzyk
};
enum plec{
    mezczyzna,kobieta
};
struct stan_gry{
    // Cechy gracza
    std::string imie;
    std::string nazwisko;
    enum klasa klasa;
    Rasa* rasa = NULL;
    enum plec plec;
    // stan gracza;
    Gracz* gracz = NULL;
    int poziom = 1;
    int pd = 0;



} stan_gry;

int main() {
    std::string komenda;
    std::string profesja;
    std::string rasa_p;
    std::cout<<"TYTUL"<<std::endl;
    std::cout<<"Rozpocznij Gre"<<std::endl;
    std::cout<<"Wczytaj Gre"<<std::endl;
    std::cout<<"Pomoc"<<std::endl;
    std::cout<<"Wyjscie"<<std::endl;
    getline(std::cin,komenda);
    if(komenda=="rozpocznij gre"){
        std::fstream historia;
        std::string prolog;
        historia.open("historia.txt");
        while(!historia.eof()){
            getline(historia,prolog);
            std::cout<<prolog<<std::endl;
        }
        historia.close();

        std::cout<<"Witaj podrozniku"<<std::endl;
        do{
        delete stan_gry.gracz;
        std::cout<<"Jak masz na imie"<<std::endl;
        std::cin>>stan_gry.imie;
        std::cout<<"Jak masz na nazwisko"<<std::endl;
        std::cin>>stan_gry.nazwisko;
            std::cout<<"Jaka masz klase? Masz do wyboru: wojownik, silacz, magik, lotrzyk"<<std::endl;
            do{
            std::cin>>profesja;
            if(profesja == "wojownik"){
                    stan_gry.klasa = wojownik;
                    stan_gry.gracz = new Wojownik(stan_gry.imie,stan_gry.nazwisko);
            }


            else if(profesja == "magik"){
                    stan_gry.klasa = magik;
                    stan_gry.gracz = new Magik(stan_gry.imie,stan_gry.nazwisko);
            }

            else if(profesja == "silacz"){
                    stan_gry.klasa = silacz;
                    stan_gry.gracz = new Silacz(stan_gry.imie,stan_gry.nazwisko);
            }

            else if(profesja == "lotrzyk"){
                    stan_gry.klasa = lotrzyk;
                    stan_gry.gracz = new Lotrzyk(stan_gry.imie,stan_gry.nazwisko);
            }
            else std::cout<<"Nie ma takiej klasy, proszê wybraæ odpowiedni¹"<<std::endl;
            }while(stan_gry.gracz == NULL);
            stan_gry.gracz->opis_klasy();
            stan_gry.gracz->wypisz_statystyki();
            std::cout<<"Pasuje"<<std::endl;
            std::cin>>komenda;
        std::cout<<"Podaj swoją rasę. Masz do wyboru: cz³owiek, elf, gnom, krasnolud"<<std::endl;
        do{
        std::cin>>rasa_p;
        if(rasa_p == "czlowiek"){
            stan_gry.rasa = new Czlowiek();
        }
        else if(rasa_p == "elf"){
            stan_gry.rasa = new Elf();
        }
        else if(rasa_p == "gnom"){
            stan_gry.rasa = new Gnom();
        }
        else if(rasa_p == "krasnolud"){
            stan_gry.rasa = new Krasnolud();
        }
        else std::cout<<"Taka rasa nie istnieje, proszę wybrać inną"<<std::endl;
        }while(stan_gry.rasa == NULL);
        stan_gry.rasa->opis_rasy();
        stan_gry.rasa->dodaj_bonusy(stan_gry.gracz);
        stan_gry.gracz->wypisz_statystyki();

        }while(komenda!="tak");
    }
    if(komenda=="wczytaj gre"){

    }
    if(komenda=="pomoc"){
        std::fstream pomoc;
        pomoc.open("pomoc.txt");
        std::string opis_pomoc;
        if(!pomoc) std::cout<<"Bohater nie potrzebuje pomocy"<<std::endl;
        else while(!pomoc.eof()){
            getline(pomoc,opis_pomoc);
            std::cout<<opis_pomoc<<std::endl;
        }
        pomoc.close();
    }
    if(komenda=="wyjscie"){
        std::cout<<"Żegnaj"<<std::endl;
        return 0;
    }
}
