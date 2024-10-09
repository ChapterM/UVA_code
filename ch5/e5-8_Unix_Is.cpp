#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    // 重定义输入输出
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int T;
    while (scanf("%d", &T) != EOF)
    {
        // 单词列表
        set<string> list;
        int Max_len = 0;

        // 读取单词，计算最大长度
        for (int i = 0; i < T; i++)
        {
            string word;
            cin >> word;
            if (Max_len < word.size())
                Max_len = word.size();
            list.insert(word);
        }
        // 计算输出列数
        int col = list.size() % (62 / (Max_len + 2));
        if(col)
            col = list.size() / (62 / (Max_len + 2)) + 1;
        else
            col = list.size() / (62 / (Max_len + 2));
        vector<string> vec[col]; // 使用括号初始化数组
        while (!list.empty())
        {
            for (int i = 0; !list.empty();)
            {
                vec[i].push_back(*list.begin());
                list.erase(list.begin());
                i++;
                i %= col;
            }
        }
        // 输出
        for (int i = 0; i < 60; i++)
            printf("-");
        printf("\n");
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                if (j == vec[i].size() - 1)
                    printf("%-*s", Max_len, vec[i][j].c_str());
                else
                    printf("%-*s", Max_len + 2, vec[i][j].c_str());
            }
            printf("\n");
        }
    }

    return 0;
}
