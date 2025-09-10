#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;
//TABULAR METHOD
int solve(int n){
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    if(n == 0){
        return 0;
    }
    dp[1] = 1;
    
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
   
}


//MEMOIZATION
// int solve(int n, vector<int> &dp){
   
    
//     if(n == 0 || n == 1){
//         return n;
//     }

//     if(dp[n] != -1){
//         return dp[n];
//     }
    
    
//     dp[n] = solve(n-1, dp) + solve(n-2, dp);
//     return dp[n];
   
// }

//SPACE OPTIMIZATION
// int solve(int n){
   
//     int prev = 0;
//     if(n == 0){
//         return 0;
//     }
//     int curr = 1;
//     if(n == 1){
//         return 1;
//     }
//     int ans = 0;
//     for(int i=2; i<=n; i++){
//         ans = curr + prev;
//         prev = curr;
//         curr = ans;
//     }
          
//     return ans;
   
// }

    int fib(int n) {
       // vector<int> dp(n+1, -1);
        int ans = solve(n);
        return ans;
    }


    int main(){
        int n=5;
        fib(n);
        return 0;
        
    }
