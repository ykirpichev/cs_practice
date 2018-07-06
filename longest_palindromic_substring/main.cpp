#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestPalindromicSubstring(const string& str)
{
    if (str.empty()) {
        return "";
    }

    string expanded = "|";

    for (auto& ch : str) {
        expanded.push_back(ch);
        expanded.push_back('|');
    }

//    cout << "expanded string " << expanded << endl;

    vector<int> lps(expanded.size(), 0);

    int r = 0;
    int c = 0;
    int pos = 0;
    int lpos = 0;
    int i = 0;
    int j = 0;

    while (pos < expanded.size()) {
        if (pos < r) {
            lpos = 2 * c - pos;
//            cout << "pos : " << pos << " c " << c << " lpos " << lpos << " r " << r << " lps[lpos] " << lps[lpos] <<  endl;

            if (lps[lpos] + pos < r) {
                lps[pos] = lps[lpos];
            } else {
                i = r;
                j = 2 * pos - r;

                while (expanded[++i] == expanded[--j] && j >= 0 && i < expanded.size())
                    ;

                c = pos;
                r = i - 1;
                lps[pos] = r - pos;
            }
            
        } else {
            j = pos - 1;
            i = pos + 1;

            while (j >= 0 && i < expanded.size() && expanded[i] == expanded[j]) {
                ++i; --j;
            }

            c = pos;
            r = i - 1;
            lps[pos] = r - pos;

        }
        ++pos;
    }

    auto it = max_element(lps.begin(), lps.end());
//    std::cout << "max element " << *it << endl; 
//    for (auto item : lps) {
//        cout << item << " ";
//    }
//    cout << endl;

    auto max_index = distance(lps.begin(), it);

//    cout << "max_index " << max_index << " max value " << *it << " str size " << expanded.size() << endl;
    auto result = expanded.substr(max_index - *it, 2 * (*it) + 1);
    result.erase(remove_if(result.begin(),
                           result.end(),
                           [](char ch) {return ch == '|';}),
                 result.end());
    return result;
}

int main(int argc, char* argv[])
{
    string str;
    cout << "input string:" << endl;
    cin >> str;
   
    cout << "longest palindromic substring is:" << endl; 
    cout << longestPalindromicSubstring(str) << endl;
    return 0;
}
