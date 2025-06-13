#include <iostream>
#include <string>
using namespace std;

char findKthChar(const string &s, int k)
{
    int i = 0;
    int n = s.length();
    int totalLen = 0;

    while (i < n)
    {
        string part = "";

        // Extract the substring (only letters)
        while (i < n && isalpha(s[i]))
        {
            part += s[i];
            i++;
        }

        // Extract the repeat count (digits)
        int count = 0;
        while (i < n && isdigit(s[i]))
        {
            count = count * 10 + (s[i] - '0');
            i++;
        }

        int expandedLen = part.length() * count;

        // Check if k falls within this block
        if (k <= totalLen + expandedLen)
        {
            int indexInBlock = (k - totalLen - 1) % part.length(); // -1 is for 0 based indexing, and first part represents the current block
                                                                   // and % second part represents
            return part[indexInBlock];
        }

        totalLen += expandedLen;
    }

    return '?'; // if k is out of range
}

int main()
{
    string encrypted = "a2b3cd3"; // "aabbbcdcdcd"
    int k = 7;
    cout << "K-th character: " << findKthChar(encrypted, k) << endl; // Output: 'c'
    return 0;
}
