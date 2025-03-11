#include <iostream>
#include <map>
using namespace std;

void count_inputs(int min, int max, map<int, int> &frequencies) {
    int input;
    cin >> input;

    while (cin) {
        if (input > max || input < min) {
            cout << "Value " << input << " is out of range." << endl;
        } else {
            frequencies[input]++;
        }
        cin >> input;
    }
}

void report_most_frequent_items(const map<int, int> &frequencies) {
    cout << "Most frequent items:" << endl;

    for (auto val : frequencies) {
        cout << val.first << " : " << val.second  << endl;
    }
}

int main() {
    int min, max;
    cin >> min >> max;

    map<int, int> frequencies;
    count_inputs(min, max, frequencies);
    report_most_frequent_items(frequencies);

    return 0;
}

