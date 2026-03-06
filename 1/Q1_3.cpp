#include <bits/stdc++.h>
using namespace std;
string dopa = "umzunsik";

int main() {
    cout << dopa.substr(0, 3) << "\n";
    reverse(dopa.begin(), dopa.end());
    cout << dopa << "\n";
    dopa += " umzunsik";
    cout << dopa << "\n";
    return 0;
}

/*
umz
kisnuzmu
kisnuzmu umzunsik
*/