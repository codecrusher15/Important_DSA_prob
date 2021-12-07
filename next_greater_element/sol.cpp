//Lab 5 Next Greatest
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n;
    cin>>n;
    long int a[n],ans[n];
    for (long int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    stack <long int> stack;  
    for (long int i = 0; i < n; i++) //putting next greatest corresponding to each entry
    {
        while (!(stack.empty()) && a[stack.top()] < a[i] )
        {
            ans[stack.top()] = a[i];
            stack.pop();
        }
        stack.push(i);
    }
    while (!stack.empty())
    {
        ans[stack.top()] = -1;
        stack.pop();
    }
    
    for (long int i = 0; i < n; i++)
    {
        cout << ans[i]<<" ";
    }
    
}
// IMT2020015 Pushkar Pawar