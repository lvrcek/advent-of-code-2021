#include <bits/stdc++.h>

using std::string;
using std::vector;

vector<string> split(string line, string del) {
    int start = 0;
    int end = line.find(del);
    vector<string> v;
    while(end != -1) {
        v.push_back(line.substr(start, end-start));
        start = end + del.size();
        end = line.find(del, start);
    }
    v.push_back(line.substr(start, end-start));
    return v;
}

int main() {
    string line;
    std::ifstream iss("in.txt");
    int counter = 0;
    while(getline(iss, line)) {
        vector<string> splitted = split(line, " | ");
        vector<string> left = split(splitted[0], " ");
        vector<string> right = split(splitted[1], " ");
        vector<int> lengths = {2, 3, 4, 7};
        for (auto s : right) {
            if (std::find(lengths.begin(), lengths.end(), s.size()) != lengths.end())
                counter++;
        }
    }
    std::cout << counter << std::endl;

    return 0;
}