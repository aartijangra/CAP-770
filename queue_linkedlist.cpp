# include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
	Node(int value)
	{
		this->data=value;
		this->next=NULL;
	}
};

class Queue
{
	Node *front;
	Node *rear;
	public:
	Queue()
	{
		front=NULL;
		rear=NULL;
	}
	void enqueue();
	void dequeue();
	void display();
};

int main()
{
	int choice;
	Queue Qu; 
	do
	{
		cout<<"\nMenu "<<endl;
		cout<<"press 1. To push element in the Queue \n";
		cout<<"press 2. To display element of Queue \n";
		cout<<"press 3. to delete element from a Queue\n";
		cout<<"press 4. to exit\n";
		cout<<"\n enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				Qu.enqueue();
				break;
			case 2:
				Qu.display();
				break;
			case 3:
				Qu.dequeue();
				break;
			
			case 4:
				break;
			default:
				cout<<"you have enterd wrong choice \n";
		}
	}while(choice!=4);
}
	


void Queue::enqueue()
{
	int info;
	cout<<"Enter elements in the queue:";
	cin>>info;
	Node *newnode= new Node(info);
	//if(front==NULL &&rear==NULL)
	if(rear==NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
	
}
void Queue::dequeue()
{
	Node *temp;
	if(front==NULL)
	{
		cout<<"Sorry the queue is empty";
	}
	else if(front==rear)//There is only one node
	{
		temp=front;
		cout<<front->data<<" is going to be deleted from the queue";
		delete(temp);
		front=NULL;
		rear=NULL;
	}
	else
	{
		temp=front;
		cout<<front->data<<"is going to be deleted from the queue";
		front=front->next;
		delete(temp);
	}
	display();
	
}
void Queue::display()
{
	Node *temp=front;
	if(front==NULL)
	{
		cout<<"\n Queue is empty, there is no Node to display";
	}
	else
	{
	    cout<<"\n elements in the queue are as follows:\n";
		/*while(temp!=rear)
		{
		cout<<temp->data<<"\t";
		temp=temp->next;
		}
		cout<<rear->data;*/

		while(temp!=NULL)
		{
		cout<<temp->data<<"\t";
		temp=temp->next;
		}

	}

}
	

