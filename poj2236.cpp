/*************************************************************************
    > File Name: poj2236.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月31日 星期二 20时23分33秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXNODE 1500

int pre[MAXNODE];
int x[MAXNODE],y[MAXNODE];
int repair[MAXNODE];

int dis(int i,int j)
{
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

int find(int x) 
{ 
    int r=x;
    while(pre[r]!=r)
		r=pre[r];
    int i=x,j;
    while(i!=r)
    {
		j=pre[i]; 
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)                                                
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        pre[fx]=fy;
}

void judge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
		cout << "SUCCESS" <<endl;
	else
		cout << "FAIL" << endl;
}
int main()
{
	int N,d;
	int i;
	char ch;
	int a,b;
	cin >> N >> d;
	for(i=1;i<=N;i++)
		cin >> x[i] >> y[i];
	while(~scanf("%c",&ch))
	{
		if(ch=='O')
		{
			scanf("%d",&a);
			repair[a]=1;
			pre[a]=a;
			for(i=1;i<=N;i++)
				if(repair[i] && a!=i && dis(a,i)<=d*d)
					join(a,i);
		}
		if(ch=='S')
		{
			scanf("%d%d",&a,&b);
			judge(a,b);
		}
	}
	return 0;
}
