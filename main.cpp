#include <iostream>
#include "DynamicArray.h"

using namespace std;

template <class T>
void printArr(Array<T> & arr) {
    for (int i = 0; i < arr.length(); i++)
        cout << arr[i] << ", ";
    cout << endl;
}

void fn1(Array<int> arr) {
    arr[0] = 20;
    printArr(arr);
}

int main()
{
    int *arr = new int[3]﻿﻿﻿{1000,2000,3000};
	Array<int> arr1(2);
	int numEls = 0;
	arr1[0] = 10; numEls = 1;

	fn1(arr1);

	printArr(arr1);

	Array<int> arr2(4);
	arr2 = arr1;    // arr2.operator = (arr1);
	arr2[0] = 30;
	printArr(arr2);
	printArr(arr1);

	/* arr1[1] = 11; numEls = 2;
	printArr(arr1);
	arr1.changeSize(4);
	arr1[2] = 12; numEls = 3;	// cout << arr1.length() << endl;
	printArr(arr1);
	arr1[3] = 13; numEls = 4; 	// cout << arr1.length() << endl;
	printArr(arr1);
	arr1.changeSize(8);
	arr1[4] = 14; numEls = 5;	// cout << arr1.length() << endl;
	printArr(arr1);

	arr1.changeSize(2);
	printArr(arr1);

	Array<string> arr2(2);
	arr2[0] = "Ryan";
	printArr(arr2); */

    return 0;
}
