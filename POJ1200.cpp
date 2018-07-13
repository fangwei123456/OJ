//http://poj.org/problem?id=1200
//比较有意思的哈希
#include <iostream>
#include <map>
using namespace std;

int n,nc,result;
char s[16000005];

int a[128];
char b[16000005];
int main() 
{
	//freopen("in.txt", "r", stdin);   
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d %s",&n,&nc,&s)!=EOF)
	{
		result = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));

		int num = 1;
		for(int i=0; ; i++)
		{
			if(s[i]=='\0' || num==nc)
				break;
			if(a[s[i]]==0)
			{
				a[s[i]] = num;
				num++;
			}
		}

		int last = 0;
		for(int j=0; j<n-1; j++)
		{
			last = (last + a[s[j]])*nc;
		}
		last = last + a[s[n-1]];
		if(b[last]==0)
		{
			b[last] = 1;
			result++;
		}

		int maxB = 1;
		for(int i=0; i<n; i++)
			maxB = maxB * nc;
		for(int i=1; ; i++)
		{//s[i] s[i+1] ... s[i+n-1]
			if(s[i+n-1]=='\0')
				break;
			last = last*nc + a[s[i+n-1]] - a[s[i-1]] * maxB;
			if(b[last]==0)
			{
				b[last] = 1;
				result++;
			}

		}
		printf("%d\n",result);



	}
	return 0;

}


