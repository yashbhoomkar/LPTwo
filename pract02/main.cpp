#include <bits/stdc++.h>
using namespace std;

const int delRow[] = {-1 , 1 , 0 , 0};
const int delCol[] = {0 , 0 , -1 , 1};

class Node
{
    public:
        int x , y;
        int gcost , hcost , fcost;

        Node() : x(0), y(0), gcost(0), hcost(0), fcost(0) {}

        Node(int x , int y , int gcost = 0, int hcost = 0)
        {
            this->x = x;
            this->y = y;
            this->gcost = gcost;
            this->hcost = hcost;
            this->fcost = gcost + hcost;
        }
};

struct CompareNode
{
    bool operator()(Node& a , Node& b)
    {
        return a.fcost > b.fcost;
    }
};

class Solution
{
    public:
        vector<vector<int>> grid;
        int n , m;
        Node start;
        Node end;

        Solution()  {}

        Solution(vector<vector<int>>& grid , Node start , Node end)
        {
            this->grid = grid;
            this->n = grid.size();
            this->m = grid[0].size();
            this->start = start;
            this->end = end;
        }

        int heuristic (const Node& a , const Node& b)
        {
            return abs(a.x - b.x) + abs(a.y - b.y);
        }

        void printPath(vector<vector<Node>>& parent)
        {
            vector<Node> path;
            Node curr = end;
            while (curr.x != start.x || curr.y != start.y)
            {
                path.push_back(curr);
                curr = parent[curr.x][curr.y];
            }
            path.push_back(start);

            reverse(path.begin(), path.end());

            for (auto& node : path)
            {
                cout << "(" << node.x << ", " << node.y << ") ";
            }
            cout << endl;
        }

        void aStar()
        {
            priority_queue<Node , vector<Node> , CompareNode> pq;
            vector<vector<bool>> visited(n , vector<bool>(m , false));
            vector<vector<Node>> parent(n , vector<Node>(m , Node(-1 , -1)));

            start.hcost = heuristic(start , end);
            start.fcost = start.gcost + start.hcost;

            pq.push(start);

            while(!pq.empty())
            {
                Node curr = pq.top();
                pq.pop();

                if(visited[curr.x][curr.y])
                {
                    continue;
                }

                if(curr.x == end.x && curr.y == end.y)
                {
                    cout<<"\n Path found : ";
                    printPath(parent);
                    return;
                }

                visited[curr.x][curr.y] = true;

                for(int i = 0 ; i < 4 ; i++)
                {
                    int nx = curr.x + delRow[i];
                    int ny = curr.y + delCol[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && !visited[nx][ny])
                    {
                        int g = curr.gcost + 1;
                        int h = heuristic(Node(nx , ny) , end);
                        Node neigh(nx , ny , g , h);
                        pq.push(neigh);
                        parent[nx][ny] = curr;
                    }
                }
            }
        }
};

void Test()
{
    Solution obj;
    obj.grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0}
    };
    obj.n = 5;
    obj.m = 5;
    obj.start = Node(0 , 0);
    obj.end = Node(4 , 4);
    obj.aStar();
}

int main()
{
    Test();
    return 0;
}