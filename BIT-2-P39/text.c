#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//9. ָ���������������
/*
int main()
{
	// һά����
		int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//16
	printf("%d\n", sizeof(a + 0));//4
	printf("%d\n", sizeof(*a));//4  
	printf("%d\n", sizeof(a + 1));//4
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4	&a��ȡ����������ĵ�ַ������ĵ�ַ��4
	printf("%d\n", sizeof(*&a));//16 &a������ĵ�ַ������ĵ�ַ�����÷��ʵ����������� 
	printf("%d\n", sizeof(&a + 1));//4  &a��ȡ����������ĵ�ַ��&a+1,�����������飬���ǵ�ַ
	printf("%d\n", sizeof(&a[0]));//4   ��һ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1));//4 �ڶ���Ԫ�صĵ�ַ
	//�ַ�����
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));	//6
	printf("%d\n", sizeof(arr + 0));//4	arr��Ԫ�صĵ�ַ  arr+0��������Ԫ�ص�ַ
	printf("%d\n", sizeof(*arr));//1    arr����Ԫ�ص�ַ  *arr���ʵ�����Ԫ��
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4
	printf("%d\n", sizeof(&arr + 1));//4
	printf("%d\n", sizeof(&arr[0] + 1));//4 �ڶ���Ԫ�صĵ�ַ
	printf("%d\n", strlen(arr));	//���ֵ  //\0��λ�ò�ȷ��
	printf("%d\n", strlen(arr + 0));//���ֵ
	printf("%d\n", strlen(*arr));//��a��-- 97��������ַ�� -- ����
	printf("%d\n", strlen(arr[1]));//��b��--����
	printf("%d\n", strlen(&arr));//���ֵ
	printf("%d\n", strlen(&arr + 1));//���ֵ-6
	printf("%d\n", strlen(&arr[0] + 1));//���ֵ-1
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));	//7  sizeof��arr�������������Ĵ�С
	printf("%d\n", sizeof(arr + 0));//4  ����Ԫ�ص�ַ 
	printf("%d\n", sizeof(*arr));//1  ��Ԫ�ص�ַ�����ã�����Ԫ��  
	printf("%d\n", sizeof(arr[1]));//1 �ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&arr));//4  
	printf("%d\n", sizeof(&arr + 1));//4  ���������������ĵ�ַ
	printf("%d\n", sizeof(&arr[0] + 1));//4
	printf("%d\n", strlen(arr));//6
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//��a��-- err
	printf("%d\n", strlen(arr[1]));//��b��-- err
	printf("%d\n", strlen(&arr));//6 -- waring     &arr--����ĵ�ַ---��ŵ�����ָ�� char(*p)[7]=&arr
	printf("%d\n", strlen(&arr + 1));//���ֵ
	printf("%d\n", strlen(&arr[0] + 1));//5
	char* p = "abcdef";//�ѳ����ַ����׵�ַ����p
	printf("%d\n", sizeof(p));//4
	printf("%d\n", sizeof(p + 1));//4
	printf("%d\n", sizeof(*p));//1	---  �ַ�����һ���ַ�
	printf("%d\n", sizeof(p[0]));//1 ��a�� 
	printf("%d\n", sizeof(&p));//4
	printf("%d\n", sizeof(&p + 1));//4
	printf("%d\n", sizeof(&p[0] + 1));//4
	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p + 1));//5
	printf("%d\n", strlen(*p));//��a��-- err
	printf("%d\n", strlen(p[0]));//��a�� -- err
	printf("%d\n", strlen(&p));//���ֵ  ----  ��ַ�޷�Ԥ��  
	printf("%d\n", strlen(&p + 1));//���ֵ 
	printf("%d\n", strlen(&p[0] + 1));//5
	//��ά����
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16  ---  a[0]Ϊ��һ��������������sizeof�ڲ��������һ������Ĵ�С
	printf("%d\n", sizeof(a[0] + 1));//4  --- a[0]�ǵ�һ�е�����������������ʱ����Ԫ�ص�ַ����Ԫ�ص�ַ��һ��Ϊ��һ�еڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(*(a[0] + 1)));//4 ---��һ�еڶ���Ԫ��
	printf("%d\n", sizeof(a + 1));//4  ---  a�Ƕ�ά����������� �� û��sizeof������������&��������������������Ԫ�ص�ַ   ---- a+1�� �ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(a + 1)));//16 --- sizeof(a[1])����ڶ��������С
	printf("%d\n", sizeof(&a[0] + 1));//4 --- �ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	printf("%d\n", sizeof(*a));//16  -- a�ǵ�һ����Ԫ�صĵ�ַ����һ�еĵ�ַ��*a���ǵ�һ��
	printf("%d\n", sizeof(a[3]));//16  ---  sizeof��������������
	/*�ܽ᣺ �����������壺
		1. sizeof(������)���������������ʾ�������飬���������������Ĵ�С��
		2. &���������������������ʾ�������飬ȡ��������������ĵ�ַ��
		3. ����֮�����е�����������ʾ��Ԫ�صĵ�ַ��
	return 0;
}
*/

//10. ָ�������
////������1
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//2,5
//	return 0;
//}

////������2.
////���ڻ�ûѧϰ�ṹ�壬�����֪�ṹ��Ĵ�С��20���ֽ�
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
////��֪���ṹ��Test���͵ı�����С��20���ֽ�
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);//0000 0000 0010 0020
//	printf("%p\n", (unsigned int)p + 0x1);//0000000000100001
//	printf("%p\n", (unsigned long)p + 0x1);//0000000000100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0000000000100004
//	return 0;
//}

////������3.
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//0x4,0x02 00 00 00
//	return 0;
//}

////������4.
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//���ű��ʽ1��3��5
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);//p[0] = *(p+0) = 1
//	return 0;
//}

////������5.
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;//int(* )[4] = int(* )[5]
//	//10000000 00000000 00000000 00000100   -4ԭ��
//	//11111111 11111111 11111111 11111011     ����
//	//11111111 11111111 11111111 11111100     ����
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//FFFFFFFFFFFFFFFC,-4//*(*(p+4)+2)
//	return 0;
//}

////������6.
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);//����aa����
//	int* ptr2 = (int*)(*(aa + 1));//�ڶ�����Ԫ�ص�ַ
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10,5
//	return 0;
//}

//int arr[10] = { 1,2,3,4,5 };
//int* p = &arr;
//*(p + 2) == p[2] == *(arr + 2) == arr[2];


////������7.
//int main()
//{
//	char* p = "abcdefg";
//	char* a[] = { "work","at","alibaba" };
//	char* *pa = a;
//	pa++;//����һ��char*
//	printf("%s\n", *pa);//at
//	return 0;
//}

//������8.
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);	//POINT
	printf("%s\n", *-- * ++cpp + 3);//ER
	printf("%s\n", *cpp[-2] + 3);//ST
	printf("%s\n", cpp[-1][-1] + 1);//EW
	return 0;
}
