#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct process{
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int pno;
	int realbt;
	bool visit;
	};
struct readyq{
	int id;
	bool v;
	};
struct process p[10];
struct readyq rq[100];
int r=0;
void rr(int n,int tq){
	int pct=-1,tct=0,index=-1,count=1,rqCount=0,i;
	while(count<=n){
		for(i=0;i<n;i++){
			if(p[i].at>pct && p[i].at<=tct && p[i].visit==false){
				rq[r].id=i;
				rq[r].v=false;
				r++;
				rqCount++;
				}
			}
		if(index!=-1 && p[index].bt!=0){
			rq[r].id=index;
			rq[r].v=false;
			r++;
			rqCount++;
			}
		if(rqCount==0){
			printf("-IDLE-");
			pct=tct;
			tct++;
			}
		else{
			for(i=0;i<r;i++){
				if(rq[i].v==false){
					index=rq[i].id;
					rq[i].v=true;
					break;
					}
				}
			if(p[index].bt<=tq){
				printf("p%d | ",p[index].pno);
				pct=tct;
				tct+=p[index].bt;
				p[index].bt=0;
				}
			else{
				printf("p%d | ",p[index].pno);
				pct=tct;
				tct+=tq;
				p[index].bt-=tq;
				}
			if(p[index].bt==0){
				count++;
				p[index].visit=true;
				p[index].ct=tct;
				p[index].tat=p[index].ct-p[index].at;
				p[index].wt=p[index].tat-p[index].realbt;
				}
			}
		}
	}											
int main(){
int n,i,tq;
	printf("Enter no.of process:");
	scanf("%d",&n);
	printf("PID AT BT\n");
	for(i=0;i<n;i++){
		scanf("%d %d %d",&p[i].pno,&p[i].at,&p[i].bt);
	 	}
	 printf("Enter tq:");
	 scanf("%d",&tq);
	 for(i=0;i<n;i++)
	 	p[i].visit=false;
	 for(i=0;i<n;i++)
	 	p[i].realbt=p[i].bt;	
	 rr(n,tq);
printf("\nReadyQueue\n");
	for(int i=0;i<r;i++){
		printf("p%d",p[rq[i].id].pno);
		
	}
	printf("\npno\tat\tct\ttat\twt\n");
	for(int i=0;i<n;i++){
		printf("\np%d\t%d\t%d\t%d\t%d\t",p[i].pno,p[i].at,p[i].ct,p[i].tat,p[i].wt);
	}
}		 				
