#include <iostream>
#include <ctime>
using namespace std;
int partition(int arr[], int start, int end)
{
    int pivot = arr[start], count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) { i++; }
        while (arr[j] > pivot) { j--; }
        if (i < pivotIndex && j > pivotIndex) { swap(arr[i++], arr[j--]); }
    }
    return pivotIndex;
}
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}
int binary_s(int l, int r, int m, int n, int arr[])
{
    
    while (l <= r) {
        int m = l + (r - l) / 2;

        
        if (arr[m] == n)
            return m;

        
        if (arr[m] < n)
            l = m + 1;

       
        else
            r = m - 1;
    }
}
int main()
{
	int rn;//рандомное число 
	int const s = 10;//размер массива
	int arr[s];
	for (int i = 0; i < s; i++)
	{
		rn = rand() % 10;
		arr[i] = rn;
	}
	quickSort(arr, 0, s - 1);
    int n;
    int k = 0;
    for (int i = 0; i < s; i++)
    {
        k++;
        cout << arr[i] <<" ";
        if (k == 10)
        {
            k = 0;
            cout << endl;
        }
    }
    cout<< "Введите число, порядковый номер которого хотите получить: ";
    cin >> n;
    int mid, l, r;
    mid = s / 2;
    l = 0;
    r = s;
    cout <<"Порядковый номер: " << binary_s(l, r, mid, n, arr);
	return 0;
}