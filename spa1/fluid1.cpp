// Noah Dinan - fluid1

#include <iostream>
using namespace std;


int main() {
    int differential = 0;
    string time, fluid, amount;
    cin >> time;
    cin >> fluid;
    cin >> amount;

    while (cin) {
        if (fluid == "urine" || fluid == "bloodloss" || fluid == "diarrhea") {
            differential -= stoi(amount);
        } else {
            differential += stoi(amount);

            if (differential >= 1000) {
                cout << "after consuming " << fluid <<" at " << time;
                cout << ", intake exceeds output by " << differential << " ml" << endl;
            }
        }

        cin >> time;
        cin >> fluid;
        cin >> amount;
    }

    cout << "the final fluid differential is " << differential << " ml";
}
