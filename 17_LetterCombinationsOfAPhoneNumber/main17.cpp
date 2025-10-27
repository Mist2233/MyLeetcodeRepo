#include<bits/stdc++.h>


using namespace std;
class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        backtrack(digits);
        return result;
    }

    // 我似乎搞错了一个问题：这里的digits是数字，而最后我们的结果是字母的结果。
    // 而我之前似乎把两个混起来了。

    void backtrack(const string& digits) {
        if (digits.empty()) return;

        if (cur_path.length() == digits.length()) {
            result.push_back(cur_path);
            return;
        }

        // 找到问题了！问题就在下面的cur_path.length() - 1这里
        // 我一开始的想法很好，觉得cur_path.length()表示实际长度，而下标应该从0开始，所以要减一。
        // 但是，我忘记考虑了，cur_path的初始长度为0，因此我其实不需要减一。
        // string todo_list = num_to_string[digits[cur_path.length() - 1]];
        string todo_list = num_to_string[digits[cur_path.length()]];

        for (char ch : todo_list) {
            cur_path.push_back(ch);
            backtrack(digits);
            cur_path.pop_back();
        }
    }

   private:
    // 设定一个数组，存放每个数字对应的字母。
    map<char, string> num_to_string = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> result;
    string cur_path;
};

// 你的原版思路保持不变，这里是一个带有更多优化的版本
class SolutionV2 {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // 直接返回空数组
        
        vector<string> result;
        string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
    
private:
    // 使用静态数组，避免每次创建对象时重新初始化
    const string phone[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        // 如果已经处理完所有数字，将当前组合加入结果
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        // 获取当前数字对应的字母
        string letters = phone[digits[index] - '0'];
        
        // 尝试当前数字的每个字母
        for (char letter : letters) {
            current.push_back(letter);    // 选择
            backtrack(digits, index + 1, current, result);  // 递归
            current.pop_back();           // 撤销选择
        }
    }
};

int main() {
    Solution solution;
    SolutionV2 solutionV2;  // 添加优化版本的测试
    
    // Test case 1: "23"
    vector<string> result1 = solution.letterCombinations("23");
    cout << "Input: \"23\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test case 2: "" (empty string)
    vector<string> result2 = solution.letterCombinations("");
    cout << "Input: \"\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test case 3: "2"
    vector<string> result3 = solution.letterCombinations("2");
    cout << "Input: \"2\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
