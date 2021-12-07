#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

  
// function to get a new node
Node* getNode(int data)
{
    // Allocate memory
    Node *newNode =
        (Node*)malloc(sizeof(Node));
      
    // put in the data    
    newNode->data = data;
    newNode->left = newNode->right = NULL;    
    return newNode;
}
  
Node* constructBst(int arr[], int start, int end)
{
    if(start > end) return NULL;
    int mid = (start+end)/2;
    Node* root = getNode(arr[mid]);
    root-> left = constructBst(arr,start,mid-1);
    root->right = constructBst(arr,mid+1,end);      
    return root;
}

void inorderTraversal(Node* root)
{
    if(root)
    {
        if(root->left) inorderTraversal(root->left);
        cout << root->data << " ";
        if(root->right) inorderTraversal(root->right);
    } 
}
int sum=0;
Node* solve(Node* root) {
    if(root)
    {
        if(root->right) solve(root->right);
        root->data += sum;
        sum = root->data;
        if(root->left) solve(root->left);
    }
    return root;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    Node *root = constructBst(arr,0,n-1);
    inorderTraversal(solve(root));
    cout << endl;
}