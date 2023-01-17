//2151753 彭坤宇 计科
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<io.h>
#include"cmd_console_tools.h"
using namespace std;
const char* to_search = ".\\stage\\*.*";//欲查找的文件，支持通配符(可选择文件类型）
void read_the_file(char name[][30], int& num) {
	intptr_t handle;                                   //用于查找的句柄
	struct _finddata_t fileinfo;                       //文件信息的结构体
	handle = _findfirst(to_search, &fileinfo);          //第一次查找
	if (handle == -1)
		cout << "无法打开[." << char(92) << "stage" << char(92) << "]目录" << endl;
	else {
		if (fileinfo.attrib != _A_SUBDIR)//
			strcpy(name[num++], fileinfo.name);
		while (!_findnext(handle, &fileinfo))               //循环查找其他符合的文件，知道找不到其他的为止
		{
			if (fileinfo.attrib != _A_SUBDIR)//
				strcpy(name[num++], fileinfo.name);
		}
		_findclose(handle);
	}
}
//读取文件夹内的文件名
void delet_wrong(char ori_name[][30], int& num) {
	for (int i = 0; i < num; i++) {
		if (ori_name[i][14] == '.' || ori_name[i][15] == '.' || ori_name[i][16] == '.' || ori_name[i][17] != '.') {
			for (int j = i; j < num; j++) {
				strcpy(ori_name[j], ori_name[j + 1]);
			}
			num--;
		}
	}
	//先删除不符合要求的
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
	//字典序升序排列
}
//删除不正确的数据，并且按照字典序升序进行排列
void change_to_num(char ori_name[][30], char num_name[][30], int num) {
	for (int i = 0; i < num; i++) {
		char s[4] = { ori_name[i][14],ori_name[i][15],ori_name[i][16],'\0' };
		strcpy(num_name[i], "关卡");
		strcat(num_name[i], s);
	}
}
//完成文件名的转换


