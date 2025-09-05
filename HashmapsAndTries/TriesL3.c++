#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;


class TriesNode{
    public:
    char data;
    TriesNode* children[26];
    bool isTreminal;

    TriesNode(char d){
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTreminal = false;
    }

};


void inserteWord(TriesNode* root, string word){
    // cout<< "Inserting  " << word <<endl;
    if(word.length() == 0){
         root->isTreminal = true;
         return;
    }


    char ch = word[0];
    int index = ch - 'a';
    TriesNode* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }else{
        child = new TriesNode(ch);
        root->children[index] = child;
 
   }
   inserteWord(child, word.substr(1));
}


void storeSuggestion(TriesNode* curr, vector<string> &temp, string prefix){
    if (curr->isTreminal)
    {
        temp.push_back(prefix);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';
        TriesNode* next = curr->children[index];

        if (next != NULL)
        {
            prefix.push_back(ch);
            storeSuggestion(next, temp, prefix);
            prefix.pop_back();
        }
        
        
    }
    
}


vector<vector<string>> getSuggestions(TriesNode* root, string input){
    TriesNode* prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for (int i = 0; i <input.length(); i++)
    {
        char lastch = input[i];
        int index = lastch - 'a';
        TriesNode* curr = prev->children[index];

        if (curr == NULL)
        {
            break;
        }else{
            vector<string> temp;
            prefix.push_back(lastch);
            storeSuggestion(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
        
    }
    return output;
}


int main(){
    vector<string> v;

    v.push_back("love");
     v.push_back("lover");
      v.push_back("loving");
       v.push_back("lost");
        v.push_back("lane");
         v.push_back("lord");
          v.push_back("land");
      
    
          string input = "lovi";
    TriesNode* root = new TriesNode('-');
    for (int i = 0; i < v.size(); i++)
    {
        inserteWord(root, v[i]);
    }
    
     vector<vector<string>> ans = getSuggestions(root, input);

     cout<< "Printing the answer:  " << endl;

     for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
    {
       cout<< ans[i][j] << " , ";
    }
    cout<<endl;
    
    }
    

    



}