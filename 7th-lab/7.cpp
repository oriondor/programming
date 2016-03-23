// 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstring>
#include <cctype>
using namespace std;

char inArr[100];//входной массив строка
char existingWords[100][100];//массив слов
int separation();
void sort(int,int);

//=====главная функция
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color f0");

	puts("Введите строку(только цифры и пробелы): ");
	gets_s(inArr);//ввод строки
	int wordsQantity = separation();//Количество слов 
	int method;//метод сортировки
	cout << "Количество слов в строке: " << wordsQantity << endl<<endl;
	cout << "Чтобы совершить сортировку:\n по возрастанию - введите 1.\n по убыванию - введите 2." << endl;
	cin >> method;
	sort(wordsQantity, method);
    return 0;
}
//=====функция разделения введенной строки на слова
int separation() {
	int q = 0;//счетчик слов
	char *delimiter = " ";//разделительные знаки
	cout <<endl<< "Список слов, содержащихся в ранее введенной строке:" << endl; 
	char *nextT;//указатель на следующую лексему
	char *p = strtok_s(inArr, delimiter, &nextT);//текущая лексема
	while (p!=NULL) {//пока есть лексемы
		strcpy_s(existingWords[q], p);//перенос текущей лексемы в массив слов в (q) строку
		q++;
		puts(p);//показать текущую лексему
		p = strtok_s(NULL, delimiter, &nextT);//продолжить поиск
	}
	cout << endl;
	return q;
}
//=====сортировка
void sort(int wordsQuantity, int method) {
	if (method>2 || method<1) {
		method = 1;
		cout << "Похоже, что-то пошло не так... Сортировка будет выполнена по возрастанию!" << endl;
	}

	int sortedWords[100];//массив отстортированных слов
	bool done = false;//готово/нет
	for (int i = 0; i < wordsQuantity; i++) {
		sortedWords[i] = atoi(existingWords[i]);
	}	
	while (!done) {
		int temp = 0;//временная переменная
		done = true;
		for (int i = 0; i < wordsQuantity - 1; i++) {
			if (method == 1) {//если метод=1, то по возрастанию....
				if (sortedWords[i] > sortedWords[i + 1]) {
					done = false;
					temp = sortedWords[i];
					sortedWords[i] = sortedWords[i + 1];
					sortedWords[i + 1] = temp;
				}
			}
			else {//...иначе - по убыванию
				if (sortedWords[i] < sortedWords[i + 1]) {
					done = false;
					temp = sortedWords[i];
					sortedWords[i] = sortedWords[i + 1];
					sortedWords[i + 1] = temp;
				}
			}
		}
	}
	cout <<endl<< "Массив был отсортирован: " << endl;
	for (int i = 0; i < wordsQuantity; i++) {
		cout << " " << sortedWords[i] << endl;
	}
	int nxt;
	cout << "Чтобы отсортировать другим методом введите 3. При любом другом значении, программа будет закрыта." << endl;
	cin >> nxt;
	if (nxt == 3)sort(wordsQuantity, method + 1); else system("color 2f");
}
