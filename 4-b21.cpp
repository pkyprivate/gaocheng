//2151753 ������ �ƿ�
#include <iostream>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4������������������κ���ʽ��ѭ��
   ---------------------------------------------------------------------
*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ݹ鷽ʽ���ʮ���Ƶ��������Ƶ�ת������ӡ
  ���������int num ��ʮ������
			int base��Ҫת���Ľ���
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
			2������������κ���ʽ��ѭ��
			3��������ʹ��cmath�еĺ���
			4��������ʹ��64λ����
***************************************************************************/
void dec_to_base_n(int num, int base)
{
	if (num < 0) {
		unsigned int num0;
		num0 = num;
		dec_to_base_n(num0 / base, base);
		if (num0 % base < 10)
			cout << num0 % base;
		else if (num0 % base == 10)
			cout << "A";
		else if (num0 % base == 11)
			cout << "B";
		else if (num0 % base == 12)
			cout << "C";
		else if (num0 % base == 13)
			cout << "D";
		else if (num0 % base == 14)
			cout << "E";
		else if (num0 % base == 15)
			cout << "F";
	}
	else {
		if (num > base || num == base) {
			dec_to_base_n(num / base, base);
			if (num % base < 10)
				cout << num % base;
			else if (num % base == 10)
				cout << "A";
			else if (num % base == 11)
				cout << "B";
			else if (num % base == 12)
				cout << "C";
			else if (num % base == 13)
				cout << "D";
			else if (num % base == 14)
				cout << "E";
			else if (num % base == 15)
				cout << "F";
		}
		else {
			if (num % base < 10)
				cout << num % base;
			else if (num % base == 10)
				cout << "A";
			else if (num % base == 11)
				cout << "B";
			else if (num % base == 12)
				cout << "C";
			else if (num % base == 13)
				cout << "D";
			else if (num % base == 14)
				cout << "E";
			else if (num % base == 15)
				cout << "F";
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	int num, base;

	cout << "������ʮ��������(int��)��Ҫת���Ľ���[2..16]" << endl;
	cin >> num >> base;		//�������������numΪint�ͷ�Χ�κ�ֵ���ɣ�baseΪ2~16��������10����

	if (base == 10) //����Ϊ10ֱ���˳�
		return -1;

	/* ��ɽ���ת������ӡ */
	dec_to_base_n(num, base);
	cout << endl;

	return 0;
}