//2151753 ������ �ƿ�
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<io.h>
#include"cmd_console_tools.h"
using namespace std;
const char* to_search = ".\\stage\\*.*";//�����ҵ��ļ���֧��ͨ���(��ѡ���ļ����ͣ�
void read_the_file(char name[][30], int& num) {
	intptr_t handle;                                   //���ڲ��ҵľ��
	struct _finddata_t fileinfo;                       //�ļ���Ϣ�Ľṹ��
	handle = _findfirst(to_search, &fileinfo);          //��һ�β���
	if (handle == -1)
		cout << "�޷���[." << char(92) << "stage" << char(92) << "]Ŀ¼" << endl;
	else {
		if (fileinfo.attrib != _A_SUBDIR)//
			strcpy(name[num++], fileinfo.name);
		while (!_findnext(handle, &fileinfo))               //ѭ�������������ϵ��ļ���֪���Ҳ���������Ϊֹ
		{
			if (fileinfo.attrib != _A_SUBDIR)//
				strcpy(name[num++], fileinfo.name);
		}
		_findclose(handle);
	}
}
//��ȡ�ļ����ڵ��ļ���
void delet_wrong(char ori_name[][30], int& num) {
	for (int i = 0; i < num; i++) {
		if (ori_name[i][14] == '.' || ori_name[i][15] == '.' || ori_name[i][16] == '.' || ori_name[i][17] != '.') {
			for (int j = i; j < num; j++) {
				strcpy(ori_name[j], ori_name[j + 1]);
			}
			num--;
		}
	}
	//��ɾ��������Ҫ���
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			if (strcmp(ori_name[i], ori_name[j]) > 0) {
				char temp[30];
				strcpy(temp, ori_name[i]);
				strcpy(ori_name[i], ori_name[j]);
				strcpy(ori_name[j], temp);
			}
		}
	}
	//�ֵ�����������
}
//ɾ������ȷ�����ݣ����Ұ����ֵ��������������
void change_to_num(char ori_name[][30], char num_name[][30], int num) {
	for (int i = 0; i < num; i++) {
		char s[4] = { ori_name[i][14],ori_name[i][15],ori_name[i][16],'\0' };
		strcpy(num_name[i], "�ؿ�");
		strcat(num_name[i], s);
	}
}
//����ļ�����ת��


