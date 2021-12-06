#include <vector>
#include <iostream>
#include "2048.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define esc 27
#define CHECK(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl
using namespace std;
typedef vector<vector<int> > Plateau;
void TestPlatVide() {
    CHECK(plateauVide() == Plateau({{ 0, 0, 0,0 }, { 0, 0, 0 ,0}, { 0, 0, 0,0 }, {0,0,0,0}}) );
}
void testPlatinitiale(){
    Plateau plat = plateauInitial();
    bool o = true;
    for (auto i: plat){
        for (auto p : i){
            if(p != 0 and p!=2 and p!= 4){
                o = false;
            }
        }
    }
    CHECK(o);
}
void testTireDeuxOuQuatre(){
    int x = 0;
    bool o = true;
    for(int i = 0 ; i<=20 ; i ++){
        x = tireDeuxOuQuatre();
        if(x != 2 and x !=4){
            o = false;
        }
    }
    CHECK(o);
}
void TestScore() {
    CHECK(score(16) == 48);
    CHECK(score(0) == 0);
    CHECK(score (2) != 2);
    CHECK(score (32) == 128);
    CHECK(score(4) * 7 + score(8) * 3 + score(16)* 1 + score(32) * 2);

}
void TestScorePlat(){
    CHECK(scorePlat({{4,4,4,2},{8,16,32,2},{4,8,4,32},{4,8,4,2}}) == 380);
    CHECK(scorePlat({{ 0, 0, 0,0 }, { 0, 0, 0 ,0}, { 0, 0, 0,0 }, {0,0,0,0}}) == 0 );
}
void deplacementTest(){
    CHECK(deplacementGauche({{4,4,4,2},{8,16,32,2},{32,16,0,16},{2,2,2,2}}) == Plateau({{8,4,2,0},{8,16,32,2},{32,32,0,0},{4,4,0,0}}));
    CHECK(deplacementHaut({{4,4,4,2},{8,16,32,2},{32,16,0,16},{2,2,2,2}}) == Plateau({{4,4,4,4},{8,32,32,16},{32,2,2,2},{2,0,0,0}}));
    CHECK(deplacementDroite({{4,4,4,2},{8,16,32,2},{32,16,0,16},{2,2,2,2}}) == Plateau({{0,4,8,2},{8,16,32,2},{0,0,32,32},{0,0,4,4}}));
    CHECK(deplacementBas({{4,4,4,2},{8,16,32,2},{32,16,0,16},{2,2,2,2}}) == Plateau({{4,0,0,0},{8,4,4,4},{32,32,32,16},{2,2,2,2}}));
}
void estGagnantTest(){
    CHECK(not estGagnant({{4,4,4,2},{8,16,32,2},{4,8,4,32},{4,8,4,2}}));
    CHECK( estGagnant({{4,4,4,2048},{8,16,32,2},{4,8,4,32},{4,8,4,2}}));

}
void estTermineTest();
int main(){
    TestScorePlat();
    deplacementTest();
    testPlatinitiale();
    testTireDeuxOuQuatre();
    TestScore();
    TestPlatVide();
}
/**void iaplateau(Plateau plateau1) {
    while (not estTermine(plateau1)) {
        dessine(plateau1) ;
        Plateau gauche = deplacementGauche(plateau1);
        Plateau droite = deplacementDroite(plateau1);
        Plateau haut = deplacementHaut(plateau1);
        Plateau bas = deplacementBas(plateau1);
        int scoredroite = 0;
        int scoregauche = 0;
        int scorebas = 0;
        int scorehaut = 0;
        for (int i = 0; i < 300; i++) {
            while (not estTermine(gauche)) {
                Plateau Bis = gauche;
                gauche = deplacementAleatoire(gauche);
                int w = tireDeuxOuQuatre();
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (gauche != Bis ) {
                    while (gauche[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    gauche[p][y] = w;
                }
            }
            scoregauche = scoregauche + scorePlat(gauche);
            gauche = deplacementGauche(plateau1);
        }
        for (int i2 = 0; i2 < 300; i2++) {
            while (not estTermine(droite)) {
                Plateau Bis = droite;
                droite = deplacementAleatoire(droite);
                int w = tireDeuxOuQuatre();
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (droite != Bis ) {
                    while (droite[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    droite[p][y] = w;
                }
            }
            scoredroite = scoredroite+ scorePlat(droite);
            droite = deplacementDroite(plateau1);
        }
        for (int i3 = 0; i3 < 300; i3++) {
            while (not estTermine(bas)) {
                Plateau Bis = bas;
                bas = deplacementAleatoire(bas);
                int w = tireDeuxOuQuatre();
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (bas != Bis ) {
                    while (bas[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    bas[p][y] = w;
                }
            }
            scorebas= scorebas + scorePlat(bas);
            bas = deplacementBas(plateau1);
        }
        for (int i4 = 0; i4 < 300; i4++) {
            while (not estTermine(haut)) {
                Plateau Bis = haut;
                haut = deplacementAleatoire(haut);
                int w = tireDeuxOuQuatre();
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (haut != Bis ) {
                    while (haut[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    haut[p][y] = w;
                }
            }
            scorehaut= scorehaut + scorePlat(haut);
            haut = deplacementHaut(plateau1);

        }
        if (scorehaut >= scoregauche and scorehaut >= scorebas and scorehaut >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau  p5 = plateau1;
            plateau1 = deplacementHaut(plateau1);
            if (p5 == plateau1){
                if(scoredroite >= scoregauche and scoredroite >= scorebas){
                    plateau1 = deplacementDroite(plateau1);
                }else if (scorebas >= scoregauche and scorebas >= scoredroite){
                    plateau1 = deplacementBas(plateau1);
                }else if ( scoregauche >= scorebas and scoregauche >= scoredroite){
                    plateau1 = deplacementGauche(plateau1);
                }
            }
            if(estTermine(plateau1)){
                exit(-1);
            }
            while (plateau1[s][c] != 0) {
                if(not estPlein(plateau1)){
                    break;
                }
                s = aleaint(0, 3);
                c = aleaint(0, 3);
            }
            plateau1[s][c] = q;
        } else if (scorebas >= scoregauche and scorebas >= scorehaut and scorebas >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p = plateau1;
            plateau1 = deplacementBas(plateau1);
            if (p == plateau1){
                if(scoredroite >= scorehaut and scoredroite >= scoregauche){
                    plateau1 = deplacementDroite(plateau1);
                }else if (scorehaut >= scoregauche and scorehaut >= scoredroite){
                    plateau1 = deplacementHaut(plateau1);
                }else if ( scoregauche >= scorehaut and scoregauche >= scoredroite){
                    plateau1 = deplacementGauche(plateau1);
                }
            }
            if(estTermine(plateau1)){
                exit(-1);
            }
            while (plateau1[s][c] != 0) {
                if(not estPlein(plateau1)){
                    break;
                }
                s = aleaint(0, 3);
                c = aleaint(0, 3);
            }
            plateau1[s][c] = q;
        } else if (scoregauche >= scorehaut and scoregauche >= scorebas and scoregauche >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau  p2 = plateau1;
            plateau1 = deplacementGauche(plateau1);
            if (p2 == plateau1){
                if(scoredroite >= scorehaut and scoredroite >= scorebas){
                    plateau1 = deplacementDroite(plateau1);
                }else if (scorebas >= scorehaut and scorebas >= scoredroite){
                    plateau1 = deplacementBas(plateau1);
                }else if ( scorehaut >= scorebas and scorehaut >= scoredroite){
                    plateau1 = deplacementHaut(plateau1);
                }
            }
            if(estTermine(plateau1)){
                exit(-1);
            }
            while (plateau1[s][c] != 0) {
                if(not estPlein(plateau1)){
                    break;
                }
                s = aleaint(0, 3);
                c = aleaint(0, 3);
            }
            plateau1[s][c] = q;
        } else if (scoredroite >= scoregauche and scoredroite >= scorebas and scoredroite >= scorehaut){
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p3 = plateau1;
            plateau1 = deplacementDroite(plateau1);
            if (p3 == plateau1){
                if(scorehaut >= scoregauche and scorehaut >= scorebas){
                    plateau1 = deplacementHaut(plateau1);
                }else if (scorebas >= scoregauche and scorebas >= scorehaut){
                    plateau1 = deplacementBas(plateau1);
                }else if ( scoregauche >= scorebas and scoregauche >= scorehaut){
                    plateau1 = deplacementGauche(plateau1);
                }
            }
            while (plateau1[s][c] != 0) {
                if( not estPlein(plateau1)){
                    break;
                }
                s = aleaint(0, 3);
                c = aleaint(0, 3);
            }
            plateau1[s][c] = q;
        }
    }
}*/

/**void iaplateau(Plateau plateau1) {
    while (not estTermine(plateau1)) {
        dessine(plateau1);
        Plateau gauche = deplacementGauche(plateau1);
        Plateau droite = deplacementDroite(plateau1);
        Plateau haut = deplacementHaut(plateau1);
        Plateau bas = deplacementBas(plateau1);
        if(scorePlat(haut) == scorePlat(gauche) == scorePlat(bas) == scorePlat(droite)){
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p5 = plateau1;
            plateau1 = deplacementAleatoire(plateau1);
            while (p5 == plateau1) {
                plateau1 = deplacementAleatoire(plateau1);
            }
            plateau1[s][c] = q;
        }
        else if (scorePlat(haut) > scorePlat(gauche) and scorePlat(haut) > scorePlat(bas)
                 and scorePlat(haut) > scorePlat(droite)) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p5 = plateau1;
            plateau1 = deplacementHaut(plateau1);
            if (p5 != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        } else if (scorePlat(bas) > scorePlat(gauche) and scorePlat(bas) > scorePlat(haut)
                   and scorePlat(bas) > scorePlat(droite)) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p = plateau1;
            plateau1 = deplacementBas(plateau1);
            if (p != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        } else if (scorePlat(gauche) > scorePlat(haut) and scorePlat(gauche) > scorePlat(bas)
                   and scorePlat(gauche) > scorePlat(droite)) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p2 = plateau1;
            plateau1 = deplacementGauche(plateau1);
            if (p2 != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        } else if (scorePlat(droite) > scorePlat(gauche) and scorePlat(droite) > scorePlat(bas)
                   and scorePlat(droite) > scorePlat(haut)) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p3 = plateau1;
            plateau1 = deplacementDroite(plateau1);
            if (p3 != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        }
    }
}

/**void iaplateau(Plateau plateau1) {
    while (not estTermine(plateau1)) {
        dessine(plateau1) ;
        Plateau gauche = deplacementGauche(plateau1);
        Plateau droite = deplacementDroite(plateau1);
        Plateau haut = deplacementHaut(plateau1);
        Plateau bas = deplacementBas(plateau1);
        int scoredroite = 0;
        int scoregauche = 0;
        int scorebas = 0;
        int scorehaut = 0;
        for (int i = 0; i < 500; i++) {
            int compteur1 = 0;
            while (not estTermine(gauche)) {
                Plateau Bis = gauche;
                gauche = deplacementAleatoire(gauche);
                int w = tireDeuxOuQuatre();
                if(w == 4){
                    compteur1 ++;
                }
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (gauche != Bis ) {
                    while (gauche[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    gauche[p][y] = w;
                }
            }
            scoregauche = scoregauche + scorePlat(gauche)-4*compteur1;
            gauche = deplacementGauche(plateau1);
        }
        for (int i2 = 0; i2 < 500; i2++) {
            int compteur2 = 0;
            while (not estTermine(droite)) {
                Plateau Bis = droite;
                droite = deplacementAleatoire(droite);
                int w = tireDeuxOuQuatre();
                if(w == 4){
                    compteur2++;
                }
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (droite != Bis ) {
                    while (droite[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    droite[p][y] = w;
                }
            }
            scoredroite = scoredroite+ scorePlat(droite) - 4*compteur2;
            droite = deplacementDroite(plateau1);
        }
        for (int i3 = 0; i3 < 500; i3++) {
            int compteur3 = 0;
            while (not estTermine(bas)) {
                Plateau Bis = bas;
                bas = deplacementAleatoire(bas);
                int w = tireDeuxOuQuatre();
                if(w == 4){
                    compteur3++;
                }
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (bas != Bis ) {
                    while (bas[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    bas[p][y] = w;
                }
            }
            scorebas= scorebas + scorePlat(bas)-4*compteur3;
            bas = deplacementBas(plateau1);
        }
        for (int i4 = 0; i4 < 500; i4++) {
            int compteur4 = 0;
            while (not estTermine(haut)) {
                Plateau Bis = haut;
                haut = deplacementAleatoire(haut);
                int w = tireDeuxOuQuatre();
                if(w == 4){
                    compteur4++;
                }
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (haut != Bis ) {
                    while (haut[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    haut[p][y] = w;
                }
            }
            scorehaut= scorehaut + scorePlat(haut) -4*compteur4;
            haut = deplacementHaut(plateau1);

        }
        if (scorehaut >= scoregauche and scorehaut >= scorebas and scorehaut >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p5 = plateau1;
            plateau1 = deplacementHaut(plateau1);
            if (p5 != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        }else if (scorebas >= scoregauche and scorebas >= scorehaut and scorebas >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p = plateau1;
            plateau1 = deplacementBas(plateau1);
            if (p != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        } else if (scoregauche >= scorehaut and scoregauche >= scorebas and scoregauche >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau  p2 = plateau1;
            plateau1 = deplacementGauche(plateau1);
            if (p2 != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        } else if (scoredroite >= scoregauche and scoredroite >= scorebas and scoredroite >= scorehaut) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p3 = plateau1;
            plateau1 = deplacementDroite(plateau1);
            if (p3 != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        }
    }
    while(not estTermine(plateau1)) {
        plateau1 = deplacementAleatoire(plateau1);
    }
    dessine(plateau1);
}**/
/**void iaplateau(Plateau plateau1) {
    int x;
    cout << "choissisez le niveau du bot de 1 a 10"<<endl;
    cin>>x;
    while (not estTermine(plateau1)) {
        Plateau gauche = deplacementGauche(plateau1);
        Plateau droite = deplacementDroite(plateau1);
        Plateau haut = deplacementHaut(plateau1);
        Plateau bas = deplacementBas(plateau1);
        double scoredroite = 0;
        double scoregauche = 0;
        double scorebas = 0;
        double scorehaut = 0;
        for (int i = 0; i < x * 20; i++) {
            int compteur1 = 0;
            while (not estTermine(gauche)) {
                Plateau Bis = gauche;
                gauche = deplacementAleatoire(gauche);
                int w = tireDeuxOuQuatre();
                if (w == 4) {
                    compteur1++;
                }
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (gauche != Bis) {
                    while (gauche[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    gauche[p][y] = w;
                }
            }
            scoregauche = scoregauche + scorePlat(gauche) - 4.0 * compteur1;
            gauche = deplacementGauche(plateau1);
        }
        for (int i2 = 0; i2 < x * 20; i2++) {
            int compteur2 = 0;
            while (not estTermine(droite)) {
                Plateau Bis = droite;
                droite = deplacementAleatoire(droite);
                int w = tireDeuxOuQuatre();
                if (w == 4) {
                    compteur2++;
                }
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (droite != Bis) {
                    while (droite[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    droite[p][y] = w;
                }
            }
            scoredroite = scoredroite + scorePlat(droite) - 4.0 * compteur2;
            droite = deplacementDroite(plateau1);
        }
        for (int i3 = 0; i3 < x * 20; i3++) {
            int compteur3 = 0;
            while (not estTermine(bas)) {
                Plateau Bis = bas;
                bas = deplacementAleatoire(bas);
                int w = tireDeuxOuQuatre();
                if (w == 4) {
                    compteur3++;
                }
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (bas != Bis) {
                    while (bas[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    bas[p][y] = w;
                }
            }
            scorebas = scorebas + scorePlat(bas) - 4.0 * compteur3;
            bas = deplacementBas(plateau1);
        }
        for (int i4 = 0; i4 < x * 20; i4++) {
            int compteur4 = 0;
            while (not estTermine(haut)) {
                Plateau Bis = haut;
                haut = deplacementAleatoire(haut);
                int w = tireDeuxOuQuatre();
                if (w == 4) {
                    compteur4++;
                }
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (haut != Bis) {
                    while (haut[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    haut[p][y] = w;
                }
            }
            scorehaut = scorehaut + scorePlat(haut) - 4.0 * compteur4;
            haut = deplacementHaut(plateau1);

        }
        if (scorehaut >= scoregauche and scorehaut >= scorebas and scorehaut >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p5 = plateau1;
            plateau1 = deplacementHaut(plateau1);
            if (p5 != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        } else if (scorebas >= scoregauche and scorebas >= scorehaut and scorebas >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p = plateau1;
            plateau1 = deplacementBas(plateau1);
            if (p != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        } else if (scoregauche >= scorehaut and scoregauche >= scorebas and scoregauche >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p2 = plateau1;
            plateau1 = deplacementGauche(plateau1);
            if (p2 != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        } else if (scoredroite >= scoregauche and scoredroite >= scorebas and scoredroite >= scorehaut) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p3 = plateau1;
            plateau1 = deplacementDroite(plateau1);
            if (p3 != plateau1) {
                while (plateau1[s][c] != 0) {
                    s = aleaint(0, 3);
                    c = aleaint(0, 3);
                }
                plateau1[s][c] = q;
            }
        }
        dessine(plateau1);
    }
}**/

