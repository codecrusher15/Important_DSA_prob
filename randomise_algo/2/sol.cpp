//Problem 2 lab 4
#include<bits/stdc++.h>
using namespace std;
long long int ans = 0;
void mergesort(long long int a[],long long int start,long long int end);
void merge(long long int a[],long long int start,long long int end);
int main()
{
    long long int n;
    cin >>n;
    long long int a[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(a,0,n-1);
    cout << ans<< endl;
}
void mergesort(long long int a[],long long int start,long long int end) //mergesort algo
{
    if(start<end)
    {
    long long int mid = (start+end)/2;
    mergesort(a,start,mid);
    mergesort(a,mid+1,end);
    merge(a,start,end);
    }
}
void merge(long long int a[],long long int start,long long int end)//merge algo
{
    long long int b[end - start +  1];
    long long int mid = (start+end)/2,i = start,j = mid +1,k = 0;
    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
            ans+=mid-i+1; //counting pairs
        }
    }
    while(i<mid+1)
    {
        b[k++]=a[i++];
    }
    while(j<end+1) b[k++]= a[j++];
    i = start;
    j = 0;
    while (i<=end)
    {
        a[i++] = b[j++];
    }
    
}