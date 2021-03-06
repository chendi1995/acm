/*************************************************************************
    > File Name: hdu1213.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月01日 星期三 19时58分26秒
 ************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int pre[1010];
int visited[1010];
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
int main()
{
	int T;
	int i,j;
	int n,m;
	int a,b;
	int sum;
	int p;
	cin >>T;
	for(i=1;i<=T;i++)
	{
		memset(pre,0,sizeof(pre));
		memset(visited,0,sizeof(visited));
		sum=0;
		cin >> n >> m;
		for(j=1;j<=n;j++)
			pre[j]=j;
		for(j=1;j<=m;j++)
		{
			cin >> a >> b;
			join(a,b);
		}
		for(j=1;j<=n;j++)
		{
			p=find(j);
			if(!visited[p])
			{
				visited[p]=1;
				sum++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
