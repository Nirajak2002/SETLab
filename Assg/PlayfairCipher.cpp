#include <bits/stdc++.h>
using namespace std;
bool printSteps=false;
int removeSpaces(char arr[], int len)
{
    int i, count = 0;
    for (i = 0; i < len; i++)
        if (arr[i] != ' ')
            arr[count++] = arr[i];
    arr[count] = '\0';
    return count;
}

void generateMatrix(char key[], int keylen, char matrix[5][5])
{
    int i, j, k, flag = 0;
    int map[26] = {0};
    for (i = 0; i < keylen; i++)
    {
        if (key[i] != 'J')
            map[key[i] - 65] = 2;
    }
    map['J' - 65] = 1;
    i = 0;
    j = 0;
    for (k = 0; k < keylen; k++)
    {
        if (map[key[k] - 65] == 2)
        {
            map[key[k] - 65] -= 1;
            matrix[i][j] = key[k];
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    for (k = 0; k < 26; k++)
    {
        if (map[k] == 0)
        {
            matrix[i][j] = (char)(k + 65);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    if(printSteps)
    {
        cout<<"\nPlayfair Matrix:\n";
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }

}

void searchChars(char matrix[5][5], char a, char b, int arr[])
{
    int i, j;
    if (a == 'J')
        a = 'I';
    else if (b == 'J')
        b = 'I';
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (matrix[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int mod5(int a)
{
    if (a < 0)
        a += 5;
    return (a % 5);
}

int prepare(char arr[], int len)
{
    string res;
    int i = 0;
    while (i < len-1 )
    {
        res.push_back(arr[i]);
        if (arr[i] == arr[i + 1])
        {
            res.push_back('X');
            i++;
        }
        else
        {
            res.push_back(arr[i + 1]);
            i += 2;
        }
    }
    if(i == len - 1)    res.push_back(arr[i]);
    len = res.size();
    strcpy(arr, res.c_str());
    if (len % 2 != 0)
    {
        arr[len++] = 'X';
        arr[len] = '\0';
    }
    if(printSteps)
    {
        cout<<"\nModified Key:"<<arr;
    }
    return len;
}

void encrypt(char plainTextarr[], char matrix[5][5], int textlen)
{
    int i, arr[4];
    for (i = 0; i < textlen; i += 2)
    {
        searchChars(matrix, plainTextarr[i], plainTextarr[i + 1], arr);
        if (arr[0] == arr[2])
        {
            plainTextarr[i] = matrix[arr[0]][mod5(arr[1] + 1)];
            plainTextarr[i + 1] = matrix[arr[0]][mod5(arr[3] + 1)];
        }
        else if (arr[1] == arr[3])
        {
            plainTextarr[i] = matrix[mod5(arr[0] + 1)][arr[1]];
            plainTextarr[i + 1] = matrix[mod5(arr[2] + 1)][arr[1]];
        }
        else
        {
            plainTextarr[i] = matrix[arr[0]][arr[3]];
            plainTextarr[i + 1] = matrix[arr[2]][arr[1]];
        }
    }
}

void decrypt(char plainTextarr[], char matrix[5][5], int textlen)
{
    string res;
    int i, arr[4];
    for (i = 0; i < textlen; i += 2)
    {
        searchChars(matrix, plainTextarr[i], plainTextarr[i + 1], arr);
        if (arr[0] == arr[2])
        {
            plainTextarr[i] = matrix[arr[0]][mod5(arr[1] - 1)];
            plainTextarr[i + 1] = matrix[arr[0]][mod5(arr[3] - 1)];
        }
        else if (arr[1] == arr[3])
        {
            plainTextarr[i] = matrix[mod5(arr[0] - 1)][arr[1]];
            plainTextarr[i + 1] = matrix[mod5(arr[2] - 1)][arr[1]];
        }
        else
        {
            plainTextarr[i] = matrix[arr[0]][arr[3]];
            plainTextarr[i + 1] = matrix[arr[2]][arr[1]];
        }
    }
    for (i = 0; i < textlen; i++)
    {
        if(plainTextarr[i]!='X') res.push_back(plainTextarr[i]);
    }
    strcpy(plainTextarr, res.c_str());
}

string playfairEncrypt(char plainTextarr[], char key[])
{
    char matrix[5][5];
    string result;
    int keylen = removeSpaces(key, strlen(key));
    int textlen = removeSpaces(plainTextarr, strlen(plainTextarr));
    textlen = prepare(plainTextarr, textlen);
    generateMatrix(key, keylen, matrix);
    encrypt(plainTextarr, matrix, textlen);
    result = plainTextarr;
    return result;
}

string playfairDecrypt(char plainTextarr[], char key[])
{
    char matrix[5][5];
    string result;
    int keylen = strlen(key);
    int textlen = strlen(plainTextarr);
    generateMatrix(key, keylen, matrix);
    decrypt(plainTextarr, matrix, textlen);
    result = plainTextarr;
    return result;
}

int main()
{
    int option;
    string key, text, cipherText;
    char keyarr[30], plainTextarr[30], cipher[30];
    
     cout << "How do you want to give input?:\n1) Through terminal\n2) Through File\n";
    cin >> option;
    cin.ignore();
    cout << "Enter key: ";
    getline(cin, key);
    strcpy(keyarr, key.c_str());
    switch (option)
    {
    case 1:
        cout << "Enter text: ";
        break;
    case 2:
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        break;
    }
    if(option==1) printSteps=true;
    getline(cin, text);
    strcpy(plainTextarr, text.c_str());
    cipherText = playfairEncrypt(plainTextarr, keyarr);
    cout << "Cipher Text: " << cipherText << endl;
    strcpy(cipher, cipherText.c_str());
    string original=playfairDecrypt(cipher, keyarr);
    cout << "Original Text: " <<original ;
    return 0;
}
