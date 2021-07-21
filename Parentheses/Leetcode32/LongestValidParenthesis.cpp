/* 
题目描述：
    给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
示例 1：
    输入：s = "(()"
    输出：2
    解释：最长有效括号子串是 "()"
示例 2：
    输入：s = ")()())"
    输出：4
    解释：最长有效括号子串是 "()()"
示例 3：
    输入：s = ""
    输出：0
提示：
    0 <= s.length <= 3 * 104
    s[i] 为 '(' 或 ')'
 */

#include<iostream>

using namespace std;

int longestValidParentheses(string s) {
    int left = 0, right = 0, maxlength = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = max(maxlength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }
    left = right = 0;
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = max(maxlength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return maxlength;
}

int main(){
    string s;
    int res = longestValidParentheses(s);
    cout << res << endl;
    return 0;
}