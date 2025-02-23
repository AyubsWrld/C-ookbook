# Getting size of file on machine 

```c
#include <stdlib.h> 
#include <stdio.h> 

// Assumes error handling has occured prior to opening the file 
size_t get_file_size( FILE* fptr)
{
  size_t sz = fseeks( fptr , 0L , SEEK_END); 
  return sz
}


int main()
{
  FILE* fptr = fopen("example.txt" , "r") ; 
  size_t file_size = get_file_size(fptr) ; 
  printf("File size : %zu\n" , file_size) ; 
  return 0 ; 
}
```





