//2151753 ������ �ƿ�
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */

	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str, 256);
	p = str;
	pa = a;
	pnum = a;
	is_num = 0;
	for (; *p != '\0'; p++) {
		*pa = 0;
		while (1) {
			if (*p >= 48 && *p <= 57) {
				*pa = 10 * (*pa) + int(*p++) - 48;
				is_num = 1;
			}
			else {
				if (is_num) {
					pa++;
				}
				is_num = 0;
				break;
			}
		}
	}
	cout << "����" << (pa - pnum) << "������" << endl;
	for (; pnum < pa; pnum++) {
		cout << *pnum << " ";
	}
	cout << endl;
	return 0;
}
