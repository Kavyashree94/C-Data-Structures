
#include<stdio.h>
#include<stdlib.h>
struct llist
{
    struct llist* prev;
    int info;
    struct llist* next;
};
struct llist* create_list(struct llist* head);
void display(struct llist* head);
void print_rev(struct llist* head);
struct llist* addtoempty(struct llist* head, int data);
struct llist* addatbeg(struct llist* head, int data);
struct llist* addatend(struct llist* head, int data);
struct llist* addafter(struct llist* head, int data, int item);
struct llist* addbefore(struct llist* head, int data, int item);
struct llist* del(struct llist* head, int data);
struct llist* reverse(struct llist* head);
/*
The next pointer of last node and prev pointer of first node are NULL.
*/
int main()
{
    struct llist* head = NULL;
    int choice, data, item;
    while (1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Add to empty list or at the beginning\n");
        printf("4.Add to beginning\n");
        printf("5.Add at end\n");
        printf("6.Add after llist\n");
        printf("7.Add before llist\n");
        printf("8.Delete\n");
        printf("9.Reverse\n");
        printf("10.Print Reverse\n");
        printf("11.Quit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = create_list(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter element to be inserted\n");
            scanf("%d", &data);
            head=addtoempty(head, data);
            break;
        case 4:
            printf("Enter element to be inserted\n");
            scanf("%d", &data);
            head = addatbeg(head, data);
            break;
        case 5:
            printf("Enter element to be inserted\n");
            scanf("%d", &data);
            head = addatend(head, data);
            break;
        case 6:
            printf("Enter element to be inserted\n");
            scanf("%d", &data);
            printf("Enter the element after which to insert\n");
            scanf("%d", &item);
            head = addafter(head, data, item);
            break;
        case 7:
            printf("Enter element to be inserted\n");
            scanf("%d", &data);
            printf("Enter the element before which to insert\n");
            scanf("%d", &item);
            head = addbefore(head, data, item);
            break;
        case 8:
            printf("Enter element to be deleted\n");
            scanf("%d", &data);
            head = del(head, data);
            break;
        case 9:
            head = reverse(head);
            break;
        case 10:
            print_rev(head);
            break;
        case 11:
            exit(1);
        default:
            printf("Wrong Choice\n");
        }
    }
    return 0;
}


struct llist* create_list(struct llist* head)
{
    int n, data,i;
    printf("Enter number of elements to create doublelinked list");
    scanf("%d", &n);
    printf("Enter first Element:");
    scanf("%d", &data);
    head = addtoempty(head,data);
    for ( i = 1; i < n; i++)
    {
        printf("Enter next Element:");
        scanf("%d", &data);
        head = addatend(head, data);
    }
    return head;
}
void display(struct llist* head)
{
    struct llist* p;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    p = head;
    while (p != NULL)
    {
        printf("%d ", (p->info));
        p = p->next;
    }
    printf("\n");
 
}
struct llist* addtoempty(struct llist* head, int data)
{
    struct llist *tmp;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    head = tmp;
    return head;
}
struct llist* addatbeg(struct llist* head, int data)
{
    struct llist* tmp;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = head;
    head->prev = tmp;
    head = tmp;
    return head;
}
struct llist* addatend(struct llist* head, int data)
{
    struct llist *tmp,*p;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    p = head;
    /*head->next = tmp;*/
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->info = data;
    tmp->prev = p;
    tmp->next = NULL;
    /*head = tmp;*/

    return head;
}
struct llist* addafter(struct llist* head, int data, int item)
{
    struct llist *tmp, * p;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    p = head;
    while (p!=NULL)
    {
        if (p->info == item)
        {
            tmp->info = data;
            /* 1. Make prev_node as previous of new_node */
            tmp->prev = p;
            /* 2. Make next of new node as next of prev_node */
            tmp->next = p->next;
            /* 3. Change previous of new_node's next node */
            while (p->next != NULL)
                p->next->prev = tmp;
            /* 4. Make the next of prev_node as new_node */
            p->next = tmp;
            return head;
        }
        p = p->next;
    }
    return head;
}
struct llist* addbefore(struct llist* head, int data, int item)
{
    struct llist* tmp, *p;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    tmp->info = data;
    if (head->info == item)
    {
        tmp->prev = NULL;
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
        return head;
    }
    p = head;
    while (p != NULL)
    {
        if(p->info == item)
        {
            tmp->next = p;
            tmp->prev = p->prev;
            p->prev->next = tmp;
            p->prev = tmp;
            return head;
        }
        p = p->next;
    }
    return head;
}
struct llist* del(struct llist* head, int data)
{
   struct llist *p,*tmp;
   if(head->next==NULL)
   {
     if(head->info==data)
     {
        tmp=head;
        head=NULL;
        free(tmp);
        return head;
     }
   }
   if(head->info==data)/*first node*/
   {
      p=head->next;
      free(p->prev);
      p->prev=NULL;
      head=p;
      return head;
   }
   p=head;
   while(p!=NULL)
   {
       if((p->info==data)&&(p->next!=NULL))/*In between nodes*/
       {
           p->prev->next=p->next;
           p->next->prev=p->prev;
           free(p);
           return head;
       }
       p=p->next;
   }
   tmp=head;
   while(tmp!=NULL)/*last node*/
   {
       if((tmp->info==data)&&(tmp->next==NULL))
       {
          tmp->prev->next=NULL;
          free(tmp);
          return head;   
       }
       tmp=tmp->next;
   }
    return head;
}

void print_rev(struct llist* head)
{
   struct llist *p;
   p=head;
   while(p->next!=NULL)
   {
       p=p->next;
   }

   while(p->prev!=NULL)
   {
      printf(" %d",p->info);
      p=p->prev;
   }
   if(p->prev==NULL)
   {
      printf(" %d",head->info);
   }
   printf("\n");
}

struct llist* reverse(struct llist* head)
{
 struct llist *p1,*p2;
   p1=head;
   p2=p1->next;
   p1->next=NULL;
   p1->prev=p2;
   while(p2!=NULL)
   {
      p2->prev=p2->next;
      p2->next=p1;
      p1=p2;
      p2=p2->prev;
   }
   head=p1;
   return head;
}