// Copyright (c) 2021 Lovro Vrcek

#include <bits/stdc++.h>

using namespace std;


int main() {
    string command;
    int val;
    int forward = 0, depth = 0;
    while (cin >> command >> val) {
        if (command == "forward") {
            forward += val;
        } else if (command == "down") {
            depth += val;
        } else {
            depth -= val;
        }
    }
    cout << forward * depth << endl;
    return 0;
}
