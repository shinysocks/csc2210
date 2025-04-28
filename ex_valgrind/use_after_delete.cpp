#include <iostream>
using namespace std;

int main() {
    int* ptr = new int;
    *ptr = 5; // use BEFORE delete
    delete ptr;
    return 0;
}
