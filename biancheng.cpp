/*************************************************************************
    > File Name: biancheng.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月17日 星期五 19时26分36秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 1010
using namespace std;
int dp[MAXN][MAXN];
char s[MAXN];
int compare(int i,int j)
{
	int start,end;
	start=i;
	end=j;
	while(i<j)
	{
		if(s[i]==s[j])
		{
			i=i+1;
			j=j-1;
		}
		else
			return 0;
	}
	return 1;
}
int main()
{
	int T;
	int n;
	int k;
	int i,j;
	int count1,count2;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%s",s);
		n=strlen(s);
		for(i=1;i<n;i++)
			for(j=0;j<=i;j++)
			{
				count1=1;
				for(k=j+1;k<=i;k++)
					if(compare(j,k))
						count1++;
				count2=1;
				for(k=i-1;k>=j;k--)
					if(compare(k,i))
						count2++;
				dp[j][i]=max(dp[j+1][i]+count1,dp[j][i-1]+count2);
			}
		printf("%d\n",dp[0][n-1]);
	}
	return 0;
}
