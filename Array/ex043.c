#include<stdio.h>
#include<string.h>
main()
{
	char str[] = "orange";
	int cnt = 0;
	while (str[cnt] != '\0') {
		cnt++;
	}
	printf("������F%s\n", str);
	printf("��������%d����\n", cnt);
	printf("��������%d����\n", strlen(str));
}