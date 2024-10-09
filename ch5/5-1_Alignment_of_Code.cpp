#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef vector<string> vec_str;

const int maxn = 1000 + 10;
vec_str arr[maxn];
vector<int> lens;
vector<int> nums;

// �����������
void print(string str, int len);

int main()
{
    // �ض����������
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    // ��ȡԴ�ļ�
    string strLine;
    string str;
    while (getline(cin, strLine))
    {
        stringstream ss(strLine);
        int i = 0;
        while (ss >> str)
        {
            arr[i].push_back(str);

            if (lens.size() < i + 1)
                lens.push_back(str.size());
            else
                lens[i] = max(lens[i], (int)str.size());
            i++;
        }

        nums.push_back(i);
    }

    // ���
    vector<int> out_arr;
    for (int i = 0; i < lens.size(); i++)
        out_arr.push_back(0);

    for (int i = 0; i < nums.size(); i++)
    {
        int n = 0;
        for (int j = 0; j < nums[i]; j++)
        {
            print(arr[n++][out_arr[j]], lens[j]);
            out_arr[j]++;
        }
        n++;
        cout << endl;
    }

    return 0;
}

void print(string str, int len)
{
    cout << str;
    for (int i = str.size(); i < len + 1; i++)
        cout << " ";
}
