#include <iostream>

using namespace std;

//0,0 1,0 2,0
//0,1 1,1 2,1
//0,2 1,2 2,2

char symbol (string str, int x, int y) //0 <= x,y < 3 (0,1,2)
{
    return str[3 * y + x];
}


bool correctField(string str)
{
    if (str.size() != 9)
        return false;
    for (int i = 0; i < 9;i++)
        if (str[i] != 'X' && str[i] != 'O' && str[i] != '.')
            return false;
    return true;
}


int charCount (string str, char symb)
{
    int i = 0, sum = 0;
    while (str.find(symb, i) != -1)
    {
        i = str.find(symb, i) + 1;
        sum++;
    }
    return sum;
}


string winCheck(string str)
{
    int petyaW = 0, vanyaW = 0;
    if (!correctField(str))
        return "Incorrect";
    for (int i = 0; i < 3; i++)
        if (symbol(str, i, 0) == symbol(str, i, 1) && symbol(str, i, 2) == symbol(str, i, 1) && symbol(str, i, 0) != '.')
        {
            if (symbol(str, i, 0) == 'X')
                petyaW++;
            else
                vanyaW++;
        }

    for (int i = 0; i < 3; i++)
        if (symbol(str, 0, i) == symbol(str, 1, i) && symbol(str, 2, i) == symbol(str, 1, i) && symbol(str, 0, i) != '.')
        {
            if (symbol(str, 0, i) == 'X')
                petyaW++;
            else
                vanyaW++;
        }

    if (symbol(str, 0, 0) == symbol(str, 1, 1) && symbol(str, 2, 2) == symbol(str, 1, 1) && symbol(str, 0, 0) != '.')
    {
        if (symbol(str, 0, 0) == 'X')
            petyaW++;
        else
            vanyaW++;
    }

    if (symbol(str, 2, 0) == symbol(str, 1, 1) && symbol(str, 0, 2) == symbol(str, 1, 1) && symbol(str, 2, 0) != '.')
    {
        if (symbol(str, 2, 0) == 'X')
            petyaW++;
        else
            vanyaW++;
    }

    if (petyaW + vanyaW > 1)
        return "Incorrect";
    if (petyaW + vanyaW == 1)
        return petyaW > vanyaW ? "Petya won" : "Vanya won";
    else return "Nobody";
}

string gameStat (string str)
{
    if (winCheck(str) == "Incorrect")
        return "Incorrect";
    if (winCheck(str) == "Nobody")
    {
        return charCount(str, 'X') == charCount(str, 'O') || charCount(str, 'X') - 1 == charCount(str, 'O') ? "Nobody" : "Incorrect";
    }
    if (winCheck(str) == "Petya won")
        return charCount(str, 'X') - 1 == charCount(str, 'O') ? "Petya won" : "Incorrect";
    if (winCheck(str) == "Vanya won")
        return charCount(str, 'X') == charCount(str, 'O') ? "Vanya von" : "Incorrect";

}



int main()
{
string upSide, medSide, downSide, str;
cout << "Input Play Field: ";
cin >> upSide >> medSide >> downSide;
str += upSide + medSide + downSide;
cout << gameStat(str);
}
