#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);

int* pop_back(int* arr, int &n);
int* pop_front(int* arr, int &n);

int* erase(int* arr, int &n, int index);
int* insert(int* arr, int &n, int index, int value );

void main()
{
	setlocale(LC_ALL, "");
	int n;	
	cout << "Input number of elements: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);


	int value;
	cout << "Input value to push back: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	

	cout << "Input value to push front: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	
	
	int index;
	cout << "Input index: "; cin >> index;
	cout << "Input value: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);


	cout << "Input index to delete value: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);


	arr = pop_back(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);


	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{

	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[n] = value;
	n++;
	delete[]arr;
	arr = buffer;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	n++;
	delete[]arr;
	arr = buffer;
	return arr;
}

int* pop_front(int* arr, int &n)
{
	int* buffer = new int[n - 1];
	for (int i = 1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	n--;
	delete[]arr;
	arr = buffer;
	return arr;
}
int* pop_back(int* arr, int &n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	n--;
	delete[]arr;
	arr = buffer;
	return arr;
}

int* erase(int* arr, int &n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		if (i >= index)
		{
			buffer[i] = arr[i + 1];
		}
		else
		{
			buffer[i] = arr[i];
		}
	}
	n--;
	delete[]arr;
	arr = buffer;
	return arr;
}
int* insert(int* arr, int &n, int index, int value)
{
	
	int* buffer = new int[n + 1];
	buffer[index] = value;
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	n++;
	delete[]arr;
	arr = buffer;
	return arr;
}

