#include <stdio.h>
#include <stdlib.h>

static int rec(int i, int j, int * w, int * v);

static int max(int i, int j);

int n, W;

int main()
{
	printf("Please input n & W : \n");
	scanf("%d %d",&n,&W);
	int * w = (int *)malloc(n * sizeof(int));
	int * v = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	printf("%d\n",rec(0,W,w,v));
	return 0;
}

int rec(int i, int j, int * w, int * v)
{
	int res;
	if (i == n)
		res = 0;
	else if (j < w[i])
		res = rec(i+1,j,w,v);
	else
		res = max(rec(i+1,j,w,v), rec(i+1,j-w[i],w,v)+v[i]);
	return res;
}

int max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}
