/*************************************************************************
    > File Name: hdu1087.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月14日 星期二 20时07分31秒
 ************************************************************************/
#include<iostream>
#include<string.h>
#define MAXSIZE 1010
#define INF 0x3f3f3f3f
using namespace std;
int a[MAXSIZE];
int dp[MAXSIZE];

int Max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int i,j;
	int max;
	int n;
	while(cin>>n && n!=0)
	{
		for(i=0;i<n;i++)
			cin >> a[i];
		dp[0]=a[0];
		max=a[0];
		for(i=1;i<n;i++)
		{
			dp[i]=a[i];
			for(j=0;j<i;j++)
			{
				if(a[i]>a[j])
					dp[i]=Max(dp[i],dp[j]+a[i]);
			}
			max=Max(max,dp[i]);
		}
		cout << max << endl;
	}
	return 0;
}

