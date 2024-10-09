#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

vector<int> list[25];

// 上方木块归位
void Back(vector<int> &a)
{
    vector<int>::iterator it = a.begin();
    while (it != a.end() - 1)
    {
        int t = *it;
        list[t].push_back(t);
        it = a.erase(it);
    }
}

// 上方木块堆叠
void Up(vector<int> &a, vector<int> &b)
{
    vector<int>::iterator p;
    while (!a.empty())
    {
        p = a.end() - 1;
        b.push_back(*p);
        a.pop_back();
    }
}

int main()
{
    // 重定向输入输出
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    // 木块数
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        list[i].push_back(i);

    // 读取指令
    string line;
    string move("move");
    string over("over");
    string onto("onto");
    string pile("pile");
    string quit("quit");
    while (true)
    {
        string str1, str2;
        int num1, num2;
        cin >> str1;

        if (str1 == quit)
            break;

        cin >> num1;
        cin >> str2;
        cin >> num2;

        if (str1 == move && str2 == onto)
        {
            Back(list[num1]);
            Back(list[num2]);
            Up(list[num1], list[num2]);
        }
        else if (str1 == move && str2 == over)
        {
            Back(list[num1]);
            Up(list[num1], list[num2]);
        }
        else if (str1 == pile && str2 == onto)
        {
            Back(list[num2]);
            Up(list[num1], list[num2]);
        }
        else if (str1 == "pile" && str2 == over)
        {
            Up(list[num1], list[num2]);
        }
    }

    // 输出
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        if (!list[i].empty())
        {
            vector<int>::iterator it = list[i].end() - 1;
            for (; it >= list[i].begin(); it--)
                cout << " " << *it;
        }
        cout << endl;
    }

    return 0;
}