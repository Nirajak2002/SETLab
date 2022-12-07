#include <bits/stdc++.h>
using namespace std;

string generateKey(string plainText, string key,bool printSteps)
{
    int i = 0;
    while (key.size() != plainText.size())
    {
        key.push_back(key[i]);
        i++;
    }
    if(printSteps==true)
    cout<<"\nModified key is: "<<key<<"\n";
    return key;
}

string encrypt(string plainText, string key)
{
    string ans;
    for (int i = 0; i < plainText.size(); i++)
    {
        char x = (plainText[i] + key[i]) % 26;
        x += 'A';
        ans.push_back(x);
    }
    return ans;
}

string decrypt(string cipherText, string key)
{
    string plainText;
    for (int i = 0; i < cipherText.size(); i++)
    {
        char x = (cipherText[i] - key[i] + 26) % 26;
        x += 'A';
        plainText.push_back(x);
    }
    return plainText;
}

int main()
{
    int option;
    bool printSteps=false;
    string key, plainText, ans;
    cout << "How do you want to give input?:\n1) Through terminal\n2) Through File\n";
    cin >> option;
    cout << "Enter key: ";
    cin >> key;
    switch (option)
    {
    case 1:
        cout << "Enter plainText: ";
        break;
    case 2:
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        break;
    }
    if(option==1)
    printSteps=true;
    cin >> plainText;
    key = generateKey(plainText, key,printSteps);
    ans = encrypt(plainText, key);
    cout << "Cipher Text: " << ans << endl;
    cout << "Original plainText: " << decrypt(ans, key);
    return 0;
}
