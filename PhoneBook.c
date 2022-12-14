#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c, n, count;
char a[20];

// structure of the linked list element
struct contact
{
    char name[10], city[10], number[20], email[20], dob[10];
    struct contact *link;
};

typedef struct contact NODE;
NODE *head;

//function to count the number of contacts in the phone book
int countcontacts()
{
    NODE *p;
    count = 0;
    p = head;
    while (p != NULL)
    {
        p = p->link;
        count++;
    }
    return count;
}

//function to get the details for a new contact in the phone book
NODE *getnode()
{
    NODE *newcontact;
    newcontact = (NODE *)malloc(sizeof(NODE));
    printf("\n---Enter Details---");
    printf("\nEnter Name: ");
    scanf("%s", newcontact->name);
    printf("\nEnter City: ");
    scanf("%s", newcontact->city);
    printf("\nEnter Phone Number: ");
    scanf("%s", newcontact->number);
    printf("\nEnter Email: ");
    scanf("%s", newcontact->email);
    printf("\nEnter DOB: ");
    scanf("%s", newcontact->dob);
    newcontact->link = NULL;
    return newcontact;
}

//function to display all the contacts present in the phone book
NODE *display()
{
    NODE *p;
    if (head == NULL)
        printf("NO CONTACTS YET!\n");
    else
    {
        p = head;
        printf("\n---CONTACTS---\n");
        printf("\nNAME\tCITY\t\tPHONE NUMBER\tEMAIL\t\tDOB(dd/mm/yyyy)");
        while (p != NULL)
        {
            printf("\n%s\t%s\t%s\t%s\t%s", p->name, p->city, p->number, p->email, p->dob);
            p = p->link;
        }
        printf("\nThe number of contacts in the list: %d", countcontacts(head));
    }
    return head;
}

//function to make space for a new contact in the phone book and take details
NODE *create()
{
    NODE *newcontact;
    if (head == NULL)
    {
        newcontact = getnode();
        head = newcontact;
    }
    else
    {
        newcontact = getnode();
        newcontact->link = head;
        head = newcontact;
    }
    return head;
}

//function to insert a contact in the phone book
void insertcontact()
{
    NODE *p, *newcontact;
    p = head;
    if (head == NULL)
    {
        newcontact = getnode();
        head = newcontact;
    }
    else
    {
        newcontact = getnode(head);
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = newcontact;
    }
}

//function to delete a contact from the phone book
void deletecontact()
{
    NODE *temp, *cur;
    cur = head;
    printf("Enter the name of the contact to be deleted: \n");
    scanf("%s", a);
    if (head == NULL)
    {
        printf("\nNo contacts to delete\n");
        return;
    }
    if (strcmp(head->name, a) == 0)
    {
        temp = head;
        head = head->link;
        free(temp);
        return;
    }
    else
    {
        while (cur->link != NULL)
        {
            if (strcmp(cur->link->name, a) == 0)
            {
                temp = cur->link;
                cur->link = cur->link->link;
                free(temp);
                return;
            }
        }
    }
}

//function to search for a contact from the phone book
void searchcontact()
{
    NODE *prev, *cur;
    cur = head;
    printf("Enter name of contact to be searched: ");
    scanf("%s", a);
    if (head == NULL)
    {
        printf("\nNo contacts in the list\n");
        return;
    }
    if (strcmp(head->name, a) == 0)
    {
        printf("Contact Found!!\n");
        printf("Name: %s\nCity: %s\nNumber: %s\nEmail: %s\nDOB: %s\n", head->name, head->city, head->number, head->email, head->dob);
        return;
    }
    else
    {
        while (cur->link != NULL)
        {
            prev = cur;
            cur = cur->link;
            if (strcmp(cur->name, a) == 0)
            {
                printf("Contact Found!!\n");
                printf("Name: %s\nCity: %s\nNumber: %s\nEmail: %s\nDOB: %s\n", cur->name, cur->city, cur->number, cur->email, cur->dob);
                return;
            }
        }
    }
    printf("No Contact Found!!\n");
    return;
}

int main()
{
    int i;
    head = NULL;
    printf("\n-----PHONE BOOK MANAGEMENT-----\n");
    do
    {
        printf("\n1.Create\t2.Display\t3.Insert\t4.Delete\t5.Search\t6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("\nHow many contacts do you want to add: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                create();
            }
            break;
        case 2:
            display();
            break;
        case 3:
            insertcontact();
            break;
        case 4:
            deletecontact();
            break;
        case 5:
            searchcontact();
            break;
        case 6:
            exit(0);
        }
    } while (c != 6);
}
