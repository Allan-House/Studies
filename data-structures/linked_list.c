// TODO:Comentários no início do código e nas funções

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

void print_list(Node *head) {
  Node *current = head;

  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
  }
}

// TODO: front

// TODO: back

void push_back(Node **head, int data) {
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

void push_front(Node **head, int data) {
  Node *new_node = malloc(sizeof(Node));
  
  if (new_node == NULL) {
    return;
  }

  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

// TODO: insertion

void pop_back(Node **head) {
  if (*head == NULL) {
    return;
  }

  // Apenas um nó
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

void pop_front(Node **head) {
  if (*head == NULL) {
    return;
  }

  Node *next_node = (*head)->next;
  free(*head);
  *head = next_node;
}

void free_list(Node **head) {
  while (*head != NULL) {
    pop_front(head);
  }
}

// TODO: deletion

int main() {
  Node *head = NULL;

  return 0;
}