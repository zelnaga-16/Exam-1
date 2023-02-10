#include "secure.h"
#include <iostream>
using namespace std;
void Draw(int counter) // чтобы было красиво в консоли я специально искривил человечка
{
    switch (counter)
    {
    case 6:
        cout << "|==================|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|\\" << endl;
        cout << "| \\" << endl;
        cout << "|  \\" << endl;
        break;
    case 5:
        cout << "|==================|" << endl;
        cout << "|                / \\" << endl;
        cout << "|               |   |" << endl;
        cout << "|                \\ /" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|\\" << endl;
        cout << "| \\" << endl;
        cout << "|  \\" << endl;
        break;

    case 4:
        cout << "|==================|" << endl;
        cout << "|                / \\" << endl;
        cout << "|               |   |" << endl;
        cout << "|                \\ /" << endl;
        cout << "|                 |" << endl;
        cout << "|                 |" << endl;
        cout << "|                 |" << endl;
        cout << "|                 |" << endl;
        cout << "|                 |" << endl;
        cout << "|" << endl;
        cout << "|\\" << endl;
        cout << "| \\" << endl;
        cout << "|  \\" << endl;
        break;
    case 3:
        cout << "|==================|" << endl;
        cout << "|                / \\" << endl;
        cout << "|               |   |" << endl;
        cout << "|                \\ /" << endl;
        cout << "|                 |" << endl;
        cout << "|                /|" << endl;
        cout << "|               / |" << endl;
        cout << "|                 |" << endl;
        cout << "|                 |" << endl;
        cout << "|" << endl;
        cout << "|\\" << endl;
        cout << "| \\" << endl;
        cout << "|  \\" << endl;
        break;
    case 2:
        cout << "|==================|" << endl;
        cout << "|                / \\" << endl;
        cout << "|               |   |" << endl;
        cout << "|                \\ /" << endl;
        cout << "|                 |" << endl;
        cout << "|                /|\\" << endl;
        cout << "|               / | \\" << endl;
        cout << "|                 |" << endl;
        cout << "|                 |" << endl;
        cout << "|\\" << endl;
        cout << "| \\" << endl;
        cout << "|  \\" << endl;
        break;
    case 1:
        cout << "|==================|" << endl;
        cout << "|                / \\" << endl;
        cout << "|               |   |" << endl;
        cout << "|                \\ /" << endl;
        cout << "|                 |" << endl;
        cout << "|                /|\\" << endl;
        cout << "|               / | \\" << endl;
        cout << "|                 |" << endl;
        cout << "|                 |" << endl;
        cout << "|                / " << endl;
        cout << "|\\             /  " << endl;
        cout << "| \\" << endl;
        cout << "|  \\" << endl;
        break;
    case 0:
        cout << "|=================|" << endl;
        cout << "|                / \\" << endl;
        cout << "|               |   |" << endl;
        cout << "|                \\ /" << endl;
        cout << "|                 |" << endl;
        cout << "|                /|\\" << endl;
        cout << "|               / | \\" << endl;
        cout << "|                 |" << endl;
        cout << "|                 |" << endl;
        cout << "|                / \\" << endl;
        cout << "|\\             /   \\" << endl;
        cout << "| \\" << endl;
        cout << "|  \\" << endl;
        break;
    }

};
void secret_word(string word, vector<char> real_letters, vector<char> fals_letters)
{
    for (int i = 0; i < word.size(); i++)
    {
        for (int a = 0; a < real_letters.size(); a++)
        {
            if (word[i] == real_letters[a])
            {
                cout << word[i];
                goto label;
            }
        }
        cout << "_";
    label:;
    }
    cout << endl;
    if (real_letters.size() > 0)
    {
        cout << "Right letters -> ";
        for (int i = 0; i < real_letters.size() - 1; i++)
        {
            cout << real_letters[i] << ",";
        }
        cout << real_letters[real_letters.size() - 1] << endl;
    }

    if (fals_letters.size() > 0)
    {
        cout << "Wrong letters -> ";
        for (int i = 0; i < fals_letters.size() - 1; i++)
        {
            cout << fals_letters[i] << ",";
        }
        cout << fals_letters[fals_letters.size() - 1] << endl;
    }
}
void check(string word, vector<char>& real_letters, vector<char>& fals_letters, int& counter)
{
    char letter;
    cout << "Enter letter -> ";
    cin >> letter;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == letter)
        {
            for (int j = 0; j < real_letters.size(); j++)
            {
                if (letter == real_letters[j])
                {
                    cout << "you entered this letter\n";
                    goto label;
                }
            }
            real_letters.push_back(letter);

            goto label;
        }
    }
    for (int j = 0; j < fals_letters.size(); j++)
    {
        if (letter == fals_letters[j])
        {
            cout << "you entered this letter\n";
            goto label;
        }
    }
    fals_letters.push_back(letter);
    counter--;
label:;

};
void Win(string word, int attempts, int number_of_letters, vector<char>real_letters, vector<char>fals_letters, int t)
{
    
    if (number_of_letters == real_letters.size())
    {
        cout << "You Win!\nYour score:\n";
    }
    else
    {
        cout << "You Lose. Don`t worry you can try again!\nYour score:\n";
    }
    cout << "Your time is " << t / 60 << " minutes " << t - (t / 60) * 60 << " seconds;\n";
    cout << "You did " << attempts << " moves\n";
    cout << "Your word was " << word << endl;
    if (real_letters.size() > 0)
    {
        cout << "Right letters -> ";

        for (int i = 0; i < real_letters.size() - 1; i++)
        {
            cout << real_letters[i] << ",";
        }
        cout << real_letters[real_letters.size() - 1] << endl;
    }

    if (fals_letters.size() > 0)
    {
        cout << "Wrong letters -> ";
        for (int i = 0; i < fals_letters.size() - 1; i++)
        {
            cout << fals_letters[i] << ",";
        }
        cout << fals_letters[fals_letters.size() - 1] << endl;
    }
    
}
int main()
{
    secure Word;

    int counter = 6;
    int number_of_letters = 0;
    string word = Word.Get_word(number_of_letters);
    vector<char>real_letters;
    vector<char>fals_letters;
    int attempts;

    int start = clock();
    for (attempts = 0; counter > 0; attempts++)
    {
        Draw(counter);
        secret_word(word, real_letters, fals_letters);
        check(word, real_letters, fals_letters, counter);
        if (number_of_letters == real_letters.size())
        {
            break;
        }
    }
    int end = clock();
    Win(word, attempts, number_of_letters, real_letters, fals_letters, (end - start) / CLOCKS_PER_SEC);
    
}
