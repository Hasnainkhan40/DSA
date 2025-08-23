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

class NodeData{
    public:

    int size;
    int maxval;
    int minval;
    bool isValid;

    NodeData(){

    }
    NodeData(int size, int max, int min, bool valid){
        this->size = size;
        maxval = max;
        minval = min;
        isValid = valid;
    }
};





Node* insertInToBst(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertInToBst(root->right, data);
    }else
    {
        root->left = insertInToBst(root->left, data);
    }
    return root;
    
}


void cerateBst(Node* &root){
    cout<< "Enter the data" << endl;
    int data;
    cin>> data;
    while (data != -1)
    {
        root = insertInToBst(root, data);
        cout<< "Enter the data" << endl;
        cin>> data;

    }
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

//FIND THE MAXIMUM VALUE IN BST
Node* miniValue(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;  
}

//FIND THE MINIMUM VALUE IN BST
Node* maxiValue(Node* root){
    if(root == NULL){
        return NULL; 
    }
    Node* temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;  
}


//SERACH IN BST
bool serchInBst(Node* root, int target){
    if(root == NULL){
        return false;
    }

    if (root->data == target)
    {
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;
    if (target > root->data)
    {
        rightAns = serchInBst(root->right, target);
    }else{
        leftAns = serchInBst(root->left, target);
    }

    return leftAns || rightAns;
}


//DELETE THE NODE
Node* deleteFromBst(Node* root, int target){
    if (root  == NULL)
    {
        return NULL;
    }
    if(root->data == target){
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }else if (root->left == NULL && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }else{
            Node* maxi = maxiValue(root->left);
            root->data = maxi->data;
            root->left = deleteFromBst(root->left, maxi->data);
            return root;
        }
        
    }else if (root->data > target)
    {
        root->left = deleteFromBst(root->left, target);
    }else
    {
         root->right = deleteFromBst(root->right, target);
    }
    return root;
}


void convertBstToLL(Node* root, Node* &head){
    if(root == NULL){
        return;
    }
    convertBstToLL(root->right, head);

    root->right = head;

    if(head != NULL){
        head->left = root;
    }

    head = root;

    convertBstToLL(root->left, head);

}

void printLL(Node* head){
    Node* temp = head;
     cout<<endl;
    while (temp != NULL)
    {
        cout<< temp->data << " ";
        temp = temp->right;
    }
    cout<<endl;
    
}

Node* convertLLToBst(Node* &head, int n){
    if(n <=0 || head == NULL){
        return NULL;
    }
    Node* leafAns = convertLLToBst(head, n-1-n/2);
    Node* root = head;
    root->left = leafAns;
    head = head->right;

    root->right= convertLLToBst(head, n/2);
    return root;
}

NodeData* findLargestBST(Node* root, int &ans){
    if (root == NULL)
    {
        NodeData* temp = new NodeData(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData* leftKaAns = findLargestBST(root->left, ans);
    NodeData* rightKaAns = findLargestBST(root->right, ans);

    NodeData* currentNodeAns =  new NodeData();

    currentNodeAns->size = leftKaAns->size + rightKaAns->size +1;
    currentNodeAns->maxval = max(root->data, rightKaAns->maxval);
    currentNodeAns->minval = max(root->data, leftKaAns->minval);

    if(leftKaAns->isValid && rightKaAns->isValid && (root->data > leftKaAns->maxval)  && (root->data < rightKaAns->minval)){
        return true;
    }
    else
    {
        false;
    }
    
    
}





int main(){
    Node* root = NULL;
    cerateBst(root);
    levelorderTbfs(root);

    

    // Node* head = NULL;
    // cout<<"Printing LL" << endl;
    // convertBstToLL(root, head);
     
    // printLL(head);

    // cout<<"Printing LL to BST" << endl;
    // Node* root1 = NULL;
    // root1 = convertLLToBst(head, 8);
    // levelorderTbfs(root1);


    // cout<< endl;
    // cout<< "Enter the target" << endl;
    // int target;
    // cin>> target;
    // bool ans =  serchInBst(root, target);
    // cout << ans;
    // cout<< "The minimum value of the tree"<<endl;
    // Node* mini =  miniValue(root);
    // cout<< mini->data;

   

    // Node* maxi = maxiValue(root);
    //  cout<< "The minimum value of the tree"<<endl;
    //  cout<< maxi->data;

    // int target;
    // cout<< "Entere the target"<<endl;
    // cin>> target;
    // while (target != -1)
    // {
    //     root = deleteFromBst(root, target);
    //     cout<<"Printing level order "  << endl;
    //     levelorderTbfs(root);

    //     cout<< "Entere the target"<<endl;
    // cin>> target;
    // }
    

    return 0;



}