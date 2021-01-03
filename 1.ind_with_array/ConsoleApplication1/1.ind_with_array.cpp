#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    string s = {}; int decimal = 0;
    int length(string a);
    int transl1(string a, int len);
    char transl2(int d);
    cout << "Enter s:\n";
    getline(cin, s);
    int len = length(s);  
    char* result = new char[20];

    decimal = transl1(s, len);
    int k;
    for (k = 0; decimal != 0; k++)  //make funct3
    {
        
        result[k] = transl2(decimal);
        decimal /= 14;
    }
    
    for (int i = k - 1; i > -1; i--)
        cout << result[i];

    
    return 0;
}
int length(string a) {
    int i = 0;
    while (a[i])
        i++;
    return i;
}

int transl1(string a, int len)
{
    int d = 0;
    for (int i = 0; i < len; i++)  //make funct2
    {
        
        d += (a[i] - '0') * pow(5, len - i - 1);   //from 5 to decimal system
    }
    return d;
}
char transl2(int d)
{
    int reminder;
    reminder = d % 14;  //from decimal to 14
    char r;
    if (reminder == 10)
        r = 'A';
    else if (reminder == 11)
        r = 'B';
    else if (reminder == 12)
        r = 'C';
    else if (reminder == 13)
        r = 'D';
    else
        r = reminder + '0';
    return r;
}