/*
���ߣ��߲Ӳ�
��дʱ�䣺2017/1/1
�޸�ʱ�䣺2018/4/4
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	stack<char>st;
	cout << "������һ���������ŵı��ʽ :" << endl;

	while (cin >> str) 
	{ 
		///ѭ�������ַ���   ���� Ctrl + z ��������������
		while (!st.empty()) st.pop();  ///��Ϊ��ѭ�����룬����Ҫȷ��ÿ�ν�����ʱ��ջΪ�գ���������һ�εĶ�����Ӱ��
		int len = str.size();
		int i;
		for (i = 0;i < len;i++) 
		{
			if (str[i] == '{' || str[i] == '[' || str[i] == '(') 
			{
				st.push(str[i]);
				continue; ///�������¶�ȡ
			}
			if (st.empty()) break;
			if (!st.empty() && str[i] == '}') 
			{
				if (st.top() != '{') 
				{
					cout << "ERROR   " << st.top() << " �� " << '}' << " �Ĵ������" << endl;
					break;
				}
				st.pop();
			}
			if (!st.empty() && str[i] == ']') 
			{
				if (st.top() != '[')
				{
					cout << "ERROR   " << st.top() << " �� " << ']' << " �Ĵ������" << endl;
					break;
				}
				st.pop();
			}
			if (!st.empty() && str[i] == ')') 
			{
				if (st.top() != '(') 
				{
					cout << "ERROR   " << st.top() << " �� " << ')' << " �Ĵ������" << endl;
					break;
				}
				st.pop();
			}
		}

		///�����ж��Ƿ�ջ���ж����
		if (i == len)
		{
			if (!st.empty()) 
			{
				int count1 = 0, count2 = 0, count3 = 0; ///count1����{}  count2����[]  count3����()
				while (!st.empty()) 
				{
					if (st.top() == '{') count1++;
					if (st.top() == '[') count2++;
					if (st.top() == '(') count3++;
					st.pop();
				}
				if (count1 != 0) cout << "�� { ���� } ��" << count1 << endl;
				if (count2 != 0) cout << "�� [ ���� ] ��" << count2 << endl;
				if (count3 != 0) cout << "�� ( ���� ) ��" << count3 << endl;
				cout << endl;
			}
			else 
			{
				cout << "YES" << endl;
			}
		}
		else if (st.empty()) 
		{ 
			///������ջ���Ѿ����ˣ��������黹û�б�����
			if (i != len)
			{
				int count1 = 0, count2 = 0, count3 = 0; ///count1����{}  count2����[]  count3����()
				for (int j = i;j < len;j++) 
				{
					if (str[j] == '}') count1++;
					if (str[j] == ']') count2++;
					if (str[j] == ')') count3++;
				}
				if (count1 != 0) cout << "�� } ���� { ��" << count1 << endl;
				if (count2 != 0) cout << "�� ] ���� [ ��" << count2 << endl;
				if (count3 != 0) cout << "�� ) ���� ( ��" << count3 << endl;
				cout << endl;
			}
			else 
			{
				cout << "YES" << endl;
			}
		}

		cout << endl << "������һ���������ŵı��ʽ :" << endl;
	}
	return 0;
}
