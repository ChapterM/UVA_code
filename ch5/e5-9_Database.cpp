#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int words[10000][10];

int main()
{
    // 重定义输入输出
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int Row, Col;
    while (scanf("%d%d", &Row, &Col) != EOF)
    {
        map<string, int> dict;
        // 读取字符串,映射到int
        int order = 0;
        for (int i = 0; i < Row; i++)
        {
            string str_line = "";
            do
            {
                getline(cin, str_line);
            } while (str_line == "");

            stringstream ss(str_line);
            string str_tmp;
            for (int j = 0; j < Col; j++)
            {
                getline(ss, str_tmp, ',');
                if (dict.count(str_tmp))
                    words[i][j] = dict[str_tmp];
                else
                {
                    words[i][j] = order++;
                    dict[str_tmp] = words[i][j];
                }
            }
        }

        int flag = true;
        // 遍历列
        for (int i = 0; i < Col; i++)
        {
            for (int j = i + 1; j < Col; j++)
            {
                map<vector<int>, int> dict_row;
                for (int k = 0; k < Row; k++)
                {
                    if (dict_row.count({words[k][i], words[k][j]}))
                    {
                        if (flag)
                        {
                            printf("NO\n");
                            flag = false;
                        }
                        printf("%d %d\n", dict_row[{words[k][i], words[k][j]}] + 1, k + 1);
                        printf("%d %d\n", i + 1, j + 1);
                    }
                    else
                        dict_row[{words[k][i], words[k][j]}] = k;
                }
            }
        }

        // 输出
        if (flag)
            printf("YES\n");
    }
    return 0;
}