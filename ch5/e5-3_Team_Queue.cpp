#include <iostream>
#include <queue>
#include <map>

using namespace std;

const int N_max = 1000 + 10;

int main()
{
    // 重定向输入输出
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
        // 读取团队数据
        for (int i = 0; i < t; i++)
        {
            scanf("%d", &n);
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &num);
                team[num] = i;
            }
        }
        // 执行操作
        char command[10];
        while (scanf("%s", command) && command[0] != 'S')
        {
            if (command[0] == 'E')
            {
                // 入队
                int temp;
                scanf("%d", &temp);
                // 获取带入队人员所在团队
                int t_order = team[temp];
                // 当前小组是否有人排队
                if (Que[t_order].empty())
                {
                    // 无人
                    order.push(t_order);
                }
                Que[t_order].push(temp);
            }
            else
            {
                // 出队
                int first = order.front();
                printf("%d\n", Que[first].front());
                Que[first].pop();
                // 检查队列是否为空
                if (Que[first].empty())
                {
                    // 删除order列表第一个元素
                    order.pop();
                }
            }
        }
        // 初始化
        team = {};
        order = {};
        for (int i = 0; i < t; i++)
            Que[i] = {};

        printf("\n");
    }

    return 0;
}