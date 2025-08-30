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



bool screchWord(TriesNode* root, string word){
    if(word.length() == 0){
        return root->isTreminal;
         
    }


    char ch = word[0];
    int index = ch - 'a';
    TriesNode* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }else{
        return false;
 
   }
   screchWord(child, word.substr(1));
   
}


void deleteWord(TriesNode* root, string word) {
    if (word.length() == 0) {
        root->isTreminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TriesNode* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
        deleteWord(child, word.substr(1));
    }
}

void printTrie(TriesNode* root, string currentWord) {
    if (root->isTreminal) {
        cout << currentWord << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            char ch = 'a' + i;
            printTrie(root->children[i], currentWord + ch);
        }
    }
}



int main(){
    TriesNode* root = new TriesNode('-');
    inserteWord(root, "coding");
    inserteWord(root, "code");
    inserteWord(root, "coder");
    inserteWord(root, "khan");
    inserteWord(root, "king");

    // if(screchWord(root, "coding")){
    //     cout<< "Presenting" << endl; 
    // }else{
    //     cout<< "Not Presenting" << endl; 
    // }

    deleteWord(root, "coding");
     cout << "Words in Trie:\n";
    printTrie(root, "");

    return 0;

    
}