#include <iostream>
#include <string>
#include <fstream>
#include "klasa.hpp"
#include "mapa.hpp"


Gracz::Gracz(std::string imie, std::string nazwisko, int start_pz, int start_pm, int sila, int zwinnosc, int inteligencja, int szczescie) {
        this->imie = imie;
        this->nazwisko = nazwisko;

        pz = start_pz;
        pm = start_pm;
        sl = sila;
        zw = zwinnosc;
        in = inteligencja;
        sz = szczescie;
        max_pz = start_pz;
        max_pm = start_pm;
}

struct StanGry stan_gry;

void Gracz::wypisz_statystyki() {
        std::cout <<"Mam " << pz << " PŻ, " << pm << " PM, " << sl << " Siły, " << zw << " zwinności, " << in << " inteligencji i " << sz << " szczęścia." << std::endl;
}

Wojownik::Wojownik(std::string imie, std::string nazwisko) : Gracz(imie, nazwisko, 40, 0, 24, 8, 2, 1) {}

void Wojownik::opis_klasy() {
        std::fstream wojownik;
        std::string opis_wojownika;
        wojownik.open("wojownik.txt");
        if(!wojownik) std::cout<<"Wybacz, ale wojownik został zabity"<<std::endl;
        else while(!wojownik.eof()){
            getline(wojownik,opis_wojownika);
            std::cout<<opis_wojownika<<std::endl;
        }
        wojownik.close();
    }

Magik::Magik(std::string imie, std::string nazwisko) : Gracz(imie, nazwisko, 20, 50, 5, 9, 30, 3) {}

void Magik::opis_klasy() {
        std::fstream magik;
        std::string opis_magika;
        magik.open("magik.txt");
        if(!magik) std::cout<<"Wybacz, ale magik został zabity"<<std::endl;
        else while(!magik.eof()){
            getline(magik,opis_magika);
            std::cout<<opis_magika<<std::endl;
        }
        magik.close();
    }

Silacz::Silacz(std::string imie, std::string nazwisko) : Gracz(imie, nazwisko, 15, 0, 40, 15, 0, 0) {}

void Silacz::opis_klasy() {
        std::fstream silacz;
        std::string opis_silacza;
        silacz.open("silacz.txt");
        if(!silacz) std::cout<<"Wybacz, ale silacz został zabity"<<std::endl;
        else while(!silacz.eof()){
            getline(silacz,opis_silacza);
            std::cout<<opis_silacza<<std::endl;
        }
        silacz.close();
    }

Lotrzyk::Lotrzyk(std::string imie, std::string nazwisko) : Gracz(imie, nazwisko, 25, 10, 15, 28, 7, 15) {}

void Lotrzyk::opis_klasy() {
        std::fstream lotrzyk;
        std::string opis_lotrzyka;
        lotrzyk.open("lotrzyk.txt");
        if(!lotrzyk) std::cout<<"Wybacz, ale lotrzyk został zabity"<<std::endl;
        else while(!lotrzyk.eof()){
            getline(lotrzyk,opis_lotrzyka);
            std::cout<<opis_lotrzyka<<std::endl;
        }
        lotrzyk.close();
    }

void Czlowiek::dodaj_bonusy(Gracz* gracz){
        gracz->pz+=4;
        gracz->pm+=4;
        gracz->sl+=4;
        gracz->in+=4;
        gracz->zw+=4;
        gracz->sz+=4;
    }
void Czlowiek::opis_rasy() {
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

void Elf::dodaj_bonusy(Gracz* gracz){
        gracz->pz+=1;
        gracz->pm+=3;
        gracz->sl+=5;
        gracz->in+=3;
        gracz->zw+=11;
        gracz->sz+=5;

    }
void Elf::opis_rasy() {
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

void Gnom::dodaj_bonusy(Gracz* gracz){
        gracz->pz-=5;
        gracz->pm+=7;
        gracz->in+=10;
        gracz->zw+=7;
        gracz->sz+=9;

    }

void Gnom::opis_rasy() {
        std::fstream gnom;
        std::string opis_gnoma;
        gnom.open("gnom.txt");
        if(!gnom) std::cout<<"Wybacz, ale gnomy wygineły"<<std::endl;
        else while(!gnom.eof()){
            getline(gnom,opis_gnoma);
            std::cout<<opis_gnoma<<std::endl;
        }
        gnom.close();
    }

void Krasnolud::dodaj_bonusy(Gracz* gracz){
        gracz->pz+=9;
        gracz->sl+=10;
        gracz->zw+=3;
        gracz->sz+=6;
    }
void Krasnolud::opis_rasy() {
        std::fstream krasnolud;
        std::string opis_krasnoluda;
        krasnolud.open("krasnolud.txt");
        if(!krasnolud) std::cout<<"Wybacz, ale krasnoludy wygineły"<<std::endl;
        else while(!krasnolud.eof()){
            getline(krasnolud,opis_krasnoluda);
            std::cout<<opis_krasnoluda<<std::endl;
        }
        krasnolud.close();
    }


    void PZ::dodatkowe_punkty(Gracz* gracz){
        gracz->pz+=1;
    }

     void PM::dodatkowe_punkty(Gracz* gracz){
        gracz->pm+=1;
    }


    void Sila::dodatkowe_punkty(Gracz* gracz){
        gracz->sl+=1;
    }

void Zwinnosc::dodatkowe_punkty(Gracz* gracz){
        gracz->zw++;
    }



    void Inteligencja::dodatkowe_punkty(Gracz* gracz){
        gracz->in+=1;
    }


    void Szczescie::dodatkowe_punkty(Gracz* gracz){
        gracz->sz+=1;
    }


void wypisz_plec(enum plec p){
    if(p == mezczyzna) std::cout<<"Mężczyzna"<<std::endl;
    else std::cout<<"Kobieta"<<std::endl;

}
void wypisz_klase(enum klasa k){
    if(k == wojownik) std::cout<<"wojownik"<<std::endl;
    else if(k == silacz) std::cout<<"siłacz"<<std::endl;
    else if(k == magik) std::cout<<"magik"<<std::endl;
    else std::cout<<"łotrzyk"<<std::endl;
}

void wypisz_rase(enum rasa_g r){
    if(r == czlowiek) std::cout<<"człowiek"<<std::endl;
    else if(r == elf) std::cout<<"elf"<<std::endl;
    else if(r == gnom) std::cout<<"gnom"<<std::endl;
    else std::cout<<"krasnolud"<<std::endl;
}

int main() {
    std::string komenda;
    std::string profesja;
    std::string rasa_p;
    std::string atrybut;
    std::string plec;
    std::cout<<"TYTUŁ"<<std::endl;
    std::cout<<"Rozpocznij Grę"<<std::endl;
    std::cout<<"Wczytaj Grę"<<std::endl;
    std::cout<<"Pomoc"<<std::endl;
    std::cout<<"Wyjście"<<std::endl;
    do{
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
        std::cout<<"Witaj podróżniku"<<std::endl;
        delete stan_gry.gracz;
        do{
        std::cout<<"Jak masz na imię"<<std::endl;
        std::cin>>stan_gry.imie;
        std::cout<<"Jak masz na nazwisko"<<std::endl;
        std::cin>>stan_gry.nazwisko;
            std::cout<<"Jaką masz klasę? Masz do wyboru: wojownik, siłacz, magik, łotrzyk"<<std::endl;
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
            else std::cout<<"Nie ma takiej klasy, proszę wybrać odpowiednią"<<std::endl;
            }while(stan_gry.gracz == NULL);
            stan_gry.gracz->opis_klasy();
            stan_gry.gracz->wypisz_statystyki();
        std::cout<<"Podaj swoją rasę. Masz do wyboru: człowiek, elf, gnom, krasnolud"<<std::endl;
        do{
        std::cin>>rasa_p;
        if(rasa_p == "czlowiek"){
            stan_gry.rasa_g = czlowiek;
            stan_gry.rasa = new Czlowiek();
        }
        else if(rasa_p == "elf"){
            stan_gry.rasa_g = elf;
            stan_gry.rasa = new Elf();
        }
        else if(rasa_p == "gnom"){
            stan_gry.rasa_g = gnom;
            stan_gry.rasa = new Gnom();
        }
        else if(rasa_p == "krasnolud"){
            stan_gry.rasa_g = krasnolud;
            stan_gry.rasa = new Krasnolud();
        }
        else std::cout<<"Taka rasa nie istnieje, proszę wybrać inną"<<std::endl;
        }while(stan_gry.rasa == NULL);
        stan_gry.rasa->opis_rasy();
        stan_gry.rasa->dodaj_bonusy(stan_gry.gracz);
        stan_gry.gracz->wypisz_statystyki();
        std::cout<<"Masz jeszcze 10 punktów do wykorzystania"<<std::endl;
        for(int i=1; i<=10; i++){
            std::cin>>atrybut;
            if(atrybut == "pz"){
                    stan_gry.bonus = new PZ();
                    stan_gry.bonus->dodatkowe_punkty(stan_gry.gracz);

           }
            else if(atrybut == "pm"){
                    stan_gry.bonus = new PM();
                    stan_gry.bonus->dodatkowe_punkty(stan_gry.gracz);

            }
            else if(atrybut == "sila"){
                    stan_gry.bonus = new Sila();
                    stan_gry.bonus->dodatkowe_punkty(stan_gry.gracz);

            }
            else if(atrybut == "zwinnosc"){
                    stan_gry.bonus = new Zwinnosc();
                    stan_gry.bonus->dodatkowe_punkty(stan_gry.gracz);

            }
            else if(atrybut == "inteligencja"){
                    stan_gry.bonus = new Inteligencja();
                    stan_gry.bonus->dodatkowe_punkty(stan_gry.gracz);

            }
            else if(atrybut == "szczescie"){
                    stan_gry.bonus = new Szczescie();
                    stan_gry.bonus->dodatkowe_punkty(stan_gry.gracz);

            }
            else{
            std::cout<<"Nie ma takiego atrybutu."<<std::endl;
            i-=1;
           }
        }
        stan_gry.gracz->wypisz_statystyki();
        std::cout<<"Podaj płeć"<<std::endl;
        do{
        std::cin>>plec;
        if(plec == "mezczyzna"){
            stan_gry.plec = mezczyzna;
        }
        else if(plec == "kobieta"){
            stan_gry.plec = kobieta;
        }
        else std::cout<<"Nie ma takiej płci"<<std::endl;
        }while(plec != "mezczyzna" && plec != "kobieta");
        std::cout<<stan_gry.imie<<std::endl;
        std::cout<<stan_gry.nazwisko<<std::endl;
        wypisz_klase(stan_gry.klasa);
        wypisz_rase(stan_gry.rasa_g);
        wypisz_plec(stan_gry.plec);
        stan_gry.gracz->wypisz_statystyki();
        std::cout<<"To ty?"<<std::endl;
        do{
        std::cin>>komenda;
        if(komenda != "nie" && komenda != "tak") std::cout<<"Nie rozumiem, możesz powtórzyć?"<<std::endl;
        }while(komenda != "nie" && komenda != "tak");
        }while(komenda != "tak");
        mapa();
        return 0;
    }
    else if(komenda == "wczytaj gre"){

    }
    else if(komenda=="pomoc"){
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
    else if(komenda=="wyjscie"){
        std::cout<<"Żegnaj"<<std::endl;
        return 0;
    }
    else std::cout<<"Nie ma takiego polecenia"<<std::endl;
    }while((komenda != "rozpocznij gre" && komenda != "wczytaj gre" && komenda != "wyjscie") || komenda == "pomoc");
}
