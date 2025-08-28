#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* createTree(){
    cout<<"enter the value:  " << endl;
    int data;
    cin>> data;
    if (data == -1)
    {
        return NULL;
    }

    Node* root = new Node(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}


//LEVEL ORDER TREVERSEL(BFS)
void levelorderTbfs(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            cout<< endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else
        { 
            cout<< front->data<< " "; 
            if (front->left != nullptr)
            {
               q.push(front->left);
            }
             if (front->right != nullptr)
            {
               q.push(front->right);
            }
            
        }
        
    }
    
}

int getKthSmllest(int arr[], int n, int k){
    priority_queue<int> pq;

    
    for(int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }


    for(int i = k; i < n; i++)
    {
        int element = arr[i];
        if(element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
    
}
int getKthGretest(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    
    for(int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }


    for(int i = k; i < n; i++)
    {
        int element = arr[i];
        if(element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
    
}


//YOU HAVE THE CBT+BST CONVORT INOT MAX HEAP
void convertInorderT(Node* root, vector<int> &inorder){
    if(root == NULL) return;

    //LNR
    convertInorderT(root->left, inorder);
    inorder.push_back(root->data);
    convertInorderT(root->right, inorder);

}
void converotPostorderT(Node* root, vector<int> &inorder, int &index){
    if(root == NULL) return;

    //LNR
    converotPostorderT(root->left, inorder, index);
    converotPostorderT(root->right, inorder, index);
    root->data = inorder[index];
    index++;

}

Node* converotIMaxHeap(Node* root){
    vector<int> inorder;
    convertInorderT(root, inorder);

    int index = 0;
    converotPostorderT(root, inorder, index);
    return root;

}


int main(){
    Node* root = NULL;
    //root = converotIMaxHeap(root);
    cout<<"jkhsdfnklndsvkln"<<endl;
    //levelorderTbfs(root);
    // int arr[] = {5, 10, 15, 20, 25, 12};
    // int n = 6;
    // int k=4;
    // cout<< "Kth smallest element  "<< getKthSmllest(arr, n, k) << endl;
    // cout<< "Kth smallest element  "<< getKthGretest(arr, n, k) << endl;
}