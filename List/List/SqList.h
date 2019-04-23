#pragma once
#define maxSize 100
#define ERROR 0
#define OK 1
typedef int STATUS ;
typedef int ElEMTYPE ;

//顺序表结构体定义
typedef struct Sqlist{
	ElEMTYPE data[maxSize];		//存放顺序表元素的数组
	int length ;				//顺序表长度
}Sqlist;


void InitList(Sqlist &L)
{
	L.length = 0;
}

/*	L的第p(0<=p<=length)个位置上插入新的元素e。p的输入不正确，返回error，
	代表插入失败；p输入正确，则将表第p个元素及以后元素右移一个位置，腾出
	一个空位置插入新元素，表长加一，插入成功，返回OK.
*/
STATUS insertElem(Sqlist &L, int p, int e)
{
	int i;
	if (p<0 || p>L.length || L.length == maxSize) return ERROR;

	for (i = L.length - 1;i >= p;--i) {
		L.data[i + 1] = L.data[i];
	}
	L.data[p] = e;
	++(L.length);
	return OK;
}

//（天勤）e.g_2.1
//返回第一个比x大的元素的位置（下标）
//按值查找同理
STATUS findElem(Sqlist L, int x) 
{
	int i;
	for (int i = 0;i < L.length;++i) {
		if (x < L.data[i]) {
			return i;
		}
	}
	return i;
}

