/*************************************************************************
    > File Name: hdu5015.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年05月19日 星期二 10时34分07秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
typedef long long LL;
#define mod 10000007
using namespace std;
typedef struct 
{
	LL a[12][12];
}Matrix;

Matrix mul(Matrix A,Matrix B,int n)
{
	int i,j,k;
	Matrix C;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		{
			C.a[i][j]=0;
			for(k=0;k<=n;k++)
				C.a[i][j]=(C.a[i][j]%mod+(A.a[i][k]%mod)*(B.a[k][j]%mod))%mod;
		}
	return C;
}
int main()
{
	int n,m;
	int i,j,t;
	LL B[15][1];
	Matrix ans;
	Matrix A;
	LL res;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		res=0;
		memset(A.a,0,sizeof(A.a));
		memset(ans.a,0,sizeof(ans.a));
		memset(B,0,sizeof(B));
		B[0][0]=23;
		B[n+1][0]=3;
		for(i=1;i<=n;i++)
			scanf("%lld",&B[i][0]);
		for(i=0;i<=n;i++)
		{
			A.a[i][0]=10;
			A.a[i][n+1]=1;
			//A.a[n+1][i]=0;
		}
		A.a[n+1][n+1]=1;
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				A.a[i][j]=1;
		for(i=0;i<=n+1;i++)
			ans.a[i][i]=1;
		t=m;
		while(m>0)
		{
			if(m%2==1)
				ans=mul(ans,A,n+1);
			m=m/2;
			A=mul(A,A,n+1);
		}
		for(i=0;i<=n+1;i++)
			res=(res+ans.a[n][i]*B[i][0])%mod;
		printf("%lld\n",res);
	}
	return 0;
}
