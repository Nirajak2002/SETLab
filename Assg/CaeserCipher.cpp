#include <bits/stdc++.h>
using namespace std;

string encrypt(string plainText, int key)
{
    string ans = "";
    for (int i = 0; i < plainText.length(); i++)
    {
        ans += char(int(plainText[i] + key - 'A') % 26 + 'A');
    }
    return ans;
}

int main()
{
    int option;
    cout << "How do you want to give input?:\n1) Through terminal\n2) Through File\n";
    cin >> option;
    string plainText;
    int key;
    cout << "Enter Key (Shift): ";
    cin >> key;
    switch (option)
    {
    case 1:
        cout << "Enter the plain text: ";
        break;
    case 2:
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        break;
    default:
        break;
    }
    cin >> plainText;
    cout << "Cipher Text: "
         << encrypt(plainText, key) << "\n";
    return 0;
}
