/******************************************************************************

Bridget Naylor
Date:11/20/2020
Lab: Lab 6

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

//Partition code taken from my Lab 3 for Quick Select
int partitionAscending( double a[], int start, int end)
{
    // cout<<"end: "<<end;
    // cout<<"In partition ascending "<<endl;
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
    
    double piv = a[pivIndex];
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
            // cout<<"double switch"<<endl;
            // cout<<"a[leftPivIndex] "<<(a[leftPivIndex])<<endl;
            // cout<<"leftPivIndex "<<leftPivIndex<<endl;
            // cout<<"a[rightPivIndex] "<<(a[rightPivIndex])<<endl;
            // cout<<"rightPivIndex "<<rightPivIndex<<endl;
            double temp = a[leftPivIndex];
            a[leftPivIndex] = a[rightPivIndex];
            a[rightPivIndex] = temp;
        }//
        else if ( goRight && (a[rightPivIndex] < piv)  )//only switch right
        {
            // cout<<"right switch"<<endl;
            // cout<<"pivPlusOne a[midIndex + 1] "<<(a[midIndex + 1])<<endl;
            // cout<<"middle Index "<<midIndex<<endl;
            // cout<<"a[rightPivIndex] "<<(a[rightPivIndex])<<endl;
            // cout<<"rightPivIndex "<<rightPivIndex<<endl;
            
            double pivPlusOne = a[midIndex + 1];
            a[midIndex + 1] = a[rightPivIndex];
            a[rightPivIndex] = pivPlusOne;
            
            //switches piv and element to the right of piv
            double pivValue = a[midIndex];
            a[midIndex] = a[midIndex + 1];
            a[midIndex + 1] = pivValue;
            
            midIndex++;
            
        }
        else if ( goLeft && (a[leftPivIndex] > piv)  )//only switch left
        {
            // cout<<"left switch"<<endl;
            // cout<<"pivMinusOne a[midIndex - 1] "<<(a[midIndex - 1])<<endl;
            // cout<<"middle Index "<<midIndex<<endl;
            // cout<<"a[leftPivIndex] "<<(a[leftPivIndex])<<endl;
            // cout<<"leftPivIndex "<<leftPivIndex<<endl;
            //switches element to left of piv with other left element <> piv
            double pivMinusOne = a[midIndex - 1];
            a[midIndex - 1] = a[leftPivIndex];
            a[leftPivIndex] = pivMinusOne;
            
            //switches piv and element to the right of piv
            double pivValue = a[midIndex];
            a[midIndex] = a[midIndex - 1];
            a[midIndex - 1] = pivValue;
            
            midIndex--;
        }
        leftPivIndex --;
        rightPivIndex ++;
    }
    
    return midIndex;
}

int partitionDescending( double a[], int start, int end)
{
    // cout<<"end: "<<end;
    // cout<<"In partition descending "<<endl;
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
    
    double piv = a[pivIndex];
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
            // cout<<"double switch"<<endl;
            // cout<<"a[leftPivIndex] "<<(a[leftPivIndex])<<endl;
            // cout<<"leftPivIndex "<<leftPivIndex<<endl;
            // cout<<"a[rightPivIndex] "<<(a[rightPivIndex])<<endl;
            // cout<<"rightPivIndex "<<rightPivIndex<<endl;
            double temp = a[leftPivIndex];
            a[leftPivIndex] = a[rightPivIndex];
            a[rightPivIndex] = temp;
        }//
        else if ( goRight && (a[rightPivIndex] > piv)  )//only switch right
        {
            // cout<<"right switch"<<endl;
            // cout<<"pivPlusOne a[midIndex + 1] "<<(a[midIndex + 1])<<endl;
            // cout<<"middle Index "<<midIndex<<endl;
            // cout<<"a[rightPivIndex] "<<(a[rightPivIndex])<<endl;
            // cout<<"rightPivIndex "<<rightPivIndex<<endl;
            
            double pivPlusOne = a[midIndex + 1];
            a[midIndex + 1] = a[rightPivIndex];
            a[rightPivIndex] = pivPlusOne;
            
            //switches piv and element to the right of piv
            double pivValue = a[midIndex];
            a[midIndex] = a[midIndex + 1];
            a[midIndex + 1] = pivValue;
            
            midIndex++;
            
        }
        else if ( goLeft && (a[leftPivIndex] < piv)  )//only switch left
        {
            // cout<<"left switch"<<endl;
            // cout<<"pivMinusOne a[midIndex - 1] "<<(a[midIndex - 1])<<endl;
            // cout<<"middle Index "<<midIndex<<endl;
            // cout<<"a[leftPivIndex] "<<(a[leftPivIndex])<<endl;
            // cout<<"leftPivIndex "<<leftPivIndex<<endl;
            //switches element to left of piv with other left element <> piv
            double pivMinusOne = a[midIndex - 1];
            a[midIndex - 1] = a[leftPivIndex];
            a[leftPivIndex] = pivMinusOne;
            
            //switches piv and element to the right of piv
            double pivValue = a[midIndex];
            a[midIndex] = a[midIndex - 1];
            a[midIndex - 1] = pivValue;
            
            midIndex--;
        }
        leftPivIndex --;
        rightPivIndex ++;
    }
    
    return midIndex;
}

void quickSortAscending( double a[], int start, int end )
{
    if ( start < end )
    {
        int index = partitionAscending( a, start, end );
        
        quickSortAscending( a, start, index - 1 );//before pi
        quickSortAscending( a, index + 1, end);//after pi
        
    }
}

void quickSortDescending( double a[], int start, int end )
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
double MPSS( double a[], double sL[], double sR[], int size )
{
    int itrL = 0;
    int itrR = 0;
    int sizeL;
    int sizeR;
    bool odd = false;
    if ( size % 2 != 0 )
    {
        sizeL = (size /2 ) + 1;
        
        odd = true;
    }
    else
    {
        sizeL = size /2 ;
    }
    
    sizeR = size / 2;
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
        quickSortAscending( sL, 0, (size / 2) );
        for ( int i = 0; i < size/ 2; i++)
        {
            cout<<"sR "<< sR[i]<<endl;
        }
    }
    else 
    {
        // need to compute the sums
        //USE the test case from class disc
        //For sL go from middle to start 
        //sL = -34, 49, -58, 76
        //76, 18, 67, 33
        //Formula to get sums
        //current node plus past node
        //sum for left
        double sum = 0;
        for ( int i = (size / 2) - 1; i > -1; i -- )
        {
            sL[i] = sum + sL[i];
            cout<<"sl Sum "<<sL[i]<<endl;
            sum = sL[i];
        }
        
        quickSortAscending( sL, 0, (size / 2) - 1 );
        //{2, -3, 1, 4, -6, 10, -12, 5.2, 3.6, -8}
        
        
        //10, -12, 5.2, 3.6, -8}
        //10, -2, 3.2, 6.8, -1.2
        
        //sum for right
        // int sum2 = 0;
        // for ( int i = (size / 2) - 1; i > -1; i -- )
        // {
        //     sR[i] = sum2 + sR[i];
        //     cout<<"sR Sum "<<sR[i]<<endl;
        //     sum2 = sR[i];
        // }
        
        double sum2 = 0;
        for ( int i = 0; i < (size/2) ; i++ )
        {
            //cout<<"sum2 "<<sum2<<" sR[i] "<<sR[i]<<endl;
            sR[i] = sum2 + sR[i];
            //cout<<"sR Sum2 "<<sR[i]<<endl;
            sum2 = sR[i];
        }
        
    }
    
    
    
    
    
    
    cout<<"Testing Values after Sort"<<endl;
    
    quickSortDescending( sR, 0, (size / 2) - 1 );
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
    //define 2 markers i for sL and j for sR
    //also define sumMin and sumCur
    
    
    int i = 0;
    int j = 0;
    double smin = 100000;
    double s = 0;
    bool stillMore = true;

    /*
    a. If s = SL(i) + SR(j) ≤ 0, then increment i.
    b. Else if s < smin, then set smin = s, and increment j,
    c. Otherwise, we have s > smin, in which case we increment j.
    d. Set MPSSmiddle = smin when the elements of SL or SR have been exhausted.
    */
    while ( i <= sizeL && j <= sizeR )
    {
        cout<<"here " <<( i >= sizeL || j >= sizeR )<<endl;
        cout<<"i "<<i<<endl;
        cout<<"j "<<j<<endl;
        cout<<"s "<<s<<endl;
        cout<<"smin "<<smin<<endl;
        if ( i >= sizeL || j >= sizeR )//return MPSSmiddle = smin when the elements of SL or SR have been exhausted.
        {
            if ( smin == 100000 )
            {
                cout<<"List had no positive numbers "<<endl;
                return -666;
            }
            return smin;
        }
        s = sL[i] + sR[j];
        
        if ( s <= 0 )//s = SL(i) + SR(j) ≤ 0, then increment i.
        {
            i++;
        }
        else if ( s < smin  )//if s < smin, then set smin = s, and increment j,
        {
            cout<<"sumMin "<<smin<<endl;
            smin = s;
            j++;
        }
        else//we have s > smin, in which case we increment j.
        {
            j++;
        }
        
    }
}


int main()
{
    //Input code taken from my Lab 3 for Quick Select
    // int size = 0;
    // while ( size < 5)
    // {
    //     cout<<"Enter a list great than 5: ";
    //     cin >> size;
    // }
    
    // double a[size];
    
    // srand (time(NULL));
    // for ( int i = 0; i < size; i++ )
    // {
    //     int posOrNeg = rand() % 2 + 1;
    //     double posNum = rand() % 21;//0 - 20
    //     double negNum = rand() % 21 -20;//-20 - -1
    //     //cout<<"posOrNeg "<<posOrNeg<<endl;
    //     //cout<<"posNum "<<posNum<<endl;
    //     //cout<<"negNum "<<negNum<<endl;
    //     if ( posOrNeg == 2 )//posOrNeg = 2 +> do pos
    //     {
    //         a[i] = posNum;
    //     }
    //     else//do neg
    //     {
    //         a[i] = negNum;
    //     }
    // }
    // for ( int j = 0; j < size; j++)
    // {
    //     cout<<"a[j] in main "<<a[j]<<endl;
    // }
    // double minPosSum = 0;
    
    // if ( size % 2 == 0 )
    // {
    //     double sL[size/2];
    //     double sR[size/2];
    //     minPosSum = MPSS( a, sL, sR, size );
    // }
    // else
    // {
    //     double sL[(size/2) + 1];
    //     double sR[size/2];
    //     minPosSum = MPSS( a, sL, sR, size );
    // }
    
    //cout<<"MPSS "<<minPosSum<<endl;
    
    double minPosSum = 0;
    int size = 10;
    int size2 = 8;
    double b[size] = {2, -3, 1, 4, -6, 10, -12, 5.2, 3.6, -8};
    double c[size2] = {-34, 49, -58, 76, 29, -71, -54, 63 };
    //{2, -3, 1, 4, -6, 10, -12, 5.2, 3.6, -8};
    //{2, -3, 1, 4, -6, 2, -3, 1, 4, -6};
    double sL[size/2];
    double sR[size/2];
    minPosSum = MPSS( b, sL, sR, size );
    cout<<"MPSS "<<minPosSum<<endl;
    return 0;
}


//Testing Cases
    //All neg even num passed
    //int bn[12] = { -3, -2, -8, -12, -20, -1, -5, -9, -1, -4, -2, -18 };
    //int size = 12;
    //All pos even num 
    //int bp[12] = { 3, 2, 8, 12, 20, 1, 5, 9, 1, 4, 2, 18 };
    
    //Half neg half pos passed
    //int bpn[12] = { 4, -2, 8, 12, -20, 2, 5, -9, 1, 4, 2, -18 };
    
    //all 0 passed
    //int z[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
    //all neg one 0 passed
    //int bnz[12] = { -3, -2, -8, -12, -20, -1, 0, -9, -1, -4, -2, -18 };
    
    //all pos one 0 passed
    //int bpz[12] = { 9, 0, 8, 12, 20, 20, 5, 9, 9, 4, 9, 18 };



