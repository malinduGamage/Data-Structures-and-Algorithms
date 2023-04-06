#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace std::chrono;
  

class Node {
public:
    int data;
    Node* next;
    
    
    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};
  
class Stack {
    Node* top;
  
public:
    Stack() { top = NULL; }
  
    void Push(int data)
    {
  
        
        Node* temp = new Node(data);
  
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
  
        
        temp->data = data;
  
        temp->next = top;
  
        
        top = temp;
    }
  
    bool isEmpty()
    {
        
        return top == NULL;
    }
  
   
    int StackTop()
    {
        
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }
  
    
    void Pop()
    {
        Node* temp;
  
        
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            return;
        }
        else {
  
        
            temp = top;
  
            top = top->next;
  
            free(temp);
        }
    }
  
    
    void Display()
    {
        Node* temp;
  
        
        if (top == NULL) {
            cout << "\nStack Underflow";
            return;
        }
        else {
            temp = top;
            while (temp != NULL) {
  
                
                cout << temp->data;
  
                
                temp = temp->next;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};
  

int main()
{
    
    Stack myStack;
  auto start = high_resolution_clock::now();

    myStack.Push(8);
    myStack.Push(10);
    myStack.Push(5);
    myStack.Push(11);
    myStack.Push(15);
    myStack.Push(23);
    myStack.Push(6);
    myStack.Push(18);
    myStack.Push(20);
    myStack.Push(17);
    myStack.Display();
    myStack.Pop() ;
    myStack.Display();
    myStack.Push(4);
    myStack.Push(30);
    myStack.Push(3);
    myStack.Push(1);
    myStack.Display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"\n\ntime : " << duration.count()<<" ms";
  
    return 0;
}