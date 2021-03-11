#include <iostream>
#include <string>
using namespace std;
int len_key = 100;//密钥最大长度定义
char* key = new char[len_key + 1];//密钥定义
int len_max = 100;//明文最大长度定义
char* pla = new char[len_max + 1];//明文定义
char* cip = new char[len_max + 1];//密文定义
int get_key()//输入密钥
{
    cout << "Input key:";
    cin.get(key, len_key + 1);
    cin.get();
    len_key = strlen(key);//更新密钥长度
    return 0;
}
int get_pla()//输入明文
{
    cout << "Input plaintext:";
    cin.get(pla, len_max + 1);
    cin.get();
    len_max = strlen(pla);//更新明文长度
    return 0;
}
int get_cip()//输入密文
{
    cout << "Input ciphertext:";
    cin.get(cip, len_max + 1);
    cin.get();
    len_max = strlen(cip);//更新密文长度
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
            cip[i] = (pla[i] + key[i % len_key] - 2 * 'a') % 26 + 'a';
        }
    }
    cout << "Ciphertext is:";
    for (int i = 0; i < len_max; i++)
    {
        cout << cip[i];
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
            pla[i] = (cip[i] - key[i % len_key]+26) % 26 + 'a';
        }
    }
    cout << "Plaintext is:";
    for (int i = 0; i < len_max; i++)
    {
        cout << pla[i];
    }
    cout << endl;
    return 0;
}
int fin()//释放内存
{
    delete pla;
    delete cip;
    delete key;
    return 0;
}
int main()
{
    int ope=-1;
    while (ope != 0)
    {
        cout << "1.加密 2.解密 0.结束" << endl;
        cin >>ope;
        cin.get();
        if (ope == 0)
        {
            fin();
            return  0;
        }
        else if (ope == 1)
        {
            get_pla();
            get_key();
            enc();
        }
        else if (ope == 2)
        {
            get_cip();
            get_key();
            dec();
        }
    }
    fin();
    return  0;
}