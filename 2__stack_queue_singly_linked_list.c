
#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 69420

typedef struct 
{
    int top;
    int arr[MAX_SIZE];
} Stack;

void initStack(Stack* stack) 
{
    stack->top = -1;
}

int isStackEmpty(Stack* stack) 
{
    return stack->top == -1;
}

int isStackFull(Stack* stack) 
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int item) 
{
    if (isStackFull(stack)) 
    {
        printf("Stack is full.\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

int pop(Stack* stack) 
{
    if (isStackEmpty(stack)) 
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}



//Queue
typedef struct 
{
    int front, rear;
    int arr[MAX_SIZE];
} Queue;

void initQueue(Queue* queue) 
{
    queue->front = 0;
    queue->rear = -1;
}

int isQueueEmpty(Queue* queue) 
{
    return queue->rear < queue->front;
}

int isQueueFull(Queue* queue) 
{
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(Queue* queue, int item) 
{
    if (isQueueFull(queue)) 
    {
        printf("Queue is full.\n");
        return;
    }
    queue->arr[++queue->rear] = item;
}

int dequeue(Queue* queue) 
{
    if (isQueueEmpty(queue)) 
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->arr[queue->front++];
}

//Singly linked list
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) 
{
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // Check if memory allocation was successful
    if (!newNode) 
    {
        printf("Memory error\n");
        return NULL;
    }
    
    // Assign data to the new node
    newNode->data = data;
    
    // Initialize next pointer of new node to NULL
    newNode->next = NULL;
    
    return newNode;
}

// Function to insert a new node at the end of the list
void insertNode(Node** head, int data) 
{
    // Create a new node with the given data
    Node* newNode = createNode(data);
    
    // If the list is empty, make the new node the head
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    
    // Traverse to the end of the list
    Node* temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    
    // Insert the new node at the end of the list
    temp->next = newNode;
}

// Function to delete a node with the given key from the list
void deleteNode(Node** head, int key) 
{
    // Start from the head node
    Node* temp = *head;
    Node* prev;
    
    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) 
    {
        // Change head
        *head = temp->next;
        
        // Free old head
        free(temp);
        
        return;
    }
    
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == NULL) return;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    
    // Free memory
    free(temp);
}






int main() 
{
    // Stack
    Stack stack;
    initStack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    printf("Stack: Popped %d\n", pop(&stack));
    printf("Stack: Popped %d\n", pop(&stack));

    // Queue
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    printf("Queue: Dequeued %d\n", dequeue(&queue));
    printf("Queue: Dequeued %d\n", dequeue(&queue));

    // Singly Linked List
    Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    printf("Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    deleteNode(&head, 1);
    printf("Linked List after deleting 1: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
