/*************************************************************************
    > File Name: hdu1029.cpp
    > Author: chendi
    > Mail: chendi1995@sohu.com 
    > The compiler environment:vim + gcc
    > Created Time: 2015年04月11日 星期六 19时14分05秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int cnt[1000005];
int a[1000005];
int main()
{
	int N;
	int i;
	while(~scanf("%d",&N))
	{
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		for(i=1;i<=N;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		for(i=1;i<=N;i++)
		{
			if(cnt[a[i]]>=(N+1)/2)
			{
				printf("%d\n",a[i]);
				break;
			}
		}
	}
	return 0;
}
