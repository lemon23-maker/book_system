#include "booklinklist.h"
#include "bookseqlist.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main() {

	int n;
	char link;//选择顺序表实现或链表实现
	printf("是否选择链式实现:Y/N\n");
	scanf("%c", &link);
	linkedlist link_booklist = NULL;
	seqlist booklist;
	//建立图书表单
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
	//读取文件
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
				//输出所有信息
			case 1:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					printf("图书信息为:\n");

					link_PrintList(link_booklist);

				}
				system("pause");
				break;
				//统计图书个数
			case 2:

				system("cls");
				printf("图书数量为%d本\n", link_Length(link_booklist));
				system("pause");
				break;
				//输出价格最高的图书信息
			case 3:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					link_PrintList(highest_price(link_booklist));
				}
				system("pause");
				break;
				//计算所有图书的平均价格
			case 4:

				system("cls");
				if (link_Empty(link_booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					printf("平均价格为%.2f元\n", average_price(link_booklist));

				}
				system("pause");
				break;
				//按书名查找图书信息
			case 5:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					char bookname[50];
					book* book2;
					getchar();
					printf("请输入书名:");
					scanf("%s", bookname);
					book2 = getbook(link_booklist, bookname);
					if (book2) {
						print_book(*book2);
					}
					else
					{
						printf("没有找到%s这本书,请确认书名是否正确\n", bookname);
					}
				}

				system("pause");
				break;
				//输出指定位置的图书信息
			case 6:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else {

					int index;
					printf("请输入指定位置序号:");
					scanf("%d", &index);
					book* b = link_Getdata(link_booklist, index);
					if (b) {
						print_book(*b);
					}
					else
					{
						printf("没有第%d本书,请确定书籍的序号\n", index);
					}

				}

				system("pause");
				break;
				//指定位置插入图书信息
			case 7:
				system("cls");
				int index;
				printf("请输入插入位置:");
				scanf("%d", &index);
				book b2;
				printf("图书信息以空格进行分隔\n");
				printf("请输入图书信息:");
				scanf("%s%s%lf", b2.book_id, b2.book_name, &b2.price);
				if (link_ListInsert(link_booklist, index, b2)) {
					printf("插入后的信息为:\n");
					link_PrintList(link_booklist);
				}
				system("pause");
				break;
				//删除指定位置的图书信息
			case 8:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					int index;
					printf("请输入要删除的位置:");
					scanf("%d", &index);
					book* b1 = link_ListDelete(link_booklist, index);
					if (b1) {

						printf("删除书籍为:");
						print_book(*b1);
						printf("删除信息后的信息为:\n");
						link_PrintList(link_booklist);
					}
					else {
						printf("删除的位置不合法,请重新确定删除的位置\n");
					}
				}
				system("pause");

				break;
				//逆序储存图书信息
			case 9:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					link_booklist = link_reverse(link_booklist);
					printf("逆序存储成功,逆序后的信息为\n");
					link_PrintList(link_booklist);

				}
				system("pause");
				break;
				//降序储存图书信息
			case 10:
				system("cls");
				if (link_Empty(link_booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					link_booklist = link_sort(link_booklist);
					printf("排序成功\n");
					printf("排序后信息为\n");
					link_PrintList(link_booklist);
				}
				system("pause");
				break;
				//退出
			case 0:
				system("cls");
				printf("感谢使用图书管理系统\n");
				system("pause");
				goto end;
			default:
				system("cls");
				printf("无此选项，请重新输入\n");
				system("pause");
				break;
			}

		}
	else//顺序实现
	{
		while (1)
		{
			system("cls");
			print_menu();

			scanf("%d", &n);
			switch (n)
			{
				//输出所有信息
			case 1:
				system("cls");
				if (Empty(&booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					printf("图书信息为:\n");

					PrintList(&booklist);

				}
				system("pause");
				break;
				//统计图书个数
			case 2:

				system("cls");
				printf("图书数量为%d本\n", Length(&booklist));
				system("pause");
				break;
				//输出价格最高的图书信息
			case 3:
				system("cls");
				if (Empty(&booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					PrintList(seq_highest_price(&booklist));
				}
				system("pause");
				break;
				//计算所有图书的平均价格
			case 4:

				system("cls");
				if (Empty(&booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					printf("平均价格为%.2f元\n", seq_average_price(&booklist));

				}
				system("pause");
				break;
				//按书名查找图书信息
			case 5:
				system("cls");
				if (Empty(&booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					char bookname[50];
					book* book2;
					getchar();
					printf("请输入书名:");
					scanf("%s", bookname);
					book2 = seq_getbook(&booklist, bookname);
					if (book2) {
						print_book(*book2);
					}
					else
					{
						printf("没有找到%s这本书,请确认书名是否正确\n", bookname);
					}
				}

				system("pause");
				break;
				//输出指定位置的图书信息
			case 6:
				system("cls");
				if (Empty(&booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else {

					int index;
					printf("请输入指定位置序号:");
					scanf("%d", &index);
					book* b = GetElem(&booklist, index);
					if (b) {
						print_book(*b);
					}
					else
					{
						printf("没有第%d本书,请确定书籍的序号\n", index);
					}

				}

				system("pause");
				break;
				//指定位置插入图书信息
			case 7:
				system("cls");
				int index;
				printf("请输入插入位置:");
				scanf("%d", &index);
				book b2;
				printf("图书信息以空格进行分隔\n");
				printf("请输入图书信息:");
				scanf("%s%s%lf", b2.book_id, b2.book_name, &b2.price);
				if (ListInsert(&booklist, index, b2)) {
					printf("插入后的信息为:\n");
					PrintList(&booklist);
				}
				system("pause");
				break;
				//删除指定位置的图书信息
			case 8:
				system("cls");
				if (Empty(&booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					int index;
					printf("请输入要删除的位置:");
					scanf("%d", &index);
					book* b1 = ListDelete(&booklist, index);
					if (b1) {

						printf("删除书籍为:");
						print_book(*b1);
						printf("删除信息后的信息为:\n");
						PrintList(&booklist);
					}
					else {
						printf("删除的位置不合法,请重新确定删除的位置\n");
					}
				}
				system("pause");

				break;
				//逆序储存图书信息
			case 9:
				system("cls");
				if (Empty(&booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					seq_reverse(&booklist);
					printf("逆序存储成功,逆序后的信息为\n");
					PrintList(&booklist);

				}
				system("pause");
				break;
				//降序储存图书信息
			case 10:
				system("cls");
				if (Empty(&booklist)) {
					printf("没有图书，请先添加图书\n");
				}
				else
				{
					sort(&booklist);
					printf("排序成功\n");
					printf("排序后信息为\n");
					PrintList(&booklist);

				}
				system("pause");
				break;
				//退出
			case 0:
				system("cls");
				printf("感谢使用图书管理系统\n");
				system("pause");
				goto end;
			default:
				system("cls");
				printf("无此选项，请重新输入\n");
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