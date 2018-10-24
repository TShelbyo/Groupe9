#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arbre_naire.h"

// Type abstrait de données

narbre n_creer_arbre_vide (void)
{
  return NULL ;
}

void ajouter_fin_freres(narbre a, narbre j)
{
  narbre curr = a;
  while(!n_est_arbre_vide(curr->frere)) curr=curr->frere;
  curr->frere = j;
}

narbre n_creer_arbre(NElt e, narbre *fils, int n) 
{
  int i = 0;
  nnoeud *rslt = (nnoeud *)malloc(sizeof(nnoeud));
  rslt->elt = e;
  rslt->frere = NULL;
  while(i<n && n_est_arbre_vide(fils[i])) i++;
  if(i==n) rslt->premier_fils = NULL;
  else rslt->premier_fils = fils[i];
  
  for(i=i+1;i<n;i++)
    if(!n_est_arbre_vide(fils[i]))
      ajouter_fin_freres(rslt->premier_fils, fils[i]);

  return rslt;
}

narbre n_fils_i(narbre a, int i)
{
  narbre currfils = a->premier_fils;
  int cpt = 0;
  while(!n_est_arbre_vide(currfils) && cpt<i)
  {
    currfils=currfils->frere;
    cpt++;
  }
  if(n_est_arbre_vide(currfils)) return NULL;
  else return currfils;
}


NElt n_racine(narbre a)
{
  assert(!n_est_arbre_vide(a));
    return a->elt ;
}

bool n_est_arbre_vide(narbre a)
{
  return (a == NULL) ;
}

// Fonctions outils

narbre n_creer_feuille(NElt e)
{
  return n_creer_arbre(e, NULL, 0) ;
}

bool n_est_feuille(narbre a)
{
  if (n_est_arbre_vide(a))
    return 0 ;
  return (n_est_arbre_vide(a->premier_fils)) ;
}

void n_print_arbre_aux(narbre a)
{
  narbre tmp ;
  if (n_est_arbre_vide(a))
    printf(".") ;
  else
  {
    printf("%c (", a->elt) ;
    tmp = a->premier_fils ;
    while(!n_est_arbre_vide(tmp))
    {
      n_print_arbre_aux(tmp) ;
      printf(" - ") ;
      tmp = tmp->frere ;
    }
    printf(")") ;
  }
}

void n_print_arbre(narbre a) // Notation préfixe
{
  n_print_arbre_aux(a) ;
  printf("\n") ;
}

void n_free_noeud(narbre a)
{
  free(a) ;
}

void n_free_arbre(narbre a)
{
  narbre tmp, tmp2 ;
  if(!n_est_arbre_vide(a))
  {
    tmp = a->premier_fils ;
    while (!n_est_arbre_vide(tmp))
    {
      tmp2 = tmp->frere ;
      n_free_arbre(tmp) ;
      tmp = tmp2 ;
    }
    free(a) ;
  }
}
