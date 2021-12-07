//Lab 4 problem 1
#include<stdio.h>
#include<iostream>
#include<random>
#include<bits/stdc++.h>
using namespace std;
int Partition(int a[],int l,int r);
int RFindRank (int A[],int  l,int r,int  rank);
int main(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    long long ans = 0;
    int base = RFindRank( arr,0,n-1,k); //finding element corresponding to k+1 rank
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>base) {ans+=arr[i];j++;}
    }
    for (int i = j; i < k; i++) 
    {
        ans+=base;
    }
    
    
    cout << ans << endl;
    return 0;
}
int RFindRank (int A[],int  l,int r,int  rank)  //find rank algorithm
{ 
if (l < r)    
{    
    int p = rand() % (r - l + 1) + l; 
    swap(A[l],A[p]);
    int k = Partition (A, l, r);
    if (rank == r - k + 1)	return A[k];
    else if (rank < r - k + 1)	return RFindRank (A, k + 1, r, rank);
    else	return RFindRank(A,l,k-1,rank-r+k-1);
    } 
    return A[r];
}
int Partition(int a[],int l,int r)  //Partition 
{
    int j = l+1;
    for (int i = l+1; i < r+1; i++)
    {
        if(a[l]>a[i])
        {
            swap(a[i],a[j]);
            j++;
        }
    }
    int temp = a[j-1];
    a[j-1] = a[l];
    a[l] = temp;
    return j-1;
}