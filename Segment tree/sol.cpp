//Lab9 problem 2
#include<bits/stdc++.h>
using namespace std;
typedef   long long int ll;
struct node
{
	ll max;
	ll sum;
};
ll find_max(struct node ST[],ll ss,ll se,ll l,ll r,ll index);
void build_ST(struct node ST[],ll arr[],ll size);
ll find_sum(struct node ST[],ll ss,ll se,ll l,ll r,ll index);
int main()
{
	ll n,n_q,size=1;
	cin>>n;
	cin >> n_q;
	while(size<n) size = size*2;
	ll arr[size];
	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (ll i = n; i < size; i++) //creating array of size which is  power of 2
	{
		arr[i] = 0;
	}
	struct node ST[2*size-1];
	build_ST(ST,arr,size);
	ll l,r;
	for (ll i = 0; i < n_q; i++) //answering each query
	{
		cin>>l;
		cin>>r;
		cout<<(r-l+1)*find_max(ST,0,size-1,l-1,r-1,0)-find_sum(ST,0,size-1,l-1,r-1,0) << endl;
	}
	
}
ll find_sum(struct node ST[],ll ss,ll se,ll l,ll r,ll index) //used to find range sum query
{
	if(l<=r)
	{
		if(l<= ss && se <= r) return ST[index].sum;
		else if(se <l || r<ss) return 0;
		else
		{
			ll mid = (se+ss)/2;
			  ll r_sum = find_sum(ST,mid+1,se,l,r,2*index+2);
			  ll l_sum = find_sum(ST,ss,mid,l,r,2*index+1);
			return r_sum+l_sum;
		}
	}else return 0;
}
ll find_max(struct node ST[],ll ss,ll se,ll l,ll r,ll index) //used to range max query
{
	if(l<=r)
	{
		if(l<=ss && se<=r) return ST[index].max;
		else if(se <l || r<ss) return 0;
		else
		{
			ll mid = (ss+se)/2;
			ll r_max = find_max(ST,mid+1,se,l,r,2*index+2);
			ll l_max = find_max(ST,ss,mid,l,r,2*index+1);
			return max(r_max,l_max);
		}
	}else return -1;
}
void build_ST(struct node ST[],ll arr[],ll size) //func to build seg tree
{
	for (ll i = size -1; i < 2*size-1; i++)
	{
		ST[i].max = arr[i-(size-1)];
		ST[i].sum = arr[i-(size-1)];
	}
	for (ll i = size-2; i >=0; i--)
	{
		ST[i].max = max(ST[2*i+1].max,ST[2*i+2].max);
		ST[i].sum = ST[2*i+1].sum + ST[2*i+2].sum;
	}
}