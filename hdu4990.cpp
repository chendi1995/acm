/*************************************************************************
    > File Name: hdu4990.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + g++
    > Created Time: 2015年05月21日 星期四 20时53分23秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

typedef struct
{
	LL a[3][3];	
}Matrix;

Matrix mul(Matrix A,Matrix B,LL mod)
{
	int i,j,k;
	Matrix C;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			C.a[i][j]=0;
			for(k=0;k<3;k++)
				C.a[i][j]=(C.a[i][j]%mod+(A.a[i][k]%mod)*(B.a[k][j]%mod))%mod;
		}
	return C;
}
int main()
{
	int i;
	LL t;
	LL m;
	LL n;
	LL B[3][1];
	Matrix A;
	Matrix ans;
	while(scanf("%lld%lld",&n,&m)!=EOF)
	{
		memset(A.a,0,sizeof(A.a));
		memset(B,0,sizeof(B));
		A.a[0][1]=2;
		A.a[0][2]=1;
		A.a[1][0]=2;
		A.a[2][2]=1;
		B[0][0]=1;
		B[2][0]=1;
	/*	if(n==1)
		{
			printf("1\n");
			continue;
		}
		else if(n>1)
		{*/
			memset(ans.a,0,sizeof(ans.a));
			for(i=0;i<3;i++)
				ans.a[i][i]=1;
			t=n-1;
			while(t>0)
			{
				if(t%2==1)
					ans=mul(ans,A,m);
				t=t/2;
				A=mul(A,A,m);
			}
			if(n%2==0)
				printf("%lld\n",((ans.a[1][0]*B[0][0])%m+(ans.a[1][1]*B[1][0])%m+(ans.a[1][2]*B[2][0])%m)%m);
			else if(n%2==1)
				printf("%lld\n",((ans.a[0][0]*B[0][0])%m+(ans.a[0][1]*B[1][0])%m+(ans.a[0][2]*B[2][0])%m)%m);
		//}
	}
	return 0;
}
