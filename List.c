/**
 * @todo	c���������CURD
 * @author Koma
 **/
#include "List.h"
/**
 * ��ʼ��������һ����ͷ�ڵ������
 **/
LinkList init( int len ) {
	int i;
	LinkList p, r, list;
	list = (LinkList)malloc(sizeof(LNode));
	list->next = NULL;
	for ( i = 0; i < len; i++ ) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i+1;
		p->next = NULL;
		if ( !list->next ) {
			list->next = p;	//��ֵͷ�ڵ�
		} else {
			r->next = p;
		}
		r = p;	//�ƶ�rָ��,ָ����һ���ڵ�
	}
	return list;
}

/**
 * ����Ԫ��
 * @param int n �����λ��
 * @param int e �����ֵ
 **/
void insertEle( LinkList l, int n, int e ) {
	LinkList p, q, ele;
	int i = 1;
	ele = (LinkList)malloc(sizeof(LNode));
	ele->data = e;
	ele->next = NULL;
	p = q = l->next;

	if ( n == 1 ) {			//��Ԫ����ӵ�����ͷ
		l->next = ele;
		ele->next = q;
		return;
	}
	while ( i != n && q->next != NULL ) {
		p = q;
		q = q->next;
		i++;
	}
	if ( i == n ) {
		p->next = ele;
		ele->next = q;
	} else if( i < n ) {	//��Ԫ����ӵ�����β
		q->next = ele;
	}
}

/**
 * ɾ���ڵ�
 * @param int n ��ɾ���ڵ��λ��
 **/
void delNode( LinkList l, int n ) {
	LinkList p, q;
	int i = 1;
	p = q = l->next;
	if ( n == 1 ) {
		l->next = q->next;
	} else {
		while ( i != n && q->next != NULL ) {
			p = q;
			q = q->next;
			i++;
		}
		if ( i == n ) {
			p->next = q->next;
		}
	}
}

/**
 * �޸Ľڵ�
 * @param int n ���޸Ľڵ��λ��
 * @param int e �޸�ֵ
 **/
void updateNode( LinkList l, int n, int e ) {
	LinkList q;
	int i = 1;
	q = l->next;
	while ( i != n && q->next != NULL ) {
		q = q->next;
		i++;
	}
	if ( i == n ) {
		q->data = e;
	}
}

/**
 * ��ӡ����
 **/
void printLink( LinkList l ) {
	LinkList q;
	q = l->next;
	while ( q->next != NULL ) {
		printf("%d ", q->data);
		q = q->next;
	}
	printf("%d\n", q->data);	//��ӡ���һ��Ԫ��
}

int testList() {
    LinkList l;
	l = init(5);
	printLink(l);
	insertEle(l, 6, 10);
	printLink(l);
	delNode(l, 2);
	printLink(l);
	updateNode(l, 6, 22);
	printLink(l);
	return 0;
}
