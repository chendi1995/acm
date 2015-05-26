/*************************************************************************
    > File Name: hdu2859.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月25日 星期六 16时41分32秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 1005
using namespace std;
char a[MAXN][MAXN];
int dp[MAXN][MAXN];
int n;
int main()
{
	int i,j;
	int ti,tj;
	int ans;
	while(cin >> n && n)
	{	
		ans=1;
		for(i=0;i<n;i++)
				scanf("%s",a[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				dp[i][j]=1;
				if(!(i==0 ||j==n-1))
				{
					ti=i;
					tj=j;
					while(ti>=0 && tj<n && a[ti][j]==a[i][tj])
					{
						ti--;
						tj++;
					}
					ti=i-ti;
					if(ti<=dp[i-1][j+1])
						dp[i][j]=ti;
					else
						dp[i][j]=dp[i-1][j+1]+1;
				}
				ans=max(ans,dp[i][j]);
			}
		printf("%d\n",ans);
	}
	return 0;
}
