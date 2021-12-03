#include <bits/stdc++.h>

using namespace std;


int main() {
    string line;
    string gamma = "", epsilon = "";
    vector<string> inputs, vv1, vv2;
    
    while (cin >> line) {
        inputs.push_back(line);
    }
    size_t length = line.size();

    vv1 = vv2 = inputs;
    int yy, ll;
    vector<int> v1(length, 0), v2(length, 0);

    char flag;

    for (int i = 0; i < length; i++) {
        if (vv1.size() == 1) {
            break;
        }

        yy = 0;
        ll = 0;
        for (int j = 0; j < vv1.size(); j++) {
            if (vv1[j][i] == '1')
                yy++;
            else
                ll++;
        }
        if (yy >= ll)
            flag = '1';
        else
            flag = '0';
        
        vector<string> t1;
        for (int j = 0; j < vv1.size(); j++) {
            if (vv1[j][i] == flag) {
                t1.push_back(vv1[j]);
            }
        }
        vv1 = t1;
    }

    for (int i = 0; i < length; i++) {
        if (vv2.size() == 1) {
            break;
        }

        yy = 0;
        ll = 0;
        for (int j = 0; j < vv2.size(); j++) {
            if (vv2[j][i] == '1')
                yy++;
            else
                ll++;
        }
        if (yy < ll)
            flag = '1';
        else
            flag = '0';
        
        vector<string> t2;
        for (int j = 0; j < vv2.size(); j++) {
            if (vv2[j][i] == flag) {
                t2.push_back(vv2[j]);
            }
        }
        vv2 = t2;
    }

    std::cout << bitset<12>(vv1[0]).to_ulong() * bitset<12>(vv2[0]).to_ulong() << endl;
    return 0;
}