
#include <iostream>
#include <limits.h>
#include <vector>
#include <unordered_map>

using namespace std;



/*17. Letter Combinations of a Phone Number
Solved
Medium
Topics
premium lock icon
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/


 void solve(vector<string> &ans, int index, string output, string digits, vector<string> &mapping){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int digit = digits[index] - '0';
        string value = mapping[digit];
        for(int i=0; i<value.length(); i++){
            char ch = value[i];
            output.push_back(ch);
            solve(ans, index+1, output, digits, mapping);
            output.pop_back();
        }

    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        int index =0;
        string output ="";
        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        solve(ans, index, output, digits, mapping);
        return ans;
        
    }





/*22. Generate Parentheses
Solved
Medium
Topics
premium lock icon
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]*/

void solve(vector<string> &ans, int n, int open, int close, string output){
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }

        if(open > 0){
            output.push_back('(');
            solve(ans, n, open-1, close, output);
            output.pop_back();
        }

        if(close > open){
            output.push_back(')');
            solve(ans, n, open, close-1, output);
            output.pop_back();
        }
    }
   
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open =n;
        int close=n;
        string output = "";
        solve(ans, n, open, close, output);
        return ans;
        
    }












int main(){

}