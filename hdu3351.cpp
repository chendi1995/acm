/*************************************************************************
    > File Name: hdu3351.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年08月02日 星期日 21时52分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

char str[2010];

int main()
{
	int kase=0;
	int num,left;
	int i;
	while(cin >>str  && str[0]!='-')
	{
		left=0;
		num=0;
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]=='{')
				left++;
			else if(left>0)
				left--;	
			else 
			{
				num++;
				str[i]='{';
				left=1;
			}
		}
		if(left>0)
			num+=left/2;
		printf("%d. %d\n",++kase,num);
	
	}
	return 0;
}
