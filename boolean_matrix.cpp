// 1) Create two temporary arrays row[M] and col[N].
//      Initialize all values of row[] and col[] as 0.
// 2) Traverse the input matrix mat[M][N]. If you see an entry mat[i][j] as true,
//      then mark row[i] and col[j] as true.
// 3) Traverse the input matrix mat[M][N] again. For each entry mat[i][j],
//       check the values of row[i] and col[j]. If any of the two values (row[i] or col[j]) is true,
//        then mark mat[i][j] as true.

// if O(1) space the use first row nd first column as row[i] and col[j]
//    i.e auxillary array
