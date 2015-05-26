/*************************************************************************
    > File Name: poj2240.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年03月31日 星期二 17时49分29秒
 ************************************************************************/
#include<iostream>

using namespace std;
map<string,int>STL;
typedef struct
{
	int a;
	int b;
	float rate;
}weight;

weight edge[]

int n,m;
int main()
{
	int i;
	int a,b;
	char str[50],str1[50],str2[50];\
	float rate;
	while(cin >> n && n!=0)
	{
		for(i=1;i<=n;i++)
		{
			cin >> str;
			STL[str]=i;
		}
		cin >> m;
		for(i=1;i<=m;i++)
		{
			cin >> str1 >> rate >> str2;
			a=STL[str1];
			b=STL[str2];

		}
	}
}
