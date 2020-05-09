#include <stdio.h>
#include <stdlib.h>

int get_linecount(FILE* fp, unsigned long size) {
  int counter = 0;
  char junk[size];
  while (1) {
    int cpreturn = (int)fgets(junk, size, fp);
    if (cpreturn == 0) {
      break;
    }
    counter += sizeof(int);
  }
  return counter;
}

// Read inputs from the inputs.txt file
char** get_inputs() {
  FILE* fpfile = fopen("inputs.txt", "r");
  // Get the size of the file
  fseek(fpfile, 0L, SEEK_END);
  unsigned long ulfileLength = ftell(fpfile);
  // Put the reader back at the top
  rewind(fpfile);
  // Get the number of lines in the file
  int ilines = get_linecount(fpfile, ulfileLength);
  // Initialize the array we will be using
  char** buffer = (char**)malloc(ilines);
  // Read from the file
  int counter = 0;
  while (1) {
    *(buffer+counter) = (char*)malloc(ulfileLength/ilines);
    int ireturn = (int)fgets((char*)(buffer+counter), ulfileLength, fpfile);
    fprintf(stdout, "%s", (char*)(buffer+counter));
    counter += sizeof(int);
    if (ireturn == 0) {
      printf("\n");
      break;
    }
  }
  fprintf(stdout, "File is %lu (some unit) in length.\n", ulfileLength);
  fprintf(stdout, "File contents:\n");

  for(int i = 0; i < counter; i++) {
    fprintf(stdout, "\t%s\n", buffer[i]);
  }

  // Close the file and handle errors
  if (fclose(fpfile) == 0) {
    fprintf(stdout, "File close successful.\n");
  } else {
    fprintf(stderr, "File close unsuccessful.\n");
  }
  
  return buffer;
}


int main(void) {
  char** ipbuffer = get_inputs();
  return 0;
}