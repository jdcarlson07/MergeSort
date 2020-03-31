
#include <iostream>

using namespace std;

void printArray(int* ar, int begin, int end)
{
    for(int i = begin; i <= end; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "\n";
}

void merge(int* ar, int begin1, int end1, int begin2, int end2)
{
    int b1, e1, b2, e2;
    b1 = begin1;
    e1 = end1;
    b2 = begin2;
    e2 = end2;
    int temp[e2];
    int count = begin1;

    while(b1 <= e1 && b2 <= e2)
    {
        if(ar[b1] < ar[b2])
        {
            temp[count] = ar[b1];
            b1++;
            count++;
        }

        else
        {
            temp[count] = ar[b2];
            b2++;
            count++; 
        }
        
    }
    while(b1 <= e1)
    {
        temp[count] = ar[b1];
        count++;
        b1++;
    }
    while(b2 <= e2)
    {
        temp[count] = ar[b2];
        count++;
        b2++;
    }

    for(int i = begin1; i < count; i++)
    {
        ar[i] = temp[i];
    }

}

//which portion of the array am I mergeSorting....
void mergeSort(int* ar, int begin, int end)
{
    //cout << "Merge Sorting: ";
    //printArray(ar, begin, end);

    //if it is not a 1 list (not trivially sorted)
    if(begin != end)
    {
        //divide in half and call mergeSort on each half
        int begin1 = begin;
        int end1 = (end + begin) / 2;
        int begin2 = end1 + 1;
        int end2 = end;

        //call mergesort on the first half
        mergeSort(ar, begin1, end1);

        //call mergesort on the second half
        //this will not fire until the entire 
        //first half is dealt with
        mergeSort(ar, begin2, end2);

        //now perform the merge step
        //cout << "Now we have to merge!!!!\n Start to cry Clancy!!!\n";
        merge(ar, begin1, end1, begin2, end2);

    }
}




int main()
{
    int ar[5] = {8,100,1,9,3};
    printArray(ar, 0, 4);
    mergeSort(ar, 0, 4);
    printArray(ar, 0, 4);
    return 0;
}