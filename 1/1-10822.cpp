#include <bits/stdc++.h>
using namespace std;

string s;
string delimeter = ",";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int result = 0;

    auto start = 0;
    auto end = s.find(delimeter);
    while(end != string::npos) {
        string temp_str = s.substr(start, end - start);
        // cout << temp_str << "\n";
        int temp = atoi(temp_str.c_str());
        result += temp;
        start = end + delimeter.size();
        end = s.find(delimeter, start);
    }
    string last = s.substr(start);
    result += atoi(last.c_str());
    cout << result << '\n';

    return 0;
}