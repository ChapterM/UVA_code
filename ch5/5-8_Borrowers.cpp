#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book
{
    string title;
    string author;
    bool isBorrowed;
    bool isup;

    Book(string t, string a, bool b, bool u) : title(t), author(a), isBorrowed(b), isup(u) {}

    bool operator<(const Book &b) const
    {
        if (author != b.author)
            return author < b.author;
        return title < b.title;
    }
};

int main()
{
    // 重定义输入输出
    freopen("../../in.txt", "r", stdin);
    freopen("../../out.txt", "w", stdout);

    // 读取图书信息
    string strLine;
    vector<Book> books;
    while (getline(cin, strLine) && strLine != "END")
    {
        string title, author;
        int i = 1;
        title += "\"";
        while (strLine[i] != '"')
            title += strLine[i++];
        title += "\"";
        i += 5;
        while (i < strLine.size())
            author += strLine[i++];
        Book book(title, author, false, true);
        books.push_back(book);
    }
    sort(books.begin(), books.end());

    // 读取借书信息
    while (getline(cin, strLine) && strLine != "END")
    {
        string command, title;
        int i = 0;
        while (strLine[i] != ' ' && i < strLine.size())
            command += strLine[i++];
        i++;

        if (command == "SHELVE")
        {
            sort(books.begin(), books.end());
            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].isBorrowed == false && books[i].isup == false)
                {
                    int j = i - 1;
                    while (j >= 0)
                    {
                        if (books[j].isup == true)
                        {
                            cout << "Put " << books[i].title << " after " << books[j].title << endl;
                            break;
                        }
                        j--;
                    }
                    if (j < 0)
                        cout << "Put " << books[i].title << " first" << endl;

                    books[i].isup = true;
                }
            }
            cout << "END" << endl;
        }
        else
        {
            while (i < strLine.size())
                title += strLine[i++];

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].title == title)
                {
                    books[i].isBorrowed = !books[i].isBorrowed;
                    if (command == "BORROW")
                        books[i].isup = false;
                    break;
                }
            }
        }
    }

    return 0;
}