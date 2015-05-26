/*************************************************************************
    > File Name: poj3186.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月23日 星期四 21时53分22秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 2010
int dp[MAXN][MAXN];
using namespace std;

int main()
{
	int N;
	int i,j;
	int k;
	int rank;
	int a[MAXN];
	while(~scanf("%d",&N))
	{
		for(i=1;i<=N;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=N;i++)
			dp[i][i]=N*a[i];
		for(k=1;k<N;k++)
		{
			for(i=1;i<=N-k;i++)
			{
				j=i+k;
				dp[i][j]=max(dp[i][j],max(dp[i+1][j]+(N-k)*a[i],dp[i][j-1]+(N-k)*a[j]));		
			}
		}
		printf("%d\n",dp[1][N]);
	}
	return 0;
}
