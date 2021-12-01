#include "booklinklist.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
//初始化表。构造一个空的线性表。
linkedlist link_Init(linkedlist L) {
	L = (node*)malloc(sizeof(node));
	
	L->next = NULL;
	return L;
}
// 求表长。返回线性表L的长度，即L中数据元素的个数。
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
//在表尾添加元素。
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

// 按值查找操作。在表L查找具有给定关键字值的元素。
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
//按位查找操作。获取表L中的第i个位置的元素的值。
elemtype* link_Getdata(linkedlist L, int i) {
	
	linkedlist p = L;
	while (i--&&p)
	{
		p = p->next;
	}
	return p?&(p->data):NULL;
}
// 插入操作。在表 L中第i个位置插入指定元素e。
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
		printf("插入位置不合法,请重新确定插入位置\n");
		return 0;
	}
	printf("插入成功");
	node1->next = p->next;
	p->next = node1;
	return 1;

}
//删除操作。删除表 L中第i个位置的元素，并用e返回删除元素的值。
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
		printf("删除位置不合法,请重新确定删除位置\n");
		return NULL;
	}
	del_ele = p->next;
	p->next = p->next->next;
	return &(del_ele->data);
}
// 输出操作。按前后顺序输出线性表L的所有元素值。
void link_PrintList(linkedlist L) {
	linkedlist p = L->next;
	printf("ISBN\t\t\t\t\t书名\t\t\t定价\n");
	while (p)
	{
		print_book(p->data);
		p = p->next;
	}
}
//判空操作。若L为空表，则返回true, 否则返回false。
int link_Empty(linkedlist L) {
	return L->next == NULL;
}
// 销毁操作。销毁线性表，并释放线性表L所占用的内存空间。
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


//比较两本书是否相同
int book_equals(book b1, book b2) {

	return strcmp(b1.book_id, b2.book_id) &&
		strcmp(b1.book_name, b2.book_name) &&
		(fabs(b1.price - b2.price) < 1e-6);
}
//输出书籍信息
void print_book(book b) {

	printf("%1s\t%30s\t%20.2f\n", b.book_id, b.book_name, b.price);

}
//查找价格最贵的书籍
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
//计算所有图书平均价格
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
//按书名查找图书信息
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
//图书逆序
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
//图书排序
linkedlist link_sort(linkedlist l) {

	if (l->next == NULL || l->next->next == NULL) {//链表为空或只有一个节点直接返回
		return l;
	}
	node* sortl = l->next;//定义新的链表，把原链表的每个节点有序插入到新链表中去
	node* cur = l->next->next;
	node* sorttail = l->next;//新链表的尾结点，方便尾插
	sorttail->next = NULL;//尾结点的next域置空
	while (cur) {
		node* sortcur = sortl;
		node* prev = NULL;
		while (sortcur && cur->data.price <= sortcur->data.price) {//原链表的cur节点在新链表中找到插入的位置
			prev = sortcur;
			sortcur = sortcur->next;
		}
		if (sortcur == NULL) {//原链表的cur节点比新链表中每个节点都小，执行尾插
			sorttail->next = cur;
			cur = cur->next;
			sorttail = sorttail->next;
			sorttail->next = NULL;
		}
		else if (prev == NULL) {//cur节点比新链表中每个节点都大，执行头插
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




//打印系统菜单
void print_menu(){

	printf("*******************图书管理系统*******************\n");
	printf("菜单:\n");
	printf("1.输出所有信息\n");
	printf("2.统计图书数量\n");
	printf("3.输出价格最高的图书\n");
	printf("4.计算所有图书的平均价格\n");
	printf("5.按书名查找图书信息\n");
	printf("6.输出指定位置的图书信息\n");
	printf("7.指定位置插入图书信息\n");
	printf("8.删除指定位置图书信息\n");
	printf("9.逆序存储图书信息\n");
	printf("10.降序存储图书信息\n");
	printf("0.退出菜单\n");
	printf("*************************************************\n");
	printf("_(:3」∠)_请输入菜单选项:");
}

