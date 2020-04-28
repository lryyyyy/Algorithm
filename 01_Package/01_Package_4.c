#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int rec(int * w, int * v, int * dp);

static int max(int i, int j);

int n, W;

int main()
{
	printf("Please input n & W : \n");
	scanf("%d %d",&n,&W);
	int sdp = W+1;
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
		for (int j = W; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
		}
	}
	return dp[W];
}

int max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}
