/*************************************************************************
    > File Name: zoj1610~.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年05月15日 星期五 17时16分07秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 8005
int color[MAXN];
int cnt[MAXN];

int main()
{
	int n;
	int i;
	int j;
	int a,b,c;
	while(~scanf("%d",&n))
	{
		memset(color,-1,sizeof(color));
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			for(j=a+1;j<=b;j++)
				color[j]=c;
		}
		for(i=1;i<MAXN;i++)
			if(color[i]!=color[i-1]&&color[i]>-1)
				cnt[color[i]]++;
		for(i=0;i<MAXN;i++)
			if(cnt[i]>0)
				printf("%d%d\n",i,cnt[i]);
		printf("\n");
	}
	return 0;
}
