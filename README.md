# Programming-In-General
## Time Complexity : Performance analysis of an algorithm
1.Let us take the same previous example to calculate the sum of “n” numbers in the array and how much time will it take to get the result.


              int calculate_sum(int arr[], int length)
              {
                int total_sum = 0;
                int i = 0;
                for( i= 0; i< len; i++)
                {
                  total_sum =  total_sum + arr[i];
                }
              }


For space complexity we take the variables, but for calculating time complexity we concentrate of the number of statements executed.

From the above code, we can calculation as:

The statement “int total_sum = 0;” will be executed 1 time. Hence 1 unit.
The statement “int i = 0;” will be executed 1 time. Hence 1 unit.

The statement “for( i= 0; i< len; i++)” will be executed “len+1” times. This is because, it will also calculate till, after the condition is false.

The statement “total_sum = total_sum + arr[i];” will execute “len” times.

Hence the total time taken to execute is = “2n+3”. For larger value of n, we ignore the constants, hence the final time complexity is “O(n)” times

2.Time complexity for matrix addition


          int add_matrix( int a[m] [n], int b [m] [n], int m, int n)
          {
            for (i = 0; i< n; i++)
            {
              for(j = 0; j<n; j++)
              {
                c[i][j] = a[i][j] + b[i][j]
              }
             }
          }
          
The first for loop “for (i = 0; i< n; i++)” will be executed (n+1) time. Hence n+1 units.
The second for loop “for(j = 0; j<n; j++)will be executed n*(n+1) time. Hence n(n+1) units.
The third statement “c[i][j] = a[i][j] + b[i][j]” will be executed “n * n” times. Hence n^2 units.

i.e

n+1+ n^2+n + n^2

2n^2 + 2n + 1

For larger value of “n” we ignore the constants, hence total time taken to execute is O(n^2).

### Below are different types of time function available:

O(1) : Constant time

O(log n) : Logarithmic Time. This type of time complexity can be achieved by continuously dividing a number by a constant

O(n) : Linear Time. It can be seen in a single for or while loop

O(n log n) : Some divide and conquer algorithm have this complexity

O(n^2) : Quadratic (Two nested loops)

O(n^3) : Cubic (Three nested loops)

O(2^n) : Exponential time

O(3^n) :      ""

O(n^n) :      ""

### Below is the increasing order of time consumption:

O(1) < O( log n) < O(n)< O( nlog n) < O(n^2) < O(n^3) < O(2^n) < O(3^n) < O(n^n)
