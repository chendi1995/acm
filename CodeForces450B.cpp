/*************************************************************************
    > File Name: CodeForces450B.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年05月18日 星期一 19时00分12秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define mod 1000000007
typedef long long LL;
using namespace std;
typedef struct
{
	LL a[2][2];
}Matrix;

Matrix mul(Matrix A,Matrix B)
{
	int i,j,k;
	Matrix C;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			C.a[i][j]=0;
			for(k=0;k<2;k++)
				C.a[i][j]=(C.a[i][j]%mod+(A.a[i][k]%mod)*(B.a[k][j]%mod)+mod)%mod;
		}
	return C;
}

int main()
{
	LL  f1,f2;
	int n,t;
	Matrix A,ans;
	LL res;
	scanf("%lld%lld",&f1,&f2);
	scanf("%d",&n);
	f1=(f1+mod)%mod;
	f2=(f2+mod)%mod;
	A.a[0][0]=1;
	A.a[0][1]=-1;
	A.a[1][0]=1;
	A.a[1][1]=0;
	ans.a[0][0]=1;
	ans.a[0][1]=0;
	ans.a[1][0]=0;
	ans.a[1][1]=1;
	if(n>2)
	{
		t=n-2;
		while(t>0)
		{
			if(t%2==1)
				ans=mul(ans,A);
			t=t/2;
			A=mul(A,A);
		}
		res=((ans.a[0][0]*f2)%mod+(ans.a[0][1]*f1)%mod)%mod;
		printf("%lld\n",res);
	}
	else
	{
		if(n==1)
			printf("%lld\n",f1);
		else if(n==2)
			printf("%lld\n",f2);
	}
	return 0;

}
