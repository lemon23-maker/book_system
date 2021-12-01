#include "booklinklist.h"
#include "bookseqlist.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main() {

	int n;
	char link;//ѡ��˳���ʵ�ֻ�����ʵ��
	printf("�Ƿ�ѡ����ʽʵ��:Y/N\n");
	scanf("%c", &link);
	linkedlist link_booklist = NULL;
	seqlist booklist;
	//����ͼ���
	if ('y' == link || 'Y' == link) {

		link_booklist = link_Init(link_booklist);
	}
	else
	{
		InitList(&booklist);
	}
	FILE* fp = NULL;
	char id[50];
	char name[50];
	double book_price;
	//��ȡ�ļ�
	fp = fopen(".\\book.txt", "r");
	while (fscanf(fp, "%s%s%lf", id, name, &book_price)) {
		book book_add;
		strcpy(book_add.book_id, id);
		strcpy(book_add.book_name, name);
		book_add.price = book_price;
		if ('y' == link || 'Y' == link) {
			link_add(link_booklist, book_add);
		}
		else
		{
			add(&booklist, book_add);
		}


		if (feof(fp))
			break;
	}

	fclose(fp);

	if ('y' == link || 'Y' == link)
		while (1)
		{
			system("cls");
			print_menu();

			scanf("%d", &n);
			switch (n)
			{
				//���������Ϣ
			case 1:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					printf("ͼ����ϢΪ:\n");

					link_PrintList(link_booklist);

				}
				system("pause");
				break;
				//ͳ��ͼ�����
			case 2:

				system("cls");
				printf("ͼ������Ϊ%d��\n", link_Length(link_booklist));
				system("pause");
				break;
				//����۸���ߵ�ͼ����Ϣ
			case 3:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					link_PrintList(highest_price(link_booklist));
				}
				system("pause");
				break;
				//��������ͼ���ƽ���۸�
			case 4:

				system("cls");
				if (link_Empty(link_booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					printf("ƽ���۸�Ϊ%.2fԪ\n", average_price(link_booklist));

				}
				system("pause");
				break;
				//����������ͼ����Ϣ
			case 5:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					char bookname[50];
					book* book2;
					getchar();
					printf("����������:");
					scanf("%s", bookname);
					book2 = getbook(link_booklist, bookname);
					if (book2) {
						print_book(*book2);
					}
					else
					{
						printf("û���ҵ�%s�Ȿ��,��ȷ�������Ƿ���ȷ\n", bookname);
					}
				}

				system("pause");
				break;
				//���ָ��λ�õ�ͼ����Ϣ
			case 6:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else {

					int index;
					printf("������ָ��λ�����:");
					scanf("%d", &index);
					book* b = link_Getdata(link_booklist, index);
					if (b) {
						print_book(*b);
					}
					else
					{
						printf("û�е�%d����,��ȷ���鼮�����\n", index);
					}

				}

				system("pause");
				break;
				//ָ��λ�ò���ͼ����Ϣ
			case 7:
				system("cls");
				int index;
				printf("���������λ��:");
				scanf("%d", &index);
				book b2;
				printf("ͼ����Ϣ�Կո���зָ�\n");
				printf("������ͼ����Ϣ:");
				scanf("%s%s%lf", b2.book_id, b2.book_name, &b2.price);
				if (link_ListInsert(link_booklist, index, b2)) {
					printf("��������ϢΪ:\n");
					link_PrintList(link_booklist);
				}
				system("pause");
				break;
				//ɾ��ָ��λ�õ�ͼ����Ϣ
			case 8:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					int index;
					printf("������Ҫɾ����λ��:");
					scanf("%d", &index);
					book* b1 = link_ListDelete(link_booklist, index);
					if (b1) {

						printf("ɾ���鼮Ϊ:");
						print_book(*b1);
						printf("ɾ����Ϣ�����ϢΪ:\n");
						link_PrintList(link_booklist);
					}
					else {
						printf("ɾ����λ�ò��Ϸ�,������ȷ��ɾ����λ��\n");
					}
				}
				system("pause");

				break;
				//���򴢴�ͼ����Ϣ
			case 9:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					link_booklist = link_reverse(link_booklist);
					printf("����洢�ɹ�,��������ϢΪ\n");
					link_PrintList(link_booklist);

				}
				system("pause");
				break;
				//���򴢴�ͼ����Ϣ
			case 10:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					link_booklist = link_sort(link_booklist);
					printf("����ɹ�\n");
					printf("�������ϢΪ\n");
					link_PrintList(link_booklist);
				}
				system("pause");
				break;
				//�˳�
			case 0:
				system("cls");
				printf("��лʹ��ͼ�����ϵͳ\n");
				system("pause");
				goto end;
			default:
				system("cls");
				printf("�޴�ѡ�����������\n");
				system("pause");
				break;
			}

		}
	else//˳��ʵ��
	{
		while (1)
		{
			system("cls");
			print_menu();

			scanf("%d", &n);
			switch (n)
			{
				//���������Ϣ
			case 1:
				system("cls");
				if (Empty(&booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					printf("ͼ����ϢΪ:\n");

					PrintList(&booklist);

				}
				system("pause");
				break;
				//ͳ��ͼ�����
			case 2:

				system("cls");
				printf("ͼ������Ϊ%d��\n", Length(&booklist));
				system("pause");
				break;
				//����۸���ߵ�ͼ����Ϣ
			case 3:
				system("cls");
				if (Empty(&booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					PrintList(seq_highest_price(&booklist));
				}
				system("pause");
				break;
				//��������ͼ���ƽ���۸�
			case 4:

				system("cls");
				if (Empty(&booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					printf("ƽ���۸�Ϊ%.2fԪ\n", seq_average_price(&booklist));

				}
				system("pause");
				break;
				//����������ͼ����Ϣ
			case 5:
				system("cls");
				if (Empty(&booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					char bookname[50];
					book* book2;
					getchar();
					printf("����������:");
					scanf("%s", bookname);
					book2 = seq_getbook(&booklist, bookname);
					if (book2) {
						print_book(*book2);
					}
					else
					{
						printf("û���ҵ�%s�Ȿ��,��ȷ�������Ƿ���ȷ\n", bookname);
					}
				}

				system("pause");
				break;
				//���ָ��λ�õ�ͼ����Ϣ
			case 6:
				system("cls");
				if (Empty(&booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else {

					int index;
					printf("������ָ��λ�����:");
					scanf("%d", &index);
					book* b = GetElem(&booklist, index);
					if (b) {
						print_book(*b);
					}
					else
					{
						printf("û�е�%d����,��ȷ���鼮�����\n", index);
					}

				}

				system("pause");
				break;
				//ָ��λ�ò���ͼ����Ϣ
			case 7:
				system("cls");
				int index;
				printf("���������λ��:");
				scanf("%d", &index);
				book b2;
				printf("ͼ����Ϣ�Կո���зָ�\n");
				printf("������ͼ����Ϣ:");
				scanf("%s%s%lf", b2.book_id, b2.book_name, &b2.price);
				if (ListInsert(&booklist, index, b2)) {
					printf("��������ϢΪ:\n");
					PrintList(&booklist);
				}
				system("pause");
				break;
				//ɾ��ָ��λ�õ�ͼ����Ϣ
			case 8:
				system("cls");
				if (Empty(&booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					int index;
					printf("������Ҫɾ����λ��:");
					scanf("%d", &index);
					book* b1 = ListDelete(&booklist, index);
					if (b1) {

						printf("ɾ���鼮Ϊ:");
						print_book(*b1);
						printf("ɾ����Ϣ�����ϢΪ:\n");
						PrintList(&booklist);
					}
					else {
						printf("ɾ����λ�ò��Ϸ�,������ȷ��ɾ����λ��\n");
					}
				}
				system("pause");

				break;
				//���򴢴�ͼ����Ϣ
			case 9:
				system("cls");
				if (Empty(&booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					seq_reverse(&booklist);
					printf("����洢�ɹ�,��������ϢΪ\n");
					PrintList(&booklist);

				}
				system("pause");
				break;
				//���򴢴�ͼ����Ϣ
			case 10:
				system("cls");
				if (Empty(&booklist)) {
					printf("û��ͼ�飬�������ͼ��\n");
				}
				else
				{
					sort(&booklist);
					printf("����ɹ�\n");
					printf("�������ϢΪ\n");
					PrintList(&booklist);

				}
				system("pause");
				break;
				//�˳�
			case 0:
				system("cls");
				printf("��лʹ��ͼ�����ϵͳ\n");
				system("pause");
				goto end;
			default:
				system("cls");
				printf("�޴�ѡ�����������\n");
				system("pause");
				break;
			}
		}
	}

end:
	{
		if(link=='y'||link=='Y')
		link_DestroyList(link_booklist);
		else
		DestroyList(&booklist);
	}


	return 0;
}