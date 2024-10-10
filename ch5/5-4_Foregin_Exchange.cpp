#include <iostream>
#include <map>

using namespace std;

struct Stu
{
    int A;
    int B;

    bool operator<(const Stu &s) const
    {
        return A < s.A || (A == s.A && B < s.B);
    }

    Stu(int a = 0, int b = 0) : A(a), B(b) {}
};

int main()
{
    // 重定义输入输出
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int n;
    while (cin >> n && n != 0)
    {
        map<Stu, int> m;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            Stu s1(a, b);
            Stu s2(b, a);
            if(m.count(s2))
                m[s2]--;
            else
                m[s1]++;
        }

        bool flag = true;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it->second != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}