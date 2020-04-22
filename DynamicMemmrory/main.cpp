#include<iostream>
using namespace std;

void Print(int arr[], int n);
void FillRAnd(int arr[], int n);

void main()
{
	int n;
	cout << "Input number of elements: "; cin >> n;
	int* arr = new int[n];
	FillRAnd(arr, n);
	Print(arr, n);


	int value;
	cout << "Input value: "; cin >> value;

	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	cout << arr << endl;
	delete[] arr;
	cout << arr << endl;
	arr = buffer;

	arr[n] = value;
	n++;
	Print(arr, n);
	delete[] arr;



}

void FillRAnd(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

