#include <iostream>
#include <fstream>

enum pole {
    las = 'l', jezioro = 'j', dom = 'd', brama = 'n', brama_z = 'i', brama_r = 'g', brama_cz = 'd', ruiny = 'y', akademia_magii = 'a', bariera = 'b', skaly = 's', sklep_z_bronia = 'u', szpital = 'x',
    sklep = 'p', gildia_wojownikow = 'w', gildia_silaczy = 'c', gildia_lotrzykow = 'k', lodka = 'o', miasto = 'm', mur = 'r', zamek = 'z', zamek_cz = 'f', pole = 'e', leze = 'q',
    skarb = 'v', spacja = '/'
};
void mapa(){
    char mapa[40][34];
    std::fstream mapa_m;
    mapa_m.open("mapa.txt");
        for(int i=0;i<40;i++){
            for(int j=0;j<34;j++){
                mapa_m>>mapa[i][j];
            }
        }
    mapa_m.close();
}
