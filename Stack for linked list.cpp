#include<iostream>
using namespace std;

struct Linked_List
{
	int data;
	Linked_List * next;
};

class Stackforlist
{
		Linked_List* top; // address of node
	public:
		Stackforlist()
		{
			top==NULL;
		}
		
		void Push(int value)
		{
			if(top==NULL)
			{
				top=new Linked_List;
				top->data=value;
				top->next=NULL;
			}
			else
			{
				Linked_List* current=top;
				while(current->next!=NULL)
				{
					current=current->next;
				}
				Linked_List* temp=new Linked_List;
				current->next=temp;
				temp->data=value;
				temp->next=NULL;
			}
		}
		
		int Pop()
		{
			Linked_List* current=top;
			if(top==NULL)
			{
				cout<<"Stack is empty ";
				return NULL;
			}
			Linked_List* perivious=current;
			
			while(current->next!=NULL)
			{
				perivious=current;
				current=current->next;
			}
			perivious->next=NULL;
			int value=current->data;
			delete current;
			return value;
		}
		
		void push1(int value)
		{
			if(top==NULL)
			{
				top=new Linked_List;
				top->data=value;
				top->next=NULL;
			}
			else
			{
				Linked_List* current=new Linked_List;
				current->next=top;
				current->data=value;
				top=current;
				//delete current;
			}
			
		}
int pop1()
{
    if (top == NULL)
    {
        // Handle underflow (stack is empty)
        // You can choose an appropriate way to handle this, such as returning an error code or throwing an exception.
        return -1; // You can choose an appropriate error value
    }
    else
    {
        int poppedValue = top->data;   
        Linked_List* temp = top;       
        top = top->next;              
        delete temp;                  
        return poppedValue;           // Return the popped value
    }
}
		int Top()
		{
			if(top==NULL)
			{
				cout<<"Stack is empty ";
				return NULL;
			}
			else
			{
				return top->data;
			}
		}
		
		bool is_Empty()
		{
			if(top==NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		void show()
		{
			Linked_List* current=top;
			if(top==NULL)
			{
				cout<<"Stack is empty ";
				return;
			}
			Linked_List* perivious=current;
			
			while(current!=NULL)
			{
				cout<<current->data<<" ";
				current=current->next;
			}
			cout<<endl;
		}		
};

int main()
{
	 Stackforlist st;
	 st.push1(1);
	 st.push1(2);
	 st.push1(3);
	 st.show();
	 cout<<"Before Pop function "<<endl;
	 st.pop1();
	 st.show();
	 cout<<"After POP function ";
	 cout<<endl;
	 cout<<"Top element "<<st.Top();
	 cout<<endl;
	 cout<<"Calling Empty Function"<<st.is_Empty();
	 return 0;
}
