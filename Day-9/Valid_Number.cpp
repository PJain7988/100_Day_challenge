#include <bits/stdc++.h>
using namespace std;
bool isNumber(string s)
{
    bool hasDigit = false, hasDot = false, hasE = false;
    int n = s.size();
    int left = 0, right = n - 1;
    while (left <= right && s[left] == ' ')
        left++;
    while (left <= right && s[right] == ' ')
        right--;
    for (int i = left; i <= right; i++)
    {
        char c = s[i];
        if (isdigit(c))
        {
            hasDigit = true;
        }
        else if (c == '+' || c == '-')
        {
            if (i > left && s[i - 1] != 'e' && s[i - 1] != 'E')
                return false;
        }
        else if (c == '.')
        {
            if (hasDot || hasE)
                return false;
            hasDot = true;
        }
        else if (c == 'e' || c == 'E')
        {
            if (hasE || !hasDigit)
                return false;
            hasE = true;
            hasDigit = false;
        }
        else
        {
            return false;
        }
    }
    return hasDigit;
}
int main()
{
    string s;
    cin >> s;
    isNumber(s);
    return 0;
}