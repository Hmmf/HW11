#include <iostream>
using namespace std;

bool numberCheck(string n) {
    bool dot = false, digit = false, correct = true;
    for (int i = 0; i < n.size(); i++)
    {
        if ((n[i] < '0' || n[i] > '9') && n[i] != '.' && n[i] != '-')
        {
            correct = false;
            break;
        }
        if (n[i] == '.')
        {
            if (dot)
            {
                correct = false;
                break;
            }
            else
                dot = true;
        }
        else if (n[i] == '-')
        {
            if (i)
            {
                correct = false;
                break;
            }
        }
        else
            digit = true;
    }
    if (!digit)
        correct = false;
    if (correct)
        return true;
    else
        return false;
}


string leftPart(string n)
{
    string ans = "";
    int numSize;
    bool startPoint = false;
    if (n[0] == '-')
        n.erase(0);
    n.find('.') == -1 ? numSize = n.size() : numSize = n.find('.');
    for (int i = 0; i < numSize; i++)
    {
        if (startPoint || n[i] != '0')
        {
            ans += n[i];
            if (!startPoint && n[i] != '0')
                startPoint = true;
        }
        else;

    }
    if (ans == "")
        return "0";
    return ans;
}


string rightPart(string n)
{
    string ans = "";
    if (n.find('.') == -1)
        return "0";
    for (int i = n.find('.') + 1; i < n.size(); i++)
    {
        ans += n[i];
    }
    int m = ans.size();
    for (int i = m - 1; i >= 0; i--)
    {
        if (ans[i] == '0')
            ans.erase(i);
        else break;
    }
    if (ans == "")
        return "0";
    return ans;
}


string numberComparer(string first, string second)
{
    bool check;//true - |first| > |Second|: false - |first| < |Second|
    bool allMinus = (first[0] == '-' && second[0] == '-');//first < 0 && second < 0
    if (leftPart(first) == "0" && rightPart(first) == "0" && leftPart(second) == "0" && rightPart(second) == "0")
        return "Equal";
    if (!numberCheck(first) || !numberCheck(second))
        return "ERROR";
    if ((first[0] == '-' || second[0] == '-') && !allMinus)
    {
        return first[0] == '-' && second[0] == '-' ? "More" : "less";
    }
    if(allMinus)
    {
        first.erase(0);
        second.erase(0);
    }
    if (leftPart(first) != leftPart(second))
    {
        if (leftPart(first).size() == leftPart(second).size())
        for(int i = 0;;i++)
        {
            if(first[i] != second[i])
            {
                check = first[i] > second[i];
                break;
            }
        }
        else leftPart(first).size() > leftPart(second).size() ? check = 1 : check = 0;
    }
    else if (rightPart(first) != rightPart(second))
    {
        if (rightPart(first).size() == rightPart(second).size())
            for(int i = first.find('.') + 1;;i++)
            {
                if(first[i] != second[i])
                {
                    check = first[i] > second[i];
                    break;
                }
            }
        else rightPart(first).size() > rightPart(second).size() ? check = 1 : check = 0;
    }
    else return "Equal";
    if (allMinus)
        check = !check;
    return check ? "More" : "less";
}

int main()
{
    string first, second;
    cout << "Input two numbers: ";
    cin >> first >> second;


    cout << numberComparer(first, second);
    //cout << numberCheck(first) << " " << numberCheck(second) << endl << leftPart(first) << " " << rightPart(first) << endl << leftPart(second) << " " << rightPart(second) << endl;
    return 0;
}
