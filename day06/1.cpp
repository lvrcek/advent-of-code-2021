// Copyright (c) 2021 Lovro Vrcek

#include <bits/stdc++.h>

std::vector<uint64_t> split(std::string s, std::string del = " ") {
    std::vector<uint64_t> v;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        v.push_back(atoi(s.substr(start, end-start).c_str()));
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back((uint64_t)atoi(s.substr(start, end-start).c_str()));
    return v;
}

int main() {
    std::ifstream iss("in.txt");
    std::string line;
    std::vector<uint64_t> histogram(9, 0);
    int days = 80;

    while (getline(iss, line)) {
        for (auto& n : split(line, ",")) {
            ++histogram[n];
        }
    }

    for (int i = 0; i < days; ++i) {
        std::vector<uint64_t> tmp(histogram.begin() + 1, histogram.end());
        tmp[6] += histogram[0];
        tmp.push_back(histogram[0]);
        histogram = tmp;
    }

    std::cout << std::accumulate(histogram.begin(), histogram.end(),
                                 decltype(histogram)::value_type(0))
              << std::endl;
    return 0;
}
