#include <iostream>

using namespace std;

int max(int nums[], int n) {
    int max = nums[0];
    for (int i = 1; i < n; i++) {
        max = (nums[i] > max) ? nums[i] : max;
    }
    return max;
}

int min(int nums[], int n) {
    int min = nums[0];
    for (int i = 1; i < n; i++) {
        min = (nums[i] < min) ? nums[i] : min;
    }
    return min;
} 

string bar(int nums[], int n, int value) {
    string bar = "";
    for (int i = 0; i < n; i++) {
        bar += (value == nums[i]) ? "#" : "";
    }
    return bar;
}

int main() {
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    if (size < 0 || size > 1000) {
        cout << "Invalid input size. Please enter a value between 1 and 1000." << endl;
        return 1;
    }

    int nums [size];

    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int maximum = max(nums, size);
    int minimum = min(nums, size);

    int max = 0;

    for (int i = maximum; i >= minimum; i--) {
        string b = bar(nums, size, i);
        max = (b.size() > max) ? b.size() : max;
        cout << i << "   |" << b << endl;
    }

    cout << "    +";

    int width = 0;

    for (int i = 0; i < max / 10.0; i++) {
        width++;
        cout << "----+----+";
    }

    cout << endl << "    ";

    for (int i = 0; i <= width * 2; i++) {
        cout << i * 5 << "    ";
    }

    cout << endl;
}
