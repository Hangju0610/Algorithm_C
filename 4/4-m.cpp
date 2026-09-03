#include <bits/stdc++.h>
using namespace std;

string s;
bool flag = true;
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        // cout << i << " : " << s[i] << '\n';
        string temp;
        if (s[i] == 'p' && i + 1 <= s.size())
        {
            temp = s.substr(i, 2);
            if (temp.compare("pi") == 0)
            {
                i++;
                continue;
            }
            else
            {
                flag = false;
                break;
            }
        }
        else if (s[i] == 'k' && i + 1 <= s.size())
        {
            temp = s.substr(i, 2);
            // cout << temp << '\n';
            if (temp.compare("ka") == 0) {
                i++;
                continue;
            }  else {
                flag = false;
                break;
            }
        }
        else if (s[i] == 'c' && i + 2 <= s.size())
        {
            temp = s.substr(i, 3);
            // cout << temp << '\n';
            if (temp.compare("chu") == 0) {
                i = i + 2;
                continue;
            } else {
                flag = false;
                break;
            }
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << "\n";
    else {
        cout << "NO" << '\n';
    }
}