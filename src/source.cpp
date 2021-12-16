//Giovanni Hernandez
//Based on the GeeksforGeeks Vigenere Cipher program

#include<iostream>
using namespace std;

string generateKey(string word, string key)
{
    int L = word.size();

    for (int i = 0; ; i++)
    {
        if (L == i)
            i = 0;
        if (key.size() == word.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string encryptedText(string word, string key)
{
    string encrypted_text;


    for (int i = 0; i < word.size(); i++)
    {
        char L = (word[i] + key[i]) % 26;
        L += 'A';

        encrypted_text.push_back(L);
    }
    return encrypted_text;
}

string decryptedText(string encrypted_text, string key)
{
    string decrypted_text;

    for (int i = 0; i < encrypted_text.size(); i++)
    {
        char L = (encrypted_text[i] - key[i] + 26) % 26;
        L += 'A';
        decrypted_text.push_back(L);
    }
    return decrypted_text;
}

int main()
{
    int choice;
    string word;
    string keyword;
    string key;
    string encrypted_text;

    cout << "What menu choice do you pick?\n";
    cout << "   1: Encryption\n";
    cout << "   2: Decryption\n";
    cin >> choice;


    switch (choice)
    {
    case 1:
        cout << "Enter the Word you want to Encrypt\n";
        cin >> word;
        cout << "Enter the Keyword\n";
        cin >> keyword;
        for (int i = 0;i < word.length();i++)
            word[i] = toupper(word[i]);
        for (int i = 0;i < keyword.length();i++)
            keyword[i] = toupper(keyword[i]);
        key = generateKey(word, keyword);
        encrypted_text = encryptedText(word, key);
        cout << "Encrypted Text: " << encrypted_text << "\n";
        break;

    case 2:
        cout << "Enter the code you want to Decrypt\n";
        cin >> encrypted_text;
        cout << "Enter the Keyword\n";
        cin >> keyword;
        for (int i = 0;i < encrypted_text.length();i++)
            encrypted_text[i] = toupper(encrypted_text[i]);
        for (int i = 0;i < keyword.length();i++)
            keyword[i] = toupper(keyword[i]);
        key = generateKey(encrypted_text, keyword);
        cout << "Decrypted Text : " << decryptedText(encrypted_text, key);
        break;

    default:
        cout << "Please choose a valid number between 1 or 2\n";
        break;
    }



    
    return 0;
}