#include <bits/stdc++.h>
#include "endf.h"
using namespace std;
void forstoring(string pass)
{
    char s;
    cout << "Do you want to store the password(y/n) : ";
    cin >> s;
    if (s == 'Y' || s == 'y')
    {
        char *passen = new char[1000];
        for (int i = 0; i < pass.size(); i++)
        {
            passen[i] = pass[i];
        }
        string title, username;
        cin.ignore();
        cout << "Enter the title for password : ";
        getline(cin, title);
        cout << "Enter the username of password : ";
        getline(cin, username);
        char *str1 = new char[1000];
        char *str = new char[1000];
        str1 = startencrption(passen);
        str = startdecryption(str1);
        cout << "after all done : " << str1 << " " << str << endl;
    }
    else if (s == 'n' || s == 'N')
    {
        return;
    }
    else
    {
        cout << "invalid input";
        forstoring(pass);
    }
}
void simple() // working
{
    string word, num, specialchar;
    cin.ignore();
    cout << "Enter the name/word for password generation : ";
    getline(cin, word);
    cout << "Enter the your number for password generation : ";
    getline(cin, num);
    cout << "Enter special characters for password generation : ";
    getline(cin, specialchar);
    string password = "";
    int l = word.size();
    int a = rand() % (l - 1);
    int b = rand() % (l - 1);
    word[a] = toupper(word[a]);
    word[b] = toupper(word[b]);
    password += word;
    int c = rand() % (specialchar.size() - 1);
    password += specialchar[c];
    password += num;
    cout << password << endl;
    forstoring(password);
}
void medium() // working
{
    string word, num, specialchar;
    int l;
    cout << "Enter the length of the password you want : ";
    cin >> l;
    cin.ignore();
    cout << "Enter the name/word for password generation : ";
    getline(cin, word);
    cout << "Enter the your number for password generation : ";
    getline(cin, num);
    cout << "Enter special characters for password generation : ";
    getline(cin, specialchar);
    string password = "", genpass;
    password += word;
    password += num;
    password += specialchar;
    for (int i = 1; i <= l; i++)
    {
        genpass.push_back(password[rand() % (password.size() - 1)]);
    }
    cout << genpass << endl;
    forstoring(genpass);
}
void hard() // working
{
    int l;
    cout << "Enter the length of the password you want : ";
    cin >> l;
    string password = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    string genpass;
    for (int i = 1; i <= l; i++)
    {
        genpass.push_back(password[rand() % (password.size() - 1)]);
    }
    cout << genpass << endl;
    forstoring(genpass);
}
void genpass()
{
    char type;
    cout << "A.Simple\nB.Medium\nC.Hard\n";
    cout << "Enter which type of password do you want to generate : ";
    cin >> type;
    if (type == 'A' || type == 'a')
    {
        simple();
    }
    else if (type == 'B' || type == 'b')
    {
        medium();
    }
    else if (type == 'C' || type == 'c')
    {
        hard();
    }
}

void otherpass()
{
}

int main()
{
    cout << "--------MENU--------" << endl;
    cout << "1.Generating new password " << endl;
    cout << "2.See other passwords " << endl;
    int choice;
    cout << "Enter the choice : ";
    cin >> choice;
    if (choice == 1)
    {
        genpass();
    }
    else if (choice == 2)
    {
        otherpass();
    }
    else
    {
        cout << "Program is closed" << endl;
        return 0;
    }
    return 0;
}