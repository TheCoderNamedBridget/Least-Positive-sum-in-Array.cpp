/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

//Partition code taken from my Lab 3 for Quick Select
int partition( int a[], int start, int end)
{
    cout<<"start "<<start<<" end "<<end<<endl;
    if ( start == end )
    {
        return start;
    }
    
    //cout<<"parts "<<start<<" e "<<end<<endl;
    int pivIndex = start;
    int midIndex = start + (end - start)/2;

    bool goLeft = true;
    bool goRight = true;
    
    int piv = a[pivIndex];
    a[start] = a[midIndex];
    a[midIndex] = piv;
    int leftPivIndex = midIndex - 1;
    int rightPivIndex = midIndex + 1;
    for ( int k = start; k < end; k ++ )
    {
        //cout<<"Herefor"<<endl;
        if ( leftPivIndex < start )
        {
            //cout<<"Hereleft"<<endl;
            //do stuff for left side
            goLeft = false;
        }
        if ( rightPivIndex > end )
        {
            //cout<<"Hereright"<<endl;
            //do stuff for left side
            goRight = false;
        }
        if ( goLeft && goRight && a[leftPivIndex] > piv && a[rightPivIndex] < piv )//if emlent on left and right need switching switch
        {
            //cout<<"double switch"<<endl;
            int temp = a[leftPivIndex];
            a[leftPivIndex] = a[rightPivIndex];
            a[rightPivIndex] = temp;
        }
        else if ( goRight && (a[rightPivIndex] < piv) )//only switch right
        {
            int pivPlusOne = a[midIndex + 1];
            a[midIndex + 1] = a[rightPivIndex];
            a[rightPivIndex] = pivPlusOne;
            
            //switches piv and element to the right of piv
            int pivValue = a[midIndex];
            a[midIndex] = a[midIndex + 1];
            a[midIndex + 1] = pivValue;
            
            midIndex++;
            
        }
        else if ( goLeft && (a[leftPivIndex] > piv) )//only switch left
        {
            //cout<<"left switch"<<endl;
            //switches element to left of piv with other left element <> piv
            int pivMinusOne = a[midIndex - 1];
            a[midIndex - 1] = a[leftPivIndex];
            a[leftPivIndex] = pivMinusOne;
            
            //switches piv and element to the right of piv
            int pivValue = a[midIndex];
            a[midIndex] = a[midIndex - 1];
            a[midIndex - 1] = pivValue;
            
            midIndex--;
        }
        // cout<<"11piv index "<<midIndex<<" piv value "<<piv<<endl;
        // cout<<"11element index "<<midIndex + 1<<" element value "<<a[midIndex + 1]<<endl;
        // cout<<"goRight "<<goRight<<endl;
        // cout<<"(a[rightPivIndex] < piv) "<<(a[rightPivIndex] < piv)<<endl;
        leftPivIndex --;
        rightPivIndex ++;
    }
    
    // for ( int i = 0; i < size; i++)
    // {
    //     cout<<"in partition "<<a[i]<<endl;
    // }
    
    return midIndex;
}


int main()
{
    //Input code taken from my Lab 3 for Quick Select
    int size = 0;
    while ( size < 1)
    {
        cout<<"Enter a positive non zero integer: ";
        cin >> size;
    }
    
    int a[size];
    
    srand (time(NULL));
    for ( int i = 0; i < size; i++ )
    {
        int posOrNeg = rand() % 2 + 1;
        int posNum = rand() % 21;//0 - 20
        int negNum = rand() % 21 -20;//-20 - -1
        //cout<<"posOrNeg "<<posOrNeg<<endl;
        //cout<<"posNum "<<posNum<<endl;
        //cout<<"negNum "<<negNum<<endl;
        if ( posOrNeg == 2 )//posOrNeg = 2 +> do pos
        {
            a[i] = posNum;
        }
        else//do neg
        {
            a[i] = negNum;
        }
    }
    for ( int j = 0; j < size; j++)
    {
        cout<<"a[j] in main "<<a[j]<<endl;
    }

    return 0;
}

