/*
作者：倪灿灿
编写时间：2017/1/1
修改时间：2018/4/4
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	stack<char>st;
	cout << "请输入一个含有括号的表达式 :" << endl;

	while (cin >> str) 
	{ 
		///循环读入字符串   按下 Ctrl + z 结束函数的输入
		while (!st.empty()) st.pop();  ///因为是循环读入，所以要确保每次进来的时候栈为空，否则会对下一次的读入有影响
		int len = str.size();
		int i;
		for (i = 0;i < len;i++) 
		{
			if (str[i] == '{' || str[i] == '[' || str[i] == '(') 
			{
				st.push(str[i]);
				continue; ///继续向下读取
			}
			if (st.empty()) break;
			if (!st.empty() && str[i] == '}') 
			{
				if (st.top() != '{') 
				{
					cout << "ERROR   " << st.top() << " 与 " << '}' << " 的错误配对" << endl;
					break;
				}
				st.pop();
			}
			if (!st.empty() && str[i] == ']') 
			{
				if (st.top() != '[')
				{
					cout << "ERROR   " << st.top() << " 与 " << ']' << " 的错误配对" << endl;
					break;
				}
				st.pop();
			}
			if (!st.empty() && str[i] == ')') 
			{
				if (st.top() != '(') 
				{
					cout << "ERROR   " << st.top() << " 与 " << ')' << " 的错误配对" << endl;
					break;
				}
				st.pop();
			}
		}

		///用来判断是否栈中有多余的
		if (i == len)
		{
			if (!st.empty()) 
			{
				int count1 = 0, count2 = 0, count3 = 0; ///count1代表{}  count2代表[]  count3代表()
				while (!st.empty()) 
				{
					if (st.top() == '{') count1++;
					if (st.top() == '[') count2++;
					if (st.top() == '(') count3++;
					st.pop();
				}
				if (count1 != 0) cout << "左 { 比右 } 多" << count1 << endl;
				if (count2 != 0) cout << "左 [ 比右 ] 多" << count2 << endl;
				if (count3 != 0) cout << "左 ( 比右 ) 多" << count3 << endl;
				cout << endl;
			}
			else 
			{
				cout << "YES" << endl;
			}
		}
		else if (st.empty()) 
		{ 
			///用来看栈中已经空了，但是数组还没有遍历完
			if (i != len)
			{
				int count1 = 0, count2 = 0, count3 = 0; ///count1代表{}  count2代表[]  count3代表()
				for (int j = i;j < len;j++) 
				{
					if (str[j] == '}') count1++;
					if (str[j] == ']') count2++;
					if (str[j] == ')') count3++;
				}
				if (count1 != 0) cout << "右 } 比左 { 多" << count1 << endl;
				if (count2 != 0) cout << "右 ] 比左 [ 多" << count2 << endl;
				if (count3 != 0) cout << "右 ) 比左 ( 多" << count3 << endl;
				cout << endl;
			}
			else 
			{
				cout << "YES" << endl;
			}
		}

		cout << endl << "请输入一个含有括号的表达式 :" << endl;
	}
	return 0;
}
