
// Que 03). Balanced Array. 
// Que Link :- https://bit.ly/37ngCeT

// Implementation

// 1st Approach in CPP
// Time Complexity = O(N), Space Complexity = O(1)

int minValueToBalance(int a[], int n) {
   int minValue, sum1 = 0, sum2 = 0;
   for(int itr = 0, btr = n - 1; itr < n / 2; ){
       sum1 += a[itr++];
       sum2 += a[btr--];
   }
   if(sum1 >= sum2) return minValue = sum1 - sum2;
   else return minValue = sum2 - sum1;
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

long minValueToBalance(long a[] ,int n) {
        int minValue, sum1 = 0, sum2 = 0;
        for(int itr = 0, btr = n - 1; itr < n / 2; ){
            sum1 += a[itr++];
            sum2 += a[btr--];
        }
        if(sum1 >= sum2) return minValue = sum1 - sum2;
        else return minValue = sum2 - sum1;
    }
