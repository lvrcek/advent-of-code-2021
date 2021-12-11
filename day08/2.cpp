#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::set;

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

set<char> union_all(vector<set<char>> sets) {
    set<char> res;
    for (auto& el : sets) {
        std::set_union(res.begin(), res.end(),
                        el.begin(), el.end(),
                        std::inserter(res, res.begin()));
    }
    return res;
}

std::map<string, std::set<char>> init_screen() {
    std::map<string, std::set<char>> screen {
        {"top", std::set<char>()},
        {"mid", std::set<char>()},
        {"bot", std::set<char>()},
        {"lu", std::set<char>()},
        {"lb", std::set<char>()},
        {"ru", std::set<char>()},
        {"rb", std::set<char>()},
    };
    return screen;
}

void print_set(set<char> s) {
    for (auto& el : s)
        std::cout << el << " ";
    std::cout << std::endl;
}

int main() {
    string line;
    std::ifstream iss("in.txt");
    int counter = 0;

    std::map<string, set<char>> screen;
    while(getline(iss, line)) {
        vector<string> spl = split(line, " | ");
        vector<string> left = split(spl[0], " ");
        vector<string> right = split(spl[1], " ");
        std::sort(left.begin(), left.end(), [](const auto& lhs, const auto& rhs) {
                return lhs.size() < rhs.size();
        });
        std::map<string, set<char>> screen = init_screen();
        vector<string> five_digs, six_digs;
        set<char> tmp;

        for (auto& digit : left) {
            if (digit.size() == 2) {
                tmp = set<char>(digit.begin(), digit.end());
                screen["ru"] = tmp;
                screen["rb"] = tmp;
            }
            if (digit.size() == 3) {
                tmp = set<char>(digit.begin(), digit.end());
                std::set_difference(tmp.begin(), tmp.end(),
                                    screen["ru"].begin(), screen["ru"].end(),
                                    std::inserter(screen["top"], screen["top"].begin()));
            }
            if (digit.size() == 4) {
                tmp = set<char>(digit.begin(), digit.end());
                std::set_difference(tmp.begin(), tmp.end(),
                         screen["ru"].begin(), screen["ru"].end(),
                         std::inserter(screen["mid"], screen["mid"].begin()));
                std::set_difference(tmp.begin(), tmp.end(),
                         screen["ru"].begin(), screen["ru"].end(),
                         std::inserter(screen["lu"], screen["lu"].begin()));
            }
            if (digit.size() == 5) {
                five_digs.push_back(digit);
            }
            if (digit.size() == 6) {
                six_digs.push_back(digit);
            }
        }

        set<char> union_tmp;
        for (auto& digit : five_digs) {
            tmp = set<char>(digit.begin(), digit.end());
            if (std::includes(tmp.begin(), tmp.end(),
                              screen["ru"].begin(), screen["ru"].end())) {
                union_tmp = union_all({screen["ru"], screen["top"], screen["mid"]});
                std::set_difference(tmp.begin(), tmp.end(),
                                    union_tmp.begin(), union_tmp.end(),
                                    std::inserter(screen["bot"], screen["bot"].begin()));
                five_digs.erase(std::remove(five_digs.begin(), five_digs.end(), digit),
                                five_digs.end());
            }
        }
        for (auto& digit : five_digs) {
            tmp = set<char>(digit.begin(), digit.end());
            if (std::includes(tmp.begin(), tmp.end(),
                              screen["mid"].begin(), screen["mid"].end())) {
                union_tmp = union_all({screen["bot"], screen["top"], screen["mid"]});
                screen["rb"].clear();
                std::set_difference(tmp.begin(), tmp.end(),
                                    union_tmp.begin(), union_tmp.end(),
                                    std::inserter(screen["rb"], screen["rb"].begin()));
                union_tmp.clear();
                std::set_difference(screen["ru"].begin(), screen["ru"].end(),
                                    screen["rb"].begin(), screen["rb"].end(),
                                    std::inserter(union_tmp, union_tmp.begin()));
                screen["ru"] = union_tmp;
                five_digs.erase(std::remove(five_digs.begin(), five_digs.end(), digit),
                                five_digs.end());
            }
        }
        for (auto& digit : five_digs) {
            tmp = set<char>(digit.begin(), digit.end());
            union_tmp = union_all({screen["top"], screen["mid"], screen["bot"], screen["ru"]});
            // screen["lb"].clear();
            std::set_difference(tmp.begin(), tmp.end(), union_tmp.begin(), union_tmp.end(),
                                std::inserter(screen["lb"], screen["lb"].begin()));
        }
        for (auto& digit : six_digs) {
            tmp = set<char>(digit.begin(), digit.end());
            if (!std::includes(tmp.begin(), tmp.end(), screen["lu"].begin(), screen["lu"].end())) {
                union_tmp = union_all({screen["ru"], screen["rb"], screen["lb"], screen["top"], screen["bot"]});
                screen["lu"].clear();
                std::set_difference(tmp.begin(), tmp.end(), union_tmp.begin(), union_tmp.end(), std::inserter(screen["lu"], screen["lu"].begin()));
                tmp.clear();
                std::set_difference(screen["mid"].begin(), screen["mid"].end(), screen["lu"].begin(), screen["lu"].end(), std::inserter(tmp, tmp.begin()));
                screen["mid"] = tmp;
            }
        }
        std::map<int, set<char>> mapping;
        mapping[0] = union_all({screen["top"], screen["bot"], screen["ru"], screen["rb"], screen["lu"], screen["lb"]});
        mapping[1] = union_all({screen["ru"], screen["rb"]});
        mapping[2] = union_all({screen["top"], screen["bot"], screen["ru"], screen["lb"], screen["mid"]});
        mapping[3] = union_all({screen["top"], screen["bot"], screen["ru"], screen["rb"], screen["mid"]});
        mapping[4] = union_all({screen["ru"], screen["rb"], screen["lu"], screen["mid"]});
        mapping[5] = union_all({screen["top"], screen["bot"], screen["rb"], screen["lu"], screen["mid"]});
        mapping[6] = union_all({screen["top"], screen["bot"], screen["rb"], screen["lu"], screen["lb"], screen["mid"]});
        mapping[7] = union_all({screen["top"], screen["ru"], screen["rb"]});
        mapping[8] = union_all({screen["top"], screen["bot"], screen["ru"], screen["rb"], screen["lu"], screen["lb"], screen["mid"]});
        mapping[9] = union_all({screen["top"], screen["bot"], screen["ru"], screen["rb"], screen["lu"], screen["mid"]});

        string number = "";
        set<char> tmp2;
        for (auto& digit: right) {
            tmp2 = set<char>(digit.begin(), digit.end());
            for (auto& el : mapping) {
                if (el.second == tmp2)
                    number += std::to_string(el.first);
            }
        }
        counter += std::stoi(number);

        // print_set(screen["top"]);
        // print_set(screen["mid"]);
        // print_set(screen["bot"]);
        // print_set(screen["ru"]);
        // print_set(screen["rb"]);
        // print_set(screen["lu"]);
        // print_set(screen["lb"]);
    }

    std::cout << counter << std::endl;


    return 0;
}