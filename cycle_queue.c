/**
 * @file cycle_queue.c
 * @brief  the arr form of the cycle queue
 * also have another two way to the queue one is the list another is instaition
 * @author tmd
 * @version 1.0
 * @date 2016-11-20
 */
#include<stdio.h>
#include<stdlib.h>
#define ARR_LEN 4
typedef struct node{
	int head;
	int tail;
	int *arr;
	int count;
}Queue;
void init(Queue* queue){
	if(queue == NULL)
		return ;
	queue->head = queue->tail =0;
	queue->arr = (int*)malloc(sizeof(int)*ARR_LEN);
	queue->count = 0;
	return;
}

static int is_empty(Queue* queue){
	if(queue->head == queue->tail){
		return 0;	
	}
	return 1;
}
static int is_full(Queue* queue){
	if(queue->head == (queue->tail + 1) % ARR_LEN){
		return 0;	
	}
	return 1;
	
}
int enqueue(Queue* queue, int value){
	if(queue == NULL)
		return -1;
	if(0 == is_full(queue)){
		return -1;	
	}
	queue->arr[queue->tail] = value;
	if(queue->tail == ARR_LEN - 1){
		queue->tail = 0;	
	}else{
		queue->tail++;	
	}
	queue->count++;
	return 0;
}
int dequeue(Queue* queue){
	if(queue == NULL)	
		return -1;
	if(0 == is_empty(queue))
		return -1;
	int i = queue->arr[queue->head];
	if(queue->head == ARR_LEN -1){
		queue->head = 0;	
	}else{
		queue->head++;	
	}
	queue->count--;
	return i;
}
void show(Queue* que){
	if(que == NULL)
		return ;
	int i;
	for(i=0;i<ARR_LEN;i++){
		printf("%d\n",que->arr[i]);	
	}
	printf("-------\n");
	return ;
}
//alse have the free queue
//void Free(Queue* que);
int main()
{
	int i;
	Queue* que = (Queue*)malloc(sizeof(Queue));
	init(que);
	enqueue(que,0);
	enqueue(que,1);
	enqueue(que,2);
	enqueue(que,3);
	i = dequeue(que);
	printf("out is %d\n",i);
	enqueue(que,4);
	show(que);
	

	//Free(que);
	return 0;
}

