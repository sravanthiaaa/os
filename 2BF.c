#include<stdio.h>
int main(){
	int n,m,i,j;
	printf("Enter no.of processes and no. of blocks:");
	scanf("%d %d",&n,&m);
	int p[n],b[m],allocated[n],occupied[m];
	printf("Enter processes size:");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
		allocated[i]=-1;
		}
	printf("Enter blocks size:");
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
		occupied[i]=0;
		}
		int intfrag=0,exfrag=0;
	for(i=0;i<n;i++){
		int index=-1;
		for(j=0;j<m;j++){
			if(!occupied[j] && p[i]<=b[j]){
			if(index==-1){
				index=j;
				}
			else if(b[j]<b[index]){
				index=j;
			}
		}
		}	
			if(index!=-1){		
				allocated[i]=index;
				intfrag+=b[index]-p[i];
				occupied[index]=1;
				//break;
				}
			}
	printf("PNo.\t\t\tPSize\t\t\tFNo\n");
	for(int i=0;i<n;i++){
		printf("%d\t\t\t %d\t\t\t",i+1,p[i]);
		if(allocated[i]!=-1)
		 printf("%d\n",allocated[i]+1);
		else
		 printf("not allocated\n");
		}
	printf("Internal Fragmentation is:%d\n",intfrag);
	printf("External Fragmentation is:");
	for(i=0;i<m;i++){
		if(occupied[i]==0){
			exfrag+=b[i];
			}
		}
	printf("%d",exfrag);
}
			
						
				
					
