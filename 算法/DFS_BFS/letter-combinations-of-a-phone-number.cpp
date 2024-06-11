#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        this->digits = digits;
        alphabet['2'] = "abc";
        alphabet['3'] = "def";
        alphabet['4'] = "ghi";
        alphabet['5'] = "jkl";
        alphabet['6'] = "mno";
        alphabet['7'] = "pqrs";
        alphabet['8'] = "tuv";
        alphabet['9'] = "wxyz";
       
        dfs(0, "");
        return ans;
    }

private:
    void dfs(int index, string str) {
        if (index == digits.length()) {
            ans.push_back(str);
            return;
        }
        for (char ch : alphabet[digits[index]]) {
            dfs(index + 1, str + ch);
        }
    }
    string digits;
    vector<string> ans;
    unordered_map<char, string> alphabet;
};