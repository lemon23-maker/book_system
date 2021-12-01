

#ifndef elemtype

#define elemtype book 
#endif 
#ifndef _node_H

#define _node_H 


typedef struct book {
	char book_id[20];
	char book_name[50];
	double price;
}book;
 

typedef struct node {
	elemtype data;
	struct node *next;
}node,*linkedlist;

void link_add(linkedlist l,elemtype e);//在表尾添加元素。
linkedlist link_Init(linkedlist L);//初始化表。构造一个空的线性表。
int link_Length(linkedlist L);// 求表长。返回线性表L的长度，即L中数据元素的个数。
int link_LocateElem(linkedlist L, elemtype e);// 按值查找操作。在表L查找具有给定关键字值的元素。
book* link_Getdata(linkedlist L, int i); //按位查找操作。获取表L中的第i个位置的元素的值。
int link_ListInsert(linkedlist L, int i, elemtype e);// 插入操作。在表 L中第i个位置插入指定元素e。
elemtype* link_ListDelete(linkedlist L, int i);//删除操作。删除表 L中第i个位置的元素，并用e返回删除元素的值。
void link_PrintList(linkedlist L);// 输出操作。按前后顺序输出线性表L的所有元素值。
int link_Empty(linkedlist L);//判空操作。若L为空表，则返回true, 否则返回false。
void link_DestroyList(linkedlist L);// 销毁操作。销毁线性表，并释放线性表L所占用的内存空间。

int book_equals(book b1, book b2);//比较两本书是否相同
void print_book(book b);//输出书籍信息
void print_menu();//打印系统菜单
linkedlist highest_price(linkedlist l);//最高价格图书
double average_price(linkedlist l);//所有书籍平均价格
book* getbook(linkedlist l,char *name);//按书名查找图书信息
linkedlist link_reverse(linkedlist l);//图书逆序
linkedlist link_sort(linkedlist l);//图书排序

#endif