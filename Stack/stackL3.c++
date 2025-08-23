#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>

using namespace std;







vector<int> prevSmaller(vector<int> &input){
    stack<int> st;
    st.push(-1);
    vector<int> ans(input.size());

    for(int i=0; i<= input.size(); i++){
        int curr = input[i];
        while (st.top() >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();

        st.push(curr);
    }
    return ans;
}
vector<int> nextSmaller(vector<int> &input){
    stack<int> st;
    st.push(-1);
    vector<int> ans(input.size());

    for(int i=input.size()-1; i>=0; i--){
        int curr = input[i];
        while (st.top() >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();

        st.push(curr);
    }
    return ans;
}


int main(){



    //NEXT SMALLER ELEMENT****MOST IMPORTENT
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);
    // vector<int> ans =  nextSmaller(input);
    vector<int> ans =  prevSmaller(input);

    cout<< "Printing the stack"<<endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i]  << " ";
    }
    cout<<endl;
    
}