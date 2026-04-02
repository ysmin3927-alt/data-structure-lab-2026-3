#include <stdio.h>

void main() {
	int j;
	char string1[20] = "dreams come ture";
	char string2[20];
	char* ptr1;
	char* ptr2;

	ptr1 = string1;
	printf("\n 스트링1의 주소 = %u \t ptr1 = %u", string1, ptr1);
	printf("\n 스트링1의 주소 = %u", &string1[0]);

	printf("\n\n string1 : %s", string1);
	printf("\n ptr1: %s", ptr1);
	printf("\n ptr1+7: %s", ptr1+7);
	printf("\n string1 : %s", &string1[7]);


}