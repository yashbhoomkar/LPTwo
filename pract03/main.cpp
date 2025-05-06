#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    //selectionSort();
    primsAlgorithmMST();
    return 0;
}