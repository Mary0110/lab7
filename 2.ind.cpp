//»з пр€мого кода в обратный 
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char reverse(char s);
    string direct = {};  //пр€мой код
    string result = {};  //обратный код
    cout << "Enter direct code\n";
    cin >> direct;
    if (direct[0] == '0')
        cout << direct;
    else
    {
        result += '1';
        for (int i = 1; direct[i]; i++)
        {
            char a = reverse(direct[i]); 
            result += a;
        }
        cout<< result;
    }
}
char reverse(char s)
{
    char a;
    if (s == '0')
        a = '1';
    else
        a = '0';
    return a;
}
