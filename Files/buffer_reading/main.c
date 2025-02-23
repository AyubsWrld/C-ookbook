#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h> 

#define BUFFER 1024


size_t get_file_size( FILE* fptr )
{
  fseek( fptr , 0L , SEEK_END ) ; 
  size_t sz = ftell(fptr) ; 
  fseek( fptr , 0L , SEEK_SET ) ; 
  return sz ; 
}

int main()
{
  char* buffer = malloc(sizeof(char) * BUFFER) ; 
  FILE* fptr = fopen( "test.txt" , "r" ); 
  FILE* dest = fopen( "dest.txt" , "w" ); 


  assert ( fptr ) ; 
  assert ( dest ) ; 

  size_t result ; 

  while( ( result = fread(buffer , sizeof(char) , BUFFER , fptr )) > 0 ){
    fwrite( buffer , sizeof(char) , BUFFER , dest )  ; 
  }

  free(buffer) ; 
  fclose(fptr) ; 
  fclose(dest) ; 
  return 0 ; 
}
