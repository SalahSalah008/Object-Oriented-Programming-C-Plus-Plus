#include <iostream>
#include <vector>

using namespace std;

void printMemVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "Value: " << v[i] << " at Memory Location: " << &v[i] << endl;
    }
}

void incVecBy10(vector<int>& v) {
    for (int& val : v) {
        val += 10;
    }
}

int main() {
    const int SIZE = 5;
    vector<int> vec(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        vec[i] = 100 + i;
    }

    cout << "Before Increment---------------" << endl;
    printMemVec(vec);

    incVecBy10(vec);

    cout << "After Increment---------------" << endl;
    printMemVec(vec);

    vec.pop_back();

    cout << "After Pop---------------" << endl;
    printMemVec(vec);

    vec.push_back(101);
    vec.push_back(102);

    cout << "After Push---------------" << endl;
    printMemVec(vec);

    return 0;
}
