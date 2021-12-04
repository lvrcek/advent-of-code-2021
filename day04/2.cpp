#include <bits/stdc++.h>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

std::vector<int> split(string s, string del=" ") {
    int start = 0;
    int end = s.find(del);
    std::vector<int> v;
    while (end != -1) {
        int n = atoi(s.substr(start, end-start).c_str());
        v.push_back(n);
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back(atoi(s.substr(start, end-start).c_str()));
    return v;
}

void print_vector(std::vector<int> v) {
    for (auto& n: v) 
        cout << n << " ";
    cout << endl;
}

void print_table(std::vector<std::vector<int>> table) {
    for (auto& v: table) 
        print_vector(v);
    cout << endl;
}

void print_grid(std::vector<std::vector<std::vector<int>>> grid) {
    for (auto& t: grid)
        print_table(t);
    cout << endl;
}

bool check_table1(std::vector<std::vector<int>> table) {
    bool flag = false;
    for (auto& line: table) {
        flag = true;
        for (auto& n: line) {
            if (n != -1)
                flag = false;
        }
        if (flag) return true;
    }
    return false;
}

bool check_table2(std::vector<std::vector<int>> table) {
    for (int i = 0; i < table[0].size(); i++) {
        bool flag = true;
        for (int j = 0; j < table.size(); j++) {
            if (table[j][i] != -1)
                flag = false;
        }
        if (flag) return true;
    }
    return false;
}

int sum_table(std::vector<std::vector<int>> table) {
    int sum = 0;
    for (auto& line: table) {
        for (auto& n: line) {
            if (n != -1)
                sum += n;
        }
    }
    return sum;
}

int main() {
    std::string line;
    std::ifstream infile("in.txt");
    std::getline(infile, line);
    std::vector<int> numbers = split(line, ",");
    std::getline(infile, line);
    std::vector<std::vector<std::vector<int>>> grids;
    std::vector<std::vector<int>> table;
    while (std::getline(infile, line)) {
        if (line.size() <= 1) {
            grids.push_back(table);
            table.clear();
            continue;
        }
        std::istringstream iss(line);
        int a,b,c,d,e;
        iss >> a >> b >> c >> d >> e;
        std::vector<int> v = {a, b, c, d, e};
        table.push_back(v);
        

    }
    grids.push_back(table);
    cout << grids.size() << " " << grids[0].size() << endl;

    std::vector<std::vector<int>> best;
    std::set<int> solved;
    bool flag = false;
    int last;
    
    for (auto& n: numbers) {
        if (flag) break;
        int index = 0;
        for (auto& table: grids) {
            for (auto& line: table) {
                for (int i = 0; i < line.size(); i++) {
                    if (line[i] == n)
                        line[i] = -1;
                }
            }
            if (check_table1(table) || check_table2(table)) {
                solved.insert(index);
                if (solved.size() == grids.size()) {
                    best = table;
                    last = n;
                    flag = true;
                    break;
                }
            }
            index++;
        }
    }
    print_table(best);
    int sum = sum_table(best);
    cout << sum << " " << last << " " << sum * last << endl;
    return 0;
}