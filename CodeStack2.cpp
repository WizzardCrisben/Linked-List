#include <iostream>
#include "stack"
using namespace std;

 
stack <int> Numbers;
stack <int> Temp;

void initialise();
void display();
void remove();
void decrement();
void swap();


int tempValue;
int restoreCount;
int control=0;
int count=0;
int value;
int firstValue;
int secondValue;
int stackValue;


int main()
{
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"This program uses two stacks (Numbers and Temp) to manage integer elements";
    cout<<"\n------------------------------------------------------------------------------\n"<<endl;
    
    do{
        
        cout<<"\nEnter appropriate action"<<endl;
        cout<<"1 to push"<<endl;
        cout<<"2 to pop"<<endl;
        cout<<"3 to display"<<endl;
        cout<<"4 to decrement"<<endl;
        cout<<"5 to swap"<<endl;
        cout<<"-1 to exit"<<endl;
        cout<<"Option: ";
        cin>>control;
        
        switch(control){
         
         case 1:
         initialise();
         break;
         
         case 2:
         remove();
         break;
         
         case 3:
         display();
         break;
         
         case 4:
         decrement();
         break;
         
         case 5:
         swap();
         break;
         default:
            cout<<"Invalid entry. Please try again."<<endl;
            
        }
        
    }while(control!=-1);
    
    
     
    return 0;
}



void initialise(){
    //Initialising Numbers stack  
    cout<<"\nPushing elements into the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
       
    cout<<"Enter element to push into stack: ";
    cin>>tempValue;
    count++;
    Numbers.push(tempValue);
    cout<<"Value "<<Numbers.top()<<" added into Numbers stack"<<endl;
}

void display(){
    //Displaying the values of the Numbers stack
    cout<<"\n\nDisplaying the values of the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------\n"<<endl;

    for(int i=0; i<count; i++){
        tempValue=Numbers.top();
        Numbers.pop();
        Temp.push(tempValue);
        cout<<tempValue<<" ";
    }
    
    cout<<"\n\n";
    //Restoring elements into the Numbers stack
    for(int i=0; i<count; i++){
        tempValue=Temp.top();
        Temp.pop();
        Numbers.push(tempValue);
        cout<<"Element "<<Numbers.top()<<" restored from Temp stack into Numbers stack"<<endl;
    }
}

void remove(){
    //removing values of the Numbers stack
    cout<<"\n\nRemoving a value from the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------\n"<<endl;
    cout<<"Enter value to pop: ";
    cin>>value;
    
    restoreCount=0;
    
    for(int i=0; i<count; i++){
        
        tempValue=Numbers.top();
        
        if(value==tempValue){
            Numbers.pop();
            cout<<"\nElement "<<tempValue<<" has been found and permanently deleted from Numbers stack";
            i=count;
            count=count-1;
        }else{
            cout<<"Element "<<tempValue<<" has been temporarily moved from Numbers stack to Temp stack"<<endl;
            Numbers.pop();
            Temp.push(tempValue);
            restoreCount++;
        }
    }
    
    cout<<"\n\n";
    //Restoring elements into the Numbers stack
    for(int i=0; i<restoreCount; i++){
        tempValue=Temp.top();
        Temp.pop();
        Numbers.push(tempValue);
        cout<<"Element "<<Numbers.top()<<" restored from Temp stack into Numbers stack"<<endl;
    }
}

void decrement(){
    //Decrementing values of the Numbers stack
    cout<<"\n\nDecrementing a value from the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------\n"<<endl;
    cout<<"Enter value in stack to be decremented: ";
    cin>>stackValue;
    cout<<"Enter value by which to decrement element in stack: ";
    cin>>value;
    
    restoreCount=0;
    
    for(int i=0; i<count; i++){
        
        tempValue=Numbers.top();
        
        if(stackValue==tempValue){
            Numbers.pop();
            tempValue=tempValue-value;
            Numbers.push(tempValue);
            cout<<"\nElement "<<stackValue<<" has been found and decremented by "<<value<<" to "<<tempValue;
            i=count;
        }else{
            cout<<"Element "<<tempValue<<" has been temporarily moved from Numbers stack to Temp stack"<<endl;
            Numbers.pop();
            Temp.push(tempValue);
            restoreCount++;
        }
    }
    
    cout<<"\n\n";
    //Restoring elements into the Numbers stack
    for(int i=0; i<restoreCount; i++){
        tempValue=Temp.top();
        Temp.pop();
        Numbers.push(tempValue);
        cout<<"Element "<<Numbers.top()<<" restored from Temp stack into Numbers stack"<<endl;
    }
}

void swap(){
    //Swap values of the Numbers stack
    cout<<"\n\nSwap values from the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------\n"<<endl;
    cout<<"Enter first value to swap in stack: ";
    cin>>firstValue;
    cout<<"Enter second value to swap with in stack: ";
    cin>>secondValue;
    
    
    restoreCount=0;
    
    for(int i=0; i<count; i++){
        
        tempValue=Numbers.top();
        
        if(firstValue==tempValue){
            Numbers.pop();
            Temp.push(secondValue);
            cout<<"\nElement "<<tempValue<<" has been found and replaced by "<<secondValue<<"\n\n";
            // i=count;
            restoreCount++;
        }else if(secondValue==tempValue){
            Numbers.pop();
            Temp.push(firstValue);
            cout<<"\nElement "<<tempValue<<" has been found and replaced by "<<firstValue<<"\n\n";
            restoreCount++;
            }else{
            cout<<"Element "<<tempValue<<" has been temporarily moved from Numbers stack to Temp stack"<<endl;
            Numbers.pop();
            Temp.push(tempValue);
            restoreCount++;
        }
    }
    
    cout<<"\n\n";
    //Restoring elements into the Numbers stack
    cout<<"Restoring elements from the Temp stack into Numbers stack\n";
    for(int i=0; i<restoreCount; i++){
        tempValue=Temp.top();
        Temp.pop();
        Numbers.push(tempValue);
        cout<<"Element "<<Numbers.top()<<" restored from Temp stack into Numbers stack"<<endl;
    }
}