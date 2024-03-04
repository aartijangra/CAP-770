#include<iostream>
# define SIZE 50
using namespace std;
class Stack{
    public:
    void push();
    void pop();
    void display();
    int top;
    int stack[SIZE];
    Stack(){
        stack[SIZE];
        top=-1;
    }
};

int main()
{   
    Stack obj;
    while(true){
        int choice;
        cout<<"Enter 1 to push into the stack"<<endl;
        cout<<"Enter 2 to pop from the stack"<<endl;
        cout<<"Enter 3 to display the stack"<<endl;
        cout<<"enter 4 to exit"<<endl;
        cout<<"Enter the choice from the above menu:"<<endl;
        cin>>choice;
        switch(choice){
            case 1: obj.push();
                break;
            case 2: obj.pop();
                break;
            case 3: obj.display();
                break;
                case 4: exit(0);
            
            default: "Sorry!! you entered wrong choice";
        }

    }
    return 0;

}
void Stack::push(){
    int num;
    cout<<"enter the number to push in stack"<<endl;
    cin>>num;
    if(top == SIZE-1) cout<<"Stack Overflow"<<endl;

    else{
        top++;
        stack[top] = num;
    }

} 
void Stack::pop(){
    if(top==-1) cout<<"stack underflow"<<endl;
    else{
        cout<<"the deleted element from the stack is"<<stack[top]<<endl;
        top=top-1;
    }
}
void Stack::display(){
    for(int i=top; i>=0; i--){
        cout<<stack[i]<<" "<<endl;
    }
}