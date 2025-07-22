#include <iostream>
#include <limits.h>
#include <vector>


using namespace std;

void solve(int n){
    if(n == 0){
        return;
    }
    cout<<n<<endl;

    solve(n-1);


}

int facto(int n){
    if(n == 1){
        return 1;
    }
    int s = facto(n-1);
    int ans = n*s;

    return ans;
}


int fibo(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    int ans = fibo(n-1) + fibo(n-2);

    return ans;
}


/*70. Climbing Stairs
Attempted
Easy
Topics
premium lock icon
Companies
Hint
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:*/

    int climbStairs(int n) {
        if(n == 0 || n == 1){
            return 1;
        }

        int ans = climbStairs(n-1) + climbStairs(n-2);
        
        return ans;
    }

    
//arryr print

void print(int arr[], int n, int i){
    if(i >= n){
        return;
    }
    // reverse couting print(arr, n, i+1);
    cout<<arr[i] << " ";
     print(arr, n, i+1);
}



    // find the max element****
void findmax(int arr[], int n, int i, int& maxi){
    if(i >= n){
        return;
    }

    if(arr[i] > maxi){
        maxi = arr[i];
    }
    /*if(arr[i] > maxi){
        maxi = arr[i];
        for minimum number
    }*/

    findmax(arr, n, i+1, maxi);
}

//find the kye in string****-*

bool checkKye(string str, int& n, int i, char kye){

    if(i >= n){
        return false;
    }
    if(str[i] == kye) return true;

    return checkKye(str, n, i+1, kye);
}

void digit(int num){
    if(num == 0){
        return;
    }

    int newValue = num / 10;
    digit(newValue);

    int digits = num % 10;
    cout << digits << " " ;
}


int main() {

    // print the all degit of this num ****
    // int num = 674;
    // digit(num);
    // return 0;
    
    
// find the kye in string****-*
//     string str = "hasnaink";
//     int n = str.length();
//     int i=0;
//     char kye = 'z';

//     bool ans = checkKye(str, n, i, kye);
//     cout<< ans << endl;
//         return 0;



    //  find the max element****
    // int arr[5] = {10,20,30,40,50};
    // int n=5;
    // int i =0;
    // int maxi1 = INT_MAX;
    // int maxi = INT_MIN;

    // findmax(arr, n, i, maxi);

    // cout<< maxi << " " <<endl;
    // return 0;

   // arryr print
//    int arr[5] = {10,20,30,40,50};
//    int n=5;
//    int i =0;

//    print(arr, n, i);

//    return 0;

    // int n;
    // cout<<"Enter the value of n" <<endl;
    // cin>>n;
    // // solve(n);
    // // facto(n);
    // fibo(n);
    // cout<< fibo(n) << endl;
    // return 0;
}