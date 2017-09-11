#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b); /* Declaration */

int main()
{
//int arr[10];
char arr[10];
int i = 0;
print("Pointer of i %d\n",*i);
//printf("size of int is %lu\n", sizeof(int));
printf("size of char is %lu\n", sizeof(char));
printf("size of array is %lu\n", sizeof(arr));
printf("number of element in array is: %d\n",sizeof(arr)/sizeof(char));
for(i=0;i<sizeof(arr)/sizeof(char);i++)
{ 
  arr[i] = 'a'; // Initializing each element seperately 
  printf("array's %d element: %c\n", i, arr[i]);
}
//printf("Sum of array element 0 and 1: %d\n", sum(arr[0],arr[1])); 
exit(0);
}

int sum(int a, int b) /* Definition */
{
	return (a+b);
}
/* arr[0] = 0 
   arr[1] = 1 */


