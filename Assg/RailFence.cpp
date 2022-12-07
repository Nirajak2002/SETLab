
#include <bits/stdc++.h>
using namespace std;

string encrypt(string plainText, int depth,bool printSteps)
{
	char matrix[depth][(plainText.length())];
	for (int i=0; i < depth; i++)
		for (int j = 0; j < plainText.length(); j++)
			matrix[i][j] = '*';
	int d = -1;
	int r = 0, c = 0;
    if(printSteps)
    {
        cout<<"\nInitial Matrix for railfence encryption:\n";
        for (int i=0; i < depth; i++) {
            for (int j = 0; j < plainText.length(); j++)
			cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
	for (int i=0; i < plainText.length(); i++)
	{
		if (r == 0 )
			d = 1;
        if(r == depth-1)
            d=-1;
		matrix[r][c++] = plainText[i];
		if(d==1) r++; //d==1 means we should go down in the matrix 
		else r--;
	}
    if(printSteps)
    {
        cout<<"\nFinal Matrix for railfence encryption:\n";
        for (int i=0; i < depth; i++) {
            for (int j = 0; j < plainText.length(); j++)
			cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
	string cipherText;
	for (int i=0; i < depth; i++)
		for (int j=0; j < plainText.length(); j++)
			if (matrix[i][j]!='*')
				cipherText.push_back(matrix[i][j]);

	return cipherText;
}

string decrypt(string ciphertext, int depth,bool printSteps)
{
    string result;
    char matrix[depth][ciphertext.length()];
    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < ciphertext.length(); j++)
        {
            matrix[i][j] = '_';
        }
    }
    int d;
    int r = 0, c = 0;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (r == 0)
            d = 1;
        else if (r == depth - 1)
            d = -1;
        matrix[r][c++] = '*';
        if (d==1)
            r++;
        else
            r--;
    }
    if(printSteps)
    {
        cout<<"\nInitial Matrix for railfence decryption:\n";
        for (int i=0; i < depth; i++) {
            for (int j = 0; j < ciphertext.length(); j++)
			cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    int k = 0;
    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < ciphertext.length(); j++)
        {
            if (matrix[i][j] == '*' && k < ciphertext.length())
                matrix[i][j] = ciphertext[k++];
        }
    }
    if(printSteps)
    {
        cout<<"\nFinal Matrix for railfence decryption:\n";
        for (int i=0; i < depth; i++) {
            for (int j = 0; j < ciphertext.length(); j++)
			cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    r = 0, c = 0;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (r == 0)
            d = 1;
        else if (r == depth - 1)
            d = -1;
        if (matrix[r][c] != '*')
            result.push_back(matrix[r][c++]);
        if (d==1)
            r++;
        else
            r--;
    }
    return result;
}

int main()
{
	int option;
    cout << "How do you want to give input?:\n1) Through terminal\n2) Through File\n";
    cin >> option;
    bool printSteps=false;
    string plainText;
    int depth;
    cout << "Enter Depth for RailFence cipher: ";
    cin >> depth;
    switch (option)
    {
    case 1:
        cout << "Enter Text: ";
        break;
    case 2:
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        break;
    default:
        break;
    }
    if(option==1) printSteps=true;
    cin >> plainText;
    string cipherText=encrypt(plainText, depth,printSteps);
    cout << "Cipher Text: "<< cipherText << "\n";
    string original=decrypt(cipherText,depth,printSteps);
    cout<<"\nOriginal text: "<<original;
    return 0;
}
