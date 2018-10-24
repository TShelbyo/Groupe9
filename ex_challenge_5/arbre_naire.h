#ifndef __ARBRE_NAIRE__
#define __ARBRE_NAIRE__

typedef char NElt ;
typedef int bool ;

struct znnoeud {
  NElt elt ;
  struct znnoeud *premier_fils;
  struct znnoeud * frere; };
typedef struct znnoeud nnoeud ;
typedef struct znnoeud * narbre;

// Type abstrait de données

narbre n_creer_arbre_vide (void) ;
narbre n_creer_arbre(NElt e, narbre *fils, int n) ;
narbre n_fils_i(narbre a, int i) ;
NElt n_racine(narbre a) ;

bool n_est_arbre_vide(narbre a) ;

// Fonctions outils

narbre n_creer_feuille(NElt e) ;
bool n_est_feuille(narbre a) ;

void n_print_arbre(narbre a) ;
void n_free_noeud(narbre a) ;
void n_free_arbre(narbre a) ;

#endif
 
