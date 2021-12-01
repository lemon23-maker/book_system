#include "bookseqlist.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
//��ʼ��������һ���յ����Ա�
void InitList(seqlist *L) {
	L->elem = (elemtype*)malloc(10 * sizeof(elemtype));
	L->length = 0;
	L->size = 10;
}
//��β���Ԫ�ء�
void add(seqlist* L, elemtype e) {

	if (L->length >= L->size)
	{
		L->elem = (elemtype*)realloc(L->elem, (L->size + 10) * sizeof(elemtype));
		L->size = L->size + 10;
	}
	L->elem[L->length] = e;
	L->length++;

}
// ������������Ա�L�ĳ��ȣ���L������Ԫ�صĸ�����
int Length(seqlist* L) {

	return L->length;

}
// ��ֵ���Ҳ������ڱ�L���Ҿ��и����ؼ���ֵ��Ԫ�ء�
int LocateElem(seqlist *L, elemtype e){

	for (int i = 0; i < L->length; i++)
	{
		if (book_equals(e, L->elem[i])) {
			return i + 1;
		}
	}
	return -1;
}
//��λ���Ҳ�������ȡ��L�еĵ�i��λ�õ�Ԫ�ص�ֵ��
elemtype* GetElem(seqlist *L, int i){
	if (i<1 || i>L->length)
		return NULL;
	return &(L->elem[i-1]);

} 
// ����������ڱ� L�е�i��λ�ò���ָ��Ԫ��e��
int ListInsert(seqlist *L, int i, elemtype e){
	if (i <= 0 || i > L->length + 1) {
		printf("����λ�ò��Ϸ���������ȷ������λ��\n");
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
	printf("������Ϣ�ɹ�\n");
	return 1;

}
//ɾ��������ɾ���� L�е�i��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ��
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
// �����������ǰ��˳��������Ա�L������Ԫ��ֵ��
void PrintList(seqlist *L){
	printf("ISBN\t\t\t\t\t����\t\t\t����\n");
	for (int i = 0; i < L->length; i++)
	{
		print_book(L->elem[i]);
	}

}
//�пղ�������LΪ�ձ��򷵻�true, ���򷵻�false��
int Empty(seqlist *L){

	return L->length == 0;

}
// ���ٲ������������Ա����ͷ����Ա�L��ռ�õ��ڴ�ռ䡣
void DestroyList(seqlist *L){

	free(L->elem);
	free(L);

}
//��߼۸�ͼ��
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
//�����鼮ƽ���۸�
double seq_average_price(seqlist* l) {

	double ave = 0;
	for (int i = 0; i < l->length; i++)
	{
		ave += l->elem[i].price;
	}
	return ave / l->length;
}
//����������ͼ����Ϣ
book* seq_getbook(seqlist* l, char* name) {

	for (int i = 0; i < l->length; i++)
	{
		if (strcmp(name, l->elem[i].book_name)==0) {

			return &l->elem[i];

		}
	}
	return NULL;
}
//ͼ������
void seq_reverse(seqlist* l) {

	for (int i = 0; i < l->length/2; i++)
	{
		book b = l->elem[i];
		l->elem[i] = l->elem[l->length - i - 1];
		l->elem[l->length - i - 1] = b;
	}
}
//ͼ������
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