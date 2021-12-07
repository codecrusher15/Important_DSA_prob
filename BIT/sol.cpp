//Lab 8 problem 1
#include<bits/stdc++.h>
using namespace std;
void update_BIT(int query,int BIT[]) //updates rank after insertion of element
{
	while(query < 1000000)
	{
		BIT[query]++;
		query += query & (-query);
	}
}
int prefix_sum(int i,int BIT[]) //finds rank of el i
{
	int sum = 0; 
	while (i>0)
	{
		sum += BIT[i];

		i -= i & (-i);
	}
	return sum;
}
int find_qrank_BIT(int query,int BIT[]) //finds element having rank query
{
	int start = 1,end = 999999,mid;
	while (start<=end)	//Binary search
	{
		mid = (start+end)/2;
		int a = prefix_sum(mid,BIT),b = prefix_sum(mid-1,BIT);
		if(a == query && b != query) return mid;
		else if(a>query || (a == query && b == query)) end = mid -1;
		else if(a<query) start = mid +1; 
	}
	return 0;

}
void del_query_BIT(int query,int BIT[]) //updates rank when element is reduced
{
	while(query < 1000000)
	{
		if(BIT[query]==0) break;
		BIT[query]--;
		query += query & (-query);
	}
}
int operations_on_BIT(int type,int query,int BIT[]) //cases of operation on BIT
{
	switch (type)
	{
	case 0:
		update_BIT(query,BIT);
		return -1;
		break;
	case 1:
		return find_qrank_BIT(query,BIT);
		break;
	case 2:
		del_query_BIT(query,BIT);
		return -1;
		break;
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	int type,query,ans=0;
	int BIT[1000000];
	for (int i = 0; i < 999999; i++)
	{
		BIT[i] = 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> type ;
		cin >> query;
		ans = operations_on_BIT(type,query,BIT);
		if(type == 1) cout << ans << endl;
	}
	
}