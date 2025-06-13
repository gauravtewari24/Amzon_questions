// #include <bits/stdc++.h>
// using namespace std;

// // bruteforce -- divide factorial by 10 till the remainder is 0.
// int main()
// {
//     int n = 28;

//     int cnt5 = 0;

//     for (int i = 5; n / i >= 1; i *= 5)
//     {
//         cnt5 += (n / i);
//     }
//     cout << cnt5;
// }

// package com.kunal.easy;

// public
// class Palindrome
// {
//     static int rev(int n)
//     {
//         // sometimes you might need some additional variables in the argument
//         // in that case, make another function
//         int digits = (int)(Math.log10(n)) + 1;
//         return helper(n, digits);
//     }

// private
//     static int helper(int n, int digits)
//     {
//         if (n % 10 == n)
//         {
//             return n;
//         }
//         int rem = n % 10;
//         return rem * (int)(Math.pow(10, digits - 1)) + helper(n / 10, digits - 1);
//     }

//     static boolean palin(int n)
//     {
//         return n == rev(n);
//     }

// public
//     static void main(String[] args)
//     {
//         System.out.println(palin(1));
//     }

// }

//     import java.util.*
//     ;
// public
// class Main
// {
// public
//     static void main(String[] args)
//     {
//         //        subseqAscii("", "abc");
//         subseq("", "abc");
//     }

//     static void subseq(String p, String up)
//     {
//         if (up.isEmpty())
//         {
//             System.out.println(p);
//             return;
//         }
//         char ch = up.charAt(0);
//         subseq(p + ch, up.substring(1));
//         subseq(p, up.substring(1));
//     }
// }

// static int sum = 0;
// static void rev1(int n)
// {
//     if (n == 0)
//     {
//         return;
//     }
//     int rem = n % 10;
//     sum = sum * 10 + rem;
//     rev1(n / 10);
// }

// // concatinate two strings - ArrayList1 , ArrayList2

// // list.set(index, value)
// // list.remove(index)
// // list.contains(value)

// // for printing directly array
// // Arrays.toString(arr)

// // Math.min && Math.max

// // reverse(array)

// static void STAR(int n)
// {
//     *****for (int row = 0; row < 2 * n; row++)
//     {
//         int totalColsInRow = row > n ? 2 * n - row : row;

//         int noOfSpaces = n - totalColsInRow;
//         for (int s = 0; s < noOfSpaces; s++)
//         {
//             System.out.print(" ");
//         }

//         for (int col = 0; col < totalColsInRow; col++)
//         {
//             System.out.print("* ");
//         }
//         System.out.println();
//     }
// }

// static void pattern31(int n)
// {
//     int originalN = n;
//     n = 2 * n;
//     for (int row = 0; row <= n; row++)
//     {
//         for (int col = 0; col <= n; col++)
//         {
//             int atEveryIndex = originalN - Math.min(Math.min(row, col), Math.min(n - row, n - col));
//             System.out.print(atEveryIndex + " ");
//         }
//         System.out.println();
//     }
// }

// // https://leetcode.com/problems/find-in-mountain-array
// int search(int[] arr, int target)
// {
//     int peak = peakIndexInMountainArray(arr);
//     int firstTry = orderAgnosticBS(arr, target, 0, peak);
//     if (firstTry != -1)
//     {
//         return firstTry;
//     }
//     // try to search in second half
//     return orderAgnosticBS(arr, target, peak + 1, arr.length - 1);
// }

// public
// int peakIndexInMountainArray(int[] arr)
// {
//     int start = 0;
//     int end = arr.length - 1;

//     while (start < end)
//     {
//         int mid = start + (end - start) / 2;
//         if (arr[mid] > arr[mid + 1])
//         {
//             // you are in dec part of array
//             // this may be the ans, but look at left
//             // this is why end != mid - 1
//             end = mid;
//         }
//         else
//         {
//             // you are in asc part of array
//             start = mid + 1; // because we know that mid+1 element > mid element
//         }
//     }
//     return start; // or return end as both are =
// }

// static int orderAgnosticBS(int[] arr, int target, int start, int end)
// {
//     // find whether the array is sorted in ascending or descending
//     boolean isAsc = arr[start] < arr[end];

//     while (start <= end)
//     {
//         // find the middle element
//         //            int mid = (start + end) / 2; // might be possible that (start + end) exceeds the range of int in java
//         int mid = start + (end - start) / 2;

//         if (arr[mid] == target)
//         {
//             return mid;
//         }

//         if (isAsc)
//         {
//             if (target < arr[mid])
//             {
//                 end = mid - 1;
//             }
//             else
//             {
//                 start = mid + 1;
//             }
//         }
//         else
//         {
//             if (target > arr[mid])
//             {
//                 end = mid - 1;
//             }
//             else
//             {
//                 start = mid + 1;
//             }
//         }
//     }
//     return -1;
// }

// // missing no && cyclic sort
// public
// static void main(String[] args)
// {
//     int[] arr = {4, 0, 2, 1};
//     System.out.println(missingNumber(arr));
// }

// public
// static int missingNumber(int[] arr)
// {

//     int i = 0;
//     while (i < arr.length)
//     {
//         int correct = arr[i];
//         if (arr[i] < arr.length && arr[i] != arr[correct])
//         {
//             swap(arr, i, correct);
//         }
//         else
//         {
//             i++;
//         }
//     }
//     // end of cyclic sort

//     // search for first missing number
//     for (int index = 0; index < arr.length; index++)
//     {
//         if (arr[index] != index)
//         {
//             return index;
//         }
//     }
//     // case 2
//     return arr.length;
// }
