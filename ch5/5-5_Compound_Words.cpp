#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    // 重定义输入输出
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);

    set<string> dict;
    // 读取单词字典
    string s;
    while (cin >> s)
        dict.insert(s);
    // 遍历字典
    for (const string &word : dict)
    {
        // 枚举分割点
        for (int i = 1; i < word.size(); i++)
        {
            // 判断两个子串是否在字典中
            if (dict.count(word.substr(0, i)) && dict.count(word.substr(i)))
            {
                cout << word << endl;
                break;
            }
        }
    }

    return 0;
}