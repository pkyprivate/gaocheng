//2151753 ������ƿ�
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ����;�̬�ֲ�����
   ----------------------------------------------------------------------------------- */
void line1(char x,char y,const char End) {
	if (x != 'A') {
		if ((x == y)&& (End - x)!=0)
			cout <<setfill(' ')<< setw(End - x) << " ";
		cout << x;
		line1(x - 1, y,End);
		cout << x;
	}
	if (x == 'A') {
		if ((x == y) && (End - x) != 0)
			cout << setfill(' ') << setw(End - x) << " ";
		cout << x;
	}
}


void line2(char x, char y, const char End) {
	if (x != End) {
		if ((x == y) && (x != 'A'))
			cout << setfill(' ') << setw(x - 'A')<<" ";
		cout << x;
		line2(x+1,y, End);
		cout << x;
	}
	else {
		if ((x == y) && (x != 'A'))
			cout << setfill(' ') << setw(x - 'A') << " ";
		cout << x;
	}
}
   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
   ***************************************************************************/
void print_tower(char x,const char End,int choose )
{
	if (choose == 1) {
		if ((x - 'A') != 0) {
			print_tower(x - 1, End, choose);
			line1(x, x,End);
			cout << endl;
		}
		else {
			line1(x, x, End);
			cout << endl;
		}
	}
	if (choose == 2) {
		if (x != End) {
			line2(x,x,End);
			cout << endl;
			print_tower(x + 1, End, choose);
		}
		else {
			line2(x, x, End);
			cout << endl;
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}
	const char End = end_ch;
	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << "=" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << "=" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch,End,1);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=')<< setw(2 * (end_ch - 'A') + 1) << "=" << endl;  /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << "=" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower('A', End, 2);
	cout << endl;
	return 0;
}