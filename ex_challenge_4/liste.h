#ifndef LISTE_H
#define LISTE_H


#include <stdlib.h>
#include <assert.h>


typedef char type_elt;
struct zMaillon
{
    type_elt elt;
    struct zMaillon *suiv;
};
typedef struct zMaillon Maillon;
typedef Maillon * Liste;

Liste creer_liste_vide();
Liste ajouter(type_elt e, Liste l);
type_elt tete(Liste l);
Liste queue(Liste l);
int est_liste_vide(Liste l);

#endif