#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>

int Task_1_2(void);
int Task_1_3(void);
long int Task_2(long int n);
void Task_12(void);

int main(void)
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	Task_1_2();
	Task_1_3();
	Task_12();

	char repeat = 'y';

	do
	{
		long int number;
		printf("Введите число: ");
		scanf("%ld", &number);

		long int result = Task_2(number);
		printf("Результат: %ld\n", result);

		printf("Повторить? (Y/N): "); 
		fflush(stdin);                
		scanf(" %c", &repeat);
	} 
	while (repeat == 'y' || repeat == 'Y');

	return 0;
}

int Task_1_2()
{
	int ROW = 9;
	int r, c;
	printf("Треугольник к заданию 2:\n");

	for (r = 1; r <= ROW;++r)
	{
		for (c = 1; c <= r;++c)
			printf("%5d", c * r);
		printf("\n");
	}
	system("pause");
	return 0;
}

int Task_1_3()
{
	int dlin, shir;
	printf("Треугольник к варианту 12:\n");
	for (dlin = 30;dlin >= 26; --dlin)
	{
		for (shir = dlin; shir <= 30; ++shir)
			printf("%5d", shir);
		printf("\n");
	}
	system("pause");
	return 0;
}

long int Task_2(long int n) 
{
	long int sum_even = 0;
	long int sum_odd = 0;
	int pos = 1; 

	while (n > 0) {
		int digit = n % 10;
		if ((pos % 2) == 0)
			sum_even += digit;
		else
			sum_odd += digit;

		n /= 10;
		pos++;
	}

	return sum_even * sum_odd;
}

// Функция вывода равнобедренной трапеции (вариант 12)
void Task_12()
{
    char symbol;
	int a;
    int h;

    printf("\nЗадача 12: Равнобедренная трапеция\n");
    printf("Введите символ из которого будет строиться фигура: ");
    scanf(" %c", &symbol);

	do 
	{
		printf("Введите размер верхнего основания (от 1 до 9): ");
		scanf("%d", &a);
	} while (a < 1 || a > 9);

    do 
	{
        printf("Введите высоту трапеции : ");
        scanf("%d", &h);
    } 
	while (h <= 0 || h > 9 || h * 2 >= a);
	const int bottom = a + 2 * h;
    
	for (int row = 0; row <= h; ++row)
	{
		int current_width = a + 2 * row;
		int spaces = (bottom - current_width) / 2;
		for (int i = 0; i < spaces; ++i)
		{
			putchar(' ');
		}
		for (int j = 0; j < current_width; ++j)
		{
			putchar(symbol);
		}

		putchar('\n');
    }
}
