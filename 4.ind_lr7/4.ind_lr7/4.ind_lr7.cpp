#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int a[5] = {10,11,12,13,14};
char letters[5] = {'A','B','C','D'};
int f = 0;
vector<char>result;

int main()
{
	void subtraction(string & n1, string & n2, vector<char> & result2);
	void addition(string & n1, string & n2, vector<char> & result);
	int to_int(char c);
	string n1, n2;
	bool f1 = false, f2 = false;

	cout << "14-digit numbers:\n";
	cin >> n1;
	cin >> n2;
	int action;
	cout << "choose 1 for addition and 2 for subtraction" << endl;
	cin >> action;

	if (n1[0] == '-')      //if negative number do not include first element
	{
		f1 = true;
		string s = {};
		for (unsigned int i = 1; i < n1.size(); i++)
			s += n1[i];
		n1 = s;
	}
	if (n2[0] == '-')      //if negative number do not include first element
	{
		f2 = true;
		string s = {};
		for (unsigned int i = 1; i < n2.size(); i++)
			s += n2[i];
		n2 = s;
	}
	unsigned int len1 = n1.size();
	unsigned int len2 = n2.size();
	int max;
	if (len1 > len2)
	{
		max = 1;
	}
	else if (len1 < len2)
	{
		max = 2;
	}
	else
	{
		for (int i = 0; n1[i]; i++)
		{
			if (to_int(n1[i]) > to_int(n2[i]))
				max = 1;
			else if (to_int(n1[i]) > to_int(n2[i]))
				max = 2;
			else if (i == len1 - 1)
				max = 1;
		}
	}

	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	if (len1 > len2)                           //filling with '0' the smaller number
	{
		for (int i = 0; i < len1 - len2; i++)
		{
			n2 += "0";
		}
	}
	else if (len2 > len1)
	{
		for (int i = 0; i < len2 - len1; i++)
		{
			n1 += "0";
		}
	}
	if (action == 1)
	{
		if (f1 == false && f2 == false)
		{
			addition(n1, n2, result);
		}
		else if (f1 == true && f2 == true)
		{
			addition(n1, n2, result);
			result.push_back('-');
		}
		else if (f1 == true)
		{
			
			if (max == 1)
			{
				subtraction(n1, n2, result);
				result.push_back('-');
			}
			else
			{
				subtraction(n2, n1, result);
			}
		}
		else if (f1 == false)
		{
			
			if (max == 2) {
				subtraction(n2, n1, result);
				result.push_back('-');
			}
			else 
				subtraction(n1, n2, result);
		}
	}
	if (action == 2)
	{
		if (f1 == false && f2 == false)
		{
			
			if (max == 2)
			{
				subtraction(n2, n1, result);
				result.push_back('-');
			}
			else
				subtraction(n1, n2, result);

		}
		else if (f1 == true && f2 == true)
		{
			
			if (max == 1)
			{
				subtraction(n1, n2, result);
				result.push_back('-');
			}
			else
				subtraction(n2, n1, result);

		}
		else if (f1 == true)
		{
			addition(n1, n2, result);
			result.push_back('-');
		}
		else if (f1 == false)
		{
			addition(n1, n2, result);
		}
	}
	cout << endl << "Result:\n"; 
    reverse(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
			cout << result[i];
}
int to_int(char d)
{
	if (d <= '9')
	{
		return d - '0';
	}
	if (d >= 'A')
	{
		return a[d - 'A'];
	}
}
void addition(string& n1, string& n2, vector<char>& result)
{
	int to_int(char d);
	vector<int>v;
	for (int i = 0; i < n1.size(); i++)
	{
		int digit = to_int(n1[i]) + to_int(n2[i]);
		v.push_back(digit);
	}
	
	for (unsigned int i = 1; i <= n1.size(); i++)
	{
		if (v[i - 1] >= 14)
		{
			if (i == n1.size())
			{
				v.push_back(0);
				n1 += '0';
			}

			v[i] += 1;
			v[i - 1] -= 14;
			if (v[i - 1] > 9)
				result.push_back(letters[v[i - 1] - 10]);
			else
				result.push_back(v[i - 1] + '0');
		}
		else {
			if (v[i - 1] > 9)
				result.push_back(letters[v[i - 1] - 10]);
			else
				result.push_back(v[i - 1] + '0');
		}
	}
}
void subtraction(string& N1, string& N2, vector<char>& result2)
{
	vector<int>v;
	for (int i = 0; i < N1.size(); i++)
	{
		int digit = to_int(N1[i]) - to_int(N2[i]);
		v.push_back(digit);
	}
	cout << endl;
	
	for (int i = 0; i < N1.size(); i++)
	{
		if (v[i] < 0)
		{
			if (i != N1.size() - 1)
			{
				v[i + 1] -= 1;
				v[i] += 14;
			}
		
			if (v[i] > 9)
				result.push_back(letters[v[i] - 10]);
			else
				result.push_back(v[i] + '0');
		}
		else
		{
			if (v[i] > 9)
				result.push_back(letters[v[i] - 10]);
			else
				result.push_back(v[i] + '0');
		}
	}
}