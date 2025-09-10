1143. Longest Common Subsequence

class Solution {
public:


int solveMemo(string& a, string& b, int i, int j, vector<vector<int>>& dp){
    if(i >= a.length()){
        return 0;
    }
    if(j >= b.length()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans =0;

    if(a[i] == b[j]){
        ans = 1 + solveMemo(a,b,i+1,j+1,dp);
    }
    else{
        ans = 0 + max( solveMemo(a,b,i+1,j,dp) ,solveMemo(a,b,i,j+1,dp));
    }
    dp[i][j] = ans;

    return dp[i][j];
}



int solveTebo(string& a, string& b){
    vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));

    for(int i_index=a.length()-1; i_index>=0; i_index--){
            for(int j_index=b.length()-1; j_index>=0; j_index--){
                int ans =0;

                if(a[i_index] == b[j_index]){
                    ans = 1 + dp[i_index+1][j_index+1];
                }
                else{
                    ans = 0 + max(dp[i_index+1][j_index], dp[i_index][j_index+1]);
                }
                dp[i_index][j_index] = ans;
            }
        }
    return dp[0][0];
}





int solveTeboSo(string& a, string& b){
   vector<int> next(a.length()+1, 0);
   vector<int> curr(a.length()+1, 0);
    
     for(int j_index=b.length()-1; j_index>=0; j_index--){
        for(int i_index=a.length()-1; i_index>=0; i_index--){
            
                    int ans =0;

                    if(a[i_index] == b[j_index]){
                        ans = 1 + next[i_index+1];
                    }
                    else{
                        ans = 0 + max(curr[i_index+1], next[i_index]);
                    }
                    curr[i_index] = ans;
                }
                next = curr;
        }
    return next[0];
}



    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        //vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        // int ans = solveMemo(text1, text2, i, j, dp);
        int ans = solveTeboSo(text1, text2);
        return ans;
         
    }
};



2: 516. Longest Palindromic Subsequence


class Solution {
public:


int solveTeboSo(string& a, string& b){
   vector<int> next(a.length()+1, 0);
   vector<int> curr(a.length()+1, 0);
    
     for(int j_index=b.length()-1; j_index>=0; j_index--){
        for(int i_index=a.length()-1; i_index>=0; i_index--){
            
                    int ans =0;

                    if(a[i_index] == b[j_index]){
                        ans = 1 + next[i_index+1];
                    }
                    else{
                        ans = 0 + max(curr[i_index+1], next[i_index]);
                    }
                    curr[i_index] = ans;
                }
                next = curr;
        }
    return next[0];
}

    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());

        int ans = solveTeboSo(a, s);
        return ans;
    }
};


3: 72. Edit Distance

class Solution {
public:

int solve(string& a, string& b, int i, int j){
    if(i == a.length()){
        return b.length() - j;
    }
     if(j == b.length()){
        return a.length() - i;
    }

    int ans =0;
    if(a[i] == b[j]){
        ans = 0+solve(a,b,i+1,j+1);
    }else{
        int replace = 1 + solve(a,b,i+1,j+1);
        int insert = 1 + solve(a,b,i,j+1);
        int remove  = 1 + solve(a,b,i+1,j);
        ans = min(insert, min(remove ,replace));

    }
    return ans;
}


int solveMemo(string& a, string& b, int i, int j, vector<vector<int>>& dp){
    if(i == a.length()){
        return b.length() - j;
    }
    if(j == b.length()){
        return a.length() - i;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans =0;
    if(a[i] == b[j]){
        ans = 0+solveMemo(a,b,i+1,j+1, dp);
    }else{
        int replace = 1 + solveMemo(a,b,i+1,j+1,dp);
        int insert = 1 + solveMemo(a,b,i,j+1,dp);
        int remove  = 1 + solveMemo(a,b,i+1,j,dp);
        ans = min(insert, min(remove ,replace));

    }
    dp[i][j] = ans;
    return dp[i][j];
}







int solveTebo(string& a, string& b){

    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));
   
    for(int col=0; col<=b.length(); col++){
        dp[a.length()][col] = b.length() - col;
    }
     for(int row=0; row<=a.length(); row++){
        dp[row][ b.length()] = a.length() - row;
    }

    for(int i_index=a.length()-1; i_index>=0; i_index--){
         for(int j_index=b.length()-1; j_index>=0; j_index--){
             int ans =0;
            if(a[i_index] == b[j_index]){
                ans = 0 + dp[i_index+1][j_index+1];
            }else{
                int replace = 1 + dp[i_index+1][j_index+1];
                int insert = 1 +dp[i_index][j_index+1];
                int remove  = 1 + dp[i_index+1][j_index];
                ans = min(insert, min(remove ,replace));
            }
             dp[i_index][j_index] = ans;
       }
    }
    
   
    return dp[0][0];
}



int solveTeboSO(string& a, string& b){

    //vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));
    vector<int> next(a.length()+1, 0);
     vector<int> curr(a.length()+1, 0);
   
    // for(int col=0; col<=b.length(); col++){
    //     dp[a.length()][col] = b.length() - col;
    // }
     for(int row=0; row<=a.length(); row++){
        next[row] = a.length() - row;
    }
    

    for(int j_index=b.length()-1; j_index>=0; j_index--){
        curr[a.length()] = b.length() - j_index;
        for(int i_index=a.length()-1; i_index>=0; i_index--){
                int ans =0;
            if(a[i_index] == b[j_index]){
                ans = 0 + next[i_index+1];
            }else{
                int replace = 1 + next[i_index+1];
                int insert = 1 +  next[i_index];
                int remove  = 1 + curr[i_index+1];
                ans = min(insert, min(remove ,replace));
            }
                curr[i_index] = ans;
        }
        next = curr;
    }
    
    return next[0];
}



    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        // vector<vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        int ans = solveTeboSO(word1, word2);
        return ans;
    }
};