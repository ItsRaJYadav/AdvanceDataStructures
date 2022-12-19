#include <iostream>
using namespace std;
int binary(int arr[], int l, int h, int key)
{
        int mid;
        while (l <= h)
        {
                mid = (l + h) / 2;
                if (arr[mid] == key)
                {
                        return mid;
                }
                else if (arr[mid] > key)
                {
                        h = mid - 1;
                }
                else
                {
                        l = mid + 1;
                }
        }
        return -1;
}
int main()
{
        int arr[] = {1, 2, 3, 4, 25, 45, 63};
        int len = sizeof(arr) / sizeof(arr[0]);
        cout<<"sorted array is  : ";
        for (int  i = 0; i < len; i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout <<"the element to be searched is : 63 "<<endl;
        cout<<"element is present at index : " <<binary(arr, 0, len - 1, 63);
}
