#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#define ll long long
#define INF 2147483647
#define LINF ((1LL << 62) - (1LL << 31))
#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define lrep(i, n) for (ll i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(a, b) { int temp = a; a = b; b = temp; }
#define lswap(a, b) { ll temp = a; a = b; b = temp; }

void debug(char*s,...){
  va_list arg;
  printf(s,*arg);
  puts("");
}

typedef struct {
  int front,rear,size,capacity;
  int*array;
} Queue;

Queue*createQueue(int capacity){
  Queue*queue=(Queue*)malloc(sizeof(Queue));
  queue->capacity=capacity;
  queue->front=queue->size=0;
  queue->rear=capacity-1;
  queue->array=(int*)malloc(queue->capacity*sizeof(int));
  return queue;
}

bool isFull(Queue*queue){
  return (queue->size==queue->capacity);
}

bool isEmpty(Queue*queue){
  return (queue->size==0);
}

void enqueue(Queue*queue,int item){
  if(isFull(queue)){
    return;
  }
  queue->rear=(queue->rear+1)%queue->capacity;
  queue->array[queue->rear]=item;
  queue->size+=1;
  debug("%d enqueued to queue", item);
}

int dequeue(Queue*queue){
  if(isEmpty(queue)){
    return -INF;
  }
  int item=queue->array[queue->front];
  queue->front=(queue->front+1)%queue->capacity;
  queue->size=queue->size-1;
  return item;
}

int front(Queue*queue){
  if(isEmpty(queue)){
    return -INF;
  }
  return queue->array[queue->front];
}

int rear(Queue*queue){
  if(isEmpty(queue)){
    return -INF;
  }
  return queue->array[queue->rear];
}

int main() {
  Queue*queue=createQueue(1000);

  enqueue(queue,10);
  enqueue(queue,20);
  enqueue(queue,30);
  enqueue(queue,40);

  debug("%d dequeued from queue\n",dequeue(queue));

  debug("Front item is %d", front(queue));
  debug("Rear item is %d", rear(queue));

  free(queue);
  return 0;
}
