#include <stdio.h>

#define SIZE 5

int newele[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)){ 
        return 1;
  }
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) {
      return 1;
  }
  return 0;
}

// Adding an num
void enQueue(int num) {
  if (isFull()){
    printf("\n Queue is full!! \n");
  }
  else {
    if (front == -1)
    { 
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    newele[rear] = num;
    printf("\n Inserted -> %d", num);
  }
}

// Removing an num
int deQueue() {
  int num;
  if (isEmpty()) {
    printf("\n Empty Queue \n");
    return (-1);
  } 
  else {
    num = newele[front];

    if (front == rear) {
      front = -1;
      rear = -1;
    } 
   
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Removed num -> %d \n", num);
    return (num);
  }
}

// Printing the queue
void print() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n newele -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", newele[i]);
    }
    printf("%d ", newele[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
  
  deQueue();

  enQueue(1);
  enQueue(2);
  enQueue(5);
  enQueue(6);

  print();
  deQueue();

  print();

  return 0;
}