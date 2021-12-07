// Problem lab 11
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll unique_bst(ll t,ll arr[]);
int main()
{
	ll arr[100009],n,t; //arr to store results
	cin >> n;
	for (ll i = 0; i < 100009; i++)
	{
		arr[i] = -1;
	}
	arr[0] = 1;
	arr[1] = 1;
	for (ll i = 0; i < n; i++)
	{
		cin>>t;
		cout<< unique_bst(t,arr) << endl;
	}
}
ll unique_bst(ll t,ll arr[])
{
	if(arr[t] == -1)
	{
		arr[t] = 0;
		for (ll i = 1; i <= t; i++)
		{
			arr[t]+=((unique_bst(i-1,arr)%1000000007)*(unique_bst(t-i,arr)%1000000007))%1000000007;
			if(arr[t]<0) arr[t] += 1000000007;
		}
		arr[t] = arr[t]%1000000007;
		return arr[t];
	}
	return arr[t];
}