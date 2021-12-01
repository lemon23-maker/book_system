
#ifndef elemtype
#define elemtype book 
typedef struct book {
	char book_id[20];
	char book_name[50];
	double price;
}book;

#endif 

#ifndef _seqlist_H
#define _seqlist_H 
typedef struct seqlist {
	elemtype *elem;
	int length;
	int size;
}seqlist;
void add(seqlist* L,elemtype e);//��β���Ԫ�ء�
void InitList(seqlist *L);//��ʼ��������һ���յ����Ա�
int Length(seqlist *L) ;// ������������Ա�L�ĳ��ȣ���L������Ԫ�صĸ�����
int LocateElem(seqlist *L,elemtype e) ;// ��ֵ���Ҳ������ڱ�L���Ҿ��и����ؼ���ֵ��Ԫ�ء�
elemtype* GetElem(seqlist *L, int i); //��λ���Ҳ�������ȡ��L�еĵ�i��λ�õ�Ԫ�ص�ֵ��
int ListInsert(seqlist *L, int i, elemtype e);// ����������ڱ� L�е�i��λ�ò���ָ��Ԫ��e��
elemtype* ListDelete(seqlist *L,int i);//ɾ��������ɾ���� L�е�i��λ�õ�Ԫ�أ�����e����ɾ��Ԫ�ص�ֵ��
void PrintList(seqlist *L) ;// �����������ǰ��˳��������Ա�L������Ԫ��ֵ��
int Empty(seqlist *L) ;//�пղ�������LΪ�ձ��򷵻�true, ���򷵻�false��
void DestroyList(seqlist *L) ;// ���ٲ������������Ա����ͷ����Ա�L��ռ�õ��ڴ�ռ䡣

int book_equals(book b1, book b2);//�Ƚ��������Ƿ���ͬ
void print_book(book b);//����鼮��Ϣ
void print_menu();//��ӡϵͳ�˵�
seqlist* seq_highest_price(seqlist *l);//��߼۸�ͼ��
double seq_average_price(seqlist *l);//�����鼮ƽ���۸�
book* seq_getbook(seqlist *l, char* name);//����������ͼ����Ϣ
void seq_reverse(seqlist* l);//ͼ������
void sort(seqlist* l);//ͼ������
#endif