/* 
题目描述：
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
    有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。 
示例 1：
    输入：s = "()"
    输出：true
示例 2：
    输入：s = "()[]{}"
    输出：true
示例 3：
    输入：s = "(]"
    输出：false
示例 4：
    输入：s = "([)]"
    输出：false
示例 5：
    输入：s = "{[]}"
    输出：true 
提示：
    1 <= s.length <= 104
    s 仅由括号 '()[]{}' 组成 
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

/* 
//力扣题解
bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {//pairs.count()判断ch对应的key是否有值
                //如果if成立存在，则说明是右括号
                //在右括号的前提下：
                //  1.如果栈为空，则说明没有按照先左后右的顺序，返回不合法
                //  2.栈中必须存在与右括号匹配的左括号，否则返回不合法
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            //如果是左括号则直接入栈
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
} */


bool isValid(const string &s){
    //length()的值为实际字符串的长度，不包括‘\0’
    if (s.length() % 2) //如果奇数直接返回不合法
        return false;
    string test;//这里用string实现栈的效果
    //使用哈希表进行查询
    unordered_map<char, char> dict = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };
    for (int i = 0; i < s.length(); i++){
        //这里if-else默认了输入都是先左后右
        //如果没有这一条件，即为了判别出现先后再左的情况
        //参考上面的题解，先判断此时的字符是左括号还是右括号
        if (test.empty()) //如果空，直接入栈
            test.push_back(s[i]);
        else{//否则判断栈顶元素与此时的s[i]是否匹配
            if (s[i] == dict[*(test.end()-1)]) //如果匹配，栈顶元素出栈
                test.pop_back();//这里的pop，是将末尾end()-1处的元素pop
            else test.push_back(s[i]); //否则，s[i]入栈
        }
    }
    if (test.empty())
        return true;
    else
        return false;
}

int main(){
    string s;
    cin >> s;
    cout << s.size() << endl;
    bool ans = isValid(s);
    cout << ans << endl;
}


