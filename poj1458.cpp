/*************************************************************************
    > File Name: poj1458.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月22日 星期三 16时49分26秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXC 305
using namespace std;
int dp[MAXC][MAXC];

int main()
{
	char s1[MAXC],s2[MAXC];
	while(~scanf("%s%s",s1,s2))
	{
		memset(dp,0,sizeof(dp));
		int m,n;
		int i,j;
		m=strlen(s1);
		n=strlen(s2);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				if(s1[i]==s2[j])
					dp[i+1][j+1]=dp[i][j]+1;
				else
					dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		cout << dp[m][n] << endl;
	}
	return 0;
}
