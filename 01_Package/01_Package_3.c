#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dp(M,N,length)	dp[(M)*(length+1)+(N)]

static int rec(int *, int *, int *, int, int);

static int max(int, int);

int main()
{
	int n, W;
	printf("Please input n & W : \n");
	scanf("%d %d",&n,&W);
	int sdp = (n+1) * (W+1);
	int * w = (int *)malloc(n * sizeof(int));
	int * v = (int *)malloc(n * sizeof(int));
	int * dp = (int *)malloc(sdp * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	memset(dp,0,sdp * sizeof(int));
	printf("%d\n",rec(w,v,dp,n,W));
	return 0;
}

int rec(w,v,dp,n,W)
int * w, * v;
int * dp;
int n, W;
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (j < w[i])
				dp(i+1,j,n) = dp(i,j,n);
			else
				dp(i+1,j,n) = max(dp(i,j,n),dp(i,j-w[i],n)+v[i]);
			printf("%3d",dp(i+1,j,n));
		}
		printf("\n");
	}
	return dp(n,W,n);
}

int max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}