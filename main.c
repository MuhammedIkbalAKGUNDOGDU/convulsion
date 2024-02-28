#include <stdio.h>

int main()
{
    int m,n,k,i,j,f,t,toplam=0,asiltop;
    printf("Please enter M : ");
    scanf("%d",&m);
    printf("Please enter N : ");
    scanf("%d",&n);
    int matrix[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Please enter your matrix %d x %d value : ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Please enter k : ");
    scanf("%d",&k);
    while(!(k<m&&k<n&&k%2!=0))
    {
        printf("Please enter another k value : ");
        scanf("%d",&k);
    }
    int filter[k][k];
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            printf("Please enter your filter %d x %d value : ",i+1,j+1);
            scanf("%d",&filter[i][j]);
            toplam += filter[i][j];
        }
    }
    int result[m-k+1][n-k+1];
    for(i=0;i<m-k+1;i++)
    {
            for(f=0;f<n-k+1;f++)
            {
              for(j=0;j<k;j++)
              {
                  for(t=0;t<k;t++)
                  {
                      asiltop+=(matrix[j+i][t+f]*filter[j][t]);
                  }
              }
              result[i][f]=(asiltop/toplam);
              asiltop=0;
            }
    }
    for(i=0;i<m-k+1;i++)
    {
        for(j=0;j<n-k+1;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
