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
    decimal = transl1(s, len);  //translation to decimal system
    
    int decimal1 = decimal;   //copy of decimal
    int size14 = 1;          //count the size of number in 14-system
    for (int i = 14; decimal1 >= 14; i*=14)
    {
        decimal1 /= i;
        size14++;
    }
   
    for (int i = size14; i > 0; i--)  //translation to 14-system
    {
         cout << transl2(decimal / (int)pow(14, i - 1));
    }
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
    for (int i = 0; i < len; i++)  
    {

        d += (a[i] - '0') * pow(5, len - i - 1);   //from 5 to decimal system
    }
    return d;
}
char transl2(int d)
{
    int reminder;
    reminder = d % 14;  //from decimal to 14-system
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