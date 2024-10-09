#include <iostream>
#include <queue>
#include <map>

using namespace std;

const int N_max = 1000 + 10;

int main()
{
    // �ض����������
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int t, n, num;
    int T = 1;
    bool first = true;
    while (scanf("%d", &t) == 1 && t != 0)
    {
        map<int, int> team;
        queue<int> Que[N_max];
        queue<int> order;

        printf("Scenario #%d\n", T++);
        // ��ȡ�Ŷ�����
        for (int i = 0; i < t; i++)
        {
            scanf("%d", &n);
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &num);
                team[num] = i;
            }
        }
        // ִ�в���
        char command[10];
        while (scanf("%s", command) && command[0] != 'S')
        {
            if (command[0] == 'E')
            {
                // ���
                int temp;
                scanf("%d", &temp);
                // ��ȡ�������Ա�����Ŷ�
                int t_order = team[temp];
                // ��ǰС���Ƿ������Ŷ�
                if (Que[t_order].empty())
                {
                    // ����
                    order.push(t_order);
                }
                Que[t_order].push(temp);
            }
            else
            {
                // ����
                int first = order.front();
                printf("%d\n", Que[first].front());
                Que[first].pop();
                // �������Ƿ�Ϊ��
                if (Que[first].empty())
                {
                    // ɾ��order�б��һ��Ԫ��
                    order.pop();
                }
            }
        }
        // ��ʼ��
        team = {};
        order = {};
        for (int i = 0; i < t; i++)
            Que[i] = {};

        printf("\n");
    }

    return 0;
}