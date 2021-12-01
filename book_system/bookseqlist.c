#include "bookseqlist.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
//初始化表。构造一个空的线性表。
void InitList(seqlist *L) {
	L->elem = (elemtype*)malloc(10 * sizeof(elemtype));
	L->length = 0;
	L->size = 10;
}
//表尾添加元素。
void add(seqlist* L, elemtype e) {

	if (L->length >= L->size)
	{
		L->elem = (elemtype*)realloc(L->elem, (L->size + 10) * sizeof(elemtype));
		L->size = L->size + 10;
	}
	L->elem[L->length] = e;
	L->length++;

}
// 求表长。返回线性表L的长度，即L中数据元素的个数。
int Length(seqlist* L) {

	return L->length;

}
// 按值查找操作。在表L查找具有给定关键字值的元素。
int LocateElem(seqlist *L, elemtype e){

	for (int i = 0; i < L->length; i++)
	{
		if (book_equals(e, L->elem[i])) {
			return i + 1;
		}
	}
	return -1;
}
//按位查找操作。获取表L中的第i个位置的元素的值。
elemtype* GetElem(seqlist *L, int i){
	if (i<1 || i>L->length)
		return NULL;
	return &(L->elem[i-1]);

} 
// 插入操作。在表 L中第i个位置插入指定元素e。
int ListInsert(seqlist *L, int i, elemtype e){
	if (i <= 0 || i > L->length + 1) {
		printf("插入位置不合法，请重新确定插入位置\n");
		return 0;
	}

	if (L->length >= L->size)
	{
		L->elem = (elemtype*)realloc(L->elem, (L->size + 10) * sizeof(elemtype));
		L->size = L->size + 10;
	}
	for (int j = L->length-1; j > i-1 ; j--)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i - 1] = e;
	L->length++;
	printf("插入信息成功\n");
	return 1;

}
//删除操作。删除表 L中第i个位置的元素，并返回删除元素的值。
elemtype* ListDelete(seqlist *L, int i){
	if (i <= 0 || i > L->length)
		return NULL;
	book b = L->elem[i - 1];
	for (int j = i-1; j < L->length-1; j++)
	{
		L->elem[j] = L->elem[j+1];
	}
	L->length--;
	L->elem[L->length] = b;
	return &L->elem[L->length];

}
// 输出操作。按前后顺序输出线性表L的所有元素值。
void PrintList(seqlist *L){
	printf("ISBN\t\t\t\t\t书名\t\t\t定价\n");
	for (int i = 0; i < L->length; i++)
	{
		print_book(L->elem[i]);
	}

}
//判空操作。若L为空表，则返回true, 否则返回false。
int Empty(seqlist *L){

	return L->length == 0;

}
// 销毁操作。销毁线性表，并释放线性表L所占用的内存空间。
void DestroyList(seqlist *L){

	free(L->elem);
	free(L);

}
//最高价格图书
seqlist* seq_highest_price(seqlist* l) {

	seqlist list;
	InitList(&list);
	book b = l->elem[0];
	for (int i = 1; i < l->length; i++)
	{
		if (l->elem[i].price > b.price) {
			b = l->elem[i];
		}
	}
	for (int i = 0; i < l->length; i++)
	{
		if (fabs(l->elem[i].price - b.price) < 1e-6) {
			add(&list, l->elem[i]);
		}
	}
	return &list;
}
//所有书籍平均价格
double seq_average_price(seqlist* l) {

	double ave = 0;
	for (int i = 0; i < l->length; i++)
	{
		ave += l->elem[i].price;
	}
	return ave / l->length;
}
//按书名查找图书信息
book* seq_getbook(seqlist* l, char* name) {

	for (int i = 0; i < l->length; i++)
	{
		if (strcmp(name, l->elem[i].book_name)==0) {

			return &l->elem[i];

		}
	}
	return NULL;
}
//图书逆序
void seq_reverse(seqlist* l) {

	for (int i = 0; i < l->length/2; i++)
	{
		book b = l->elem[i];
		l->elem[i] = l->elem[l->length - i - 1];
		l->elem[l->length - i - 1] = b;
	}
}
//图书排序
void sort(seqlist* l) {

	int i, j;
	book t;
	for (i = 0; i < l->length - 1; i++)
		for (j = 0; j < l->length - 1 - i; j++)
		{
			if (l->elem[j].price > l->elem[j + 1].price)
			{
				t = l->elem[j]; l->elem[j] = l->elem[j + 1]; l->elem[j + 1] = t;
			}
		}
}