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
        min = (nums[i] > min) ? nums[i] : min;
    }
    return min;
}

void generateFrequency(int nums[], int n, int frequency[]) {
    for (int i = 0; i < n; i++) {
        frequency[i] = 1;
        for (int j = i + 1; j < n; j++) {
            frequency[i] += (nums[i] == nums[j]) ? 1 : 0;
        }
    }
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
    int frequency [size];

    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int maximum = max(nums, size);
    int minimum = min(nums, size);

    generateFrequency(nums, size, frequency);

    for (int i = 0; i < size; i++) {
        cout << frequency[i] << " ";
    }

}

