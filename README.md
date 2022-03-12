# Programming-In-General

## Constructor Overloading
We can use this keyword inside the constructor, which can be used to invoke the other constructor of the same class.

```java
public class Student {  
  //instance variables of the class  
  int id,passoutYear;  
  String name,contactNo,collegeName;  

  Student(String contactNo, String collegeName, int passoutYear){  
    this.contactNo = contactNo;  
    this.collegeName = collegeName;  
    this.passoutYear = passoutYear;  
  }  

  Student(int id, String name){  
    this("9899234455", "IIT Kanpur", 2018);  
    this.id = id;  
    this.name = name;  
  }  
  
  public static void main(String[] args) {  
    //object creation  
    Student s = new Student(101, "John");  
    System.out.println("Printing Student Information: \n");  
    System.out.println("Name: "+s.name+"\nId: "+s.id+"\nContact No.: "+s.contactNo+"\nCollege Name: "+s.contactNo+"\nPassing Year: "+s.passoutYear);  
  }  
}  
```

    Printing Student Information: 

    Name: John
    Id: 101
    Contact No.: 9899234455
    College Name: 9899234455
    Passing Year: 2018

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


    Printing Student Information: 

    Name: John
    Id: 101
    Contact No.: 9899234455
    College Name: 9899234455
    Passing Year: 2018


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

### Comparator

        static bool comp(const vector<int>& vec1, const vector<int>& vec2){
            if(vec1[0] != vec2[0])
                return vec1[0] < vec2[0];
            else
                return vec1[1]<vec2[1];
        } 


## Hashing : 

Provides O(1) time on average for insert, search and delete ( O(n) in worst case ).
The idea is to use hash function that converts key to a smaller number and uses the small number as index in a table called hash table ( array ) .

### Hash Function : 

Maps a big number or string to a small integer that can be used as index in hash table.

A good hash function should have following properties

1) Efficiently computable.

2) Should uniformly distribute the keys (Each table position equally likely for each key)

### Collision Handling: 

Since a hash function gets us a small number for a big key, there is possibility that two keys result in same value. The situation where a newly inserted key maps to an already occupied slot in hash table is called collision and must be handled using some collision handling technique. Following are the ways to handle collisions:

#### Chaining / Separate Chaining:

The idea is to make each cell ( after collision ) of hash table point to a linked list of records that have same hash function value. Chaining is simple, but requires additional memory outside the table.

#### Open Addressing: 

In open addressing, all elements are stored in the hash table itself. Each table entry contains either a record or NIL. When searching for an element, we one by one examine table slots until the desired element is found or it is clear that the element is not in the table.

##### 1.Linear Probing : 

In linear probing, we linearly probe for next slot. 

    let hash(x) be the slot index computed using a hash function and S be the table size
    
    If slot hash(x) % S is full, then we try (hash(x) + 1) % S
    If (hash(x) + 1) % S is also full, then we try (hash(x) + 2) % S
    If (hash(x) + 2) % S is also full, then we try (hash(x) + 3) % S 
    ...............................................................................
    ...............................................................................


#### 2.Quadratic Probing : 

We look for i2‘th slot in i’th iteration. 

    let hash(x) be the slot index computed using hash function.  
    
    If slot hash(x) % S is full, then we try (hash(x) + 1*1) % S
    If (hash(x) + 1*1) % S is also full, then we try (hash(x) + 2*2) % S
    If (hash(x) + 2*2) % S is also full, then we try (hash(x) + 3*3) % S
    ...............................................................................
    ...............................................................................

#### 3.Double Hashing : 

We use another hash function hash2(x) and look for i*hash2(x) slot in i’th rotation. 

    let hash(x) be the slot index computed using hash function.
    
    If slot hash(x) % S is full, then we try (hash(x) + 1*hash2(x)) % S
    If (hash(x) + 1*hash2(x)) % S is also full, then we try (hash(x) + 2*hash2(x)) % S
    If (hash(x) + 2*hash2(x)) % S is also full, then we try (hash(x) + 3*hash2(x)) % S
    ...............................................................................
    ...............................................................................

