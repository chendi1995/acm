/*************************************************************************
    > File Name: uva10689.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + g++
    > Created Time: 2015年05月25日 星期一 16时32分46秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<cmath>
typedef long long LL;
using namespace std;
typedef struct 
{
	int a[2][2];
}Matrix;

Matrix mul(Matrix A,Matrix B,int mod)
{
	int i,j,k;
	Matrix C;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			C.a[i][j]=0;
			for(k=0;k<2;k++)
				C.a[i][j]=(C.a[i][j]+(A.a[i][k]%mod)*(B.a[k][j]%mod))%mod;
		}
	return C;
}


int main()
{
	int T;
	scanf("%d",&T);
	int B[2][1];
	int a,b;
	int mod;
	LL n;
	LL t;
	int m;
	int res;
	while(T--)
	{
		res=0;
		scanf("%d%d%lld%d",&a,&b,&n,&m);
		mod=pow(10,m);
		Matrix A;
		Matrix ans;
		A.a[0][0]=0;
		A.a[0][1]=1;
		A.a[1][0]=1;
		A.a[1][1]=1;
		memset(ans.a,0,sizeof(ans.a));
		ans.a[0][0]=1;
		ans.a[1][1]=1;
		B[0][0]=a%mod;
		B[1][0]=b%mod;
		if(n==0)
			printf("%d\n",B[0][0]);
		else if(n==1)
			printf("%d\n",B[1][0]);
		else
		{
			t=n-1;
			while(t>0)
			{
				if(t%2==1)
					ans=mul(ans,A,mod);
				t=t/2;
				A=mul(A,A,mod);
			}
			res=((ans.a[1][0]*B[0][0])%mod+(ans.a[1][1]*B[1][0])%mod)%mod;
			printf("%d\n",res);
		}	
	}
	return 0;
}
