#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>


// //THIS IS THE WEIGHTED GRAPH
// class GraphWt {
// public:
//     unordered_map<T, list<pair<T, T>>> adjList;

//     void addEdge(T u, T v, int wt, bool direction) {
//         if (direction == 1) {
//             // Directed edge
//             adjList[u].push_back(make_pair(v, wt));
//         } else {
//             // Undirected edge
//             adjList[u].push_back(make_pair(v, wt));
//             adjList[v].push_back(make_pair(u, wt));
//         }
//         cout << "Printing the Graph:" << endl;
//         printAdjList();
//         cout << endl;
//     }

//     void printAdjList() {
//         for (auto i : adjList) {
//             cout << i.first << ": { ";
//             for (auto p : i.second) {
//                 cout << "{ " << p.first << ", " << p.second << "} ";
//             }
//             cout << "}" << endl;
//         }
//     }

//     void bfs(T src,  unordered_map<T, bool>& vis){
//         queue<T> q;
//         q.push(src);
//         vis[src] = true;

//         while (!q.empty())
//         {
//             T frontNode = q.front();
//             cout<<frontNode<<" ";
//             q.pop();

//             for(auto nbr: adjList[frontNode]){
//                 T nbrData = nbr.first;
//                 if(!vis[nbrData]){
//                     q.push(nbrData);
//                     vis[nbrData] = true;
//                 }
//             }
//         }

//     }

//     void dfs(T src,  unordered_map<T, bool>& vis){
//         vis[src] = true;
//         cout<< src << " ";
//         for(auto nbr: adjList[src]){
//             T nbrData = nbr.first;
//             if (!vis[nbrData])
//             {
//                 dfs(nbrData, vis);
//             }

//         }

//     }
// };


// THIS IS THE NON WEIGHTED GRAPH
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        if (direction == 1)
        {
            // Directed edge
            adjList[u].push_back(v);
        }
        else
        {
            // Undirected edge
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        cout << "Printing the Graph:" << endl;
        printAdjList();
        cout << endl;
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << ": { ";
            for (auto p : i.second)
            {
                cout << "{ " << p << ", " << "} ";
            }
            cout << "}" << endl;
        }
    }

    void bfsTrevel(T src, unordered_map<T, bool> &vis)
    {
        queue<T> q;
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;
                if (!vis[nbrData])
                {
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
    }

    void dfsTrevel(T src, unordered_map<T, bool> &vis)
    {
        vis[src] = true;
        cout << src << " ";
        for (auto nbr : adjList[src])
        {
            //  T nbrData = nbr.first;
            if (!vis[nbr])
            {
                dfs(nbr, vis);
            }
        }
    }
     // UNDRECTEDT CYCIL IN GRAPH BY BFS
    bool checkCycilBfs(int src, unordered_map<int, bool> &visited, unordered_map<int, int> &parent)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = fNode;
                }
                else
                {
                    if (visited[nbr] && nbr != parent[fNode])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    // UNDRECTEDT CYCIL IN GRAPH BY DFS
    bool checkCycilDfs(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;
        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool checkAns = checkCycilDfs(nbr, visited, src);
                if (checkAns == true)
                {
                    return true;
                }
            }
            if (visited[nbr] && nbr != parent)
            {
                return true;
            }
        }
        return false;
    }
     // DRECTEDT CYCIL IN GRAPH BY DFS
     bool checkDirCycilDfs(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;
        for (auto nbr : adjList[src]){
            if (!visited[nbr]){
                bool checkAns = checkDirCycilDfs(nbr, visited, dfsVisited);
                if (checkAns == true){
                    return true;
                }
                
            }
              if (visited[nbr] == true && dfsVisited[nbr] == true){
                return true;
               }
           
        }
        dfsVisited[src] = false;
        return false;
    }
  
    void topoDfs(int src, unordered_map<int, bool> &visited, stack<int>& ans)
    {
        visited[src] = true;
    
        for (auto nbr : adjList[src]){
            if (!visited[nbr]){
                topoDfs(nbr, visited, ans);
            }
        }
        ans.push(src);
    }

    void topoBfs(int n, vector<int>& ans){
        queue<int> q;
        unordered_map<int, int> indegree;
        for(auto i: adjList){
            int src = i.first;
            for(auto nbr: i.second){
                indegree[nbr]++;
                
            }
        }
        for (int i = 0; i < n; i++)
        {
           if (indegree[i] == 0){
             q.push(i);
           } 
        }

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            ans.push_back(fNode);
            for(auto nbr: adjList[fNode]){
                indegree[nbr]--;
                if (indegree[nbr] == 0){
                    q.push(nbr);
                } 
            }
        } 
    }
};


int main()
{
    Graph<int> g;
    int n = 4;
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 3, 1);
    

    // bool ans = false;
    unordered_map<int, bool> visited;
   //unordered_map<int, int> parent;
    //unordered_map<int, bool> dfsVisited;
    // stack<int> ans;
    vector<int> ans;
    // for (int i = 0; i < n; i++){
        // if (!visited[i]){
            g.topoBfs(n, ans);
        // }
    // }
    for(auto i: ans){
        cout<< i << " ";
    }
    // while (!ans.empty())
    // {
    //     cout<< ans.top();
    //     ans.pop();
    // }
    
    // if (ans == true){
    //     cout << "present cycil" << endl;
    // }
    // else{
    //     cout << "apsent cycil" << endl;
    // }

    // GraphWt<int> g;
    // g.addEdge(0, 1, 10, 0);
    // g.addEdge(1, 2, 20, 0);
    // g.addEdge(1, 3, 40, 0);
    // g.addEdge(2, 3, 50, 0);

    // unordered_map<int, bool> visited;
    // for (int i = 0; i <= 3; i++)
    // {
    //     if (!visited[i])
    //     {
    //        g.bfs(i, visited);
    //     }

    // }

    // unordered_map<int, bool> visited;
    // for (int i = 0; i <= 3; i++)
    // {
    //     if (!visited[i])
    //     {
    //        g.dfs(i, visited);
    //     }

    // }

    return 0;
}
