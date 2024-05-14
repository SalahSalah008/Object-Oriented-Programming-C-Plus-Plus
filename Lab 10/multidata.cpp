#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <numeric>

using namespace std;

template<typename T>
int iterativeSearch(const vector<T>& v, T elem) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == elem) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void vecGen(const string& filename, vector<T>& v) {
    ifstream file(filename);
    T num;
    v.clear();
    while (file >> num) {
        v.push_back(num);
    }
    file.close();
}

template<typename T>
int binarySearch(const vector<T>& v, int start, int end, T elem) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[mid] == elem) {
            return mid;
        } else if (v[mid] > elem) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v_int;
    vecGen<int>("10000_numbers.csv", v_int);
    vector<int> elem_to_find_int;
    vecGen<int>("test_elem.csv", elem_to_find_int);

    for(size_t i = 0; i < elem_to_find_int.size(); ++i) {
        clock_t start = clock();
        int index = binarySearch(v_int, 0, v_int.size() - 1, elem_to_find_int[i]);
        clock_t end = clock();
        double elapsed_time_in_sec = double(end - start) / CLOCKS_PER_SEC;
        cout << index << " " << elapsed_time_in_sec << " sec" << endl;
    }

    vector<double> v_double;
    vecGen<double>("1000_double.csv", v_double);
    vector<double> elem_to_find_double;
    vecGen<double>("double_to_find.csv", elem_to_find_double);

    for(size_t i = 0; i < elem_to_find_double.size(); ++i) {
        clock_t start = clock();
        int index = binarySearch(v_double, 0, v_double.size() - 1, elem_to_find_double[i]);
        clock_t end = clock();
        double elapsed_time_in_sec = double(end - start) / CLOCKS_PER_SEC;
        cout << index << " " << elapsed_time_in_sec << " sec" << endl;
    }

    return 0;
}
