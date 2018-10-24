#include <stdio.h>
#include <limits.h>
#include "arbre_binaire.h"
#include "arbre_naire.h"
#include <stdlib.h>

void serialisation_aux(arbre a, char *s, int *i)
{
  if(est_arbre_vide(a))
  {
    s[(*i)++] = '0';
    return;
  }
  s[(*i)++] = '1';
  s[(*i)++] = a->elt;
  serialisation_aux(a->fils_gauche,s,i);
  serialisation_aux(a->fils_droit,s,i);
}

char *serialisation(arbre a,  int *i)
{
  char *code = (char *)malloc(2000);
  *i = 0;
  serialisation_aux(a,code,i);
  code[*i + 1] = '\0';
  return code;
}

arbre deserialisation_aux(char *s, int *i)
{
  arbre b = creer_arbre_vide();
  if(s[(*i)] == '0' || s[*i] == '\0') 
  {
    (*i)++;
    return creer_arbre_vide();
  }
  if(s[*i] == '1')
  {
    (*i)++;
    b = creer_feuille(s[*i]);
    (*i)++;
    b->fils_gauche = deserialisation_aux(s,i);
    b->fils_droit = deserialisation_aux(s,i);
    return b;
  }
  return NULL;
}

arbre deserialisation(char *s)
{
  int i = 0;
  return deserialisation_aux(s,&i);
}
int main ()
{
  int i;
  arbre fc = creer_feuille('c'), fx = creer_feuille('x'), fy = creer_feuille('y');
  arbre fb = creer_arbre('b', fc, NULL), fd = creer_arbre('d', fx, fy);
  arbre fa = creer_arbre('a',fb,fd);

  //Ex challenge: serialisation arbre

  char *code = serialisation(fa,&i);
  printf("s: %s\n", code);

  arbre testD = deserialisation(code);
  print_arbre(testD);
  return 0 ;
}
  
