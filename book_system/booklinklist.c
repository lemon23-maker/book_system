#include "booklinklist.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
//��ʼ��������һ���յ����Ա�
linkedlist link_Init(linkedlist L) {
	L = (node*)malloc(sizeof(node));
	
	L->next = NULL;
	return L;
}
// ������������Ա�L�ĳ��ȣ���L������Ԫ�صĸ�����
int link_Length(linkedlist L) {
	int num = 0;
	linkedlist p = L->next;
	while (p)
	{
		num++;
		p = p->next;
	}
	return num;
}
//�ڱ�β���Ԫ�ء�
void link_add(linkedlist l,elemtype e) {
	linkedlist p = l;
	node* node1 = (node*)malloc(sizeof(node));
	node1->data = e;
	while (p->next)
	{
		p = p->next;
	}
	p->next = node1;
	node1->next = NULL;
}

// ��ֵ���Ҳ������ڱ�L���Ҿ��и����ؼ���ֵ��Ԫ�ء�
int link_Locatedata(linkedlist L, elemtype e) {
	int num = 1;
	linkedlist p = L->next;
	while (p) {
		if (book_equals(p->data, e)) {
			return num;
		}
	}
	return 0;
}
//��λ���Ҳ�������ȡ��L�еĵ�i��λ�õ�Ԫ�ص�ֵ��
elemtype* link_Getdata(linkedlist L, int i) {
	
	linkedlist p = L;
	while (i--&&p)
	{
		p = p->next;
	}
	return p?&(p->data):NULL;
}
// ����������ڱ� L�е�i��λ�ò���ָ��Ԫ��e��
int link_ListInsert(linkedlist L, int i, elemtype e) {

	linkedlist p = L;
	node *node1 = (node *)malloc(sizeof(node));
	node1->data = e;
	i--;
	while (i>0&&p)
	{
		p = p->next;
		i--;
	}
	if (i < 0 || !p) {
		printf("����λ�ò��Ϸ�,������ȷ������λ��\n");
		return 0;
	}
	printf("����ɹ�");
	node1->next = p->next;
	p->next = node1;
	return 1;

}
//ɾ��������ɾ���� L�е�i��λ�õ�Ԫ�أ�����e����ɾ��Ԫ�ص�ֵ��
elemtype* link_ListDelete(linkedlist L, int i) {
	linkedlist p = L;
	node* del_ele = NULL;
	i--;
	while (i>0&&p)
	{
		p = p->next;
		i--;
	}
	if (!p || i < 0) {
		printf("ɾ��λ�ò��Ϸ�,������ȷ��ɾ��λ��\n");
		return NULL;
	}
	del_ele = p->next;
	p->next = p->next->next;
	return &(del_ele->data);
}
// �����������ǰ��˳��������Ա�L������Ԫ��ֵ��
void link_PrintList(linkedlist L) {
	linkedlist p = L->next;
	printf("ISBN\t\t\t\t\t����\t\t\t����\n");
	while (p)
	{
		print_book(p->data);
		p = p->next;
	}
}
//�пղ�������LΪ�ձ��򷵻�true, ���򷵻�false��
int link_Empty(linkedlist L) {
	return L->next == NULL;
}
// ���ٲ������������Ա����ͷ����Ա�L��ռ�õ��ڴ�ռ䡣
void link_DestroyList(linkedlist L) {
	if (!L->next)
		return;
	linkedlist p = L->next;
	linkedlist p1 = L;
	while (p)
	{
		p1->next = p->next;
		free(p);
		p = p1->next;
	}
	free(p1);
}


//�Ƚ��������Ƿ���ͬ
int book_equals(book b1, book b2) {

	return strcmp(b1.book_id, b2.book_id) &&
		strcmp(b1.book_name, b2.book_name) &&
		(fabs(b1.price - b2.price) < 1e-6);
}
//����鼮��Ϣ
void print_book(book b) {

	printf("%1s\t%30s\t%20.2f\n", b.book_id, b.book_name, b.price);

}
//���Ҽ۸������鼮
linkedlist highest_price(linkedlist l)
{
	book book = l->next->data;
	linkedlist p = l->next->next;
	linkedlist booklist = NULL;
	booklist = link_Init(booklist);
	while (p) {
		
		if (p->data.price > book.price) {

			book = p->data;

		}
		p = p->next;
	}
	p = l->next;
	while (p)
	{
		if (fabs(p->data.price-book.price)<1e-6) {

			link_add(booklist, p->data);

		}
		p = p->next;
	}

	return booklist;
}
//��������ͼ��ƽ���۸�
double average_price(linkedlist l) {
	
	double ave = 0;
	linkedlist p = l->next;
	while (p)
	{
		ave += p->data.price;
		p = p->next;
	}
	return ave/link_Length(l);
}
//����������ͼ����Ϣ
book* getbook(linkedlist l,char *name) {

	book* book = NULL;
	linkedlist p = l->next;
	while (p)
	{
		if (strcmp(p->data.book_name, name)==0) {
			book = &(p->data);
			return book;
		}
		p = p->next;
	}
	return NULL;
}
//ͼ������
linkedlist link_reverse(linkedlist l) {
	linkedlist booklist = (linkedlist)malloc(sizeof(node));
	booklist->next = NULL;
	linkedlist p = l->next;
	linkedlist p1 = NULL;
	while (p)
	{	
		p1 = p->next;
		p->next = booklist->next;
		booklist->next = p;
		p = p1;
	}
	return booklist;
}
//ͼ������
linkedlist link_sort(linkedlist l) {

	if (l->next == NULL || l->next->next == NULL) {//����Ϊ�ջ�ֻ��һ���ڵ�ֱ�ӷ���
		return l;
	}
	node* sortl = l->next;//�����µ�������ԭ�����ÿ���ڵ�������뵽��������ȥ
	node* cur = l->next->next;
	node* sorttail = l->next;//�������β��㣬����β��
	sorttail->next = NULL;//β����next���ÿ�
	while (cur) {
		node* sortcur = sortl;
		node* prev = NULL;
		while (sortcur && cur->data.price <= sortcur->data.price) {//ԭ�����cur�ڵ������������ҵ������λ��
			prev = sortcur;
			sortcur = sortcur->next;
		}
		if (sortcur == NULL) {//ԭ�����cur�ڵ����������ÿ���ڵ㶼С��ִ��β��
			sorttail->next = cur;
			cur = cur->next;
			sorttail = sorttail->next;
			sorttail->next = NULL;
		}
		else if (prev == NULL) {//cur�ڵ����������ÿ���ڵ㶼��ִ��ͷ��
			node* next = cur->next;
			cur->next = sortl;
			sortl = cur;
			cur = next;
		}
		else {
			prev->next = cur;
			cur = cur->next;
			prev->next->next = sortcur;
		}
	}
	l = sortl;
	return l;
}




//��ӡϵͳ�˵�
void print_menu(){

	printf("*******************ͼ�����ϵͳ*******************\n");
	printf("�˵�:\n");
	printf("1.���������Ϣ\n");
	printf("2.ͳ��ͼ������\n");
	printf("3.����۸���ߵ�ͼ��\n");
	printf("4.��������ͼ���ƽ���۸�\n");
	printf("5.����������ͼ����Ϣ\n");
	printf("6.���ָ��λ�õ�ͼ����Ϣ\n");
	printf("7.ָ��λ�ò���ͼ����Ϣ\n");
	printf("8.ɾ��ָ��λ��ͼ����Ϣ\n");
	printf("9.����洢ͼ����Ϣ\n");
	printf("10.����洢ͼ����Ϣ\n");
	printf("0.�˳��˵�\n");
	printf("*************************************************\n");
	printf("_(:3����)_������˵�ѡ��:");
}

