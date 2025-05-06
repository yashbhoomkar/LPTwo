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


int main()
{
    SelectionSort obj;
    obj.main();
    return 0;
}