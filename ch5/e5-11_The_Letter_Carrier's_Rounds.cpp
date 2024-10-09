#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// ������ϵ��
struct MTA
{
    string city;
    vector<string> names;

    MTA(string city = "", vector<string> names = {}) : city(city), names(names) {}
};

// ��
struct people
{
    string name;
    string address;

    people(string name = "", string address = {}) : name(name), address(address) {}

    bool operator==(const people &p) const
    {
        return name == p.name && address == p.address;
    }
};

int main()
{
    // �ض����������
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    // ��ȡ������ϵ��
    int city_num = 0;
    string strline;
    vector<MTA> MTA_vec;
    map<string, int> MTA_map;
    while (getline(cin, strline) && strline != "*")
    {
        string str_city, str_name;
        int num;
        vector<string> str_vec;

        // ��ȡ����
        stringstream ss(strline);
        ss >> str_city;
        ss >> str_city;
        MTA_map[str_city] = city_num++;
        // ��ȡ�����ڵ���ϵ��
        ss >> num;
        for (int i = 0; i < num; i++)
        {
            ss >> str_name;
            str_vec.push_back(str_name);
        }
        MTA_vec.push_back(MTA(str_city, str_vec));
    }

    do
    {
        // ��ȡ�����˺�������
        people sender;
        vector<people> receiver;
        bool read_flag = false;
        while (getline(cin, strline))
        {
            if(strline == "*")
                break;
            read_flag = true;
            string str_name, str_address;
            stringstream ss(strline);
            bool first = true;

            string strTmp;
            while (ss >> strTmp)
            {
                stringstream ss1(strTmp);
                getline(ss1, str_name, '@');
                getline(ss1, str_address);
                if (first)
                {
                    sender = people(str_name, str_address);
                    first = false;
                }
                else
                {
                    // ����������Ƿ��Ѿ�����
                    if(find(receiver.begin(),receiver.end(),people(str_name, str_address)) == receiver.end())
                        receiver.push_back(people(str_name, str_address));
                }
            }
        }
        if(!read_flag)
            break;

        // ��ȡ�ʼ�����
        string str_content;
        while (getline(cin, strline) && strline != "*")
        {
            str_content += strline;
            str_content += "\n\t ";
        }

        // �����ʼ�
        string receiver_city;
        while (receiver.size())
        {
            bool receiver_flag = false;
            receiver_city = receiver.begin()->address;
            vector<string> names = MTA_vec[MTA_map[receiver_city]].names;
            printf("Connection between %s and %s\n", sender.address.c_str(), receiver_city.c_str());
            printf("\t HELO %s\n\t 250\t \n", sender.address.c_str());
            printf("\t MAIL FROM:<%s@%s>\n\t 250\n\t ", sender.name.c_str(), sender.address.c_str());
            for (auto r = receiver.begin(); r != receiver.end();)
            {
                string temp_city = r->address;
                string temp_name = r->name;
                if (temp_city == receiver_city)
                {
                    r = receiver.erase(r);
                    printf("RCPT TO:<%s@%s>\n\t ", temp_name.c_str(), temp_city.c_str());

                    if (count(names.begin(), names.end(), temp_name))
                    {
                        printf("250\n\t ");
                        receiver_flag = true;
                    }
                    else
                        printf("550\n\t ");
                }
                else
                    r++;
            }
            if (receiver_flag)
            {
                printf("DATA\n\t 354\n\t ");
                printf("%s.\n\t 250\n\t ", str_content.c_str());
            }
            printf("QUIT\n\t 221\n");
        }
    } while (true);

    return 0;
}
