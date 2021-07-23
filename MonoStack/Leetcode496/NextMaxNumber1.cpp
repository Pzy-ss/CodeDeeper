/* 
题目描述：
    给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
    请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
    nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。
示例 1:
    输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
    输出: [-1,3,-1]
    解释:
        对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
        对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
        对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
示例 2:
    输入: nums1 = [2,4], nums2 = [1,2,3,4].
    输出: [3,-1]
    解释:
        对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
        对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
提示：
    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 104
    nums1和nums2中所有整数 互不相同
    nums1 中的所有整数同样出现在 nums2 中
进阶：
    你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？ 
*/
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

vector<int> nums1, nums2;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> pairs;
    stack<int> stk;
    vector<int> ans;
    //处理nums2，得到每个数的解
    for (int i = nums2.size() - 1; i >= 0; i--){
        while(!stk.empty() && nums2[i] >= stk.top()){
            stk.pop();
        }
        //利用哈希表存储答案
        pairs[nums2[i]] = stk.empty() ? -1 : stk.top();
        stk.push(nums2[i]);
    }
    //遍历nums1，输出结果
    for (auto num : nums1){
        ans.push_back(pairs[num]);
    }

    return ans;
}

int main(){
    vector<int> ans;
    int x;
    int in_flag = 0;
    while (cin >> x){
        if (cin.get() == '\n'){//检测到换行符
            //根据当前in_flag状态读取输入
            if (in_flag % 2 == 0)
                nums1.push_back(x);
            else
                nums2.push_back(x);
            in_flag ++ ;
            //判断是否需要输出
            if (in_flag % 2 == 0 && in_flag != 0){
                ans = nextGreaterElement(nums1, nums2);
                for (auto item : ans){
                    cout << item << " ";
                }
                cout << endl;
                nums1.clear();
                nums2.clear();
            }
        }
        //没有换行符则正常读取
        else{
            if (in_flag % 2 == 0){
                nums1.push_back(x);
            }
            else{
                nums2.push_back(x);
            }
        }
        

    }
    return 0;
    
}