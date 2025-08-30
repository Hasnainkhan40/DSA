#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;


void storeString(string str){
    unordered_map<char, int> freq;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch]++;
    }

     for(auto i: freq){
        cout<< i.first << "-> " << i.second <<endl;
    }
    
}





int main(){

    string str = "khankhankhankhan";

    storeString(str);

    // unordered_map<string, int> m;
    // m["scorpio"] = 9;
    // m["baleno"] = 6;
    // m["fortuner"] = 10;


    // if(m.find("fortuner") != m.end()){
    //     cout<< "Present" << endl;
    // }else
    // {
    //     cout<< "Not Present" << endl;
    // }

    // cout << m.count("Inove")<<endl;

    // cout << m.size()<<endl;
    
    // for(auto i: m){
    //     cout<< i.first << "-> " << i.second <<endl;
    // }

 return 0;

}