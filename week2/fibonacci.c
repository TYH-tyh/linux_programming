#include<stdio.h>

int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}

} 
int main()
{
	int n = 0;
	int ret = 0;
	printf("������һ������");
	scanf("%d", &n);
	ret = fibonacci(n);
	printf("쳲��������еĵ�������ǣ�%d\n", ret);
	return 0;
}
