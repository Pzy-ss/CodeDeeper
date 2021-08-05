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
#include<string>

using namespace std;

/*力扣解法
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
} */

//参照上面解法的思路自己再写一遍
//贪心算法，主要思路是从左到右遍历，检测右括号数大于左括号数的情况
//然后从右到左遍历，检测左括号数大于右括号数的情况
int longestValidParentheses(const string &s){
    int cur_len = 0;
    int max_len = 0;
    int left = 0, right = 0;
    //从左到右遍历
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            left ++;
        }
        else if (s[i] == ')'){
            right ++;
        }
        //判断左右括号数量关系
        if (right > left){
            left = 0;
            right = 0;
        }
        else if (left == right){
            cur_len = left + right;
        }
        max_len = max(max_len, cur_len);
    }
    //重置left, right
    left = right = 0;
    //从左到右检测不到类似((())左括号一直大于右括号的情况
    //所以还需要从右到左遍历
    for (int i = s.length() - 1; i >= 0; i--){
        if (s[i] == '('){
            left ++;
        }
        else if (s[i] == ')'){
            right ++;
        }
        //判断左右括号数量关系
        if (left > right){
            left = 0;
            right = 0;
        }
        else if (left == right){
            cur_len = left + right;
        }
        max_len = max(max_len, cur_len);
    }
    return max_len;
}

int main(){
    string s;
    cin >> s;
    int res = longestValidParentheses(s);
    cout << res << endl;
    return 0;
}