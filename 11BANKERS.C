#include<stdio.h>
void bankers(int allocation[],int max[],int available[],int n,int m){
	int need[n][m],flag;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			need[i][j]=max[i][j]-allocation[i][j];
			}
		}
	int finish[10],safe[10];
	for(i=0;i<n;i++)
		finish[i][j]=0;
	for(i=0;i<n;i++){
		flag=0;
		if(finish[i]==0){
		for(j=0;j<m;j++){
			if(need[i][j]>available[j]){
				flag=1;
				break;
				}
			}
		if(flag==0){
			finish[i]=1;
			sequence[k]=i;
			k++;
			for(j=0;j<m;j++){
				available[j]+=allocation[i][j];
				}
			i=-1;
			}
		}
	}			
flag=0;
if(i=0;i<n;i++){
	if(finish[i]==0){
		printf("deadlock");
		flag=1;
		break;
		}
	}
	if(flag==0){
	printf("safe sequence:");
	for(i=0;i<n;i++){
		printf("%d\t",sequence[i];
		}
	}
}							
						
int main(){
	int n,m,i,j;
	printf("enter no of processes and no of resorces:");
	scanf("%d %d",&n,&m);
	int allocation[n][m],max[n][m];
	printf("Allocation matrix:");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&allocation[i][j]);
			}
		}
	printf("max matrix:");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&max[i][j]);
			}
		}
		int available[m];
		printf("Available:");
	for(j=0;j<m;j++)
		scanf("%d",&available[j];
	bankers(allocation,max,available,n,m);
}					
