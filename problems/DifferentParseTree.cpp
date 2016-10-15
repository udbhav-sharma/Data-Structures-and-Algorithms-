#include <stack>
#include <iostream>

using namespace std;

bool isNumber(char c)
{
	if(c>='0' && c<='9')
		return true;
	return false;
}

bool isOperator(char c)
{
	if(c=='*' || c=='+')
		return true;
	return false;
}

bool isBracket(char c)
{
	if(c=='(' || c==')')
		return true;
	return false;
}

void baeautify(string postfix)
{
	stack<string> temp;
	for(int i=0;i<postfix.length();i++)
	{
		string temp_string="";
		temp_string+=postfix[i];
		if(isOperator(postfix[i]))
		{
			string right=temp.top();
			temp.pop();
			string left=temp.top();
			temp.pop();
			temp_string='{'+left+postfix[i]+right+'}';
		}
		temp.push(temp_string);
	}
	cout<<temp.top()<<endl;
}

void print(string postfix,stack<char> operators)
{
	while(!operators.empty())
	{
		postfix+=operators.top();
		operators.pop();
	}
	//cout<<postfix<<endl;
	baeautify(postfix);
}

void generate_parse(string expression,int i,string postfix,stack<char> operators)
{
	if(i==expression.length())
		print(postfix,operators);
	else if(isNumber(expression[i]))
	{
		postfix+=expression[i];
		generate_parse(expression,i+1,postfix,operators);
	}
	else if(isBracket(expression[i]))
	{
		if(expression[i]=='(')
		{
			operators.push(expression[i]);
			generate_parse(expression,i+1,postfix,operators);
		}
		else
		{
			while(!operators.empty() && operators.top()!='(')
			{
				postfix+=operators.top(); 
				operators.pop();
			}
			operators.pop();
			generate_parse(expression,i+1,postfix,operators);
		}
	}
	else
	{
		string temp_postfix=postfix;
		stack<char> temp_operators=operators;
		while(true)
		{
			temp_operators.push(expression[i]);
			generate_parse(expression,i+1,temp_postfix,temp_operators);
			temp_operators.pop();
			if(temp_operators.empty() || isBracket(temp_operators.top()))
				break;
			temp_postfix+=temp_operators.top();
			temp_operators.pop();
		}
	}
}

int main()
{
	string expression;
	cin>>expression;

	stack<char> operators;
	generate_parse(expression,0,"",operators);

	return 0;
}