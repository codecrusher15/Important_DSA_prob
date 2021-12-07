//lab 12 P2
#include<bits/stdc++.h>
using namespace std;
int get(int x,int w[])
{

	if (x == w[x]) return x;
	return w[x] = get(w[x],w);
}

void merge (int a, int b,int w[])
{  	
	w[a] = b;
}

int main ()
{
	int n,m;
      	cin >> n >> m;
	vector <pair<int,int>> v;
	int A[200001],B[200001],C[200001],D[200001];
      	v.clear ();
      	for (int i = 1; i <= m; i++)
	{
	  	cin >> A[i] >> B[i] >> C[i];
	  	v.push_back (make_pair (C[i], i));
	}
      	sort (v.begin (), v.end ());
      	reverse (v.begin (), v.end ());

      	for (int i = 1; i <= n; i++)	D[i] = i;
	long long int	ans = 0;
      	for (int i = 0; i < v.size (); i++)
	{
		int temp = v[i].second;
		int q, w;
	  	q = A[temp];
	  	w = B[temp];
		q = get(q,D);
		w = get(w,D);

	  	if (q != w)
		{
			ans += C[temp];
			merge(q, w,D);
	    	}

	}

      	cout << ans << endl;

    }
