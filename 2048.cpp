#include <vector>
#include <iostream>
#include <ctime>
#include "2048.h"
using namespace std;
typedef vector<vector<int> > Plateau;

int main() {
    system("CLS");
    int compteur = 0;
    srand(time(0));
    Plateau Jeux = plateauInitial();
    int compteur1 = 0;
    for (auto i : Jeux) {
        for (auto v : i) {
            if (v == 4) {
                compteur++;
            }
        }
    }
    afficheString("Score : ");
    afficheScore(scorePlat(Jeux) - 4 * compteur);
    cout << endl;
    while (not estTermine(Jeux) ) {
        Plateau Bis = Jeux;
        dessine(Jeux) ;
        Jeux = deplacement(Jeux);
        int w = tireDeuxOuQuatre();
        int x = aleaint(0, 3);
        int y = aleaint(0, 3);
        if (Jeux != Bis) {
            while (Jeux[x][y] != 0) {
                x = aleaint(0, 3);
                y = aleaint(0, 3);
            }
            Jeux[x][y] = w;
            system("CLS");
            if (w == 4) {
                compteur = compteur + 1;
                afficheString("Score : ");
                afficheScore(scorePlat(Jeux) - 4 * compteur);
                cout << endl;
            } else {
                afficheString("Score : ");
                afficheScore(scorePlat(Jeux) - 4 * compteur);
                cout << endl;
            }
        }
        else{
            system("CLS");
            afficheString("Score : ");
            afficheScore(scorePlat(Jeux) - 4 * compteur);
            cout << endl;
        }
        if(estGagnant(Jeux) and compteur1 < 1){
            cout << "Veut tu continuer ? si oui cliquer 'y' sinon n'importe quelle touche" << endl;
            bool a =continueajouer();
            compteur1++;
            if(a){
                continue;
            }else{
                break;
            }
        }
    }
    if(estGagnant(Jeux)){
        system("CLS");
        cout << "congratulation celebration" << endl;
    }else{
        system("CLS");
        dessine(Jeux) ;
        cout << "Dommage perdu tu a fais : " << scorePlat(Jeux) - 4 * compteur<<endl;
    }
}