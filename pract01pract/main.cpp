#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> adj;
        int V, E;

        Solution()
        {
            V = 0;
            E = 0;
        }

        void displayGraph()
        {
            for(int i = 0 ; i < V ; i++)
            {
                cout<<i<<" -> ";
                for(auto each : adj[i])
                {
                    cout<<each<<" ";
                }
                cout<<endl;
            }
        }

        void dfs(int node , vector<bool>& visited)
        {
            visited[node] = true;
            cout<<node<<" ";
            for(auto each : adj[node])
            {
                if(!visited[each])
                {
                    dfs(each , visited);
                }
            }
        }


        void dfs_util(int node)
        {
            vector<bool> visited(V , false);
            dfs(node , visited);
            cout<<endl;
            return;
        }

        void bfs(int node)
        {
            vector<bool> visited(V , false);
            queue<int> q;
            q.push(node);
            visited[node] = true;

            while(!q.empty())
            {
                int temp = q.front();
                q.pop();
                cout<<temp<<" ";
                for(auto each : adj[temp])
                {
                    if(!visited[each])
                    {
                        q.push(each);
                        visited[each] = true;
                    }
                }
            }
        }

};

void Test()
{
    Solution obj;
    obj.adj = {
        {1, 2},       // 0 -> 1, 2
        {0, 3, 4},    // 1 -> 0, 3, 4
        {0, 4},       // 2 -> 0, 4
        {1, 5},       // 3 -> 1, 5
        {1, 2, 5},    // 4 -> 1, 2, 5
        {3, 4}        // 5 -> 3, 4
    };
    obj.V = 3;
    obj.E = 3;


    obj.dfs_util(0);

    cout<<endl;

    obj.bfs(0);
    cout<<endl;
    
}

int main()
{
    Test();
    return 0;
}