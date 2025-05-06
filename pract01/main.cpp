/*
Implement depth first search algorithm and Breadth First Search algorithm, use an undirected
graph and develop a recursive algorithm for searching all the vertices of a graph or tree data
structure.
 */


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> adj;
        int V;
        int E;

        Solution()
        {
            V = 0;
            E = 0;
        }

        void dfs_util(int node , vector<bool>& visited)
        {
            visited[node] = true;
            cout<<node<<" ";

            for(auto each : adj[node])
            {
                if(!visited[each])
                {
                    dfs_util(each , visited);
                }
            }
        }

        void dfs(int start_node)
        {
            vector<bool> visited(adj.size() , false);

            cout<<"DFS Traversal : ";
            dfs_util(start_node , visited);
            cout<<endl;
            return;
        }

        void displayGraph()
        {
            for(int i = 0; i < V; i++)
            {
                cout << i << " -> ";
                for(int j = 0; j < adj[i].size(); j++)
                {
                    cout << adj[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        void bfs(int start_node)
        {
            vector<bool> visited(adj.size() , false);
            queue<int> q;
            q.push(start_node);
            visited[start_node] = true;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                cout<<node<<" ";
                for(auto each : adj[node])
                {
                    if(!visited[each])
                    {
                        q.push(each);
                        visited[each] = true;
                    }
                }
            }
            cout<<endl;
            return;
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

    obj.displayGraph();

    obj.dfs(0);

    cout<<"\n BFS traversal : ";
    obj.bfs(0);
}

int main()
{
    Test();
    return 0;
}