#include<bits/stdc++.h>
using namespace std;

struct Hashing
{
        unordered_map<int,int> hashmap;
        void init()
        {
                hashmap.clear();
        }
        void update(int key, int newval)
        {
                hashmap[key]=newval;
        }
        void delete_key(int key)
        {
                if(hashmap.count(key))
                        hashmap.erase(key);
        }
        int get_val(int key)
        {
                return hashmap[key];
        }
};
/*
 * use Hashing struct provided above as blackbox in case you don't know C++ STL.
 * 
 * init() -> clears the hashmap.
 * update(key,newval) -> updates the value mapped by key to the new value.
 * delete_key(int key) -> deletes the key if present in hashmap.
 * get_val(int key) -> retrieves the value mapped by key.
 * 
 * Time complexity of all the operations mentioned above are O(1)
 * 
 * 
*/

/*
 * The code required to be written does not need any knowledge of C++.
 * So, C code using the Hashing struct as blackbox will work fine.
 * 
*/


int main()
{
    struct Hashing h;
    h.init();
    long long int n,ans = 0;
    scanf("%lld",&n);
    for (long long int i = 0; i < n; i++)
    {
        long long int x,y;
        scanf("%lld %lld",&x,&y);
        h.update(y-x,h.get_val(y-x)+1);
        long long int temp = h.get_val(y-x);
        if(temp)
        {
            ans += temp*(temp-1)/2 - (temp-1)*(temp-2)/2;
        }
    }
    printf("%lld",ans);

}
