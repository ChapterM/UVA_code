#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 建筑物
struct Elevation
{
    // 序号
    int id;
    // 坐标
    int x_start;
    int x_end;
    int y_start;
    int y_end;
    // 高度
    int h;

    // 构造函数
    Elevation(int id, int x, int y, int w, int d, int h)
        : id(id), x_start(x), y_start(y), h(h)
    {
        x_end = x_start + w;
        y_end = y_start + d;
    }

    // 比较函数
    bool operator<(const Elevation &e) const
    {
        if (x_start != e.x_start)
            return x_start < e.x_start;
        
        if(x_end != e.x_end)
            return x_end < e.x_end;

        return id < e.id;
    }
};

// 建筑物遮挡区域
struct Block
{
    int x;
    int h;

    Block(int x, int h)
        : x(x), h(h) {}

    bool operator<(const Block &b) const
    {
        return x < b.x;
    }
};

set<Elevation> Elevations;
set<Block> Blocks;

// 更新遮挡区域
bool update_Blocks(const Elevation &e);

int main()
{
    // 重定义输入输出
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    int T = 1;
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        Elevations.clear();
        Blocks.clear();
        // 读取建筑信息
        for (int i = 1; i <= n; i++)
        {
            int x, y, w, d, h;
            cin >> x >> y >> w >> d >> h;
            Elevations.insert(Elevation(i, x, y, w, d, h));
        }
        // 初始化遮挡区域
        auto it = Elevations.end();
        it--;
        Blocks.insert(Block(0, 0));
        Blocks.insert(Block(it->x_end, 0));
        printf("map #%d, the visible buildings are numbered as follows:", T++);
        // 更新遮挡区域
        for (auto it = Elevations.begin(); it != Elevations.end(); it++)
        {
            if (update_Blocks(*it))
                printf(" %d", it->id);
        }
        printf("\n");
    }

    return 0;
}

bool update_Blocks(const Elevation &e)
{
    bool flag = false;
    // 遍历遮挡区域
    
    return flag;
}