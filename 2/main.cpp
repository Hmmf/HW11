#include <iostream>
using namespace std;


bool marks(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '%' || a == '\'' || a == '&' || a == '\\' || a == '$' || a == '#' || a == '/' || a == '=' || a == '?' || a == '^' || a == '_' || a == '`' || a == '{' || a == '|' || a == '}' || a == '~' || a == '!')
        return 1;
    else return 0;
}


bool firstPart(string mail)
{
    int i = 0;
        while (mail[i] != '@')
        {
            if ((mail[i] >= 'a' && mail[i] <= 'z') || (mail[i] >= 'A' && mail[i] <= 'Z') || (mail[i] >= '0' && mail[i] <= '9') || mail[i] == '-' || mail[i] == '.' || marks(mail[i]) == 1)
            {
                if (i != 0 && (mail[i] == '.' && mail[i - 1] == '.'))
                    return 0;
            }
            else return 0;
            i++;
        }
        if (i != 0 && i != mail.size() - 1)
        {
            if (i <= 64)
                return 1;
            else return 0;
        }
    else return 0;
}


bool secondPart(string mail)
{
    int i = 0;
    while (mail[i] != '@')
        i++;
    i++;
    if (mail.size() - i - 1 <= 63)
    {
        for (; i < mail.size(); i++)
        {
            if ((mail[i] >= 'a' && mail[i] <= 'z') || (mail[i] >= 'A' && mail[i] <= 'Z') || (mail[i] >= '0' && mail[i] <= '9') || mail[i] == '-' || mail[i] == '.')
            {
                if (mail[i] == '.' && mail[i - 1] == '.')
                    return 0;
            }
            else return 0;
        }
        return 1;
    }
    else return 0;

}

int main() {
    string mail;
    cout << "Input email: ";
    cin >> mail;
    if (firstPart(mail) && secondPart(mail))
        cout << "Yes";
    else cout << "No";
    return 0;
}
