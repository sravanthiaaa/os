#include <stdio.h>

void BestFit(int b[], int m, int p[], int n)
{
 
    int allocation[n];
    int occupied[m];
    
 
    for(int i = 0; i < n; i++){
        allocation[i] = -1;
    }
    
    for(int i = 0; i < m; i++){
        occupied[i] = 0;
    }
 
   
    for (int i = 0; i < n; i++)
    {
        
        int index= -1;
        for (int j = 0; j < m; j++) { 
            if (b[j] >= p[i] && !occupied[j])
            {
                
                if (index== -1)
                    index= j;
                    
                
                else if (b[j] < b[index])
                    index= j;
            }
        }
 
        
        if (index != -1)
        {
            
            allocation[i] = index;
            
            
            occupied[index] = 1;
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, p[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
 
int main()
{
    int n,m,i;
	printf("enter no.of process");
	scanf("%d",&n);
	printf("enter no.of blocks");
	scanf("%d",&m);
	int p[n],b[m];
	printf("processes:");
	for(i=0;i<n;i++)
	{
	scanf("%d",&p[i]);
	}
	printf("blocks:");
	for(i=0;i<m;i++)
	{
	scanf("%d",&b[i]);
	}
	
 
    BestFit(b, m, p, n);
 
    return 0 ;
   }
