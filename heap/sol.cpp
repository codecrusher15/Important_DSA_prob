#include<bits/stdc++.h>
using namespace std;
void top_down_heapify(int h[],int n,int i)
{
    while ((2*i+2) < n)
    {
        int max = (2*i+2);
        if(h[max]<h[2*i+1]) max = 2*i+1;
        if(h[i]<h[max])
        {
            int temp = h[i];
            h[i] = h[max];
            h[max] = temp;
            i = max;
        }
        else i=n;
    }
    if(2*i+1<n)
    {
        if(h[2*i+1]>h[i])
        {
            int temp = h[i];
            h[i] = h[2*i+1];
            h[2*i+1] = temp;
        }
    }
}
void bottom_up_heapify(int h[],int i)
{
    int p = (i-1)/2;
    while(p>-1)
    {
        if(h[p]<h[i])
        {
          int temp = h[p];
          h[p] = h[i];
          h[i] = temp;
          i = p;
          p = (i-1)/2;
        }
        else p = -1;
    }
}
void insert(int h[],int *n,int val)
{
    h[*n] = val;
    *n = *n+1;
    bottom_up_heapify(h,*n-1);
}
int del_max_from_heap(int h[],int *n)
{
    int temp = h[0];
    h[0] = h[*n-1];
    *n = *n-1;
    top_down_heapify(h,*n,0);
    return temp;
}
int main()
{
    int n,L,P;
    cin >>n;
    int shop[n],drug[n];
    for (int i = 0; i < n; i++)
    {
        cin >> drug[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> shop[i];
    }
    cin >> L;
    cin >> P;
    int max_heap[n],reach = P,t_n=0,ans = 0;
    while (reach<L)
    {
        for (int i = 0; i < n; i++)
        {
            if((L-shop[i])<=reach && shop[i]>=0)
            {
                insert(max_heap,&t_n,drug[i]);
                shop[i] = -1;
            }
        }
        if(t_n <= 0)
        {
            cout << "-1";
            return 0;
        }
        ans++;
        reach += del_max_from_heap(max_heap,&t_n);
    }
    cout << ans;
}