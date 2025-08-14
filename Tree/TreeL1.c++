#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>

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

void preorder(Node* root){
    //basecase
    if(root == nullptr){
        return;
    }
    //N
    cout << root->data << " ";
    //L
     preorder(root->left);
    //R
    preorder(root->right);

}

void inorder(Node* root){
    //basecase
    if(root == nullptr){
        return;
    }
    
    //L
     inorder(root->left);
    //N
    cout << root->data << " ";
    //R
    inorder(root->right);

}

void postorder(Node* root){
    //basecase
    if(root == nullptr){
        return;
    }
    
    //L
    postorder(root->left);
    //R
    postorder(root->right);
    //N
    cout << root->data << " ";
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

int main(){
    Node* root = createTree();

    cout<< "Printing Preorder: ";
    preorder(root);
    cout<< endl;

    cout<< "Printing inorder: ";
    inorder(root);
    cout<< endl;

    cout<< "Printing Postorder: ";
    postorder(root);
    cout<< endl;

    cout<< "Printing Level trevelsel bfs: ";
    levelorderTbfs(root);
    cout<< endl;
    return 0;
}