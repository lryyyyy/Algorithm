#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dp(M,N,length)	dp[(M)*(length)+(N)]

static int rec(int * w, int * v, int * dp);

static int max(int i, int j);

int n, W;

int main()
{
	printf("Please input n & W : \n");
	scanf("%d %d",&n,&W);
	int sdp = (n + 1) * W;
	int * w = (int *)malloc(n * sizeof(int));
	int * v = (int *)malloc(n * sizeof(int));
	int * dp = (int *)malloc(sdp * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	memset(dp,0,sdp * sizeof(int));
	printf("%d\n",rec(w,v,dp));
	return 0;
}

int rec(int * w, int * v, int * dp)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (j < w[i])
				dp(i+1,j,W) = dp(i,j,W);
			else
				dp(i+1,j,W) = max(dp(i,j,W),dp(i,j-w[i],W)+v[i]);
		}
	}
	return dp(n,W-1,W);
}

int max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}
