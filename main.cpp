/******************************************************************************

Bridget Naylor
Date:11/20/2020
Lab: Lab 6

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

//Partition code taken from my Lab 3 for Quick Select
int partitionAscending( int a[], int start, int end)
{
    if ( start == end )
    {
        return start;
    }
    
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
        if ( leftPivIndex < start )
        {
            //do stuff for left side
            goLeft = false;
        }
        if ( rightPivIndex > end )
        {
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
        leftPivIndex --;
        rightPivIndex ++;
    }
    
    return midIndex;
}

int partitionDescending( int a[], int start, int end)
{
    cout<<"end: "<<end;
    cout<<"In partition descending "<<endl;
    for ( int i = 0; i < end; i++)
    {
        cout<<"a "<< a[i]<<endl;
    }
    if ( start == end )
    {
        return start;
    }
    
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
        if ( leftPivIndex < start )
        {
            //do stuff for left side
            goLeft = false;
        }
        if ( rightPivIndex > end )
        {
            //do stuff for left side
            goRight = false;
        }
        if ( goLeft && goRight && a[leftPivIndex] < piv && a[rightPivIndex] > piv )//if emlent on left and right need switching switch
        {
            cout<<"double switch"<<endl;
            int temp = a[leftPivIndex];
            a[leftPivIndex] = a[rightPivIndex];
            a[rightPivIndex] = temp;
        }
        else if ( goRight && (a[rightPivIndex] > piv) && a[rightPivIndex] < 21 )//only switch right
        {
            cout<<"right switch"<<endl;
            cout<<"pivPlusOne a[midIndex + 1] "<<(a[midIndex + 1])<<endl;
            cout<<"middle Index "<<midIndex<<endl;
            cout<<"a[rightPivIndex] "<<(a[rightPivIndex])<<endl;
            cout<<"rightPivIndex "<<rightPivIndex<<endl;
            int pivPlusOne = a[midIndex + 1];
            a[midIndex + 1] = a[rightPivIndex];
            a[rightPivIndex] = pivPlusOne;
            
            //switches piv and element to the right of piv
            int pivValue = a[midIndex];
            a[midIndex] = a[midIndex + 1];
            a[midIndex + 1] = pivValue;
            
            midIndex++;
            
        }
        else if ( goLeft && (a[leftPivIndex] < piv) )//only switch left
        {
            cout<<"left switch"<<endl;
            cout<<"pivMinusOne a[midIndex - 1] "<<(a[midIndex - 1])<<endl;
            cout<<"middle Index "<<midIndex<<endl;
            cout<<"a[leftPivIndex] "<<(a[leftPivIndex])<<endl;
            cout<<"leftPivIndex "<<leftPivIndex<<endl;
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
        leftPivIndex --;
        rightPivIndex ++;
    }
    
    return midIndex;
}

void quickSortAscending( int a[], int start, int end )
{
    if ( start < end )
    {
        int index = partitionAscending( a, start, end );
        
        quickSortAscending( a, start, index - 1 );//before pi
        quickSortAscending( a, index + 1, end);//after pi
        
    }
}

void quickSortDescending( int a[], int start, int end )
{
    // cout<<"in sort descending "<<endl;
    // for ( int i = 0; i < end; i++)
    // {
    //     cout<<"a "<< a[i]<<endl;
    // }
    if ( start < end )
    {
        int index = partitionDescending( a, start, end  );
        
        quickSortDescending( a, start, index - 1 );//before pi
        quickSortDescending( a, index + 1, end);//after pi
        
    }
}


//sort sL in ascending order
//sort sR in descending order
void divideArray( int a[], int sL[], int sR[], int size )
{
    int itrL = 0;
    int itrR = 0;
    bool odd = false;
    if ( size % 2 != 0 )
    {
        odd = true;
    }
    //split a into 2 subarrays 
    for ( int i = 0; i < size; i++ )
    {
        if ( (i < (size / 2) && !odd) || ( i < ((size / 2) + 1) && odd ) )
        {
            //cout<<"hereL"<<endl;
            sL[itrL] = a[i];
            itrL++;
        }
        else
        {
            //cout<<"hereR"<<endl;
            sR[itrR] = a[i];
            itrR++;
        }
    }
    cout<<"Testing Original Values "<<endl;
    if ( odd )
    {
        for ( int i = 0; i < (size/ 2) + 1; i++)
        {
            cout<<"sL "<< sL[i]<<endl;
        }
        quickSortAscending( sL, 0, (size / 2) + 1 );
        for ( int i = 0; i < size/ 2; i++)
        {
            cout<<"sR "<< sR[i]<<endl;
        }
    }
    else 
    {
        for ( int i = 0; i < (size/ 2) ; i++)
        {
            cout<<"sL "<< sL[i]<<endl;
        }
        quickSortAscending( sL, 0, size / 2 );
        for ( int i = 0; i < size/ 2; i++)
        {
            cout<<"sR "<< sR[i]<<endl;
        }
    }
    
    cout<<"Testing Values after Sort"<<endl;
    
    quickSortDescending( sR, 0, size / 2 );
    if ( odd )
    {
        for ( int i = 0; i < (size/ 2) + 1; i++)
        {
            cout<<"sL "<< sL[i]<<endl;
        }
        
        for ( int i = 0; i < size/ 2; i++)
        {
            cout<<"sR "<< sR[i]<<endl;
        }
    }
    else 
    {
        for ( int i = 0; i < (size/ 2) ; i++)
        {
            cout<<"sL "<< sL[i]<<endl;
        }
        
        for ( int i = 0; i < size/ 2; i++)
        {
            cout<<"sR "<< sR[i]<<endl;
        }
    }
    
}


int main()
{
    //Input code taken from my Lab 3 for Quick Select
    int size = 0;
    while ( size < 3)
    {
        cout<<"Enter a list great than 3: ";
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
    
    if ( size % 2 == 0 )
    {
        int sL[size/2];
        int sR[size/2];
        divideArray( a, sL, sR, size );
    }
    else
    {
        int sL[(size/2) + 1];
        int sR[size/2];
        divideArray( a, sL, sR, size );
    }
    
    
    
    return 0;
}

