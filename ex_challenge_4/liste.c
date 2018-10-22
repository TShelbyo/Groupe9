#include "liste.h"

Liste creer_liste_vide() { return NULL; }

Liste ajouter(type_elt e, Liste l)
{
    Maillon *m = (Maillon *)malloc(sizeof(Maillon));
    assert(m != NULL);
    m->elt = e;
    m-> suiv = l;
    return m;
}

type_elt tete(Liste l)
{
    assert(!est_liste_vide(l));
    return l->elt;
}

Liste queue(Liste l)
{
    assert(!est_liste_vide(l));
    return l->suiv;
}

int est_liste_vide(Liste l) { return l == NULL; }