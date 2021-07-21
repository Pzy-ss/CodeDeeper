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
#include<stack>
#include<unordered_map>

using namespace std;

/* 力扣解法
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


int longestValidParentheses(const string &s){
    //首先，合格字串的长度等于最后一个匹配的右括号下标减去前一个右括号下标
    //因此，需要保证栈底元素为前一个未匹配的右括号下标
    //另外，一开始栈中需要先入栈一个-1以应对没有右括号的情况
    stack<int> stk;
    stk.push(-1);
    int max_len = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){//如果是左括号直接把下标入栈
            stk.push(i);
        }
        else{
            stk.pop();
            if (stk.empty()){//只有没有左括号下标入栈，才会导致pop之后栈为空
            //要不然pop之后，栈中至少存在前一个未匹配的右括号下标
            //此时直接入栈，使得栈中始终存在未匹配的右括号下标
                stk.push(i);
            }
            else{
                max_len = max(max_len, i - stk.top());
            }
        }
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