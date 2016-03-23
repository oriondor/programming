// 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstring>
#include <cctype>
using namespace std;

char inArr[100];//������� ������ ������
char existingWords[100][100];//������ ����
int separation();
void sort(int,int);

//=====������� �������
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color f0");

	puts("������� ������(������ ����� � �������): ");
	gets_s(inArr);//���� ������
	int wordsQantity = separation();//���������� ���� 
	int method;//����� ����������
	cout << "���������� ���� � ������: " << wordsQantity << endl<<endl;
	cout << "����� ��������� ����������:\n �� ����������� - ������� 1.\n �� �������� - ������� 2." << endl;
	cin >> method;
	sort(wordsQantity, method);
    return 0;
}
//=====������� ���������� ��������� ������ �� �����
int separation() {
	int q = 0;//������� ����
	char *delimiter = " ";//�������������� �����
	cout <<endl<< "������ ����, ������������ � ����� ��������� ������:" << endl; 
	char *nextT;//��������� �� ��������� �������
	char *p = strtok_s(inArr, delimiter, &nextT);//������� �������
	while (p!=NULL) {//���� ���� �������
		strcpy_s(existingWords[q], p);//������� ������� ������� � ������ ���� � (q) ������
		q++;
		puts(p);//�������� ������� �������
		p = strtok_s(NULL, delimiter, &nextT);//���������� �����
	}
	cout << endl;
	return q;
}
//=====����������
void sort(int wordsQuantity, int method) {
	if (method>2 || method<1) {
		method = 1;
		cout << "������, ���-�� ����� �� ���... ���������� ����� ��������� �� �����������!" << endl;
	}

	int sortedWords[100];//������ ���������������� ����
	bool done = false;//������/���
	for (int i = 0; i < wordsQuantity; i++) {
		sortedWords[i] = atoi(existingWords[i]);
	}	
	while (!done) {
		int temp = 0;//��������� ����������
		done = true;
		for (int i = 0; i < wordsQuantity - 1; i++) {
			if (method == 1) {//���� �����=1, �� �� �����������....
				if (sortedWords[i] > sortedWords[i + 1]) {
					done = false;
					temp = sortedWords[i];
					sortedWords[i] = sortedWords[i + 1];
					sortedWords[i + 1] = temp;
				}
			}
			else {//...����� - �� ��������
				if (sortedWords[i] < sortedWords[i + 1]) {
					done = false;
					temp = sortedWords[i];
					sortedWords[i] = sortedWords[i + 1];
					sortedWords[i + 1] = temp;
				}
			}
		}
	}
	cout <<endl<< "������ ��� ������������: " << endl;
	for (int i = 0; i < wordsQuantity; i++) {
		cout << " " << sortedWords[i] << endl;
	}
	int nxt;
	cout << "����� ������������� ������ ������� ������� 3. ��� ����� ������ ��������, ��������� ����� �������." << endl;
	cin >> nxt;
	if (nxt == 3)sort(wordsQuantity, method + 1);
}
