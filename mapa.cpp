#include <iostream>
#include <fstream>
#include <string>
#include "mapa.hpp"
#include "klasa.hpp"
enum pole {
    las = 'l', jezioro = 'j', dom = 'd', brama = 'n', brama_z = 'i', brama_r = 'g', brama_cz = 'd', ruiny = 'y',
    akademia_magii = 'a', bariera = 'b', skaly = 's', sklep_z_bronia = 'u', szpital = 'x',
    sklep = 'p', gildia_wojownikow = 'w', gildia_silaczy = 'c', gildia_lotrzykow = 'k', lodka = 'o', miasto = 'm', mur = 'r',
    zamek = 'z', zamek_cz = 'f', pole = 'e', leze = 'q', skarb = 'v', spacja = '/'
};
int miejsce(enum pole p, int poz, int pio, char mapa_g[40][34], std::string komenda){
    std::fstream lokacja;
    lokacja.open("pozycja.txt");
    if(p == miasto){
        std::cout<<"jesteś w miescie"<<std::endl;
        return true;
    }
    else if(p == zamek){
        std::cout<<"jesteś w zamku"<<std::endl;
        return true;
    }
    else if(p == las){
        std::cout<<"jesteś w lesie"<<std::endl;
        return true;
    }
    else if(p == dom){
        std::cout<<"jesteś w domie"<<std::endl;
        return true;
    }
    else if(p == ruiny){
        std::cout<<"jesteś w ruinach"<<std::endl;
        return true;
    }
    else if(p == akademia_magii){
        std::cout<<"jesteś w akademii magii"<<std::endl;
        return true;
    }
    else if(p == sklep_z_bronia){
        std::cout<<"jesteś w sklepie z bronią"<<std::endl;
        return true;
    }
    else if(p == szpital){
        std::cout<<"jesteś w szpitalu"<<std::endl;
        return true;
    }
    else if(p == sklep){
        std::cout<<"jesteś w sklepie"<<std::endl;
        return true;
    }
    else if(p == gildia_wojownikow){
        std::cout<<"jesteś w gildii wojowników"<<std::endl;
        return true;
    }
    else if(p == gildia_silaczy){
        std::cout<<"jesteś w gildii silaczy"<<std::endl;
        return true;
    }
    else if(p == gildia_lotrzykow){
        std::cout<<"jesteś w gildii łotrzyków"<<std::endl;
        return true;
    }
    else if(p == zamek_cz){
        std::cout<<"jesteś w zamku czarnoksieznika"<<std::endl;
        return true;
    }
    else if(p == pole){
        std::cout<<"jesteś na polu"<<std::endl;
        return true;
    }
    else if(p == leze){
        std::cout<<"jesteś w leżu smoka"<<std::endl;
        return true;
    }
    else if(p == skarb){
        std::cout<<"znalazłeś skarb"<<std::endl;
        return true;
    }
    else if(p == mur){
        std::cout<<"nie możesz przekroczyć muru"<<std::endl;
        return false;
    }
    else if(p == skaly){
        std::cout<<"nie możesz przekroczyć skał"<<std::endl;
        return false;
    }
    lokacja.close();
}
struct {
    enum pole pole;
}lok;
void mapa(){
    char mapa_g[40][34];
    char pozycja;
    int poz=15,pio=11;
    std::string komenda;
    std::fstream mapa_m;
    mapa_m.open("mapa.txt");
        for(int i=0;i<40;i++){
            for(int j=0;j<34;j++){
                mapa_m>>mapa_g[i][j];
            }
        }
        mapa_m.close();
        do{
        getline(std::cin,komenda);
        if(komenda == "polnoc") poz-=1;
        else if(komenda == "poludnie") poz+=1;
        else if(komenda == "wschod") pio+=1;
        else if(komenda == "zachod") pio-=1;
        pozycja=mapa_g[poz][pio];
        if(pozycja == 'm') lok.pole = miasto;
        else if(pozycja == 'z') lok.pole = zamek;
        else if(pozycja == 'l') lok.pole = las;
        else if(pozycja == 'd') lok.pole = dom;
        else if(pozycja == 'y') lok.pole = ruiny;
        else if(pozycja == 'a') lok.pole = akademia_magii;
        else if(pozycja == 'u') lok.pole = sklep_z_bronia;
        else if(pozycja == 'x') lok.pole = szpital;
        else if(pozycja == 'p') lok.pole = sklep;
        else if(pozycja == 'w') lok.pole = gildia_wojownikow;
        else if(pozycja == 'c') lok.pole = gildia_silaczy;
        else if(pozycja == 'k') lok.pole = gildia_lotrzykow;
        else if(pozycja == 'f') lok.pole = zamek_cz;
        else if(pozycja == 'e') lok.pole = pole;
        else if(pozycja == 'q') lok.pole = leze;
        else if(pozycja == 'v') lok.pole = skarb;
        else if(pozycja == 'r') lok.pole = mur;
        else if(pozycja == 's') lok.pole = skaly;
        if(komenda == "status"){
        std::cout<<stan_gry.imie<<std::endl;
        std::cout<<stan_gry.nazwisko<<std::endl;
        wypisz_klase(stan_gry.klasa);
        wypisz_rase(stan_gry.rasa_g);
        wypisz_plec(stan_gry.plec);
        stan_gry.gracz->wypisz_statystyki();
        }
        else if(komenda == "polnoc" || komenda == "poludnie" || komenda == "wschod" || komenda == "zachod"){
        if(miejsce(lok.pole,poz,pio,mapa_g,komenda) == false){
        if(komenda == "polnoc") poz+=1;
        else if(komenda == "polodnie") poz-=1;
        else if(komenda == "wschod") pio-=1;
        else if(komenda == "zachod") pio+=1;
        }
        }
    }while(komenda != "wyjdz z gry");
    std::cout<<"Żegnaj"<<std::endl;
}

