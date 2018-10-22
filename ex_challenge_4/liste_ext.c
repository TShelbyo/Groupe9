#include "liste_ext.h"

int rechercher(type_elt e, Liste l)
{
    if(tete(l) == e) return 1;
    else if(est_liste_vide(l)) return 0;
    return rechercher(e,queue(l));
}

int rechercherPos(type_elt x, Liste l, int i)
{
    if(tete(l) == x) return i;
    else if(est_liste_vide(l)) return -1;
    return rechercherPos(x,queue(l),i+1);
}

Liste inverser_rec(Liste l, Liste l2)
{
    if(est_liste_vide(l)) return l2;
    else return inverser_rec(ajouter(tete(l),l2),queue(l));
}

Liste inverser(Liste l)
{
    Liste l2 = (Liste)malloc(sizeof(Maillon));
    return inverser_rec(l,l2);
}