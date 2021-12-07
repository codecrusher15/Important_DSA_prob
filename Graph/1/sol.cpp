#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<int> adj[],int u,int v) //add edge to non directed graph
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int n,m,u,start;
	cin >>n >> m;
	vector<int> adj_list[200001]; //graph
	queue <int> q,q1;
	int A[m][2];
	for (int i = 0; i < m; i++) //taking edge input 
	{
		cin >> A[i][0];
		cin >> A[i][1];
		q1.push(A[i][0]);
		q1.push(A[i][1]);
	}
	for (int i = 0; i < m; i++) //loading edges in adjency list
	{
		add_edge(adj_list,A[i][0],A[i][1]);
	}
	
	int L[200001];
	for (int i = 0; i < 200001; i++)
	{
		L[i] = -1;
	}
	start = A[0][0];
	L[start] = 0;
	while(!q1.empty())
	{
		if(L[q1.front()] == -1)
		{
			q.push(q1.front());
			q1.pop();
			
		}
		else
		{
			while(L[q1.front()] != -1) q1.pop();
		}
		while(!q.empty())
		{
			u = q.front();
			q.pop();
			for(auto v:adj_list[u])
			{
				if(L[v]<0)
				{
					q.push(v);
					L[v] = L[u] + 1; //level in graph
				}
			}
		}

	}
	int flag = 1; //flag is set to 0 is not bipartate
	q.push(start);
	for (int i = 0; i < m; i++)
	{
		if(A[i][0] == A[i][1]){ flag = 0;}
		if(L[A[i][0]]%2 == L[A[i][1]]){ flag = 0;} //condition for a graph to be not bipartate
	}
	if(flag == 1 ) cout << "YES";
	else cout <<"NO";
}