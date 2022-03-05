#include<iostream>

/*19.Известны следующие данные о N учениках класса: фамилия, дата рождения (число, месяц и год).
Вывести на экран фамилии тех учеников, у кого сегодня день рождения (сегодняшнюю дату вводить с клавиатуры).*/

struct student
{
	char name[100];
	int D, M, Y;
};

void keyboard(student& s)
{
	printf("Введите имя студента и дату его рождедния:\n");
	scanf_s("%s\n%d%d%d", s.name, 100, &s.D, &s.M, &s.Y);
}

void file(student s[],int n)
{
	FILE* a;
	if (fopen_s(&a, "1.txt", "r"))
	{
		printf("couldn't open file 1.txt");
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		fscanf_s(a, "%s%d%d%d", s[i].name, 100, &s[i].D, &s[i].M, &s[i].Y);
	}

	fclose(a);
}

void printStruct(student s)
{
	printf("%s\n%d//%d//%d\n", s.name, s.D, s.M, s.Y);
}

void printName(student s)
{
	printf("%s", s.name);
}

void bithday(student s[],int n , int D, int M)
{
	for (int i = 0; i < n; i++)
	{
		if (s[i].D == D && s[i].M == M)
		{
			printName(s[i]);
		}
	}
	
}

int main()
{
	system("chcp 1251");
	system("cls");

	const int N = 5;
	student arr[N];
	int way, D, M, Y;

	printf("Выберите способ заполнения массива:\n");
	printf("1 - с клавиатуры\n");
	printf("2 - из текстового файла\n");
	do
	{
		scanf_s("%d", &way);
	} while (way < 1 || way>2);

	switch (way)
	{
	case 1:
		for (int i = 0; i < N; i++)
		{
			keyboard(arr[i]);
		}

		for (int i = 0; i < N; i++)
		{
			printStruct(arr[i]);
		}
		break;
	case 2:
		file(arr, N);

		for (int i = 0; i < N; i++)
		{
			printStruct(arr[i]);
		}
		break;
	}

	printf("Введите дату:\n");
	scanf_s("%d%d%d", &D, &M, &Y);

	bithday(arr, N, D, M);
	
	return 0;
}