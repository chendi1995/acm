/*************************************************************************
    > File Name: uva10655.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + g++
    > Created Time: 2015年05月26日 星期二 19时53分55秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Matrix
{
	ll a[2][2];
	 Matrix()
	{
		memset(a,0,sizeof(a));
	}
};
typedef struct Matrix M;

Matrix mul(Matrix A,Matrix B)
{
	int i,j,k;
	Matrix C;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			C.a[i][j]=0;
			for(k=0;k<2;k++)
				C.a[i][j]+=A.a[i][k]*B.a[k][j];
		}
	return C;
}


int main()
{
	ll p,q,n;
	ll B[2][1];
	ll t;
	M ans;
	while(cin >> p >> q >>n)
	{
		/*if(p==0 && q==0)
			break;
		scanf("%lld",&n);*/
		M A;
		A.a[0][0]=p;
		A.a[0][1]=-q;
		A.a[1][0]=1;
		A.a[1][1]=0;
		B[0][0]=p;
		B[1][0]=2;
		if(n==0)
		{
			cout << 2 <<endl;
		}
		else 
		{
			memset(ans.a,0,sizeof(ans.a));
			ans.a[0][0]=1;
			ans.a[1][1]=1;
			t=n-1;
			while(t>0)
			{
				if(t%2==1)
					ans=mul(ans,A);
				t=t/2;
				A=mul(A,A);
			}
			printf("%lld\n",ans.a[0][0]*B[0][0]+ans.a[0][1]*B[1][0]);
		}
	}
	return 0;
}
