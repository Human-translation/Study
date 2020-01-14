#include<stdio.h>

int str_num(char *str)
{
	if (*str == '\0' || NULL == str)
	{
		printf("���Ϸ�\n");
		return -1;//���Ϸ�
	}
	long long num = 0;
	char first = *str;
	int fuhao = 1;   //��¼����
	if (first == '-')
	{
		str++;
		fuhao = -1;
	}
	else if (first == '+')
	{
		str++;
		fuhao = 1;
	}
	if ('\0' == *str)
	{
		printf("���Ϸ�\n");
		return -1;
	}
	while (*str != '\0')
	{
		if (*str <= '9' && *str >= '0')
		{
			num = num * 10 + (*str - '0');
			if ((fuhao == 1 && num > 0x7fffffff) || (fuhao == -1 && (fuhao *num)<(signed int)0x80000000))
			{
				printf("���:num = %lld\n", num);
				return -2;  //���
			}
		}
		else {
			printf("���Ϸ�\n");
			return -1;//���Ϸ�
		}
		str++;
	}
	return fuhao*num;

}

void Test()
{

	char *string = "-111111234";
	int res = str_num(string);
	printf("res = %d\n", res);

	char *str1 = "\0";
	str_num(str1);

	char *str2 = "+";
	str_num(str2);

	char *str3 = "10000000000000000000000000000000";
	str_num(str3);

	char *str4 = "+12-1627";
	str_num(str4);

}

int main()
{
	Test();
	return 0;
}