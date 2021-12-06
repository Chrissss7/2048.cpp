using namespace std;
typedef vector<vector<int> > Plateau;
/** Fonction score explicite d une  case d'un plateau
 * @param a la case dont on veut calculer le score.
 * @return Le score de la case "a"
 */
float score(int a);
/** Fonction qui calucle le nombre de Score d' un plateau;
 * @param plateau le plateau dont on veut le score;
 * @return Le score d'un plateau
 */
float scorePlat(Plateau plateau);
/** Fonction qui renvoie un entier aux hasard compris entre a et b inclus.
 * @param a un entier.
 * @param b un entier.
 * @return Un entier aleatoire entre a et b.
 * */
int aleaint(int a , int b);
/** genere un Plateau de dimensions 4*4 ne contenant que des 0
* @return un Plateau vide
**/
Plateau plateauVide();
/** genere deux nombres sur des cases aleatoires d'un Plateau vide
 * @return un Plateau en d�but de jeu
 **/
Plateau plateauInitial();
/** genere aleatoirement un 2 ou un 4 avec des probabilites respectives de 9/10 et 1/10
 * @return 2 ou 4
 **/
int tireDeuxOuQuatre();
/** deplace les tuiles d'un Plateau vers la gauche et les combine si possible
 * @param plateau le Plateau
 * @return le Plateau une fois deplace vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau);
/** deplace les tuiles d'un Plateau vers la droite et les combine si possible
 * @param plateau le Plateau
 * @return le Plateau une fois deplace vers la droite
 **/
Plateau deplacementDroite(Plateau plateau);
/** deplace les tuiles d'un Plateau vers le haut et les combine si possible
* @param plateau le Plateau
* @return le Plateau une fois deplace vers le haut
**/
Plateau deplacementHaut(Plateau plateau);
/** ddplace les tuiles d'un Plateau vers le bas et les combine si possible
 * @param plateau le Plateau
 * @return le Plateau une fois deplace vers le bas
 **/
Plateau deplacementBas(Plateau plateau);

/** deplace les tuiles d'un Plateau dans la direction donnee et genere une nouvelle tuile si le deplacement est
valide
* @param plateau le Plateau
* @param direction la direction
* @return le Plateau deplace dans la direction
**/
Plateau deplacement(const Plateau& plateau);
/** affiche un Plateau
 * @param p le Plateau
 **/
void dessine( Plateau p);
/** permet de savoir si une partie est termine
 * @param plateau un Plateau
 * @return true si la partie est termine, false sinon
 **/
bool estTermine(const Plateau& plateau);
/** permet de savoir si une partie est gagnee
 * @param plateau un Plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau);
/** Voit si l utulisateur veut continuer a jouer apres avoir atteint 2048
 * @return true si l utulisateur clique y false sinon
 */

bool continueajouer();
Plateau deplacementAleatoire(Plateau plateau);
void iaplateau(Plateau plateau);
void afficheScore(int a);
void afficheString(string s);
void deplacementTest();
void TestScorePlat();
void TestScore();
void testTireDeuxOuQuatre();
void testPlatinitiale();
void TestPlatVide();








