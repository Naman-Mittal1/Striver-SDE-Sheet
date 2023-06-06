#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int zero=0, one=0, two=0;
   for(int i =0; i<n; i++)
   {
      if(arr[i] == 0)
         zero++;

      if(arr[i] == 1)
         one++;
      
      if(arr[i] == 2)
         two++;
   }

   int i=0;

   while(zero!=0)
   {
      arr[i] = 0;
      i++;
      zero--;
   }

   while(one!=0)
   {
      arr[i] = 1;
      i++;
      one--;
   }

   while(two!=0)
   {
      arr[i] = 2;
      i++;
      two--;
   }
}