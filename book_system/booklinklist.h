

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

void link_add(linkedlist l,elemtype e);//�ڱ�β���Ԫ�ء�
linkedlist link_Init(linkedlist L);//��ʼ��������һ���յ����Ա�
int link_Length(linkedlist L);// ������������Ա�L�ĳ��ȣ���L������Ԫ�صĸ�����
int link_LocateElem(linkedlist L, elemtype e);// ��ֵ���Ҳ������ڱ�L���Ҿ��и����ؼ���ֵ��Ԫ�ء�
book* link_Getdata(linkedlist L, int i); //��λ���Ҳ�������ȡ��L�еĵ�i��λ�õ�Ԫ�ص�ֵ��
int link_ListInsert(linkedlist L, int i, elemtype e);// ����������ڱ� L�е�i��λ�ò���ָ��Ԫ��e��
elemtype* link_ListDelete(linkedlist L, int i);//ɾ��������ɾ���� L�е�i��λ�õ�Ԫ�أ�����e����ɾ��Ԫ�ص�ֵ��
void link_PrintList(linkedlist L);// �����������ǰ��˳��������Ա�L������Ԫ��ֵ��
int link_Empty(linkedlist L);//�пղ�������LΪ�ձ��򷵻�true, ���򷵻�false��
void link_DestroyList(linkedlist L);// ���ٲ������������Ա����ͷ����Ա�L��ռ�õ��ڴ�ռ䡣

int book_equals(book b1, book b2);//�Ƚ��������Ƿ���ͬ
void print_book(book b);//����鼮��Ϣ
void print_menu();//��ӡϵͳ�˵�
linkedlist highest_price(linkedlist l);//��߼۸�ͼ��
double average_price(linkedlist l);//�����鼮ƽ���۸�
book* getbook(linkedlist l,char *name);//����������ͼ����Ϣ
linkedlist link_reverse(linkedlist l);//ͼ������
linkedlist link_sort(linkedlist l);//ͼ������

#endif