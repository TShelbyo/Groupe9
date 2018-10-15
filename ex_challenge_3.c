#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FALSE 0
#define TRUE 1

typedef int type_elt;
struct zMaillon
{
    type_elt elt;
    struct zMaillon *suiv;
};
typedef struct zMaillon Maillon;
typedef Maillon * Liste;

Liste creer_liste_vide_gr_09() { return NULL; }
int est_liste_vide_gr_09(Liste l) { return l == NULL; }

type_elt tete_gr_09(Liste l)
{
    assert(!est_liste_vide_gr_09(l));
    return l->elt;
}

Liste queue_gr_09(Liste l)
{
    assert(!est_liste_vide_gr_09(l));
    return l->suiv;
}


Liste ajouter_gr_09(type_elt e, Liste l)
{
    Maillon *m = (Maillon *)malloc(sizeof(Maillon));
    assert(m != NULL);
    m->elt = e;
    m-> suiv = l;
    return m;
}

void tri_gr_09(Liste l)
{
    Maillon *tmp,*n_moins_un;
    Liste n;
    int echange = TRUE;

    n = l;
    tmp = NULL;
    while(echange)
    {
        n = l ;
        echange = FALSE;
        while(n != NULL)
        {
            if(n->suiv != NULL)
            {
                if (n->elt > n->suiv->elt)
                {
                    echange = TRUE;
                    tmp = n->suiv->suiv;
                    n_moins_un->suiv = n->suiv;
                    n->suiv->suiv = n;
                    n_moins_un= n->suiv;
                    n->suiv = tmp;
                    if(n->suiv != NULL) if(n->suiv->suiv == l) l = n;
                }
                else
                {
                    n_moins_un = n;
                    n = n->suiv;
                }
            }
            else
            {
                n = n->suiv;
                n_moins_un = n;
            }
        }
    }
}

Liste inverser_gr_09(Liste l, Liste l2)
{
    if(est_liste_vide_gr_09(l)) return l2;
    else return inverser_gr_09(queue_gr_09(l), ajouter_gr_09(tete_gr_09(l),l2));
    //tri(l);
}

int palindrome_aux_gr_09(Liste l1, Liste l2)
{
    if(l1 == l2)    return 1;
    if(l1->elt == l2->elt)
    {
        if(l1->suiv != NULL && l2->suiv != NULL) return palindrome_aux_gr_09(l1->suiv, l2->suiv);
        else return 1;
    }
    return 0;
}


int palindrome_gr_09(Liste l)
{
    Liste l2;
    if(l->suiv == NULL) return 1;
    return palindrome_aux_gr_09(l,inverser_gr_09(l2,l));
}

int main()
{
    Liste l;
    Maillon *tmp;

    l = creer_liste_vide_gr_09();
    l = ajouter_gr_09(1, l);
    l = ajouter_gr_09(2, l);
    l = ajouter_gr_09(3, l);
    l = ajouter_gr_09(2, l);
    l = ajouter_gr_09(1, l);

    // 0 1 2 3 0 1 2

    printf("Palindrome : %d\n", palindrome_gr_09(l));

    tri_gr_09(l);
    tmp = l;
    while(tmp != NULL)
    {
        printf("%d\n",tmp->elt);
        tmp = tmp->suiv;
    }


    return 0;
}