// Copyright (c) 2021 Lovro Vrcek

#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    ifstream iss("in.txt");
    string gamma = "", epsilon = "";
    vector<string> inputs;
    const int bitlen = 12;
    vector<int> v1(bitlen, 0), v2(bitlen, 0);
    while (iss >> line) {
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '1')
                ++v1[i];
            else
                ++v2[i];
        }
    }
    for (int i = 0; i < bitlen; ++i) {
        if (v1[i] > v2[i]) {
            gamma += "1";
            epsilon += "0";
        } else {
            gamma += "0";
            epsilon += "1";
        }
    }
    cout << bitset<bitlen>(gamma).to_ulong() * bitset<bitlen>(epsilon).to_ulong()
         << endl;
    return 0;
}
