#include <iostream>
#include <ctime>
using namespace std;
int mark[26] = { 0 };//标志位
int key[26];//密钥
int len_max = 100;//明文最大长度定义
char* pla = new char[len_max + 1];//明文定义
char* cip = new char[len_max + 1];//密文定义
int rand_key()//随机密钥
{
	srand((unsigned)time(NULL));
	int t = 0;
	int temp;
	while (t != 26)
	{
		temp = rand() % 26;
		if (mark[temp] == 0)
		{
			mark[temp] = 1;
			key[t] = temp;
			t++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << (char)(i + 'a') << " ";
	}
	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << (char)(key[i] + 'A') << " ";
	}
	cout << endl;
	return 0;
}
int get_key()//输入密钥
{
	for (int i = 0; i < 26; i++)
	{
		cout << char('a' + i) << ":";
		char temp;
		cin >> temp;
		key[i] = temp - 'A';
	}
	for (int i = 0; i < 26; i++)
	{
		cout << (char)(i + 'a') << " ";
	}
	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << (char)(key[i] + 'A') << " ";
	}
	cout << endl;
	cin.get();
	return 0;
}
int get_pla()//输入明文
{
	cout << "输入明文:";
	cin.get(pla, len_max + 1);
	cin.get();
	len_max = strlen(pla);//更新明文长度
	for (int i = 0; i < len_max; i++)
	{
		if (pla[i] != ' ')
		{
			pla[i] -= 'a';
		}
	}
	return 0;
}
int get_cip()//输入密文
{
	cout << "输入密文:";
	cin.get(cip, len_max + 1);
	cin.get();
	len_max = strlen(cip);//更新密文长度
	cout << "密文:";
	for (int i = 0; i < len_max; i++)
	{
		if (cip[i] != ' ')
		{
			cip[i] -= 'A';
		}
	}
	return 0;
}
int enc()//加密
{
	for (int i = 0; i < len_max; i++)
	{
		if (pla[i] == ' ') //空格不做加密
		{
			cip[i] = ' ';
		}
		else
		{
			cip[i] = key[pla[i]];
		}
	}
	cout << "密文:";
	for (int i = 0; i < len_max; i++)
	{
		if (cip[i] != ' ')
		{
			cout << char(cip[i] + 'A');
		}
		else
		{
			cout << cip[i];
		}
	}
	cout << endl;
	return 0;
}
int dec()//解密
{
	for (int i = 0; i < len_max; i++)
	{
		if (cip[i] == ' ') //空格不做解密
		{
			pla[i] = ' ';
		}
		else
		{
			for (int t = 0; t < 26; t++)
			{
				if (key[t] == cip[i])
				{
					pla[i] = t;
				}
			}
		}
	}
	cout << "明文:";
	for (int i = 0; i < len_max; i++)
	{
		cout << char(pla[i]+'a');
	}
	cout << endl;
	return 0;
}
int fin()
{
	delete cip;
	delete pla;
	return 0;
}
int main()
{
	int ope = -1;
	while (ope != 0)
	{
		cout << "1.随机加密 2.手动加密 3.解密 0.结束" << endl;
		cin >> ope;
		cin.get();
		if (ope == 0)
		{
			fin();
			return 0;
		}
		else if (ope == 1)
		{
			rand_key();
			get_pla();
			enc();
		}
		else if (ope == 2)
		{
			get_key();
			get_pla();
			enc();
		}
		else if (ope == 3)
		{
			get_key();
			get_cip();
			dec();
		}
	}
	fin();
	return 0;
}