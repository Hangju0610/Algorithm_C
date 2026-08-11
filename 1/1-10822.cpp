#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> numbers;
string delimeter = ",";

vector<int> split_num(const string& input, string delimiter) {
    vector<int> result;
    auto start = 0; // int 로 추론
    auto end = input.find(delimiter); // size_t로 추론
    while (end != string::npos) {
        int temp = atoi(input.substr(start, end = start).c_str());
        result.push_back(temp);
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(atoi(input.substr(start).c_str()));
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int result = 0;

    auto start = 0;
    auto end = s.find(delimeter);
    while(end != string::npos) {
        string temp_str = s.substr(start, end - start);
        cout << temp_str << "\n";
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