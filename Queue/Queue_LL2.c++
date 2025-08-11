#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

//REVERS THE K LENTH
void reverseK(queue<int> &q, int k){
    stack<int> st;
    int count =0;
    int n = q.size();

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        st.push(temp);
        count++;
        if (count == k)
        {
            break;
        }
        
    }

    while (!st.empty())
    {
        int temp = st.top();
        st.pop();
        q.push(temp);
    }

    count =0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;
        if(count == n-k){
            break;
        }
    }
    
    
    
}



//reverse the queue by itretive aproch
void reverseQueue(queue<int> &q){
    stack<int> st;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        st.push(temp);
    }

     while (!st.empty())
    {
        int temp = st.top();
        st.pop();
        q.push(temp);
    }
    
}
//reverse the queue by recursive aprroch aproch
void reverseQueuebyRecusion(queue<int> &q){
    if(q.empty()){
        return;
    }
    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
}


//INTERLIVE 2 QUEUE
void interlive(queue<int> &q){
    if(q.empty()){
        cout<< "Queueu is empty";
        return;
    }
    int n = q.size();
    int k=n/2;
    int count =0;
    queue<int> q2;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;
        if(count == k){
            break;
        }
    }

    while (!q.empty() && !q2.empty())
    {
        int first = q2.front();
        q2.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);
        
    }
    if (n&1)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}


//FIRST NAGATIVE NUMBERS
void firstnegative(int arr[], int n, int k){
     deque<int> q;
     for (int i = 0; i < k; i++)
     {
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
     }

     for (int i = k; i < n; i++)
     { 
        if (q.empty())
        {
            cout<< 0 << " ";
        }else
        {
            cout<< arr[q.front()] << " ";
        }

        while ((!q.empty()) && (i-q.front() >= k))
        {
            q.pop_front();
        }
        if (arr[i] < 0)
        {
            q.push_back(i);
        }

     }
      if (q.empty())
        {
            cout<< 0 << " ";
        }else
        {
            cout<< arr[q.front()] << " ";
        }
}

void firstnonrepeat(string strem){
   int freq[26] = {0};
    queue<char> q;

    string ans = "";

    for (int i = 0; i < strem.size(); i++)
    {
       char ch = strem[i];

       freq[ch-'a']++;
        q.push(ch);

        while (!q.empty())
        {
            if (freq[q.front() - 'a'] > 1)
            {
                q.pop();
            }else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    cout<<"First  " <<ans<< " ";
    
}


int main(){
    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // q.push(6);
    //  q.push(100);

   // reverseQueue(q);
   // reverseQueuebyRecusion(q);
//    int k=3;
//    reverseK(q, k);

    //  interlive(q);
    // cout << "Queue after reversing:" << endl;
    // while (!q.empty()) {
    //     cout << q.front() << endl;
    //     q.pop();
    // }

    // int arr[] = {12,-1,-7,8,-15,30,16,28};
    // int n=8;
    // int k=3;

    // firstnegative(arr, n, k);
    string strem = "aabc";
    firstnonrepeat(strem);
        
    

    return 0;



}


