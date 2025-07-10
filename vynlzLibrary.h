#ifndef CLIONPROJECTS_ASSIGNMENT10_H
#define CLIONPROJECTS_ASSIGNMENT10_H
#include "stdio.h"
#include"stdlib.h"
#define MAX_SIZE 10


// <---------------------------------Linked List ------------------------------------>
struct peop{
    int value;
    struct peop *next;
    struct peop *prev;

};

struct peop *createNode(int value){
    struct peop *newNode = (struct peop*)malloc(sizeof(struct peop*));
    newNode->value =value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void addingData(struct peop **head,int value){
    struct peop *newNode = createNode(value);
    newNode->next = *head;

    if(*head != NULL){
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void gettingData(struct peop *head){
    struct peop *end;
    if(head==NULL){
        return ;
    }

    while(head != NULL){
        printf("Showing Data Forward: %d\n",head->value);
        end = head;
        head = head->next;
    }

    printf("<-------------------->\n");

    while (end != NULL){
        printf ("Showing Data Backward:%d\n", end->value);
        end = end->prev;
    }

}

void append(struct peop **head,int key){
    struct peop *newNode = createNode(key);
    struct peop *temp = *head;
    if(temp == NULL) {
        *head = newNode;
        return ;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    newNode->prev = temp;
    newNode->next = NULL;
}

void deleteNode(struct peop **head,int key){
    struct peop *temp = *head;
    struct peop *prev;
    if(temp != NULL && temp->value == key){
        *head = temp->next;
        free(temp);
        return ;
    }

    while(temp != NULL && temp->value != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)return ;

    prev->next = temp->next;
    (temp->next)->prev = prev;

    free(temp);

}

// <---------------------------------Stack------------------------------------>


struct Stack{
    int item[MAX_SIZE];
    int top;
};


void initialize(struct Stack *stack){
    stack->top = -1;
}

int checkingFullorNot(struct Stack *stack){
    return (stack->top == MAX_SIZE-1);   // Once it is full ,it will return 1;
}                                         //if it is not same ,it will return 0;

void push(struct Stack *stack,int value){
    if(checkingFullorNot(stack)){    // return 1;
        printf("Stack is Full \n");
    }
    else {                // return 0;
        stack->item[++stack->top] =value;
        printf("Value inserted to place ->%d : Value = %d \n",stack->top,stack->item[stack->top]);
    }
}

int checkingeEmptyorNot(struct Stack*stack){
    return (stack->top == -1);
}



int pop (struct Stack*stack){
    if(checkingeEmptyorNot(stack)){  //return 1
        printf("StackunderFlow\n");
        exit(1);
    }

    else {        //return 0
        return stack->item[stack->top--];
    }

}

int peek (struct Stack*stack) {
    if (checkingeEmptyorNot(stack)) {         //return 1
        printf("Stack have no idea\n");
        return -1;
    } else {
        return stack->item[stack->top];
    }
}


//<----stack with linkedlist------>

struct Node {
    int data;
    struct Node* next;
};

struct StackforLinkedList {
    struct Node* top;
};

void initializeStack(struct StackforLinkedList* stack) {
    stack->top = NULL;
}

int isEmpty(struct StackforLinkedList* stack) {
    return (stack->top == NULL);
}

void pushforLinkedList(struct StackforLinkedList* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d\n", stack->top->data);
    printf("New Node pushed!\n");
}

int popforLinkedList(struct StackforLinkedList* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    } else {
        struct Node* temp = stack->top;
        int data = temp->data;
        stack->top = temp->next;
        free(temp);
        return data;
    }
}

//----------------<tree data structure>-----------------
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create_node(int data){

    struct TreeNode* new_node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    if(new_node == NULL){
        printf("Malloc Failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct TreeNode* insert_node(struct TreeNode* root, int data){

    if(root == NULL){
        root = create_node(data);

    } else if(data < root->data){

        root->left = insert_node(root->left, data);
    }else{
        root->right = insert_node(root->right, data);
    }

    return root;
}

struct TreeNode* find_minimum(struct TreeNode* root){
    while (root->left != NULL){

        root = root->left;

    }
    return root;
}


struct TreeNode* delete_node(struct TreeNode* root, int data){

    if(root==NULL){
        return root;
    }

    if(data<root->data){

        root->left = delete_node(root->left, data);
    } else if(data>root->data){
        root->right =  delete_node(root->right, data);
    } else{

        if(root->left == NULL){
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL){
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = find_minimum(root->right); // inorder successor

        root->data = temp->data;

        root->right = delete_node(root->right, temp->data);

    }
    return root;
}

void inorder_traversal(struct TreeNode* root){

    if(root != NULL){
        inorder_traversal(root->left);
        printf("%d\n", root->data);
        inorder_traversal(root->right);
    }

}

//Queue Data Structure

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX_SIZE - 1;     // rear == 9 break
}

void enQueue(int value) {
    if (isFull()) {
        printf("Enqueue is full\n");
    } else {
        front++;
                                     //--->rear = 8
        rear++;                     //--->rear = 9

        for (int i = rear; i > 0; i--) {
            queue[i] = queue[i - 1];
        }

        queue[0] = value;
    }
}

int deQueue() {
    int dequeuedValue;
    if (front == -1 ) {
        printf("Queue is empty\n");
        return -1;
    }
    else if(front>rear){
        printf("Wrong data\n");
        return -1;
    }
    else {

        dequeuedValue = queue[front];
        front--;
        return dequeuedValue;

    }
}

void display() {
    if (rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = 0; i <= front; i++) {     //value of rear = 9
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}


#endif //CLIONPROJECTS_ASSIGNMENT10_H