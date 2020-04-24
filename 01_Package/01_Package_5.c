#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 999

#define dp(M,N,length)	dp[(M)*(length+1)+(N)]

static int rec(int *, int *, int *, int, int, int);

static int min(int, int);

int main()
{
	int n, W;
	double div, max = 0;
	printf("Please input n & W : \n");
	scanf("%d %d",&n,&W);
	int * w = (int *)malloc(n * sizeof(int));
	int * v = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&w[i],&v[i]);
		div = v[i]*1.0/w[i];
		max = max>div?max:div;
	}
	int len = max * W + 1;
	int sdp = (n+1) * (len+1);
	int * dp = (int *)malloc(sdp * sizeof(int));
	for (int i = 0; i < len; i++)
		dp(0,i,len) = INF;
	dp[0] = 0;
	printf("%d\n",rec(w,v,dp,n,W,len));
	return 0;
}

int rec(w,v,dp,n,W,len)
int * w, * v;
int * dp;
int n, W, len;
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= len; j++)
		{
			if (j < v[i])
				dp(i+1,j,len) = dp(i,j,len);
			else
				dp(i+1,j,len) = min(dp(i,j,len),dp(i,j-v[i],len)+w[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= len; j++)
		{
			printf("%6d",dp(i+1,j,len));
		}
		printf("\n");
	}
	for (int i = len;;i--)
		if (dp(n,i,len) <= W || i < 0)
			return i;
}

int min(int i, int j)
{
	if (i < j)
		return i;
	else
		return j;
}