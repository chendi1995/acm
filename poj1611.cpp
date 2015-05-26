/*************************************************************************
    > File Name: poj1611.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月01日 星期三 17时15分27秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
using namespace std;

int pre[30010];

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

int  judge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
		return 1;	
	else
		return 0;
}
int main()
{
	int n,m;
	int i,j;
	int k;
	int a,b;
	int sum;
	while(scanf("%d%d",&n,&m) && !(n==0 && m==0))
	{
		sum=0;
		for(i=0;i<n;i++)
			pre[i]=i;
		for(i=1;i<=m;i++)
		{
			cin >> k;
			cin >> b;
			for(j=2;j<=k;j++)
			{
				cin >>a;
				join(a,b);
			}
		}
		for(i=0;i<n;i++)
			if(judge(0,i))
				sum++;
		cout << sum << endl;
	}
}
