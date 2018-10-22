#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "pile.h"
#define N 20

int opération(Pile *p, char signe){
    int tmp;
    if (!est_pile_vide(*p)){
        if(!est_pile_vide(queue(*p))){
            tmp = top(*p) ;
            *p = pop(*p) ;
            switch(signe){
                case '*': tmp *= top(*p);break;
                case '+': tmp += top(*p);break;
                case '-': tmp -= top(*p);break;
                case '/': tmp /= top(*p);break;
                default : break ;
            }
            *p = pop(*p) ;
            *p = push (tmp, *p) ;
            return 0 ;
        }
    }
    return 1;
}

int evaluation(char table[]){
    int test = 0 ;
    int i = 0;
    Pile p = creer_pile_vide();
    while (test == 0 && table[i]!= 0){
        if (table[i] == ('*')||table[i] == ('-')||table[i] == ('+')||table[i] == ('/')){
            test = opération(&p, table[i]) ;
        } else {
            p = push(table[i] - 48, p) ;
        }
        i++ ;  
    }
    if (test == 1 || !est_pile_vide(queue(p))){
        return -1 ;
    }
    return top(p) ;     
}



int main()
{
    char table[N] ;
    scanf("%s", table) ;
    printf("l'evaluation est %d  \n", evaluation(table)) ;
    return 0;
}
