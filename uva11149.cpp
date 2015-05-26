/*************************************************************************
    > File Name: uva11149.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + g++
    > Created Time: 2015年05月25日 星期一 18时53分47秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define MAXN 41
using namespace std;
struct Matrix 
{
	int a[MAXN][MAXN];
	Matrix(){memset(a,0,sizeof(a));}
};
typedef struct Matrix M;
M A;
int n;

M E;

M mul(M A,M B)
{
	M C;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				C.a[i][j]=(C.a[i][j]+(A.a[i][k]*B.a[k][j])%10)%10;
	return C;
}

M add(M A,M B)
{
	M C;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			C.a[i][j]=(A.a[i][j]+B.a[i][j])%10;
	return C;
}

M powermod(M A,int k)
{
	M ans;
	for(int i=0;i<n;i++)
		ans.a[i][i]=1;
	while(k>0)
	{			
		if(k%2==1)
			ans=mul(ans,A);
		k=k/2;
		A=mul(A,A);
	}
	return ans;
}

M cal(int k)
{
	if(k==1)
		return A;
	else if(k&1)
	{
		return add(mul(cal(k/2),add(E,powermod(A,k/2))),powermod(A,k));
	}
	else 
	{

		return mul(cal(k/2),add(E,powermod(A,k/2)));
	}
}

int main()
{
	int i,j;
	int k;
	M res;
	while(scanf("%d%d",&n,&k)&&n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&A.a[i][j]);
				A.a[i][j]=A.a[i][j]%10;
			}
		for(i=0;i<n;i++)
			E.a[i][i]=1;
		res=cal(k);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j<n-1)
					printf("%d ",res.a[i][j]);
				else
					printf("%d",res.a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
