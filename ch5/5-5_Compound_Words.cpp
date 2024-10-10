#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    // �ض����������
    freopen("../../in.txt","r",stdin);
    freopen("../../out.txt","w",stdout);

    set<string> dict;
    // ��ȡ�����ֵ�
    string s;
    while (cin >> s)
        dict.insert(s);
    // �����ֵ�
    for (const string &word : dict)
    {
        // ö�ٷָ��
        for (int i = 1; i < word.size(); i++)
        {
            // �ж������Ӵ��Ƿ����ֵ���
            if (dict.count(word.substr(0, i)) && dict.count(word.substr(i)))
            {
                cout << word << endl;
                break;
            }
        }
    }

    return 0;
}