//Problem 1 lab 3
#include<stdio.h>
#include<unordered_map>
#include<string.h>
#include<iostream>
using namespace std;
long long int rabin_carp(string s,int len);
int main()
{
    int n;
    scanf("%d",&n);
    string str;
    cin >> str;
    long long int count = 0;//final count
    for (int i = 0; i < n; i++)
    {
        count += rabin_carp(str,i+1);
    }
    cout << count;
}
long long int rabin_carp(string s,int len)  //function returns number of distinct substrings of length len
{
    unordered_map<long long int ,int> umap;
    long long int count = 0;
    long long int p=0,b=1;
    for (int i = 0; i < len; i++)
    {
        int temp = s[i] - 'a' +1;
        p = (p*27+temp);
        b = (b*27);
    }
    umap[p]+=1;
    for (unsigned int i = len; i < s.length(); i++)
    {
        int old = s[i-len] - 'a' + 1;
        int n = s[i] - 'a' +1;
        p = (p*27 +n - old*b );
        umap[p]++;
    }
    for(auto x:umap)
    {
        if (x.second>0)
        {
            count++;
        }
        
    }
    umap.clear();   //clearing the map
    return count;
}
//IMT2020015