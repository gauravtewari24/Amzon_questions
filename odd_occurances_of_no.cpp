// XOR of all elements gives us odd occurring elements.
// Please note that the XOR of two elements is 0 if both elements are the same
// and the XOR of a number x with 0 is x.
int getOddOccurrence(int ar[], int ar_size)
{
    int res = 0;
    for (int i = 0; i < ar_size; i++)
        res = res ^ ar[i];

    return res;
}
