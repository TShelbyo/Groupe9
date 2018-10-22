#include "pile.h"

int est_pile_vide(Pile p){
    return est_liste_vide(p) ;
}

Pile creer_pile_vide(){
    return creer_liste_vide() ;
}
Pile push(int x, Pile p){
    return ajouter(x, p) ;
}
int top(Pile p){
    return tete(p) ;
}
Pile pop (Pile p){
    Liste Tmp = queue(p) ;
    free(p) ;
    return Tmp ;
}
void free_Pile(Pile p){
    if (!est_pile_vide(queue(p))){
        free_Pile(queue(p)) ;
    }
    free (p) ;
}