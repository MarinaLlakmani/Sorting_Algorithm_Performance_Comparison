#include "TimedSorts.h"

TimedSorts::TimedSorts():data(0,0),length(0) {
	//Simple "empty" value constructor
}

TimedSorts::TimedSorts(const vector<int>& firstData) {
	data = firstData;
	//Initializing constructor
}

void TimedSorts::fillData(int size) {
	//Function to set length to size
	//Then fill data with integers 0 to size-1
	length = size;
	data.resize(length);
	sort(data.begin(), data.end(), 0);
}

void TimedSorts::setData(const vector<int>& newData) {
	//set data and length to passed in values
	data = newData;
}

void TimedSorts::PrintData() {
	//print out all values in data
	for (int num : data) {
		cout << num << " ";
	}
	cout << endl;
}

void TimedSorts::scramble(int seed) {
	if (seed == -2) {
		//Sort array in reverse order
		sort(data.begin(), data.end(), greater<>());
	}
	else if (seed == -1)
	{
		//"True" random scramble
		random_device rd;
		mt19937 g(rd());
		shuffle(data.begin(), data.end(), g);
	}
	else if (seed != 0) {
		mt19937 g(seed);
		shuffle(data.begin(), data.end(), g);
	}
}

bool TimedSorts::isSorted() {
	//Check if data is sorted
	return is_sorted(data.begin(), data.end());
}

duration<double, TIME_UNIT> TimedSorts::getLatestSortTime() {
	return Duration;
}

duration<double, TIME_UNIT> TimedSorts::BubbleSort() {
	//Implement Bubble sort, return time taken to sort
	auto begin = high_resolution_clock::now();
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				mySwap(data[j], data[j + 1]);
			}
		}
	}
	auto end = high_resolution_clock::now();
	Duration = duration_cast<duration<double, TIME_UNIT>>(end - begin);
	return Duration;
}

duration<double, TIME_UNIT> TimedSorts::InsertionSort() {
	//Implement Insertion sort, return time taken to sort
	auto begin = high_resolution_clock::now();
	for (int i = 1; i < length; i++) {
		int x = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > x) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = x;
	}
	auto end = high_resolution_clock::now();
	Duration = duration_cast<duration<double, TIME_UNIT>> (end - begin);
	return Duration;
}

duration<double, TIME_UNIT> TimedSorts::MergeSort() {
	//Implement Merge sort, return time taken to sort
	auto begin = high_resolution_clock::now();
	mergeSortRecurse(0, length - 1);
	auto end = high_resolution_clock::now();
	Duration = duration_cast<duration<double, TIME_UNIT >> (end - begin);
	return Duration;

}

void TimedSorts::mergeSortRecurse(int l, int r) {
	//Recursive call for Merge sort
	if (l < r) {
		int m = l + (r - 1) / 2;
		mergeSortRecurse(l, m);
		mergeSortRecurse(m+ 1, r);
		merge(l, m, r);
	}
}
	
void TimedSorts::merge(int l, int m, int r) {
	//Merge function as part of merge sort
	int d1 = m - l + 1;
	int d2 = r - m;
	vector <int> L(d1), R(d2);
	for (int i = 0; i < d1; i++) {
		L[i] = data[l + 1];
	}
	for (int j = 0; j < d2; j++) {
		R[j] = data[m + j + 1];
	}

	int i = 0, j = 0, k = l;
	while (i < d1 && j < d2) {
		if (L[i] <= R[j]) {
			data[k] = L[i];
			i++;
		}
		else {
			data[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < d1) {
		data[k] = L[i];
		i++;
		j++;
	}
	while (j < d2) {
		data[k] = R[j];
		k++;
		j++;
	}
}

duration<double, TIME_UNIT> TimedSorts::QuickSort() {
	//Implement Quick sort, return time taken to sort
	auto begin = high_resolution_clock::now();
	quickSortRecurse(0, length - 1);
	auto end = high_resolution_clock::now();
	Duration = duration_cast<duration<double, TIME_UNIT>>(end - begin);
	return Duration;

}

int TimedSorts::partition(int low, int high)
{
	//Partition function as part of quick sort
	int p = data[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (data[j] < p) {
			i++;
			mySwap(data[i], data[j]);
		}
	}
	mySwap(data[i + 1], data[high]);
	return(i + 1);
}

void TimedSorts::quickSortRecurse(int low, int high)
{
	//Recursive call for Quick sort
	if (low < high) {
		int pi = partition(low, high);
		quickSortRecurse(low, pi - 1);
		quickSortRecurse(pi + 1, high);
	}
}



duration<double, TIME_UNIT> TimedSorts::BuiltInSort() {
	//Use built-in sort() functio, return time taken to sort
	//HINT: Look at scramble() for an example of using sort()...	
	auto begin = high_resolution_clock::now();
	sort(data.begin(), data.end());
	auto end = high_resolution_clock::now();
	Duration = duration_cast<duration<double, TIME_UNIT>>(end - begin);
	return Duration;
}

void TimedSorts::mySwap(int& xp, int& yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}
