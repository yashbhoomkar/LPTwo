#include <bits/stdc++.h>
using namespace std;

#define P pair<int,int>


class SelectionSort
{
    public:

        void selectionSort(vector<int>& vct)
        {   
            int size = vct.size();
            for(int i = 0; i < size ; i++)
            {
                int minIndex = i;
                for(int j = i + 1 ; j < size ; j++)
                {
                    if(vct[j] < vct[minIndex])
                    {
                        minIndex = j;
                    }
                }
                swap(vct[i] , vct[minIndex]);
            }
        }

        void printVector(vector<int>& vct)
        {
            for(int i = 0; i < vct.size() ; i++)
            {
                cout << vct[i] << " ";
            }
            cout << endl;
        }

        int main()
        {
            vector<int> vct = {64, 25, 12, 22, 11};
            selectionSort(vct);
            printVector(vct);

            return 0;
        }
};


class PrimsAlgorithmMST
{
    public:
        vector<vector<pair<int, int>>> adj;  // {vertex, weight}
        int V , E;

        void primsMST()
        {
            // {weight , vertex , parent}
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            vector<int> visited(V, 0);
            pq.push({0 , 0 , -1}); // Starting with vertex 0

            while(!pq.empty())
            {
                vector<int> curr = pq.top();
                pq.pop();

                int weight = curr[0];
                int vertex = curr[1];
                int parent = curr[2];

                if(visited[vertex] == 1)
                {
                    continue;
                }

                // Mark vertex as visited
                visited[vertex] = 1;

                if(parent != -1)
                {
                    cout << parent << " - " << vertex << " : " << weight << endl;
                }

                // Explore all adjacent vertices of the current vertex
                for(auto edge : adj[vertex])
                {
                    int v = edge.first;
                    int w = edge.second;
                    if (!visited[v])
                    {
                        pq.push({w, v, vertex});
                    }
                }
            }
        }

        int main()
        {
            // adj -> {vertex, weight}
            vector<vector<pair<int, int>>> adj = {
                {{1, 2}, {2, 1}},        // Vertex 0
                {{0, 2}, {2, 1}},        // Vertex 1
                {{0, 1}, {1, 1}, {3, 2}, {4, 2}}, // Vertex 2
                {{2, 2}, {4, 1}},        // Vertex 3
                {{2, 2}, {3, 1}}         // Vertex 4
            };

            this->adj = adj;
            this->V = 5;
            this->E = 6;

            primsMST();

            return 0;
        }
};

// Single Source Shortest Path -> Dijkstra
class Dijkstra
{
    public:
        int V;
        vector<vector<pair<int,int>>> adj;
        
        vector<int> dijkstra(int source)
        {
            vector<int> dist(V , INT_MAX);
            priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
            
            pq.push({0,source});
            dist[source] = 0;

            while(!pq.empty())
            {
                auto curr = pq.top();
                pq.pop();

                int currdist = curr.first;
                int node = curr.second;

                for(auto it : adj[node])
                {
                    int adjNode = it.first;
                    int edgWt = it.second;

                    if(currdist + edgWt < dist[adjNode])
                    {
                        dist[adjNode] = currdist + edgWt;
                        pq.push({dist[adjNode] , adjNode});
                    }

                }
            }


            return dist;
        }

        void printVector(vector<int> &v)
        {
            for(auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
        }

        int main()
        {
            // adj -> {vertex, weight}
            this->V = 5;
            adj.resize(V);

            // Constructing the graph
            adj[0].push_back({1, 2});
            adj[0].push_back({2, 4});
            adj[1].push_back({2, 1});
            adj[1].push_back({3, 7});
            adj[2].push_back({3, 3});
            adj[3].push_back({4, 1});
            int source = 0;

            vector<int> dist = dijkstra(source);

            printVector(dist);
            return 0;
        }
};

void selectionSort()
{
    SelectionSort obj;
    obj.main();
}

void primsAlgorithmMST()
{
    PrimsAlgorithmMST obj;
    obj.main();
}

void SingleSourceShortestPathDijkstra()
{
    Dijkstra obj;
    obj.main();
}

int main()
{
    //selectionSort();
    //primsAlgorithmMST();
    SingleSourceShortestPathDijkstra();
    return 0;
}