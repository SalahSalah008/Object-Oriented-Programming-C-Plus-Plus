#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <numeric>

using namespace std;

int iterativeSearch(vector<int> v, int elem) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == elem) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> &v, int start, int end, int elem) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (v[mid] == elem) {
        return mid;
    } else if (v[mid] > elem) {
        return binarySearch(v, start, mid - 1, elem);
    } else {
        return binarySearch(v, mid + 1, end, elem);
    }
}

void vecGen(string filename, vector<int> &v) {
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num) {
        v.push_back(num);
    }
    file.close();
}

int main() {
    vector<int> v;
    vecGen("100000_numbers.csv", v);

    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    vector<double> iterative_times;
    vector<double> binary_times;

    for (int i = 0; i < elem_to_find.size(); i++) {
        int elem = elem_to_find[i];
        clock_t start = clock();
        iterativeSearch(v, elem);
        clock_t end = clock();
        iterative_times.push_back(double(end - start) / CLOCKS_PER_SEC);
    }

    for (int i = 0; i < elem_to_find.size(); i++) {
        int elem = elem_to_find[i];
        clock_t start = clock();
        binarySearch(v, 0, v.size() - 1, elem);
        clock_t end = clock();
        binary_times.push_back(double(end - start) / CLOCKS_PER_SEC);
    }

    double iterative_average = accumulate(iterative_times.begin(), iterative_times.end(), 0.0) / iterative_times.size();
    double binary_average = accumulate(binary_times.begin(), binary_times.end(), 0.0) / binary_times.size();

    cout << "Average time for iterative search: " << iterative_average << " sec" << endl;
    cout << "Average time for binary search: " << binary_average << " sec" << endl;

    return 0;
}