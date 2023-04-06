#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace std::chrono;

struct Stack{
    
    int top=-1;
    int size;
    int arr[];

    public:

    Stack(int size){
        this->arr[size];
        this->size = size;
        return;
    }
    void Push(int value){
        if(this->isFull()){
            printf("\nStack OverFlow");
        }
        else{
            this->top+=1;
            this->arr[this->top]=value;
            
        }
        return;
    }
    int Pop(){
        if(this->isEmpty()){
            printf("\nStack UnderFlow");
            return -9999;
        }
        else{
            int TopValue = this->arr[this->top];
            this->top -=1;
            return TopValue;
        }
    }
    bool isEmpty(){
        if(this->top==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(this->top>=this->size-1){
            return true;
        }
        return false;
    }
    int StackTop(){
        return this->top;
    }
    void Display(){
        
        cout<<endl<<"[ ";
        for(int i=this->top;i>=0;i--){
            if(i==0){
                cout<<this->arr[i];
            }
            else{
            cout<<this->arr[i]<<" , ";
            }
        }
        cout<<" ]";
        return;
    }

};


int main(){


    auto start = high_resolution_clock::now();
    
   

    Stack myStack(20) ;
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