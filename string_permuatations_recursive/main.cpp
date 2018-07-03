#include <string>
#include <set>
#include <iostream>

using namespace std;

set<string> all_permutations(const string& str, int index = 0) {

    if (index == str.size()) {
        return {""};
    }

    auto substr_permutations = all_permutations(str, index + 1);

    set<string> result;
    for (auto& item : substr_permutations) {
        for (int i = 0; i <= item.size(); ++i) {
            result.insert(item.substr(0, i) + str[index] + item.substr(i));
        } 
    }

    return result;
}

int main(int argc, char* argv[]) {
    string str;

    cout << "input string: " << endl;
    getline(cin, str);

    cout << "your string is: " << str << endl;

    cout << "all permutations of " << str << " :" << endl;
    for (auto& s: all_permutations(str)) {
        cout << s << endl;
    }

    cout << "=================" << endl;

    return 0;
}
