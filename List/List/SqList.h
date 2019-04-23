#pragma once
#define maxSize 100
#define ERROR 0
#define OK 1
typedef int STATUS ;
typedef int ElEMTYPE ;

//˳���ṹ�嶨��
typedef struct Sqlist{
	ElEMTYPE data[maxSize];		//���˳���Ԫ�ص�����
	int length ;				//˳�����
}Sqlist;


void InitList(Sqlist &L)
{
	L.length = 0;
}

/*	L�ĵ�p(0<=p<=length)��λ���ϲ����µ�Ԫ��e��p�����벻��ȷ������error��
	�������ʧ�ܣ�p������ȷ���򽫱��p��Ԫ�ؼ��Ժ�Ԫ������һ��λ�ã��ڳ�
	һ����λ�ò�����Ԫ�أ�����һ������ɹ�������OK.
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

//�����ڣ�e.g_2.1
//���ص�һ����x���Ԫ�ص�λ�ã��±꣩
//��ֵ����ͬ��
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

