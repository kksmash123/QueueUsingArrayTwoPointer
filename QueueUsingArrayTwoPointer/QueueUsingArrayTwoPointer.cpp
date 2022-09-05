// QueueUsingArrayTwoPointer - array with two pointer front and rear pointer for deletion and insertion respectively

#include <iostream>

using namespace std;


struct queue
{
	int size;
	int front;
	int rear;
	int* Q;
};

//function declaration 

void enqueue(struct queue* q, int x);
bool IsFull(struct queue* q);
bool IsEmpty(struct queue* q);




//delete element in queue
void dequeue(struct queue* q)
{
	if (IsEmpty(q))
	{
		cout << "Queue is empty can't delete ." << endl;
		return;
	}
	cout<< q->Q[++q->front]<<" deleted from the queue ."<<endl;
	
}


//display
void display(struct queue* q)
{
	if (IsEmpty(q))
	{
		cout << "Queue is empty " << endl;
		return;
	}

	int i =q-> front;
	while (i < q->rear)
		cout << q->Q[++i] << " ";

	cout << endl;

}



//enqueue
void enqueue(struct queue* q ,int x)
{

	//queue full condition check
	if (IsFull(q))
	{
		cout << "Queue is full insertion of "<<x<<" not possible ."<< endl;
		return;
	}

	cout << x << " sucessfully Inserted into the Queue ." << endl;
	q->Q[++q->rear] = x;

}



//queue full condition check
bool IsFull(struct queue* q)
{
	return (q->rear == q->size - 1) ? 1 : 0;
}


//queue empty condition check
bool IsEmpty(struct queue* q)
{
	return (q->front==q->rear) ? 1 : 0;
}




int main()
{
	struct queue q;
	q.size = 3;
	q.front = q.rear = -1;
	q.Q = new int[q.size];


	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);

	display(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	cout << "after deletion " << endl;
	display(&q);
	enqueue(&q, 40);//eventhough the queue is empty we can't occupy that space 

	//here the queue is empty as well as full condition satisfies resetting pointer and circular 
	//queue to overcome this.

}