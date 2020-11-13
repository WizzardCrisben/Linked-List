#include <iostream>
#include <string>
#include <iterator> 
#include <array>
#include "list"
using namespace std;


void showlist(list <string> g);
void swap(string, string);
 
list <string> Pandemics;        //create/instantiate the Pandemics list
list <string> Comorbidities;    //create/instantiate the Comorbidities list
int restoreCount;
int arrSize=3;
string tempValue;

int main()
{
    string arr1[3]={"Spanish Flue", "Ebola", "COVID-19"};
    string arr2[3]={"HIV", "TB", "Cancer"};
    string value;
    
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"This program uses list to manage string elements";
    cout<<"\n------------------------------------------------------------------------------\n"<<endl;
    
    cout<<"Initialising the Pandemics list"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;

    for(int i = 0; i < arrSize; i++){ 
        Pandemics.push_back(arr1[i]);       //initialise the Pandemics list Question 6.1
        cout<<i+1<<". ["<<arr1[i]<<"] added to Pandemics list"<<endl;
    } 
    
    //Displays Pandemics list Question 6.2
    cout<<"\nDisplaying the Pandemics list"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout << "List 1 (Pandemics) has the values: "; 
    showlist(Pandemics); 
  
    cout<<"\nInitialising the Comorbidities list"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    for(int i = 0; i < arrSize; i++){ 
        Comorbidities.push_front(arr2[i]); //initialise the Comorbidities list Question 6.3
        cout<<i+1<<". ["<<arr2[i]<<"] added to Comorbidities list"<<endl;
    }
    
    //Displays Comorbidities list Question 6.4
    cout << "\nList 2 (Comorbidities) has the values: "; 
    showlist(Comorbidities); 
    
    cout<<"\nMerging the Comorbidities list into Pandemics list"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    //merges the Comorbidities list into Pandemics list Question 6.5
    for(int i = 0; i < arrSize; i++){ 
        value=Comorbidities.back();
        Comorbidities.pop_back();        
        Pandemics.push_back(value);
        cout<<value<<" moved from Comorbidities to Pandemics list"<<endl;
    }
    
    //Displays Pandemics list after merge
    cout<<"\nDisplaying the Pandemics list"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout << "\nList 1 (Pandemics) has the values after merge: "; 
    showlist(Pandemics); 
  
    arrSize=Pandemics.size();
    
    //Swapping elements Question 6.6
    cout<<"\nSwapping elements"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    swap("TB", "Ebola");    //Swaps elements in the Pandemics list Question 6.6
    
    cout<<"\nDisplaying the Pandemics list"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout << "\nList 1 (Pandemics) has the values after the swap: "; 
    showlist(Pandemics);        //Displays elements after the Swap Question 6.7
      
    cout<<"\nDisplaying the size of the Pandemics list"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"The size of the Pandemics list is: "<<Pandemics.size()<<endl;	//Question 6.8
    
    cout<<"\n-------------------------------The End------------------------------"<<endl;
        
    return 0;
}


void showlist(list <string> healthList) 
{ 
    list <string> :: iterator iter; 
    for(iter = healthList.begin(); iter != healthList.end(); ++iter) 
        cout << *iter << "    ";
    cout << '\n'; 
} 

void swap(string firstValue, string secondValue){
    //Swap values of the Comorbidities list
    
    restoreCount=0;
    
    for(int i=0; i<arrSize; i++){
        
        tempValue=Pandemics.back();
        
        if(firstValue==tempValue){
            Pandemics.pop_back();        
            Comorbidities.push_back(secondValue);
            cout<<"\nElement "<<tempValue<<" has been found and replaced by "<<secondValue<<"\n\n";
            restoreCount++;
        }else if(secondValue==tempValue){
            Pandemics.pop_back();        
            Comorbidities.push_back(firstValue);
            cout<<"\nElement "<<tempValue<<" has been found and replaced by "<<firstValue<<"\n\n";
            restoreCount++;
            }else{
            cout<<"Element "<<tempValue<<" has been temporarily moved from Pandemics list to the Comorbidities list"<<endl;
            Pandemics.pop_back();        
            Comorbidities.push_back(tempValue);
            restoreCount++;
        }
    }
    
    cout<<"\n\n";
    //Restoring elements into the Pandemics list
    cout<<"Restoring elements from the Comorbidities list into Pandemics list\n";
    for(int i=0; i<restoreCount; i++){
        tempValue=Comorbidities.back();
        Comorbidities.pop_back();
        Pandemics.push_back(tempValue);
        cout<<"Element "<<Pandemics.back()<<" restored from Comorbidities list into Pandemics list"<<endl;
    }
}