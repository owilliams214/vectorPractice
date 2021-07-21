
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void timesTable();
void sortVector();

int main()
{
    cout << "CT326 Midterm Project - Dr. Zhang" << endl;
    
    cout << "Hello World - From Alcorn" << endl;
    char answer;
    do{
        
        
        
        cout << "Command; t for [times table]: s for [square root]: q to[quit program]: ";
        cin >> answer;
        
        if (answer == 't') timesTable();
        else if (answer == 's') sortVector();
        
    }while (answer != 't' && answer != 's');
    
    ifstream file("sortedNumbers.txt");
    string content;
    
    if (file.is_open())
    {
    
    while(getline(file, content)) {
        cout << content << endl;
    }
    }
    
    else {
        cout << "Unable to open file" << endl;
    }
    
    file.close();
    
    
    system("pause");
    return 0;
    
}

void timesTable()
{
    for (int first = 1; first <= 12; first++)
    {for (int second = 1; second <= first; second++)
    {cout << first << " X " << second << "=" <<
        first * second << " \t";}
        cout << endl;
    }
    
    
}

void sortVector()
{
    int numbers[50];
    int count = 0;
    int num;
    do
    {
        cout << "Enter a number.  Enter -1 to stop entering numbers: ";
        cin >> num;
        
        
        if (num!= -1)
        {
            numbers[count++] = num;
        }
        
    }while(num != -1);
    
    /*for (int cindex = 0; cindex < count; cindex++)
    {
        int smallest = numbers[cindex];
        int found = cindex;
        for (int findex = cindex + 1; findex < count; findex++)
        {
            if (numbers[findex] < smallest)
            {
                smallest = numbers[findex];
                found = findex;
            }
            
            if (found != cindex){
            numbers[found]= numbers[cindex];
            numbers[cindex] = smallest;
            }
        }
    }*/
    
    bool notSwap = 1;
    int swapIndex = 0;
    do
    {
        if (numbers[swapIndex] > numbers[swapIndex+1] && swapIndex + 1 < count)
            {
                int temp = numbers[swapIndex+1];
                numbers[swapIndex+1] = numbers[swapIndex];
                numbers[swapIndex] = temp;
                notSwap = 0;
            }
            
        swapIndex++;
            
        if (swapIndex == count && notSwap == 0)
            {
                swapIndex = 0;
                notSwap = 1;
            }
            
            
            }while (!(swapIndex == count && notSwap == 1));
   //for (int index = 0; index < count; index++)
    //{cout << numbers[index] << " ";}
    
    
    cout << numbers[0] << " " << numbers[count/2] << " " <<
    numbers[count-1] << endl;
    
    
    ofstream myfile ("sortedNumbers.txt");
    //myfile.open;
    
    
   if (myfile.is_open())
    {
   myfile << numbers[0] << " " << numbers[count/2] << " " << numbers[count-1] << endl;
  }
    
    else {
        cout << "Unable to open file" << endl;
    }
    
    myfile.close();
    
    
}






