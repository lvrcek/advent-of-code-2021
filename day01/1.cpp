#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, prev;
    int flag = 0;
    int total = 0;
    string line;
    while (getline(cin, line)) {
        if (line.size() == 0)
            break;
        n = atoi(line.c_str());
        if (!flag) {
            flag = 1;
            prev = n;
            continue;
        }
        if (n > prev)
            total++;
        prev = n;
    }
    cout << total << endl;
    return 0;
}