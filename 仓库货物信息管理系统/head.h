/***********************************
    @���ƣ��ֿ������Ϣ����ϵͳ���
    @author��super-so,��������,ɧ��
    @create��2019.12.30~2019.12.31
************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define N 100

int  users();
void menu();
int  dataout();
void datain(int i);
void read(int i);
void query(int i);
void change(int i);
void sort(int i);
int  in(int i);
void out(int i);
int  clear(int i);

int sign = 1;                    //��ʾ���ã�����0�����ļ�ʧ��
int hang = 0;

struct goods                    //
{
    int num;					//���
    char name[100];				//����
    char category[100];			//���
    char specifications[100];	//���
    char manufactor[100];		//����
    char area[100];				//����
    int  inventory;				//�����
};

struct users
{
    char zh[20];                //����Ա�˺�
    char password[50];          //����Ա����
};

struct goods goods[N];
struct users Users[N];
