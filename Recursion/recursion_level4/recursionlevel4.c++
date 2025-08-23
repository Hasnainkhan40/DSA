#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;



/*
***very importren pettern***
322. Coin Change
Medium
Topics
premium lock icon
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

*/


int solve(vector<int> &arr , int target){
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solve(arr, target - arr[i]);
        if(ans != INT_MAX){
            mini = min(mini, ans+1);
        }
    }
    return mini;
    
}

int solvelen(vector<int>& arr, int n){

    if(n == 0){
        return 0;
    }

    if(n < 0){
        return INT_MIN;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solvelen(arr, n - arr[i]);
        if(ans != INT_MIN){
            maxi = max(maxi, ans+1);
        }
        
    }
    return maxi;
    
}



 // most importarnt inclid and exclud most repeted
    // ***print sub sequences***

void printSubSequenc(string str, string ans , int i){
    if(i >= str.length()){
        cout<< ans << endl;
        return;
    }

    printSubSequenc(str, ans, i+1);
    
    ans.push_back(str[i]);
    printSubSequenc(str, ans, i+1);

}




 // most importarnt inclid and exclud most repeted
    // ***print sun of not adjents***
void solveInEx(vector<int>& arr, int i,int sum, int &maxi){
    if(i >= arr.size()){
        maxi = max(sum, maxi);
        return;
    }

    //include
    solveInEx(arr, i+2, sum+arr[i], maxi);
   //exclud
   solveInEx(arr, i+1, sum, maxi);


}



int main(){
     
    //  most importarnt inclid and exclud most repeted
    //  ***print sun of not adjents***
    // vector<int> arr{2,1,4,9};
    // int sum = 0;
    // int maxi = INT_MIN;
    // int i=0;

    // solveInEx(arr, i, sum, maxi);
    // cout<< maxi << " "<< endl;
    


    // vector<int> arr{5,2,2};
    // int len = 7;

    // int ans = solvelen(arr, len);

    // if(ans < 0){
    //     ans = 0;
    // }
    // cout<< ans << " ";


    // most importarnt inclid and exclud most repeted
    // ***print sub sequences***

    // string str = "abc";
    // string ans = " ";
    // int i =0;

    // printSubSequenc(str, ans, i);
    // return 0;


    // 322. Coin Change
    // vector<int> arr{1,2,};
    // int target = 5;

    // int ans = solve(arr, target);

    // cout << ans << " ";
    
    // return 0;
}