/* 
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，
找出只包含 1 的最大矩形，并返回其面积。
示例 1：
    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0
    输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    输出：6
    解释：最大矩形如上图所示。
示例 2：
    输入：matrix = []
    输出：0
示例 3：
    输入：matrix = [["0"]]
    输出：0
示例 4：
    输入：matrix = [["1"]]
    输出：1
示例 5：
    输入：matrix = [["0","0"]]
    输出：0
提示：
    rows == matrix.length
    cols == matrix[0].length
    0 <= row, cols <= 200
    matrix[i][j] 为 '0' 或 '1' 
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<char>> matrix;
vector<char> curr_row;
int maximalRectangle(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    if (row == 0 || col == 0) return 0;
    vector<vector<char>> left;
    bool all_zero_flag = 0;
    for (int i = 0; i < row; i ++ ){
        int cur = 0;
        for (int j = 0; j < col; j++){
            if(matrix[i][j] == '1') {
                cur ++ ;
                all_zero_flag = 1;
            }
            else cur = 0;
            left[i].push_back(cur);
        }
    }
    if(all_zero_flag) return 0;
    int res = 0;
    for (int j = 0; j < col; j++){//对于每一列，按照直方图最大面积计算

        stack<int> stk;
        int up[row], down[row];
        for (int i = 0; i < row; i++){
            while (!stk.empty() && left[i][j] <= left[stk.top()][j]) stk.pop();
            up[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        for (int i = row - 1; i >=0; i--){
            while (!stk.empty() && left[i][j] <= left[stk.top()][j]) stk.pop();
            down[i] = stk.empty() ? row : stk.top();
        }

        for (int i = 0; i < row; i ++ ){
            int height = down[i] - up[i] - 1;
            int area = height*left[i][j];
            res = max(res, area);
        }
        
    }

    return res;
}

int main(){
    int row, col;
    int x;
    cin >> row >> col;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> x;
            curr_row.push_back(x);
        }
        matrix.push_back(curr_row);
        curr_row.clear();
    }
    int res = maximalRectangle(matrix);
    cout << res << endl;
    return 0;
}