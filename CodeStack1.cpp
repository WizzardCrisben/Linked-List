//Student details
//Some of the functionality could have been done using recursive functions
//The program could have also been interactive to allow users to input data and control action, but due to limited time, even the program below would have sufficed

#include <iostream>
#include "stack"
using namespace std;

 
stack <int> Numbers;
stack <int> Temp;

void initialise(int []);
void display();
void remove(int);
void decrement(int, int);
void swap(int, int);

int arrSize=10;
int tempValue;
int restoreCount;


int main()
{
    int arr[arrSize]={55, 46, 90, 39, 20, 13, 56, 100, 20, 77};
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"This program uses two stacks (Numbers and Temp) to manage integer elements";
    cout<<"\n------------------------------------------------------------------------------\n"<<endl;

    
    initialise(arr);    
    display();
    remove(39);
    decrement(110, 10);
    swap(40, 13);
    display();
    return 0;
}



void initialise(int arr[]){
    //Initialising Numbers stack  
    cout<<"\nInitialising the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<arrSize; i++){
        tempValue=arr[i];
        Numbers.push(tempValue);
        cout<<"Value "<<Numbers.top()<<" added into Numbers stack"<<endl;
    }
    
    
}

void display(){
    //Displaying the values of the Numbers stack
    cout<<"\n\nDisplaying the values of the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------\n"<<endl;

    for(int i=0; i<arrSize; i++){
        tempValue=Numbers.top();
        Numbers.pop();
        Temp.push(tempValue);
        cout<<tempValue<<" ";
    }
    
    cout<<"\n\n";
    //Restoring elements into the Numbers stack
    for(int i=0; i<arrSize; i++){
        tempValue=Temp.top();
        Temp.pop();
        Numbers.push(tempValue);
        cout<<"Element "<<Numbers.top()<<" restored from Temp stack into Numbers stack"<<endl;
    }
}

void remove(int value){
    //removing values of the Numbers stack
    cout<<"\n\nRemoving a value from the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------\n"<<endl;
    
    restoreCount=0;
    
    for(int i=0; i<arrSize; i++){
        
        tempValue=Numbers.top();
        
        if(value==tempValue){
            Numbers.pop();
            cout<<"\nElement "<<tempValue<<" has been found and permanently deleted from Numbers stack";
            i=arrSize;
            arrSize=arrSize-1;
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

void decrement(int stackValue, int value){
    //Decrementing values of the Numbers stack
    cout<<"\n\nDecrementing a value from the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------\n"<<endl;
    
    restoreCount=0;
    
    for(int i=0; i<arrSize; i++){
        
        tempValue=Numbers.top();
        
        if(stackValue==tempValue){
            Numbers.pop();
            tempValue=tempValue-value;
            Numbers.push(tempValue);
            cout<<"\nElement "<<stackValue<<" has been found and decremented by "<<value<<" to "<<tempValue;
            i=arrSize;
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

void swap(int firstValue, int secondValue){
    //Swap values of the Numbers stack
    cout<<"\n\nSwap values from the Numbers stack"<<endl;
    cout<<"------------------------------------------------------------------------------\n"<<endl;
    
    restoreCount=0;
    
    for(int i=0; i<arrSize; i++){
        
        tempValue=Numbers.top();
        
        if(firstValue==tempValue){
            Numbers.pop();
            Temp.push(secondValue);
            cout<<"\nElement "<<tempValue<<" has been found and replaced by "<<secondValue<<"\n\n";
            // i=arrSize;
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