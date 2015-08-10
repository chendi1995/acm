/*************************************************************************
    > File Name: hdu2577.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年08月02日 星期日 19时49分56秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define MAXN 105

using namespace std;
int dp[MAXN][2];
int main()
{
	int T,i;
	char str[MAXN];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		if(str[0]>='a' && str[0]<='z')
		{
			dp[0][0]=1;
			dp[0][1]=2;
		}
		if(str[0]>='A' && str[0]<='Z' )
		{
			dp[0][0]=2;
			dp[0][1]=2;
		}
		for(i=1;i<strlen(str);i++)
		{
			if(str[i]>='a' && str[i]<='z' && str[i-1]>='a' && str[i-1]<='z')
			{
				dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+2);
			}
			if(str[i]>='A' && str[i]<='Z' && str[i-1]>='A' && str[i-1]<='Z')
			{
				dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+1);
			}
			if(str[i]>='a' && str[i]<='z' && str[i-1]>='A' && str[i-1]<='Z')
			{
				dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+2);
			}
			if ( str[i]>='A' && str[i]<='Z' && str[i-1]>='a' && str[i-1]<='z')
			{
				dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+1);
			}
		}
		printf("%d\n",min(dp[i-1][0],dp[i-1][1]+1));
	}
	return 0;
}
