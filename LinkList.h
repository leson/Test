#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
/* define a link node strut */
struct student
{
    long num;
    struct student *prior; /* define point to the struct */
    struct student *next;
};



#endif // LINKLIST_H_INCLUDED
