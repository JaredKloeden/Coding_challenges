#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

string caesar_shift(string input, int key)
{
    //Function to shift the input sentence by the key size
    string output = input;
    for (int i = 0; i < input.length(); i++)
    {
        int temp = input[i];
        if (temp >= 97 && temp <= 122)
        {
            output[i] = ((temp - 97 + key) % 26) + 97;
        }
        else if (temp >= 65 && temp <= 90)
        {
            output[i] = ((temp - 65 + key) % 26) + 65;
        }
    }
    return output;
}

int main(int argc, char const *argv[])
{
    char option = 'q';

    while (option != 'e' && option != 'd')
    {
        cout << "Encrypt, decrypt or quit? (e/d/q): ";
        cin >> option;
        if (option == 'q')
        {
            return 0;
        }
    }

    //Input sentence

    string sentence = "";
    cout << "Enter your sentence: ";
    while (getline(std::cin, sentence))
    {
        if (sentence != "")
        {
            break;
        }
    }

    if (option == 'e')
    {
        //Encryption

        int key = 0;
        bool key_flip = false;

        //Input key
        while (key < 1 || key > 26)
        {
            if (key_flip)
            {
                cout << "Please enter a number between 0 and 26" << endl;
            }
            key_flip = true;
            cout << "Enter your key: ";
            cin >> key;
        }

        //Encrypt sentence
        string shifted_sentence = caesar_shift(sentence, key);

        cout << "Your encrypted sentence is: " << shifted_sentence << endl;
    }
    else
    {
        //Check all possible keys
        for (int i = 1; i < 26; i++)
        {
            cout << caesar_shift(sentence, i) << endl;
        }
    }

    return 0;
}
