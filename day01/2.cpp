// Copyright [2021] Lovro Vrcek

#include <bits/stdc++.h>

using namespace std;

int main() {
    int prev;
    int total = 0;
    string line;
    vector<int> values;

    while (getline(cin, line)) {
        if (line.size() == 0)
            break;
        values.push_back(atoi(line.c_str()));
    }

    prev = accumulate(values.begin(), values.begin() + 3, 0);
    for (auto it = values.begin() + 1; it != values.end() - 2; it++) {
        int curr = accumulate(it, it + 3, 0);
        if (curr > prev) {
            total++;
        }
        prev = curr;
    }
    cout << total << endl;
    return 0;
}
