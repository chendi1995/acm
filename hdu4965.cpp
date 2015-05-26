/*************************************************************************
    > File Name: hdu4965.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + g++
    > Created Time: 2015年05月22日 星期五 17时10分26秒
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
	int  a[6][6];
}Matrix;

Matrix mul(Matrix A,Matrix B,int m)
{
	int i,j,k;
	Matrix C;
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
		{
			C.a[i][j]=0;
			for(k=0;k<m;k++)
				C.a[i][j]=(C.a[i][j]%6+(A.a[i][k]%6)*(B.a[k][j]%6))%6;
		}
	return C;
}
int main()
{
	Matrix M;
	LL t;
	Matrix ans;
	int  A[1000][6];
	int  B[6][1000];
	int A1[1000][6];
	int res;
	int tmp;
	int i,j,k;
	int n,m;
	while(scanf("%d%d",&n,&m)&&!(n==0 && m==0))
	{
		memset(M.a,0,sizeof(M.a));
		memset(A1,0,sizeof(A1));
		memset(ans.a,0,sizeof(ans.a));
		res=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%d",&A[i][j]);
			}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&B[i][j]);
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				for(k=0;k<n;k++)
				{
					M.a[i][j]=(M.a[i][j]%6+(B[i][k]*A[k][j])%6)%6;
				}
		t=n*n-1;
		for(i=0;i<m;i++)
			ans.a[i][i]=1;
		while(t>0)
		{
			if(t%2==1)
				ans=mul(ans,M,m);
			t=t/2;
			M=mul(M,M,m);
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				for(k=0;k<m;k++)
				{
					A1[i][j]=(A1[i][j]%6+(A[i][k]*ans.a[k][j])%6)%6;
				}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				tmp=0;
				for(k=0;k<m;k++)
				{
					tmp=tmp+A1[i][k]*B[k][j];
				}
				res+=tmp%6;
			}
		printf("%d\n",res);
	}
	return 0;
}
