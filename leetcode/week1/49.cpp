#include <bits/stdc++.h>

using namespace std;

void backtrace(vector<int>& trace, vector<bool>& status, 
               vector<vector<int>>& res, vector<int>& nums)
{
    //结束条件
     if (trace.size() == nums.size())
     {
         res.push_back(trace);
         return;
     }
     for (int i = 0; i < nums.size(); ++i)
     {
         if (!status[i])
         {
             //做选择
             status[i] = true;
             trace.push_back(nums[i]);
             backtrace(trace, status, res, nums);
             //撤销选择
             status[i] = false;
             trace.pop_back();
        }
     }
}

vector<vector<int>> permute(vector<int>& nums)
{
    //路径
    vector<int> trace;
    //选择列表的状态
    vector<bool> status(nums.size(), false);
    vector<vector<int>> res;
    backtrace(trace, status, res, nums);
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3};
    for (auto i: permute(nums))
    {
        for (auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

