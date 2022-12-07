#include <bits/stdc++.h>
using namespace std;

string encrypt(string key, string plainText,bool printSteps) {
vector <int> pos;
    for(int i=1;i<=key.length();i++)
    {
        int j;
        for(j=0;j<key.length();j++)
        {
            if(key[j]==char(i+48))
            break;
        }
        pos.push_back(j);
    }
    string cipherText="";
    int k=0,j;
    int rows=(int)ceil(floor(plainText.length())/floor(key.length()));
    int cols=key.length();
    vector<vector<char>> mat( rows , vector<char> (cols, 0)); 
    for(int i=0;i<rows;i++)
    {
        for( j=0;j<cols;j++)
        {
            mat[i][j]='*';
        }
    }
    for(int i=0;i<rows;i++)
    {
        for( j=0;j<cols;j++)
        {
            if(plainText[k]=='\0')
              break;
            mat[i][j]=plainText[k++];
        }
        if(j!=key.length())
        break;
    }
    if(printSteps)
    {
        cout<<"\nMatrix for columnar encryption:\n";
     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<key.length();j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    }
    int cnt=0;
    for(int loop=0;loop<cols;loop++)
    {
        for(int j=0;j<rows;j++)
        {
                cipherText.push_back(mat[j][pos[loop]]);
        }
    }
  return cipherText;
 
}
string decrypt(string key, string cipherText,bool printSteps)
 {
    
vector <int> pos;
    for(int i=1;i<=key.length();i++)
    {
        int j;
        for(j=0;j<key.length();j++)
        {
            if(key[j]==char(i+48))
            break;
        }
        pos.push_back(j);
    }
    string plainText="";
    int j,cnt=0;
    int rows=(int)ceil(floor(cipherText.length())/floor(key.length()));
    int cols=key.length();
    vector<vector<char>> mat( rows , vector<char> (cols, 0)); 
    for(int i=0;i<cols;i++)
    {
        for( j=0;j<rows;j++)
        {
            mat[j][pos[i]]=cipherText[cnt++];
        }
    }
    if(printSteps){
cout<<"\nMatrix for columnar decryption:\n";
     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    }
    
    
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
          if(mat[i][j]!='*')
          plainText.push_back(mat[i][j]);
        }
    }
  return plainText;
 
}
string removeDummy(string cipherText)
{
    string ans;
    for(int i=0;i<cipherText.size();i++)
    {
        if(cipherText[i]!='*')
        ans.push_back(cipherText[i]);
    }
    return ans;
}
int main() 
{
  int option;
    cout << "How do you want to give input?:\n1) Through terminal\n2) Through File\n";
    cin >> option;
    string plainText;
    string key;
    bool printSteps=false;
    cout << "Enter key: ";
    cin >> key;
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
    string cipherText=encrypt(key,plainText,printSteps);
    cout << "Cipher Text: "
         << removeDummy(cipherText) << "\n";
    string original=decrypt(key,cipherText,printSteps);
    cout << "Original Text: "
         << original << "\n";
    return 0;
}