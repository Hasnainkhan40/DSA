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

void creatMap(int inorder[], int size, map<int,int> &valueToindexMap){
    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToindexMap[element] = index;
    }
}

//CEREATE THE TREE BY USEING PREORDER AND INORDER 
Node* preandInTree(map<int,int> &valueToindexMap, int preorder[], int inorder[],  int &preIndex, int inorderStart, int inorderEnd, int size){
    if(preIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }

    int element = preorder[preIndex];
    preIndex++;
    Node* root = new Node(element);
    int position = valueToindexMap[element];

    root->left = preandInTree(valueToindexMap, preorder, inorder, preIndex, inorderStart, position-1, size);
    root->right = preandInTree(valueToindexMap, preorder, inorder, preIndex, position+1, inorderEnd, size);

    return root;

}


//CEREATE THE TREE BY USEING POSTORDER AND INORDER 
Node* postAndInTree(map<int,int> &valueToindexMap, int postorder[], int inorder[],  int &postIndex, int inorderStart, int inorderEnd, int size){
    if(postIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }

    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);
    int position = valueToindexMap[element];

  
    root->right = postAndInTree(valueToindexMap, postorder, inorder, postIndex, position+1, inorderEnd, size);
      root->left = postAndInTree(valueToindexMap, postorder, inorder, postIndex, inorderStart, position-1, size);

    return root;

}

int main(){
    // int inorder[] = {10,8,6,2,4,12}; 
    // int preorder[] = {2,8,10,6,4,12};
    // int size = 6;
    // int preIndex = 0;
    // int inorderStart = 0;
    // int inorderEnd = size-1;
    // map<int,int> valueToindexMap;
    // creatMap(inorder, size, valueToindexMap);
    // Node*root = preandInTree(valueToindexMap, preorder, inorder, preIndex, inorderStart, inorderEnd, size);

    // cout<<"Printing Tree" << endl;

    // levelorderTbfs(root);

    int inorder[] = {8,14,6,2,10,4,}; 
    int postorder[] = {8,6,14,4,10,2};
    int size = 6;
    int postIndex = size-1;
    int inorderStart = 0;
    int inorderEnd = size-1;
    map<int,int> valueToindexMap;
    creatMap(inorder, size, valueToindexMap);
    Node*root = postAndInTree(valueToindexMap, postorder, inorder, postIndex, inorderStart, inorderEnd, size);

    cout<<"Printing Tree" << endl;

    levelorderTbfs(root);


}