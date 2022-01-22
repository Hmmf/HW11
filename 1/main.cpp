#include <iostream>

using namespace std;

string encrypt_caesar(string word, int a) {
    a %= 26;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            if (word[i] + a > 'Z')
                word[i] = word[i] + a - 26;
            else if (word[i] + a < 'A')
                word[i] = word[i] + a + 26;
            else
                word[i] = word[i] + a;
        } else if (word[i] >= 'a' && word[i] <= 'z') {
            if (word[i] + a > 'z')
                word[i] = word[i] + a - 26;
            else if (word[i] + a < 'a')
                word[i] = word[i] + a + 26;
            else
                word[i] = word[i] + a;
        }
    }
    return word;
}

}

int main()
{
    char ans;
    string word;
    int a;
    cout << "Input your sentence: ";
    cin >> word;
    cout << "Input step size of crypt: ";
    cin >> a;
    cout << "Decrypt or encrypt? D/E";
    cin >> ans;
    if (tolower(ans) == 'd')
        cout << encrypt_caesar(word, a * -1);
    else if (tolower(ans) == 'e')
        cout << encrypt_caesar(word, a);
    else;
    return 0;
}
