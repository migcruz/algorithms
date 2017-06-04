#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;


string reverse(string s)
{
    int length = s.length();
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}