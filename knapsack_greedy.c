#include<stdio.h>

#define MAX_ITEMS 100

double computeMaxValue(double w,double weight[],double value[],double ratio[],int nItems){

	double cw=0;

	double cv=0;

	printf("\nItems considered are: ");

	while(cw<w){

		int item=getNextItem(weight,value,ratio,nItems);

		if(item==-1){

			break;

		}

		printf("%d",item+1);

		if(cw+weight[item]<=w){

			cw+=weight[item];

			cv+=value[item];

			ratio[item]=0;

		}

		else{

			cv+=(ratio[item]*(w-cw));

			cw+=(w-cw);

			break;

		}

	}

	return cv;

}

int getNextItem(double weight[], double value[], double ratio[],int nItems){

	double highest=0;

	int i,index=-1;

	for(i=0;i<nItems;i++){

		if(ratio[i]>highest){

			highest=ratio[i];

			index=i;

		}

	}

	return index;

}

int main(){

	int i,nItems;

	double w;

	double weight[MAX_ITEMS];

	double value[MAX_ITEMS];

	double ratio[MAX_ITEMS];

	printf("Enter number of items: \n ");

	scanf("%d",&nItems);

	printf("ENter the weight of items: \n");

	for(i=0;i<nItems;i++){

		scanf("%lf",&weight[i]);

	}

	printf("Enter the value/profit of the item:\n");

	for(i=0;i<nItems;i++){

		scanf("%lf",&value[i]);

	}

	for(i=0;i<nItems;i++){

		ratio[i]=value[i]/weight[i];

	}

	printf("Enter the capacity of the Knapsack: ");

	scanf("%lf",&w);

	printf("\n The maximum value in a knapsack of capacity %2f is: %2f \n",w,computeMaxValue(w,weight ,value,ratio,nItems));

	return 0;

}