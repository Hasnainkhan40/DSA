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

//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
void printTopView(Node* root){
    map<int,int> hdToNodemap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
       
        Node* frontNode  = temp.first;
        int hd = temp.second;

        if(hdToNodemap.find(hd) == hdToNodemap.end()){
            hdToNodemap[hd] = frontNode->data;
        }

        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd-1));
        }

          if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd+1));
        }
        
    }
    cout<< "Printing Tree " << endl;
    for(auto i : hdToNodemap){
        cout<< i.second <<" ";
    }
    
}



//PRINT THE BOTTOM VIEW 
void printBottomView(Node* root){
    map<int,int> hdToNodemap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
       
        Node* frontNode  = temp.first;
        int hd = temp.second;

       
            hdToNodemap[hd] = frontNode->data;
        

        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd-1));
        }

          if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd+1));
        }
        
    }
    cout<< "Printing Tree " << endl;
    for(auto i : hdToNodemap){
        cout<< i.second <<" ";
    }
    
}

//PRINT LEFT VIEW
void printLeftView(Node* root, int level, vector<int> &leftViwe){
    if(root == NULL){
        return;
    }

    if (level == leftViwe.size())
    {
        leftViwe.push_back(root->data);
    }
    printLeftView(root->left, level+1, leftViwe);
    printLeftView(root->right, level+1, leftViwe);
    
}

//PRINT RIGHT VIEW
void printRightView(Node* root, int level, vector<int> &leftViwe){
    if(root == NULL){
        return;
    }

    if (level == leftViwe.size())
    {
        leftViwe.push_back(root->data);
    }
    printRightView(root->right, level+1, leftViwe);
    printRightView(root->left, level+1, leftViwe);
    
}

//PRINT LEFT BOUNDARY
void printLeftBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if (root->left == NULL && root->right== NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    if (root->left != NULL)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }

}
//PRINT RIGHT BOUNDARY
void printRightBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if (root->left == NULL && root->right== NULL)
    {
        return;
    }

    if (root->right != NULL)
    {
        printRightBoundary(root->right);
    }
    if(root->left != NULL)
    {
        printRightBoundary(root->left);
    }
    cout<<root->data<<" ";
}

//PRINT ALL LEEF BOUNDARY
void printLeefBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if (root->left == NULL && root->right== NULL)
    {
        cout<<root->data<< " ";
    }
    printLeefBoundary(root->left);
        printLeefBoundary(root->right);
}

//PRINT ALL BOUNDARY
void printBoundaryOfTree(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printLeftBoundary(root->left);
    printLeefBoundary(root->left);
    printLeefBoundary(root->right);
    printRightBoundary(root->right);
}




//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
int main(){
    Node* root = createTree();

    levelorderTbfs(root);
    printBoundaryOfTree(root);
    // printTopView(root);
   // printBottomView(root);
    
    //vector<int> leftView;

    vector<int> rightView;

  
    //printLeftView(root, 0, leftView);
    //printRightView(root, 0, rightView);
    
    // cout<< "Printing the tree"<<endl;
    // for (int i = 0; i < rightView.size(); i++)
    // {
    //     cout<< rightView[i] << " ";
    // }
    

    // cout<< "Printing Preorder: ";
    // preorder(root);
    // cout<< endl;

    // cout<< "Printing inorder: ";
    // inorder(root);
    // cout<< endl;

    // cout<< "Printing Postorder: ";
    // postorder(root);
    // cout<< endl;

    // cout<< "Printing Level trevelsel bfs: ";
    // levelorderTbfs(root);
    // cout<< endl;
    return 0;
}