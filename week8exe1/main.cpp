#pragma once
#include <iostream>
#include "StackVector.h"
using namespace std;
string infixToPostfix(string s)
{
	int i = 0;
	StackVector<char> stack(s.length()+1);
	
	string str;

	while (i < s.length())
	{
		char ch = s[i];
		if (ch == '(')
			stack.push(ch);
		else if (ch == ')')
		{
			while (!(stack.top() == '('))
			{
				str += stack.pop();
				str += ' ';

			}
			stack.pop();
		}
		else if (ch == '*' || ch == '/'||ch=='+'|| ch == '-')
		{
			if (ch == '+' || ch == '-')
			{
				while ((stack.top() == '*') || (stack.top() == '/'))
				{
					str += stack.pop();
					str += ' ';

				}
			}
			stack.push(ch);
		}
		else if (ch >= '0') {
			str += ch;
			if ((i + 1) < s.length())
			{
				if (s[i + 1]<'0' || s[i + 1]>'9')
					str += ' ';
			}
			else {
				str += ' ';
			}
			

		}

        i++;
	}
	while (!stack.isEmpty())
	{
		str += stack.pop();
		str += ' ';
	}

	return str;
}
float calcPostfix(string s)
{
	float sum;
	StackVector<int> stack(s.length()+1);
	for (int i = 0; i < s.length(); i++)
	{	
		if (s[i] == '*' )
		{
			int l = stack.pop();
			int y = stack.pop();
			sum=l* y;
			stack.push(sum);
		}
		else if (s[i] == '/')
		{
			int l = stack.pop();
			int y = stack.pop();
			sum = y /l ;
			stack.push(sum);
		}
		else if (s[i] == '-')
		{
			int l = stack.pop();
			int y = stack.pop();
			sum =  y-l;
			stack.push(sum);
		}
		else if (s[i] == '+')
		{
			int l = stack.pop();
			int y = stack.pop();
			sum = l + y;
			stack.push(sum);
		}
		if (s[i] >= '0')
		{
			int num=0;
			bool flag = false;
				while ((i ) < s.length()&&s[i ] != ' ')
				{
					flag = true;
					num = num * 10;
				    num+= (s[i]-48) ;
					i++;
				}
				if (!flag)
					num = s[i]-48;
			stack.push(num);
		}

	}
	return stack.pop();
}


int main() {
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << "in postfix form: " << postfix << endl;
	cout << "calculated value: " << calcPostfix(postfix) << endl;
	return 0;
}
//enter an infix expression as a string
//(5 + 3)* ((20 / 10) + (8 - 6))
//in postfix form : 5 3 + 20 10 / 8 6 - +*
//calculated value : 32

