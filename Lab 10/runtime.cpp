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

void writeTimes(string filename, const vector<double> times, const vector<int> n) {
    ofstream myFile(filename);
    myFile << "Number of Elements (n)\t Time (sec) " << endl;
    for(int i = 0; i < times.size(); i++) {
        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

double average(const vector<double>& a) {
    double sum = 0.0;
    for (double num : a) {
        sum += num;
    }
    return sum / a.size();
}

int main() {
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    vector<int> file_sizes;
    vecGen("sizes.csv", file_sizes);

    vector<double> itimes, btimes;
    vector<int> times_sizes;

    for (int size : file_sizes) {
        string filename = to_string(size) + "_numbers.csv";
        vector<int> v;
        vecGen(filename, v);

        cout << filename << endl;

        // Time iterative search
        vector<double> times;
        for (int elem : elem_to_find) {
            clock_t start = clock();
            iterativeSearch(v, elem);
            clock_t end = clock();
            times.push_back(double(end - start) / CLOCKS_PER_SEC);
        }
        double average_itime = average(times);
        itimes.push_back(average_itime);
        times.clear();

        // Time binary search
        sort(v.begin(), v.end());  // Sort the vector for binary search
        for (int elem : elem_to_find) {
            clock_t start = clock();
            binarySearch(v, 0, v.size() - 1, elem);
            clock_t end = clock();
            times.push_back(double(end - start) / CLOCKS_PER_SEC);
        }
        double average_btime = average(times);
        btimes.push_back(average_btime);

        times_sizes.push_back(v.size());
    }

    writeTimes("iterativeSearch_times.csv", itimes, times_sizes);
    writeTimes("binarySearch_times.csv", btimes, times_sizes);

    return 0;
}
