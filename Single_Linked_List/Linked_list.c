
#include<stdio.h>
#include<stdlib.h>

struct llist
{
    int info;
    struct llist* next;
};


struct llist* create_list(struct llist* head);
void display(struct llist* head);
void count(struct llist* head);
void search(struct llist* head, int data);
struct llist* addatbeg(struct llist* head, int data);
struct llist* addatend(struct llist* head, int data);
struct llist* addafter(struct llist* head, int data, int item);
struct llist* addbefore(struct llist* head, int data, int item);
struct llist* addatpos(struct llist* head, int data, int item);
struct llist* del(struct llist* head, int data);
struct llist* reverse(struct llist* head);

int main()
{
    struct llist* head = NULL;
    int choice, data, item, pos;
    while (1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");//repeated elements count
        printf("4.Search\n");//repeated elements search
        printf("5.Add to empty list or at the beginning\n");
        printf("6.Add to end\n");
        printf("7.Add after llist\n");
        printf("8.Add before llist\n");
        printf("9.Add at psoition\n");
        printf("10.Delete\n");//7-10
        printf("11.Reverse\n");
        printf("12.Quit\n");
        printf("Enter your choice\n");
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            head = create_list(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            count(head);
            break;
        case 4:
            printf("Enter element to be searched\n");
            scanf_s("%d", &data);
            search(head, data);
            break;
        case 5:
            printf("Enter element to be inserted\n");
            scanf_s("%d", &data);
            head = addatbeg(head, data);
            break;
        case 6:
            printf("Enter element to be inserted\n");
            scanf_s("%d", &data);
            head = addatend(head, data);
            break;
        case 7:
            printf("Enter element to be inserted\n");
            scanf_s("%d", &data);
            printf("Enter the element after which to insert\n");
            scanf_s("%d", &item);
            head = addafter(head, data, item);
            break;
        case 8:
            printf("Enter element to be inserted\n");
            scanf_s("%d", &data);
            printf("Enter the element after which to insert\n");
            scanf_s("%d", &item);
            head = addbefore(head, data, item);
            break;
        case 9:
            printf("Enter element to be inserted\n");
            scanf_s("%d", &data);
            printf("Enter the position at which to insert\n");
            scanf_s("%d", &pos);
            head = addatpos(head, data, pos);
            break;
        case 10:
            printf("Enter element to be deleted\n");
            scanf_s("%d", &data);
            head = del(head, data);
            break;
        case 11:
            head = reverse(head);
            break;
        case 12:
            exit(1);
        default:
            printf("Wrong Choice\n");
        }
    }
    return 0;
}

struct llist* addatbeg(struct llist* head, int data)
{
    struct llist* tmp;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    tmp->info = data;
    tmp->next = head;
    head = tmp;
    return head;

}
struct llist* addatend(struct llist* head, int data)
{
    struct llist* tmp,*p;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    tmp->info = data;
    p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->next= NULL;
    return head;
}
struct llist* create_list(struct llist* head)
{
    int n,i,val;
    head = NULL;
    printf("Enter the number of elements:\n");
    scanf_s("%d", &n);
    printf("Enter first element:");
    scanf_s("%d", &val);
    head=addatbeg(head, val);
    for (i = 1; i < n; i++)
    {
        printf("Enter next element:");
        scanf_s("%d", &val);
        head = addatend(head, val);
    }

    return head;

}
void display(struct llist* head)
{
    struct llist* p;
    p = head;
    while (p != NULL)
    {
        printf("%d ", (p->info));
        p = p->next;
    }
    printf("\n");
}
void count(struct llist* head)
{
    int n=0;
    struct llist* p;
    p = head;
    while (p != NULL)
    {
        ++n;
        p = p->next;
    }
    printf("Count is %d:\n", n);


}

void search(struct llist* head, int data)
{
    int n = 1;
    struct llist *p;
    p = head;
    while (p != NULL)
    {
        if (p->info == data)
        {
            printf("Item found at pos  %d\n", n);
            return;
        }
        ++n;
        p = p->next;
    }
}

struct llist* addafter(struct llist* head, int data, int item)
{
    struct llist* tmp, * p;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    p = head;
    while (p != NULL)
    {
        if (p->info == item)
        {
            //printf("1");
            tmp->next = p->next;
            tmp->info = data;
            p->next = tmp;
            return head;
           // printf("%d\n", p->info);
            //    p->next = tmp->next;
        }
        p = p->next;
    }
    return head;

}
struct llist* addbefore(struct llist* head, int data, int item)
{
    struct llist* tmp, * p;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    
    if (head->info == item)
    {
        tmp->info = data;
        tmp->next = head;
        head = tmp;
        return head;
    }

    p = head;

    while (p->next != NULL)
    {
        if (p->next->info == item)
        {
            //printf("1");
            tmp->next = p->next;
            tmp->info = data;
            p->next = tmp;
            return head;
            // printf("%d\n", p->info);
             //    p->next = tmp->next;
        }
        p = p->next;
    }
    return head;
}
struct llist* addatpos(struct llist* head, int data, int pos)
{
    struct llist* tmp, * p;
    int i;
    tmp = (struct llist*)malloc(sizeof(struct llist));
    tmp->info = data;
    if (pos == 1)
    {
        tmp->next = head;
        head = tmp;
        return head;
    }
    p = head;
    for (i = 1; i < (pos - 1) && (p != NULL); i++)
        p = p->next;
    if (p == NULL)
        printf("There are less than %d elements\n", pos);
    else
    {
        tmp->next = p->next;
        p->next = tmp;
    }
    return head;

}
struct llist* del(struct llist* head, int data)
{
    struct llist* tmp, * p;
    tmp = (struct llist*)malloc(sizeof(struct llist));

    if(head->info==data)
    {
 /*       printf("%d %d\n", head, (head->next));
        printf("%d %d\n", head->info, (head->next->info));
        printf("%d %d\n", *(head), *(head->next));*/
       tmp = head;
       //p = p->next;
       head = tmp->next;
       free(tmp);
       //printf("%d %d\n", head, (head->next));
       //printf("%d %d\n", head->info, (head->next->info));
       //printf("%d %d\n", *(head), *(head->next));
       return head;
   }
    p = head;
    while (p->next != NULL)
    {
        if (p->next->info == data)
        {
            tmp = p->next;
            //p = p->next;
            p->next = tmp->next;
            free(tmp);
            return head;

        }
        p = p->next;
    }
    return head;
}
struct llist* reverse(struct llist* head)
{
    struct llist* prev, * curr, * next1;
    prev = NULL;
    curr = head;
    next1 = NULL;
    while (curr != NULL)
    {
        next1 = curr->next;//stashing-save next ptr in tmp variable
        curr->next = prev;//reversing
        //advance prev and curr
        prev = curr;
        curr = next1;
    }
    head = prev;
    return head;
}