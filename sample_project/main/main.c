#include <stdio.h>
#include "esp_log.h"
#include "esp_attr.h"
int IRAM_ATTR add(int a, int b)
{
//	printf("in function add(a, b)\n");
//	printf("&a = %p, &b = %p\n",&a, &b);
	ESP_LOGI(__func__, "&a = %p, &b = %p\n",&a, &b);
	return a + b;
}

int IRAM_ATTR sub(int a, int b)
{
//	printf("in function add(a, b)\n");
//	printf("&a = %p, &b = %p\n",&a, &b);
	ESP_LOGI(__func__, "&a = %p, &b = %p\n",&a, &b);
	return a - b;
}


int IRAM_ATTR add2(int* const a, int* const b)
{
//	printf("in function add2(a, b)\n");
//	printf("&a = %p, &b = %p\n",a, b);
	ESP_LOGI(__func__, "&a = %p, &b = %p\n",&a, &b);
	return *a + *b;
}


void app_main(void)
{
	// printf tutorials
	// integer number
	int b = 100;
	int a = 100;
	printf("in function main()\n");
	printf("&a = %p, &b = %p\n",&a, &b);
	int c = add(a,b);
	printf("c = %d, &c = %p\n", c, &c);
	printf("&add(a, b)= %p\n", &add);

	int d = add2(&a, &b);
	printf("d = %d, &d = %p\n", d, &d);
	printf("&add(a, b)= %p\n", &add2);


	int (*fn_array[])(int,int) = {add, sub, add, sub};

	printf("size of fn_array =  %d\n", sizeof (fn_array)/sizeof(int));

	for(int i = 0; i < sizeof (fn_array)/sizeof(int); i++)
	{
		printf("fn_array[%d] return %d\n", i, fn_array[i](a, b));
	}

}
