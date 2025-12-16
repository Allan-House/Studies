#include <stdlib.h>
#include <stdio.h>

/** TODO:
 * front()
 * back()
 * Status de retorno.
 * Comentários explicativos.
 * Implementação e testes na main.
*/ 

/**
 * @brief Represents a node in a singly linked list.
 *
 * Each node stores an integer value and a pointer
 * to the next node in the list. The last node points
 * to NULL.
 */
typedef struct node {
  int data;              /**< Value stored in the node */
  struct node *next;     /**< Pointer to the next node in the list */
} Node;

/**
 * @brief Prints all elements of the linked list.
 *
 * Iterates through the list starting from the head
 * and prints the data stored in each node.
 *
 * @param head Pointer to the first node of the list.
 */
void print_list(Node *head) {
  Node *current = head;

  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
  }
}

/**
 * @brief Inserts a new element at the end of the list.
 *
 * Allocates a new node and appends it to the tail
 * of the linked list.
 *
 * @param head Double pointer to the head of the list.
 * @param data Value to be stored in the new node.
 */
void push_back(Node **head, int data) {
  if (head == NULL) {
    return;
  }

  Node *new_node = malloc(sizeof(Node));

  if (new_node == NULL) {
    return;
  }

  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  Node *current = *head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}

/**
 * @brief Inserts a new element at the beginning of the list.
 *
 * Allocates a new node and updates the head pointer
 * to point to the new node.
 *
 * @param head Double pointer to the head of the list.
 * @param data Value to be stored in the new node.
 */
void push_front(Node **head, int data) {
  Node *new_node = malloc(sizeof(Node));
  
  if (new_node == NULL) {
    return;
  }

  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

/**
 * @brief Inserts a new element at a specific index.
 *
 * Inserts a node at the given position in the list.
 * If the index is greater than the list size, the
 * element is inserted at the end.
 *
 * @param head Double pointer to the head of the list.
 * @param index Position where the element should be inserted.
 * @param data Value to be stored in the new node.
 */
void insertion(Node **head, int index, int data) {
  if (index < 0 || head == NULL) {
    return;
  }

  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    return;
  }
  
  new_node->data = data;

  /* Insert at the beginning */
  if (index == 0) {
    new_node->next = *head;
    *head = new_node;
    return;
  }

  if (*head == NULL) {
    free(new_node);
    return;
  }

  Node *current = *head;
  
  /* Move to the node just before the desired index */
  for (int i = 0; i < index - 1; i++) {
    if (current->next == NULL) {
      /* Index out of bounds */
      free(new_node);
      return;
    }
    current = current->next;
  }

  new_node->next = current->next;
  current->next = new_node;
}

/**
 * @brief Removes the last element of the list.
 *
 * Frees the memory of the last node and updates
 * the list accordingly.
 *
 * @param head Double pointer to the head of the list.
 */
void pop_back(Node **head) {
  if (head == NULL || *head == NULL) {
    return;
  }

  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }

  Node *current = *head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

/**
 * @brief Removes the first element of the list.
 *
 * Frees the memory of the head node and updates
 * the head pointer.
 *
 * @param head Double pointer to the head of the list.
 */
void pop_front(Node **head) {
  if (head == NULL || *head == NULL) {
    return;
  }

  Node *next_node = (*head)->next;
  free(*head);
  *head = next_node;
}

/**
 * @brief Deletes an element at a specific index.
 *
 * Removes the node at the given position if it exists
 * and frees its allocated memory.
 *
 * @param head Double pointer to the head of the list.
 * @param index Index of the element to be removed.
 */
void deletion(Node **head, int index) {
  if (index < 0 || head == NULL || *head == NULL) {
    return;
  }

  /* Remove first element */
  if (index == 0) {
    Node *to_delete = *head;
    *head = to_delete->next;
    free(to_delete);
    return;
  }

  Node *current = *head;

  /* Move to the node just before the one to delete */
  for (int i = 0; i < index - 1; i++) {
    if (current->next == NULL) {
      /* Index out of bounds */
      return;
    }
    current = current->next;
  }

  Node *to_delete = current->next;
  if (to_delete == NULL) {
    return;
  }

  current->next = to_delete->next;
  free(to_delete);
}


/**
 * @brief Frees all nodes in the linked list.
 *
 * Iteratively removes all elements from the list
 * and sets the head pointer to NULL.
 *
 * @param head Double pointer to the head of the list.
 */
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

int main() {
  Node *head = NULL;

  return 0;
}
