#include "secure.h"

/*
אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ

abcdefghijklmnopqrstuvwxyz
*/
string secure::dencrypt(string input)
{
    vector<char> word(input.begin(), input.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                if ((j - 3) >= 0) 
                {
                    word[i] = alphabet[(j - 3)];
                }
                else
                {
                    word[i] = alphabet[26+(j - 3)];
                }
                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}

string secure::encrypt(string input)
{
    vector<char> word(input.begin(), input.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j + 3) % 26];
                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}

string secure::Get_word(int& number_of_letters)
{
    int id = 0;
    string word;

    ifstream file;
    file.open("Words_eng.txt");
    if (file)
    {
        while (!file.eof())
        {
            getline(file, word);
            id++;
        }
        file.close();

    }
    std::srand(std::time(NULL));
    int random_variable = rand() % id;




    file.open("Words_eng.txt");
    if (file) 
    {
        for (id = 0; id <= random_variable; id++)
        {
            getline(file, word);
        }
        file.close();
    }
    word = dencrypt(word);

    vector<char> letters;

    for (int i = 0; i < word.size(); i++)
    {
        for (int j = 0; j < letters.size(); j++)
        {
            if (word[i] == letters[j])
            {
                goto label;
            }
        }
        letters.push_back(word[i]);
        number_of_letters++;
    label:;
    }
    return word;
    
}

void secure::Add_word(string input)
{
    fstream file;
    file.open("Words_eng.txt", ios::app);
    string word = encrypt(input);
    file << word.c_str() << endl;
    file.close();
    
}
