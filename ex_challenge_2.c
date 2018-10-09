#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ERROR_TABLE_OVERFLOW -1

void affichage(int tab[], int n)
{
    int i = 0;
    printf("Tableau: ");
    for(i=0;i<n;i++)
        printf("%d ", tab[i]);
}

int appartient_gr_09(int x, int *t1, int s1, int n1)
{
    int trouve = 0;
    int indice = -1;
    int m;
    int i = 0;
    int j=s1;

    while(i<j && !trouve)
    {
        m = (i+j)/2;
        if(x == t1[m])
        {
            trouve=1;
            indice=m;
        }
        else 
        {
            if(x < t1[m])
                j = m-1;
            else
                i = m+1;
        }
    }

    if(i == j)
        if(t1[i] == x)
        {
            trouve=1;
            indice = i;
        }

    return indice;
}

int inclus_gr_09(int *t1, int s1, int n1, int *t2, int s2, int n2)
{
    int i = 0;
    int indice, *tmp;
    int taille_tmp, nb_elt_tmp;
    tmp = t2;
    taille_tmp = s2;
    nb_elt_tmp = n2;

    if(n1>n2) return FALSE;
    while(i<n1)
    {
        indice = appartient_gr_09(t1[i],tmp, taille_tmp, nb_elt_tmp);
        i++;
        if(indice == -1) return FALSE;
        tmp+=indice;
        taille_tmp-=indice;
        nb_elt_tmp-=indice;
    }

    return TRUE;
}

int union_gr_09(int *t1, int s1, int n1, int *t2, int s2, int n2, int *t3, int s3, int *n3)
{
    int i = 0;
    int j = 0;  

    *n3 = 0;
    if(s1 > s3 || s2 > s3) return ERROR_TABLE_OVERFLOW;

    while(i<n1 && j<n2 && *n3<s3)
    {
        if(t1[i] < t2[j])
            t3[(*n3)++] = t1[i++];
        else if(t1[i] > t2[j])
            t3[(*n3)++] = t2[j++];
        else
        {
            t3[(*n3)++] = t2[j++];
            i++;
        }
    }

    while(i<n1 && *n3<s3) t3[(*n3)++] = t1[i++];
    while(j<n2 && *n3<s3) t3[(*n3)++] = t2[j++];

    if(*n3>=s3) return ERROR_TABLE_OVERFLOW;

    return 0;
}

int inter_gr_09(int *t1, int s1, int n1, int *t2, int s2, int n2, int *t3, int s3, int *n3)
{
    int i, n, s;
    int *tmp;

    *n3 = 0;

    i = 0;
    if(n1 < n2)
    {
        tmp = t1;
        n = n1;
        s = s1;
    }
    else
    {
        tmp = t2;
        n = n2;
        s = s2;
    }

    while(i<n && *n3 < s3)
    {
        if(appartient_gr_09(tmp[i], tmp, s, n) != -1)
            t3[(*n3)++] = tmp[i];
        i++;
    }

    if(*n3>=s3) return ERROR_TABLE_OVERFLOW;
    return 0;
}

int main()
{
    int i;
    int t1[5] = {1,4,5,7,9};
    int s1 = 5;
    int n1 = 5;

    int t2[4] = {1,2,7,9};
    int s2 = 4;
    int n2 = 4;

    int t3[10];
    int s3 = 10;
    int n3;

    printf("Union: \n");
    if(union_gr_09(t1, s1, n1, t2, s2, n2, t3, s3, &n3) == ERROR_TABLE_OVERFLOW) printf("Erreur: Tableau de sortie trop petit\n");
    else for(i=0;i<n3;i++) printf("%d ", t3[i]);
    printf("\n");

    printf("Intersection \n");
    if(inter_gr_09(t1, s1, n1, t2, s2, n2, t3, s3, &n3) == ERROR_TABLE_OVERFLOW) printf("Erreur: Tableau de sortie trop petit\n");
    else for(i=0;i<n3;i++) printf("%d ", t3[i]);

    printf("\n");

    //printf("%d\n", inclus_gr_09(t2,4,4, tab, 5, 5));

    return 0;
}

