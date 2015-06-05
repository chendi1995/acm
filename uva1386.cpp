/*************************************************************************
    > File Name: uva1386.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + g++
    > Created Time: 2015年05月28日 星期四 17时28分51秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 501
using namespace std;

typedef long long LL;
LL n,m,d,k;
LL R[MAXN];
LL A[MAXN];
LL ans[MAXN];
LL res[MAXN];

void mul(LL A[],LL B[])
{
	LL C[MAXN];
	memset(C,0,sizeof(C));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			C[i]=(C[i]+A[j]*B[(i-j+n)%n])%m;
		}
	memcpy(A,C,sizeof(C));
}

int main()
{
	LL i,j;
	while(scanf("%lld%lld%lld%lld",&n,&m,&d,&k)!=EOF)
	{	
		memset(R,0,sizeof(R));
		memset(A,0,sizeof(A));
		memset(ans,0,sizeof(ans));
		memset(res,0,sizeof(res));
		for(i=0;i<n;i++)
			scanf("%lld",&R[i]);
		for(i=0;i<=d;i++)
		{
			A[(i+n)%n]=1;
			A[(-i+n)%n]=1;
		}
		ans[0]=1;
		while(k>0)
		{
			if(k%2==1)
				mul(ans,A);
			k=k/2;
			mul(A,A);
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				res[i]=(res[i]+ans[j]*R[(i-j+n)%n])%m;
			}
		for(i=0;i<n;i++)
		{	
			if(i<n-1)
				printf("%lld ",res[i]);
			else
				printf("%lld\n",res[i]);
		}
	}
		return 0;
}
