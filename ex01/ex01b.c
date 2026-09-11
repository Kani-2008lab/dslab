#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*next;
  };
  
  struct node* createnode(int data) {
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      if(newnode == NULL) {
          fprintf(stderr, "memory allocation failed\n");
          exit(EXIT_FAILURE);
}
newnode->data = data;
newnode->next = NULL;
return newnode;
}
void insertAtEnd(struct node** head,int data) {
     struct node* newnode = createnode(data);
     if(*head == NULL) {
         *head = newnode;
         return;
    }
    struct node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertAtposition(struct node** head, int data, int position) {
    if(position < 0) {
        printf("Enter: Invalid position.\n");
        return;
  }
  
  struct node* newnode = createnode(data);
  
  if(position == 0) {
      newnode->next = *head;
     *head = newnode;
     return;
  }
  
  struct node* current = *head;
  struct node* previous = NULL;
  int currentpos = 0;
  while((current != NULL) && (currentpos < position)) {
      previous = current;
      current = current->next;
      currentpos++;
  }
  
  if(currentpos != position) {
     printf("Error: Invalid position.\n");
     free(newnode);
     return;
   }

newnode->next = current;
previous->next = newnode;
}

int searchelement(struct node **head, int data) {
    struct node* temp = *head;
    int position = 0;
    while(temp != NULL) {
        if(temp->data == data) {
           return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

void deleteelement(struct node** head, int position) {
    if (*head == NULL) {
       printf("Error: list is empty.\n");
       return;
   }
   if (position < 0) {
       printf("Error: Invalid position.\n");
       return;
  }
  
  struct node* temp = *head;
  
  if (position == 0) {
      *head = temp->next;
      free(temp);
      return;
  }
  
  struct node* previous = NULL;
  int currentpos = 0;
  while (temp != NULL && currentpos < position) {
      previous = temp;
      temp = temp->next;
      currentpos++;
  }
  
  if (temp == NULL) {
     printf("Error: Invalid position.\n");
     return;
    }
  
  previous->next = temp->next;
  free(temp);
}

void displaylist(struct node* head) {
    if (head == NULL) {
        printf("list is empty.\n");
        return;
    }
    printf("linked list: ");
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
      }
      printf("NULL\n");
  }
  
  int main() {
      struct node* head = NULL;
      int choice, data, position, result;
      
      while(1) {
          printf("\nsingly linked list operation menu:\n");
          printf("1. insert at end\n");
          printf("2. insert at position\n");
          printf("3. search element\n");
          printf("4. delete element\n");
          printf("5. display list\n");
          printf("6. exit\n");
          printf("Enter your choice: ");
          scanf("%d", &choice);
          
          switch(choice) {
              case 1:
                  printf("Enter data to insert at end: ");
                  scanf("%d", &data);
                  insertAtEnd(&head, data);
                  break;
              case 2:
                 printf("Enter data to insert: ");
                 scanf("%d", &data);
                 printf("Enter position to insert (0 - based index): ");
                 scanf("%d", &position);
                 insertAtposition(&head, data, position);
                 break;
              case 3:
                 printf("Enter element to search: ");
                 scanf("%d", &data);
                 result = searchelement(&head, data);
                 if(result != -1)
                     printf("element found at position: %d\n", result);
                else
                     printf("element not found in the list\n");
                break;
             case 4:
                printf("Enter position to delete (0 - based index): ");
                scanf("%d", &position);
                deleteelement(&head, position);
                break;
            case 5:
                displaylist(head);
                break;
            case 6:
                while(head != NULL) {
                     struct node* temp = head;
                     head = head->next;
                     free(temp);
                }
                return 0;
           default:
                printf("invalid choice! please enter a valid option.\n");
       }
   }
   return 0;
}
