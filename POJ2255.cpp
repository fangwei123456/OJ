//http://poj.org/problem?id=2255
//POJ2255，二叉树重构，网上代码太麻烦，本代码too simple
#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;
char s1[40],s2[40];
int finder, n1, n2;
pair<int,int> node[40];

void restruct(int left, int right, int parent, bool isLeft)//均为s2中的下标
{
	for(int i=left; i<=right; i++)
	{
		if(s2[i]==s1[finder])
		{
			if(isLeft)
				node[parent].first = i;
			else
				node[parent].second = i;

			finder++;
			if(finder==n1)
				return;

			restruct(left,i-1,i,true);
			restruct(i+1,right,i,false);

		}
	}
}

void printfNode(int cur)//后序遍历
{
	
	if(cur<0 || cur>=n2)
		return;
	printfNode(node[cur].first);
	printfNode(node[cur].second);
	cout<<s2[cur];

}
int main() {
	//freopen("in.txt", "r", stdin);   
	//freopen("out.txt", "w", stdout);
    while(cin>>s1>>s2)
    {
		n1 = strlen(s1);
		n2 = strlen(s2);
		finder = 0;
		//node初始化
		for(int i=0; i<n2; i++)
		{
			node[i].first = -1;
			node[i].second = -1;
		}
		int root;
		for(int i=0; i<n2; i++)
		{
			if(s2[i]==s1[0])
			{
				finder++;
				restruct(0,i-1,i,true);
				restruct(i+1,n2-1,i,false);
				root = i;
				break;
			}

		}
		printfNode(root);
		cout<<endl;
    }
    return 0;
}

