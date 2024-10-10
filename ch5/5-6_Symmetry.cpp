#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    float x, y;

    Point(float x = 0, float y = 0) : x(x), y(y) {}

    bool operator<(const Point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// �Գ���
float X;

bool cmp(const Point &p1, const Point &p2)
{
    if (p1.x == p2.x && p1.x < X / 2)
        return p1.y < p2.y;
    else if (p1.x == p2.x && p1.x >= X / 2)
        return p1.y > p2.y;

    return p1.x < p2.x;
}

int main()
{
    // �ض����������
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        // ����㼯
        vector<Point> vec;
        float x, y;
        while (n--)
        {
            cin >> x >> y;
            vec.push_back(Point(x, y));
        }

        // �ҵ��Գ���
        sort(vec.begin(), vec.end());
        int t = vec.size();
        if (t % 2 == 1)
            X = vec[t / 2].x * 2;
        else
            X = vec[t / 2].x + vec[t / 2 - 1].x;

        // �ж϶Գ���
        sort(vec.begin(), vec.end(), cmp);
        bool flag = true;
        for (int i = 0; i < t / 2; i++)
        {
            if (vec[i].x + vec[t - i - 1].x != X)
            {
                flag = false;
                break;
            }
        }
        // ���
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}