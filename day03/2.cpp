// Copyright (c) 2021 Lovro Vrcek

#include <bits/stdc++.h>

using namespace std;


int main() {
    string line;
    ifstream iss("in.txt");
    string gamma = "", epsilon = "";
    vector<string> inputs, gam_vec, eps_vec, t1, t2;
    const int bitlen = 12;

    while (iss >> line) {
        inputs.push_back(line);
    }

    gam_vec = eps_vec = inputs;
    int ones, zeros;
    char flag;

    for (int i = 0; i < bitlen; ++i) {
        if (gam_vec.size() == 1)
            break;
        ones = zeros = 0;
        for (int j = 0; j < gam_vec.size(); ++j) {
            if (gam_vec[j][i] == '1')
                ++ones;
            else
                ++zeros;
        }
        flag = ones >= zeros ? '1' : '0';
        t1.clear();
        for (int j = 0; j < gam_vec.size(); ++j) {
            if (gam_vec[j][i] == flag)
                t1.push_back(gam_vec[j]);
        }
        gam_vec = t1;
    }

    for (int i = 0; i < bitlen; ++i) {
        if (eps_vec.size() == 1)
            break;
        ones = zeros = 0;
        for (int j = 0; j < eps_vec.size(); ++j) {
            if (eps_vec[j][i] == '1')
                ++ones;
            else
                ++zeros;
        }
        flag = ones < zeros ? '1' : '0';
        t2.clear();
        for (int j = 0; j < eps_vec.size(); j++) {
            if (eps_vec[j][i] == flag)
                t2.push_back(eps_vec[j]);
        }
        eps_vec = t2;
    }

    cout << bitset<bitlen>(gam_vec[0]).to_ulong() * bitset<bitlen>(eps_vec[0]).to_ulong()
         << endl;
    return 0;
}
