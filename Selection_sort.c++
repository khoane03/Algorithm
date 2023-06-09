#include <iostream>
using namespace std;

void SELECTION(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
                min = j; 
        }
          swap(a[min], a[i]);
    }
}

int main()
{
    int arr[] = {9, 0, 2, 3, 4, 1, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    SELECTION(arr, size);

    cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
