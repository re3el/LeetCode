#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(int low, int high, vector<int> &list)
{
    int pivot = list[high];
    int pos = low;
    
    for(int i=low; i<=high-1; i++)
    {
        if(list[i] <= pivot)
            swap(list[i],list[pos++]);
    }
    swap(list[pos],list[high]);
    return pos;
}


void quickSort(int low, int high, vector<int> &list)
{
    // if not while!
    if(low < high)
    {
        int pos = partition(low, high, list);
        quickSort(low, pos-1, list);
        quickSort(pos+1, high, list);
    }
}

int main()
{
    vector<int> list = {1,14,5,4,2,60,12,4,12,3,4,5,5,1,120,232,18};
    int n = list.size();
    quickSort(0,n-1,list);
    
    for(auto i:list)
        cout<<i<<" ";
}