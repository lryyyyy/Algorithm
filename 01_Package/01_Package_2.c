#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dp(M,N,length)	dp[(M)*(length+1)+(N)]

static int rec(int, int, int *, int *, int *, int);

static int max(int, int);

int main()
{
	int n, W;
	printf("Please input n & W : \n");
	scanf("%d %d",&n,&W);
	int sdp = n * W;
	int * w = (int *)malloc(n * sizeof(int));
	int * v = (int *)malloc(n * sizeof(int));
	int * dp = (int *)malloc(sdp * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	memset(dp,-1,sdp * sizeof(int));
	printf("%d\n",rec(0,W,dp,w,v,n));
	return 0;
}

int rec(i, j, dp, w, v, n)
int i, j;
int * dp, * w, * v, n;
{
	if (dp(i,j,n) >= 0)
		return dp(i,j,n);
	int res;
	if (i == n)
		res = 0;
	else if (j < w[i])
		res = rec(i+1,j,dp,w,v,n);
	else
		res = max(rec(i+1,j,dp,w,v,n),rec(i+1,j-w[i],dp,w,v,n)+v[i]);
	dp(i,j,n) = res;
	return dp(i,j,n);
}

int max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}