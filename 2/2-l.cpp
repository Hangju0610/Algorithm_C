#include <bits/stdc++.h>
using namespace std;

int n, a, score, prevTime;
int leadTime[3];
string s;

int calTime(string s) {
    int min = stoi(s.substr(0, 2));
    int sec = stoi(s.substr(3, 2));
    return (min * 60) + sec;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> s;
        int curTime = calTime(s);
        // 점수 비교, 1이 넣으면 +1, 2가 넣으면 -1

        if (score > 0) {
            leadTime[1] += curTime - prevTime;
        } else if (score < 0) {
            leadTime[2] += curTime - prevTime;
        }

        if (a == 1) {
            score++;
        } else {
            score--;
        }

        prevTime = curTime;
    }

    if (score > 0) {
        leadTime[1] += 48 * 60 - prevTime;
    } else if (score < 0) {
        leadTime[2] += 48 * 60 - prevTime;
    }

    for (int i = 1; i < 3; i ++) {
        int min = leadTime[i] / 60;
        int sec = leadTime[i] % 60;

        string s_min = to_string(min);
        string s_sec = to_string(sec);
        if (s_min.size() == 1) {
            s_min = '0' + s_min;
        }
        if (s_sec.size() == 1) {
            s_sec = '0' + s_sec;
        }
        cout << s_min << ':' << s_sec << '\n';
    }
    return 0;
}

/*
1. 한줄씩 받으면서 score를 매긴다.
2. score를 매길 때, 점수차를 비교하고, 변경된 경우, changeTime을 변경한다.
3. originalTeam이 필요한가?

*/