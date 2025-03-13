#include<stdio.h>
#include<stdlib.h>
#define INF 999
int parent[100],cost[100][100];
int findParent(int i){
	while(parent[i]!=0){
		i=parent[i];
	}
	return i;
}
int UnionVertex(int i,int j){
	if(i!=j){
		parent[j]=i;
		return 1;
	}
	return 0;
}
int main(){
	int i,j,n,min,ne=1;
	int u=0,v=0,a=0,b=0,mincost=0;
	printf("ENter the number of vertices in graph\n");
	scanf("%d",&n);
	printf("ENter the cost matrix\n");
	for(i=1;i<=n;i++){
		parent[i]=0;
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){
				cost[i][j]=INF;
			}
		}	
	}
	printf("THe edges of minimum spanning treee are");
	while(ne<n){
		min=INF;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min){
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			} 
  		}
		u=findParent(u);
		v=findParent(v);
		if(UnionVertex(u,v)){
			printf("%d edge selected (%d---%d) cost=%d\n",ne++,a,b,min);
			mincost+=min;
		}
		cost[a][b]=cost[b][a]=INF;
	}
	printf("Minimum cost =%d\n",mincost);
	return 0;
}
				