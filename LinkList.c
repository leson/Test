/*
 * @author: lizhenbin
 * @date: 2011-09-14
 * @descrption: list operation
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define NULL 0



/* create struct */
struct student *create()
{
    struct student *head; /* link head and node point */
    struct student *p;
    struct student *q;
    long x;

    head = (struct student*)malloc(sizeof(struct student));
    q = head;
    head->next = NULL;
    printf("\nPlease input node numbers to the list: \n");
    scanf("%ld",&x);
    while(x!=0)
    {
        /* create node */
        p = (struct student*)malloc(sizeof(struct student));
        p->num = x;
        p->next = NULL;
        q->next = p;
        p->prior = q;
        q = p;
        scanf("%ld",&x);
    }
    return head;
}

/* Output list all datas */
void print(struct student *head)
{
    struct student *p;
    p = head->next;
    printf("\nThe list is: ");
    if(p==NULL)
    {
        printf("\nInput list is NULL!");
    }
    while(p!=NULL)
    {
        printf("%ld ", p->num);
        p = p->next;
    }
    printf("\n");
}

/* delete list node */
void del(struct student *head)
{
    struct student *p;
    struct student *q;
    int i;
    int j=0;

    printf("Please input delete position: ");
    scanf("%d", &i);
    if(i<1)
    {
        printf("You input %d error.", i);
        printf("\nTry again, Input nnum: ");
        scanf("%d", &i);
    }
    p = head;
    while(j<=i-1 && p!=NULL)
    {
        p = p->next;
        j++;
    }
    if(p==NULL)
    {
        printf("\nThere is no %d in the list.", i);
        exit(1);
    }
    else
    {
        /* delete list node */
        q = p;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        p = p->next;
        free(q);
    }
}

/* insert list node */
void insert(struct student *head)
{
    struct student *p;
    struct student *q = head;
    int i;
    int j = 0;

    p = (struct student*)malloc(sizeof(struct student));
    printf("\nPlease input the student No you want to insert: ");
    scanf("%ld", &p->num);
    printf("\nInput the student %d position to insert: ",p->num);
    scanf("%d", &i);
    if(i<1)
    {
        printf("\nYou input %d error.", i);
        printf("\nTry again, Input nnum: ");
        scanf("%d", &i);
    }
    while(j<=i-1 && q->next!=NULL)
    {
        q = q->next;
        j++;
    }
    if(q->next==NULL && j!=i)
    {
        p->next = NULL;
        p->prior = q;
        q->next = p;
    }
    else
    {
        q->prior->next = p;
        p->prior = q->prior;
        p->next = q;
        q->prior = q;
    }
}

/* search list node position and data */
void search(struct student *head)
{
    struct student *p;
    long number, i=1, j=0;

    printf("\nPlease input the index you want to search: ");
    scanf("%d", &number);
    p = head->next;
    printf("\nThe number in the list position is: ");

    while(p!=NULL)
    {
        if(p->num==number)
        {
            printf("%d\n",i);
            j = 1;
        }
        p = p->next;
        i++;
    }
    if(j==0)
    {
        printf("There is no %ld in the list.\n",number);
    }
}

/* read data from file input */
struct student *filein()
{
    struct student *p1;
    struct student *p2;
    struct student *head;
    int i = 0;
    FILE *fp;

    char file[20] = "d:/list/node.txt";
    printf("\nFileName is: %s\n", file);
    if((fp=fopen(file, "r"))==NULL)
    {
        printf("Can not open file: %s", file);
        exit(0);
    }
    p2 = (struct student*)malloc(sizeof(*p1));
    head = p2;
    p1 = (struct student*)malloc(sizeof(*p1));
    while(fread(p1, sizeof(*p1), 1, fp)==1)
    {
        i++;
        p2->next = p1;
        p2 = p1;
        p1->next = NULL;
        p1 = (struct student*)malloc(sizeof(*p1));
    }
    free(p1);
    fclose(fp);
    if(i==0)
    {
        printf("\nNo recored in %s ", file);
    }
    return head;
}

/* save the list result to file */
void savefile(struct student* head)
{
    struct student *p1;
    FILE *fp;
    char file[20] = "d:/list/node.txt";
    printf("\nFileName: %s", file);
    printf("\nPlease wait.../n");
    if((fp=fopen(file,"w"))==NULL)
    {
        printf("\nCan not open file: %s", file);
        exit(0);
    }
    p1 = head->next;
    while(p1!=NULL)
    {
        fwrite(p1, sizeof(struct student), 1, fp);
        p1 = p1->next;
    }
    fclose(fp);
}

/* print the operate menu */
void showMenu()
{
    printf("|-------------------------------------------------|\n");
    printf("|            Link List Opearte Menu               |\n");
    printf("|-------------------------------------------------|\n");
    printf("|                 1: Insert                       |\n");
    printf("|                 2: Delete                       |\n");
    printf("|                 3: Search                       |\n");
    printf("|                 4: FileIn                       |\n");
    printf("|                 5: Savefile                     |\n");
    printf("|                 6: Print List                   |\n");
    printf("|                 7: Print Menu                   |\n");
    printf("|                 8: Exit                         |\n");
    printf("|-------------------------------------------------|\n");
}

/* main funtion */
void testLinkList()
{
    int a=0;
    struct student *la;
    la = create();
    /*
    la = (struct student*)malloc(sizeof(struct student));
    la->next = NULL;
    */
    while(1)
    {
        showMenu();
        scanf("\n%d", &a);
        switch(a)
        {
            case 1: insert(la); break;
            case 2: del(la); break;
            case 3: search(la); break;
            case 4: filein(); break;
            case 5: savefile(la); break;
            case 6: print(la); break;
            case 7: showMenu(); break;
            case 8: exit(1);
            default: printf("\nInput error,Try again.");break;
        }
    }
}
