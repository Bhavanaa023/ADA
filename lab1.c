#include<stdio.h>
#include<time.h>
void main() {
	int i,n,j,k,temp;
	printf("Enter size of an array\n");
	scanf("%d",&n);
	int a[n];
	srand(time(NULL));
	for(i=1;i<=n;i++){
		a[i]=rand()%1000;		
	}
	clock_t start=clock();
	for(i=1;i<=n;i++){
		j=i;
		for(k=i+1;k<=n;k++){
			if(a[k]<a[j]){
				j=k;
			}
		}
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	clock_t end=clock();
	double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
	printf("TIme taken to sort %d elements in %lf seconds\n",n,time_taken);
	
	//printf("Selection sorted elements are\n");
	//for(i=1;i<=n;i++){
		//printf("%d\t",a[i]);
	//}
	//printf("\n");
}