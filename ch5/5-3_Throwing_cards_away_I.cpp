#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // �ض����������
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int n;
    while (cin >> n)
    {
        if(n == 0)
            break;

        // ��ʼ������
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);
        
        // ִ�в���
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