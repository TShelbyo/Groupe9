#include <stdio.h>

#define N 10
int main()
{
    int t[N]={-1,2,5,-1,-1,1,6,-1,2,-1};
    int nTab[N];
    int i,j,k;

    j=0;
    for(i=0;i<N;i++)
    {
        if(t[i] != -1)
            nTab[j++] = t[i];
    }
    for(k=j+1;k<N;k++)
        nTab[k] = -1;
    printf("Tab: ");



    for(k=0;k<N;k++)
        printf("%d ", nTab[k]);
    printf("\n");
    return 0;
}