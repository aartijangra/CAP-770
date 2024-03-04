#include <iostream>
#define SIZE 10
using namespace std;
class Queue
{	int front=-1;
	int rear=-1;
	public:
	void enqueue(int queue[],int);
	void dequeue(int queue[],int);
	void display(int queue[]);
	
};
int main()
	{   Queue obj; 
		while(true)
		{
			int choice,queue[SIZE];
			cout<<"Press 1 to insert the element"<<endl;
			cout<<"Press 2 to delete the element"<<endl;
			cout<<"Press 3 to display"<<endl;
			cout<<"Press 4 to exit"<<endl;
			cout<<"Enter the choice from the above menu:";
			cin>>choice;
			
			switch (choice)
			{
				case 1: obj.enqueue(queue,SIZE);
					break;
				case 2: obj.dequeue(queue,SIZE);
					break;
				case 3: obj.display(queue);
					break;
				case 4: exit(0);
				
				default: "Sorry!! you have entered wrong choice";
	
			}
		}
		return 0;
    }

void Queue::enqueue(int queue[],int n)		
{
	int value;
	cout<<"Enter the value to push:";
	cin>>value;
	if(rear==-1)
	{   rear++;
	    front++;
	    queue[rear]=value;
	    cout<<endl<<value<<endl<<"has been inserted in the queue"<<endl;
	}
	else
	{
	    if(rear==n-1)
	    {
		    cout<<"Queue Overflow";
	    }
	    else
	    {
		    rear++;
		    queue[rear]=value;
		    cout<<endl<<value<<endl<<"has been inserted in the queue"<<endl;
	    }

    }
}
void Queue::dequeue(int queue[],int n)
{
	if((front==-1)||(front>rear))
	{
		cout<<"Queue underflow"<<endl;
	}
	else
	{
		cout<<"The deleted element from the queue is:"<<queue[front]<<endl;
		front=front+1;
	}
} 
void Queue::display(int queue[])
{
	for(int j=front;j<=rear;j++)
	{
		cout<<queue[j]<<endl;
	}
}

