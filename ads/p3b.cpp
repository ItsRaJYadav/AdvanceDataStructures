#include <iostream>
#include <vector>
using namespace std;
int ternary(vector<int> arr, int start, int end, int key)
{
        int mid1;
        int mid2;
        while (start <= end)
        {
                mid1 = start + (end - start) / 3;
                mid2 = end - (end - start) / 3;
                if (arr[mid1] == key)
                {
                        return mid1;
                }
                else if (arr[mid2] == key)
                {
                        return mid2;
                }
                else if (arr[mid1] > key)
                {
                        end = mid1 - 1;
                }
                else if (arr[mid2] < key)
                {
                        start = mid2 + 1;
                }
                else
                {
                        start = mid1 + 1;
                        end = mid2 - 1;
                }
        }
        return -1;
}
int main()
{
        vector<int> arr = {1, 2, 3, 4, 5, 87, 110};
        cout << "Index of 87 =" << ternary(arr, 0, arr.size() - 1, 87);
}
