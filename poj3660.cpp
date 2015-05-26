/*************************************************************************
    > File Name: poj3660.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月30日 星期一 21时32分47秒
 ************************************************************************/
#include<iostream>
#define MAXNODE 105
using namespace std;

int N,M;
int map[MAXNODE][MAXNODE];

void floyd()
{
	int i,j,k;
	for(k=1;k<=N;k++)
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				map[i][j]=map[i][j] ||(map[i][k] && map[k][j]);
}

int main()
{
	int i,j;
	cin >> N >> M;
	int a,b;
	int node;
	int result=0;
	for(i=1;i<=M;i++)
	{	
		cin >> a >> b;
		map[a][b]=1;
	}
	floyd();
	for(i=1;i<=N;i++)
	{
		node=0;
		for(j=1;j<=N;j++)
		{
			if(map[i][j])
				node++;
			if(map[j][i])
				node++;
		}
		if(node==N-1)
			result++;
	}
	cout << result << endl;
	return 0;
}
