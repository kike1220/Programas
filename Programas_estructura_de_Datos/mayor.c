#include <stdio.h>
#define T 10
void leer(int v[],int);
int maximo(int v[],int,int,int);
int main(){
	int v[T],max,i=0,n,max1;
	scanf("%d", &n);
	leer(v,n);
	max1=v[0];
	max=maximo(v,n,i,max1);
	printf("%d", max);
	
	return 0;
}
void leer(int v[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d", &v[i]);
	}
}
int maximo(int v[], int n,int i,int max)
{	
	if(i==n)
	{
		return max;
	}
	else
	{
		if(max<v[i])
		{
			max=v[i];
		}
	}
	maximo(v,n,i+1,max);
}
