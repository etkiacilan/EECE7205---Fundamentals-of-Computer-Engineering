// Example program
#include <iostream>
#include <chrono>
using namespace std;

// Function prototype;
void insertion_sort(int sort_this_array[], int input_array_size);
void merge_sort(int A[], int l, int h);
void merge(int A[], int l, int mid, int h);

int main()
{
	// define clocks.
	std::chrono::high_resolution_clock::time_point start_time_merge, end_time_merge, start_time_insertion, end_time_insertion;
	 
	// input array specs.
	int A[10]{ 0 };
	int B[10]{ 0 };

	for (int i = 0; i < 10; i++) {
		A[i] = 11 - i;
		B[i] = 11 - i;
	}

	// sort array with insertion sort.
	start_time_insertion = std::chrono::high_resolution_clock::now();
	insertion_sort(A, 10);
	end_time_insertion = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed_time1 = end_time_insertion - start_time_insertion;
	cout << "Elapsed Time for Insertion Sort: " << elapsed_time1.count() << endl;


	// print sorted A.
	cout << "SORTED WITH INSERTION SORT" << endl;
	for (auto dummy : A) {
		cout << dummy << endl;
	}


	// sort array with merge sort.
	start_time_merge = std::chrono::high_resolution_clock::now();
	merge_sort(B, 0, 9);
	end_time_merge = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed_time2 = end_time_merge - start_time_merge;
	cout << "Elapsed Time for Merge Sort: " << elapsed_time2.count() << endl;


	// print sorted B.
	cout << "SORTED WITH MERGE SORT" << endl;
	for (auto dummy : B) {
		cout << dummy << endl;
	}

	return 0;
}

void insertion_sort(int sort_this_array[], int input_array_size) {

	int n{ input_array_size };
	int key{ 0 };
	int i{ 0 };

	for (int j = 1; j < n; j++) {

		key = sort_this_array[j];
		i = j - 1;

		while (i > -1 && sort_this_array[i] > key) {
			sort_this_array[i + 1] = sort_this_array[i];
			i -= 1;
		}
		sort_this_array[i + 1] = key;

		/* /* For demonstration of Q2.
		cout << "==============" << j << "===============" << endl;
		for (int t = 0; t < input_array_size; t++) {
			cout << sort_this_array[t] << endl;
		} */

	}


}

void merge_sort(int A[], int l, int h) {

	if (l < h) {

		int mid = (l + h) / 2; // integer division (floor).
		merge_sort(A, l, mid);
		merge_sort(A, mid + 1, h);
		merge(A, l, mid, h);
	}
}


void merge(int A[], int l, int mid, int h) {

	int i{ l };
	int j{ mid + 1 };
	int k{ l };
	int* B = new int[h + 1] {0}; // create a dynamic array.

	while (i <= mid && j <= h) {

		if (A[i] < A[j]) {
			B[k] = A[i];
			k++;
			i++;
		}
		else {
			B[k] = A[j];
			k++;
			j++;
		}
	}

	for (; i <= mid; i++) {
		B[k] = A[i];
		k++;
	}

	for (; j <= h; j++) {
		B[k] = A[j];
		k++;
	}

	for (int t = l; t <= h; t++) {
		A[t] = B[t];
	}

	delete[] B; // delete B.
}