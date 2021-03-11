#include <iostream>
#include <ctime>
using namespace std;
int k[2] = { -1,0 };//密钥初始化
int len_max = 100;//明文最大长度定义
char* pla = new char[len_max + 1];//明文定义
char* cip = new char[len_max + 1];//密文定义
int mgcd(int num_a, int num_b)//判断两数互质
{
    int temp;
    if (num_a < num_b)
    {
        temp = num_a; num_a = num_b; num_b = temp;
    }
    while (num_a % num_b)
    {
        temp = num_b;
        num_b = num_a % num_b;
        num_a = temp;
    }
    return num_b;//返回1互质
}
int inv(int num_a, int num_b)//遍历求逆
{
    for (int i = 0; i < num_b; i++)
    {
        if (num_a * i % num_b == 1)
        {
            return i;
        }
    }
    return 0;
}
int rand_key()//随机密钥
{
    srand((unsigned)time(NULL));
    while (mgcd(k[0], 26) != 1)
    {
        k[0] = rand() % 24 + 2;//2-25中的随机数
    }
    k[1] = rand() % 26;
    cout << "key=(" << k[0] << "," << k[1] << ")" << endl;
    return 0;
}
int get_key()//输入密钥
{
    cout << "输入密钥:";
    cin >> k[0] >> k[1];
    cout << "key=(" << k[0] << "," << k[1] << ")" << endl;
    return 0;
}
int get_pla()//输入明文
{
    cout << "输入明文:";
    cin.get(pla, len_max + 1);
    cin.get();
    len_max = strlen(pla);//更新明文长度
    cout << "明文:";
    for (int i = 0; i < len_max; i++)
    {
        if (pla[i] != ' ')
        {
            pla[i] -= 'a';
            cout << (int)pla[i] << " ";
        }
    }
    cout << endl;
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
            cip[i] -= 'a';
            cout << (int)cip[i] <<" ";
        }
    }
    cout << endl;
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
            cip[i] = (pla[i] * k[0] + k[1]) % 26 + 'a';
        }
    }
    cout << "密文:";
    for (int i = 0; i < len_max; i++)
    {
        cout << cip[i];
    }
    cout << endl;
    return 0;
}
int dec()//解密
{
    int inv_num = inv(k[0], 26);
    for (int i = 0; i < len_max; i++)
    {
        if (cip[i] == ' ') //空格不做解密
        {
            pla[i] = ' ';
        }
        else
        {
            pla[i] = ((cip[i] - k[1]) * inv_num + inv_num * 26) % 26 + 'a';
        }
    }
    cout << "明文:";
    for (int i = 0; i < len_max; i++)
    {
        cout << pla[i];
    }
    cout << endl;
    return 0;
}
int fin()
{
    delete pla;
    delete cip;
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
            return  0;
        }
        else if (ope == 1)
        {
            get_pla();
            rand_key();
            enc();
        }
        else if (ope == 2)
        {
            get_pla();
            get_key();
            enc();
        }
        else if (ope == 3)
        {
            get_cip();
            get_key();
            dec();
        }
    }
    fin();
    return 0;
}