#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>result;
int main()
{
	string s1 = {}, s2 = {};                                  //decimal numbers string
	void sum(vector<int> & v, vector<int> & v2, bool f, bool f2);
	void complement(bool f, vector<int> & v);
	void to_int(string & s, vector<int> & v);
	void to_binary(string & s);
	vector<int>S1;
	vector<int>S2;
	bool f1 = 0, f2 = 0;
	cout << "Enter decimal numbers:\n";
	cin >> s1 >> s2;

	to_binary(s1);                                  //translating decimal numbers to binary
	to_binary(s2);

	if (s1[s1.size() - 1] == '-')      //if negative number do not include first element
	{
		f1 = 1;
		string s = {};
		for (unsigned int i = 0; i < s1.size() - 1; i++)
			s += s1[i];
		s1 = s;
		to_int(s1, S1);    //translate to int by digit
	}
	else {                //if positive
		to_int(s1, S1);    //translate to int by digit
	}

	if (s2[s2.size() - 1] == '-')
	{
		f2 = 1;
		string s = {};
		for (unsigned int i = 0; i < s2.size() - 1; i++)
			s += s2[i];
		s2 = s;
		to_int(s2, S2);
	}
	else {
		to_int(s2, S2);
	}

	int n1 = 0, n2 = 0;                                //absolute value of number 1 and number 2
	for (unsigned int i = 0; i < S1.size(); i++)
		n1 += S1[i] * pow(2, S1.size() - i - 1);
	for (unsigned int i = 0; i < S2.size(); i++)
		n2 += S2[i] * pow(2, S2.size() - i - 1);

	while (S1.size() != 8)      //fill with 0s to 8-digit number
	{
		S1.push_back(0);
	}
	while (S2.size() != 8)
	{
		S2.push_back(0);
	}
	reverse(S1.begin(), S1.end());
	reverse(S2.begin(), S2.end());
	complement(f1, S1);
	complement(f2, S2);
	sum(S1, S2, f1, f2);

	if (result[result.size() - 1] == 1)                    //if got negative number
	{
		for (int i = result.size() - 2; i > -1; i--)       // inversion except for the first digit
		{
			if (result[i] == 0)
				result[i] = 1;
			else
				result[i] = 0;
		}
		if ((f1 == false && n1 < n2) | (f2 == false && n1 > n2))
		{
			result[0]++;                                                  //adding '1' in the 2 cases
			for (unsigned int i = 0; i < result.size() - 1; i++)
			{
				if (result[i] > 1)
				{
					result[i] = 0;
					if(i != result.size() - 1)
					    result[i + 1]++;
				}
			}
		}
	}
	cout << "Result in direct form:\n";                 
	for (int i = result.size() - 1; i > -1; i--)
		cout << result[i];
}
void to_binary(string& s)
{
	string r; ; int n = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] != '-')
			n = (s[i] - '0') * pow(10, s.size() - i - 1) + n;                                                                                         //-1????????????
	}
	while (n != 0) 
	{ 
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2; 
	}
	if (s[0] == '-')
		r += '-';
	s = r;
}
void to_int(string& s, vector<int>& v)    //char to int
{
	for (unsigned int i = 0; i < s.size(); i++)
	{
		v.push_back((int)s[i] - (int)('0'));  
	}
}
void complement(bool f, vector<int>& v)
{
	if (f)   //if negative number
	{
		for (unsigned int i = 0; i < v.size(); i++)    //ones complement (inversion)
		{
			if (v[i] == 0)
				v[i] = 1;
			else 
				v[i] = 0;
		}
		v[v.size() - 1]++;                              //twos complement (adding 1)
		for (int i = v.size() - 1; i > -1 ; i--)
		{
			if (v[i] > 1)
			{
				v[i] = 0;
				v[i - 1]++;
			}
		}
	}
}
void sum(vector<int>& v, vector<int>& v2, bool f, bool f2)
{
	for (int i = v.size() - 2; i > -2 ; i--)
	{
		if (v[i + 1] + v2[i +1] == 0)
		{
			result.push_back(0);
			continue;
		}
		if (v[i + 1] + v2[i + 1] == 1)
		{
			result.push_back(1);
			continue;
		}
		if (v[i + 1] + v2[i + 1] == 2)
		{
			result.push_back(0);
			if(i!= -1)
				v[i]++;
			continue;
		}
		if (v[i + 1] + v2[i + 1] == 3)
		{
			result.push_back(1);
			if (i != -1)
				v[i]++;
			continue;
		}
	}
}