#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Enum for operation return status */
typedef enum {
  kListSuccess = 0,
  kListErrorNullPointer,
  kListErrorAllocationFailed,
  kListErrorEmptyList,
  kListErrorIndexOutOfBounds,
  kListErrorInvalidIndex
} ListStatus;

/* Represents a node in a singly linked list. */
typedef struct node {
  int data;              /**< Value stored in the node */
  struct node *next;     /**< Pointer to the next node in the list */
} Node;

/* Prints all elements of the linked list. */
void print_list(const Node *head) {
  const Node *current = head;

  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
  }
}

/* Inserts a new element at the end of the list. */
ListStatus push_back(Node **head, int data) {
  if (head == NULL) {
    return kListErrorNullPointer;
  }

  Node *new_node = malloc(sizeof(Node));

  if (new_node == NULL) {
    return kListErrorAllocationFailed;
  }

  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
    return kListSuccess;
  }

  Node *current = *head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
  return kListSuccess;
}

/* Inserts a new element at the beginning of the list. */
ListStatus push_front(Node **head, int data) {
  if (head == NULL) {
    return kListErrorNullPointer;
  }

  Node *new_node = malloc(sizeof(Node));
  
  if (new_node == NULL) {
    return kListErrorAllocationFailed;
  }

  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
  
  return kListSuccess;
}

/* Inserts a new element at a specific index. */
ListStatus insertion(Node **head, int index, int data) {
  if (head == NULL) {
    return kListErrorNullPointer;
  }
  
  if (index < 0) {
    return kListErrorInvalidIndex;
  }

  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    return kListErrorAllocationFailed;
  }
  
  new_node->data = data;

  if (index == 0) {
    new_node->next = *head;
    *head = new_node;
    return kListSuccess;
  }

  if (*head == NULL) {
    free(new_node);
    return kListErrorIndexOutOfBounds;
  }

  Node *current = *head;
  
  /* Move to the node just before the desired index */
  for (int i = 0; i < index - 1; i++) {
    if (current->next == NULL) {
      free(new_node);
      return kListErrorIndexOutOfBounds;
    }
    current = current->next;
  }

  new_node->next = current->next;
  current->next = new_node;
  return kListSuccess;
}

/* Removes the last element of the list. */
ListStatus pop_back(Node **head) {
  if (head == NULL) {
    return kListErrorNullPointer;
  }
  
  if (*head == NULL) {
    return kListErrorEmptyList;
  }

  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return kListSuccess;
  }

  Node *current = *head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
  
  return kListSuccess;
}

/* Removes the first element of the list. */
ListStatus pop_front(Node **head) {
  if (head == NULL) {
    return kListErrorNullPointer;
  }
  
  if (*head == NULL) {
    return kListErrorEmptyList;
  }

  Node *next_node = (*head)->next;
  free(*head);
  *head = next_node;
  
  return kListSuccess;
}

/* Deletes an element at a specific index. */
ListStatus deletion(Node **head, int index) {
  if (head == NULL) {
    return kListErrorNullPointer;
  }
  
  if (*head == NULL) {
    return kListErrorEmptyList;
  }
  
  if (index < 0) {
    return kListErrorInvalidIndex;
  }

  if (index == 0) {
    Node *to_delete = *head;
    *head = to_delete->next;
    free(to_delete);
    return kListSuccess;
  }

  Node *current = *head;

  /* Move to the node just before the one to delete */
  for (int i = 0; i < index - 1; i++) {
    if (current->next == NULL) {
      return kListErrorIndexOutOfBounds;
    }
    current = current->next;
  }

  Node *to_delete = current->next;
  if (to_delete == NULL) {
    return kListErrorIndexOutOfBounds;
  }

  current->next = to_delete->next;
  free(to_delete);
  
  return kListSuccess;
}


/* Returns the first element of the list */
ListStatus front(const Node *head, int *value) {
  if (value == NULL) {
    return kListErrorNullPointer;
  }
  
  if (head == NULL) {
    return kListErrorEmptyList;
  }
  
  *value = head->data;
  return kListSuccess;
}

/* Returns the last element of the list */
ListStatus back(const Node *head, int *value) {
  if (value == NULL) {
    return kListErrorNullPointer;
  }
  
  if (head == NULL) {
    return kListErrorEmptyList;
  }
  
  const Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  
  *value = current->data;
  return kListSuccess;
}

/* Returns the element at a specified index */
ListStatus get(const Node *head, int index, int *value) {
  if (value == NULL) {
    return kListErrorNullPointer;
  }
  
  if (index < 0) {
    return kListErrorInvalidIndex;
  }
  
  if (head == NULL) {
    return kListErrorEmptyList;
  }
  
  const Node *current = head;
  
  for (int i = 0; i < index; i++) {
    if (current->next == NULL) {
      return kListErrorIndexOutOfBounds;
    }
    current = current->next;
  }
  
  *value = current->data;
  return kListSuccess;
}

/* Frees all nodes in the linked list. */
void free_list(Node **head) {
  if (head == NULL) {
    return;
  }

  Node *current = *head;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

/* Helper function to convert status to string */
const char* list_status_to_string(ListStatus status) {
  switch (status) {
    case kListSuccess:
      return "Success";
    case kListErrorNullPointer:
      return "Error: Null pointer";
    case kListErrorAllocationFailed:
      return "Error: Memory allocation failed";
    case kListErrorEmptyList:
      return "Error: Empty list";
    case kListErrorIndexOutOfBounds:
      return "Error: Index out of bounds";
    case kListErrorInvalidIndex:
      return "Error: Invalid index";
    default:
      return "Error: Unknown";
  }
}


int main() {
  Node *head = NULL;

  return 0;
}
