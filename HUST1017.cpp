/*************************************************************************
    > File Name: HUST1017.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月18日 星期三 16时29分38秒
 ************************************************************************/
#include<iostream>
#define MAXSIZE 1000000
#define MAXM 10000
#define MAXN 10000

int U[MAXSIZE],D[MAXSIZE],L[MAXSIZE],R[MAXSIZE],Row[MAXSIZE],Col[MAXSIZE];
int H[MAXM],S[MAXN];
int m,n;
int size;

void init()
{
	int i;
	for(i=0;i<=m;i++)
	{
		S[i]=0;
		U[i]=D[i]=i;
		L[i]=i-1;
		R[i]=i+1;
	}
	R[m]=0;
	L[0]=m;
	for(i=1;i<=n;i++)
		H[i]=-1;
}

void link(int r,int c)
{
	size++;
	Col[size]=c;
	++S[c];
	Row[size]=r;
	D[size]=D[c];
	U[D[c]]=size;
	U[size]=c;
	D[c]=size;
	if(H[r]<0)
		H[r]=L[size]=R[size]=size;
	else
	{
		R[size]=R[H[r]];
		L[R[H[r]]]=size;
		L[size]=H[r];
		R[H[r]]=size;
	}

}

void remove(int c)
{
	int i,j;
	L[R[c]]=L[c];
	R[L[c]]=R[c];
	for(i=D[c];i!=c;i=D[i])
		for(j=R[i];j!=i;j=R[j])
		{
			U[D[j]]=U[j];
			D[U[j]]=D[j];
			--S[Col[j]];
		}

}

void resume(int c)
{
	int i,j;
	for(i=U[c];i!=c;i=U[i])
		for(j=L[i];j!=i;j=L[j])
			++S[Col[U[D[j]]]]
}

int main()
{
	while(scanf("%d%d",&m,&n))
	{
		init();
	}
}
