#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // 重定义输入输出
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int n;
    while (cin >> n)
    {
        if(n == 0)
            break;

        // 初始化队列
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);
        
        // 执行操作
        cout << "Discarded cards:";
        while (q.size() > 1)
        {
            cout << " " << q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            if (q.size() > 1)
                cout << ",";
        }
        cout << endl;
        cout << "Remaining card: " << q.front() << endl;
    }

    return 0;
}