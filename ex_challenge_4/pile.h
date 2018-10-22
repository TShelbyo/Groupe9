#include <stdlib.h>
#include "liste.h"

typedef Liste Pile;

int est_pile_vide(Pile p);
Pile creer_pile_vide();
Pile push(int x, Pile p);
int top(Pile p);
Pile pop (Pile p);
void free_Pile(Pile p);