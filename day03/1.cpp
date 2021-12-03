#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    string gamma = "", epsilon = "";
    vector<string> inputs;
    vector<int> v1(12, 0), v2(12, 0);
    while (cin >> line) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '1')
                v1[i]++;
            else
                v2[i]++;
        }
    }
    for (int i = 0; i < 12; i++) {
        if (v1[i] > v2[i]) {
            gamma += "1";
            epsilon += "0";

        }
        else {
            gamma += "0";
            epsilon += "1";
        }
    }
    cout << bitset<12>(gamma).to_ulong() * bitset<12>(epsilon).to_ulong() << endl;
    return 0;
}