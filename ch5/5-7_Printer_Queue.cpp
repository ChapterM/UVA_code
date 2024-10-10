#include <iostream>
#include <queue>

using namespace std;

// �ж��Ƿ���ڸ�����������
bool First(queue<int> q, int t);

int main()
{
    // �ض����������
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        // ��ȡ�������
        int n, m;
        cin >> n >> m;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            q.push(x);
        }

        // ģ���ӡ����
        int time = 0;
        while (true)
        {
            if(First(q, q.front()))
            {
                time++;
                if(m == 0)
                {
                    cout << time << endl;
                    break;
                }
                else
                {
                    q.pop();
                    m--;
                }
            }
            else
            {
                q.push(q.front());
                q.pop();
                m = (m == 0) ? q.size() - 1 : m - 1;
            }
        }
    }

    return 0;
}

bool First(queue<int> q, int t)
{
    for (int i = 0; i < q.size(); i++)
    {
        if (q.front() > t)
        {
            return false;
        }
        q.push(q.front());
        q.pop();
    }
    return true;
}