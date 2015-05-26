/*************************************************************************
    > File Name: hdu1176.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月15日 星期三 19时35分17秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 100010
using namespace std;
int v[15][MAXN];
int dp[15][MAXN];

int main()
{
	int n;
	int i,j;
	int a,b;
	int maxt;
	while(scanf("%d",&n) && n)
	{
		maxt=0;
		memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			v[a][b]++;
			maxt=max(maxt,b);
		}
		
		for(j=maxt;j>=1;j--)
		{
			for(i=0;i<=10;i++)
			{
				if(i==0)
					dp[i][j-1]=max(dp[i+1][j],dp[i][j])+v[i][j];
				else if(i==10)
					dp[i][j-1]=max(dp[i-1][j],dp[i][j])+v[i][j];
				else
					dp[i][j-1]=max(max(dp[i+1][j],dp[i][j]),dp[i-1][j])+v[i][j];
			//	cout << dp[i][j-1] << " ";
			}
			//printf("\n");
		}
		printf("%d\n",max(max(dp[5][0],dp[6][0]),dp[4][0]));
		
	}
	return 0;
}
