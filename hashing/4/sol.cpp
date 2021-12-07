#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


int has_pal_substr(string s, int len)/* returns 1 if there is a palindromic substring of length len in s, otherwise 0*/
{
    string sp = s;
    reverse(sp.begin(), sp.end());
    unordered_map<long long int ,int> umap;
    long long int count = 0;
    long long int p=0,b=1;
    //Rabin karp on s
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
    p = 0,b = 1;
    // Rabin karp on reverse of s
    for (int i = 0; i < len; i++)
    {
        int temp = sp[i] - 'a' +1;
        p = (p*27+temp);
        b = (b*27);
    }
    if(umap[p]) return 1;
    for (unsigned int i = len; i < s.length(); i++)
    {
        int old = sp[i-len] - 'a' + 1;
        int n = sp[i] - 'a' +1;
        p = (p*27 +n - old*b );
        if(umap[p]) return 1;
    }
    return 0;
}
    

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s ;
    int odd_len[(n+1)/2], even_len[n/2]; // odd_len stores odd nos. till n. even_len stores even nos. till n.
    for(int i=2;i<=n;i+=2){
        even_len[i/2-1] = i;
    }
    for(int i=1;i<=n;i+=2){
        odd_len[i/2] = i;
    }
    // binary search code for odd_len array
    int start = 0, end = (n+1)/2 -1;
    int ans_odd = 0;
    while(start <= end){
        int mid = (start + end)/2;
        int len = odd_len[mid];
        if(has_pal_substr(s,len)) {
            ans_odd = len;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    // write binary search code for even_len array
    start = 0, end = n/2 -1;
    int ans_even = 0;
    while (start<=end)
    {
        int mid = (start + end)/2;
        int len = even_len[mid];
        if(has_pal_substr(s,len))
        {
            ans_even = len;
            start = mid+1;
        }
        else end = mid -1;
    }
    
    /* TO DO */
    int ans = max(ans_odd,ans_even);
    cout << ans << endl;
    return 0;
}
