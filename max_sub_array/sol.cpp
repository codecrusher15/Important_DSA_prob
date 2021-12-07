//Lab5 max of k size subarray
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n;
    cin >> k;
    int a[n],ans[n-2];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    deque <int> dq; //queue to maintain largest element of k size subarray in the front
    for (int i = 0; i < k; i++)
    {
        while (!(dq.empty()) && (a[dq.back()]<=a[i]))   //removing elements at back if current element is greater.
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        ans[i-k] = a[dq.front()];
        if(a[i-k]==a[dq.front()]) dq.pop_front();
        while (!(dq.empty()) && (a[dq.back()]<=a[i]))   //removing elements at back if current element is greater.
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans[n-k] = a[dq.front()];
    for (int i = 0; i < n-k+1; i++)
    {
        cout<<ans[i]<<" ";
    }
    

}
//IMT2020015