#include <iostream>
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


int main() {
    int n;
    cout<<"Enter the value of n" <<endl;
    cin>>n;
    // solve(n);
    // facto(n);
    fibo(n);
    cout<< fibo(n) << endl;
    return 0;
}