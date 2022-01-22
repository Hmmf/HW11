#include <iostream>
using namespace std;


bool dotCheck (string ip)
{
    int i = 0, c = 0;
    while (i != -1 && i < ip.size())
    {

        i = ip.find('.' , i + 1);
        c++;
        if (i == 0 || i == ip.size() - 1 ||  ip[i - 1] == '.' || ip[i + 1] == '.')
            return false;
    }
    return c == 4;
}


int correctIp(string ip)
{
    int i, c;
    if (!dotCheck(ip))
        return false;
    int dotPos = 0;
    for (int j = 0; j < 4; j++)
    {
        i = 0;
        c = 0;
        while (ip[dotPos + i] != '.' && dotPos + i < ip.size())
        {
            if (ip[dotPos + i] >= '0' && ip[dotPos + i] <= '9')
            {
                c = c * 10 + ip[dotPos + i] - '0';
                if (c == 0 && ip[dotPos + i + 1] != '.' && dotPos + i + 1 < ip.size())
                    return false;
                i++;
            }
            else return false;
        }
        if (c > 255)
            return false;
        dotPos += i + 1;
    }
    return true;
}


int main()
{
    string ip;
    cout << "Input your ip: ";
    cin >> ip;
    if (correctIp(ip))
        cout << "Yes";
    else cout << "No";
    return 0;
}
