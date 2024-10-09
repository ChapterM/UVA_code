#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    // �ض����������
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int T;
    cin >> T;
    // ��ȡ����������
    while(T--)
    {
        vector<int> vec;
        // ��ȡ����
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            // �����д�������
            vec.push_back(temp);
        }
        vec.push_back(vec[0]);

        // ��������
        int loop = 1000;
        while(loop--)
        {
            for (int i = 0;i<vec.size()-1;i++)
            {
                vec[i] = abs(vec[i] - vec[i+1]);
            }
            *(vec.end()-1) = vec[0];
        }

        // �ж������Ƿ�Ϊ0
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