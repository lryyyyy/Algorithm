#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dp(M,N,length)	dp[(M)*(length)+(N)]

static int rec(int i, int j, int * dp, int * w, int * v);

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
	memset(dp,-1,sdp * sizeof(int));
	printf("%d\n",rec(0,W,dp,w,v));
	return 0;
}

int rec(int i, int j, int * dp, int * w, int *v)
{
	if (dp(i,j,W) >= 0)
		return dp(i,j,W);
	int res;
	if (i == n)
		res = 0;
	else if (j < w[i])
		res = rec(i+1,j,dp,w,v);
	else
		res = max(rec(i+1,j,dp,w,v),rec(i+1,j-w[i],dp,w,v)+v[i]);
	dp(i,j,W) = res;
	return dp(i,j,W);
}

int max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}
