#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    // 重定义输入输出
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int T;
    cin >> T;
    // 读取测试用例数
    while(T--)
    {
        vector<int> vec;
        // 读取序列
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            // 将序列存入数组
            vec.push_back(temp);
        }
        vec.push_back(vec[0]);

        // 计算序列
        int loop = 1000;
        while(loop--)
        {
            for (int i = 0;i<vec.size()-1;i++)
            {
                vec[i] = abs(vec[i] - vec[i+1]);
            }
            *(vec.end()-1) = vec[0];
        }

        // 判断序列是否为0
        bool flag = true;
        for (int i = 0;i<vec.size();i++)
        {
            if(vec[i] != 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "ZERO" << endl;
        }
        else
        {
            cout << "LOOP" << endl;
        }
    }
}