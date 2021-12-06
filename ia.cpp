#include <ctime>
#include <vector>
#include <iostream>
#include "2048.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define esc 27
using namespace std;
typedef vector<vector<int> > Plateau;
int main(){
    srand(time(nullptr));
    iaplateau(plateauInitial());
}

