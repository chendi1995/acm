/*************************************************************************
    > File Name: hdu1978.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年08月03日 星期一 21时25分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
int dp[105][105];
int a[105][105];
int main()
{
	int m,n;
	int x,y;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		dp[m][n]=1;
		for(i=m;i>=1;i--)
			for(j=n;j>=1;j--)
			{
				for(x=0;;x++)
					for(y=0;;y++)
					{

					}
			}
	}
}
