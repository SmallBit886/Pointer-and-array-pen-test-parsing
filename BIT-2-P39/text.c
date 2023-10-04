#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//9. 指针和数组笔试题解析
/*
int main()
{
	// 一维数组
		int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//16
	printf("%d\n", sizeof(a + 0));//4
	printf("%d\n", sizeof(*a));//4  
	printf("%d\n", sizeof(a + 1));//4
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4	&a，取出的是数组的地址，数组的地址是4
	printf("%d\n", sizeof(*&a));//16 &a是数组的地址，数组的地址解引用访问的是整个数组 
	printf("%d\n", sizeof(&a + 1));//4  &a，取出的是数组的地址，&a+1,跳过整个数组，还是地址
	printf("%d\n", sizeof(&a[0]));//4   第一个元素的地址
	printf("%d\n", sizeof(&a[0] + 1));//4 第二个元素的地址
	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));	//6
	printf("%d\n", sizeof(arr + 0));//4	arr首元素的地址  arr+0，还是首元素地址
	printf("%d\n", sizeof(*arr));//1    arr是首元素地址  *arr访问的是首元素
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4
	printf("%d\n", sizeof(&arr + 1));//4
	printf("%d\n", sizeof(&arr[0] + 1));//4 第二个元素的地址
	printf("%d\n", strlen(arr));	//随机值  //\0的位置不确定
	printf("%d\n", strlen(arr + 0));//随机值
	printf("%d\n", strlen(*arr));//‘a’-- 97（当作地址） -- 错误
	printf("%d\n", strlen(arr[1]));//‘b’--错误
	printf("%d\n", strlen(&arr));//随机值
	printf("%d\n", strlen(&arr + 1));//随机值-6
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));	//7  sizeof（arr）计算的是数组的大小
	printf("%d\n", sizeof(arr + 0));//4  是首元素地址 
	printf("%d\n", sizeof(*arr));//1  首元素地址解引用，是首元素  
	printf("%d\n", sizeof(arr[1]));//1 第二个元素的大小
	printf("%d\n", sizeof(&arr));//4  
	printf("%d\n", sizeof(&arr + 1));//4  是跳过整个数组后的地址
	printf("%d\n", sizeof(&arr[0] + 1));//4
	printf("%d\n", strlen(arr));//6
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//‘a’-- err
	printf("%d\n", strlen(arr[1]));//‘b’-- err
	printf("%d\n", strlen(&arr));//6 -- waring     &arr--数组的地址---存放到数组指针 char(*p)[7]=&arr
	printf("%d\n", strlen(&arr + 1));//随机值
	printf("%d\n", strlen(&arr[0] + 1));//5
	char* p = "abcdef";//把常量字符串首地址传给p
	printf("%d\n", sizeof(p));//4
	printf("%d\n", sizeof(p + 1));//4
	printf("%d\n", sizeof(*p));//1	---  字符串第一个字符
	printf("%d\n", sizeof(p[0]));//1 ‘a’ 
	printf("%d\n", sizeof(&p));//4
	printf("%d\n", sizeof(&p + 1));//4
	printf("%d\n", sizeof(&p[0] + 1));//4
	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p + 1));//5
	printf("%d\n", strlen(*p));//‘a’-- err
	printf("%d\n", strlen(p[0]));//‘a’ -- err
	printf("%d\n", strlen(&p));//随机值  ----  地址无法预测  
	printf("%d\n", strlen(&p + 1));//随机值 
	printf("%d\n", strlen(&p[0] + 1));//5
	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16  ---  a[0]为第一行数组名，放在sizeof内部，计算第一行数组的大小
	printf("%d\n", sizeof(a[0] + 1));//4  --- a[0]是第一行的数组名；数组名此时是首元素地址，首元素地址加一，为第一行第二个元素地址
	printf("%d\n", sizeof(*(a[0] + 1)));//4 ---第一行第二个元素
	printf("%d\n", sizeof(a + 1));//4  ---  a是二维数组的数组名 ； 没有sizeof（数组名），&（数组名），所以是首元素地址   ---- a+1是 第二行的地址
	printf("%d\n", sizeof(*(a + 1)));//16 --- sizeof(a[1])计算第二行数组大小
	printf("%d\n", sizeof(&a[0] + 1));//4 --- 第二行的地址
	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	printf("%d\n", sizeof(*a));//16  -- a是第一行首元素的地址，第一行的地址，*a就是第一行
	printf("%d\n", sizeof(a[3]));//16  ---  sizeof（）不参与运算
	/*总结： 数组名的意义：
		1. sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小。
		2. &数组名，这里的数组名表示整个数组，取出的是整个数组的地址。
		3. 除此之外所有的数组名都表示首元素的地址。
	return 0;
}
*/

//10. 指针笔试题
////笔试题1
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//2,5
//	return 0;
//}

////笔试题2.
////由于还没学习结构体，这里告知结构体的大小是20个字节
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);//0000 0000 0010 0020
//	printf("%p\n", (unsigned int)p + 0x1);//0000000000100001
//	printf("%p\n", (unsigned long)p + 0x1);//0000000000100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0000000000100004
//	return 0;
//}

////笔试题3.
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//0x4,0x02 00 00 00
//	return 0;
//}

////笔试题4.
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//逗号表达式1，3，5
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);//p[0] = *(p+0) = 1
//	return 0;
//}

////笔试题5.
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;//int(* )[4] = int(* )[5]
//	//10000000 00000000 00000000 00000100   -4原码
//	//11111111 11111111 11111111 11111011     反码
//	//11111111 11111111 11111111 11111100     补码
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//FFFFFFFFFFFFFFFC,-4//*(*(p+4)+2)
//	return 0;
//}

////笔试题6.
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);//跳过aa数组
//	int* ptr2 = (int*)(*(aa + 1));//第二行首元素地址
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10,5
//	return 0;
//}

//int arr[10] = { 1,2,3,4,5 };
//int* p = &arr;
//*(p + 2) == p[2] == *(arr + 2) == arr[2];


////笔试题7.
//int main()
//{
//	char* p = "abcdefg";
//	char* a[] = { "work","at","alibaba" };
//	char* *pa = a;
//	pa++;//跳过一个char*
//	printf("%s\n", *pa);//at
//	return 0;
//}

//笔试题8.
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
