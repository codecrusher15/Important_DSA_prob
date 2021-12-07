#include<bits/stdc++.h>
using namespace std;

struct Hashing
{
        unordered_map<int,int> hashmap;
        // Used to insert a value with key.
        void insert(int key, int val)
        {
                hashmap[key]=val;
        }
    // Used ro delete key from hash table.
        void delete_key(int key)
        {
                if(hashmap.count(key))
                        hashmap.erase(key);
        }
    // used to get value using key. Returns 0 if key not present. 
        int get_val(int key)
        {
                return hashmap[key];
        }
};

int solve(int n,int arr[], int k){
    struct Hashing h;
    int curr = 0,count = 0;
    for (int i = 0; i < n; i++)
    {
        curr+= arr[i];  //current sum
        if(k==curr) count++;
        count+=h.get_val(curr-k);
        h.insert(curr,h.get_val(curr)+1);
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << solve(n,arr,k) << endl;
}
