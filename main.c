#include <stdio.h>

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
int* get_inputs() {
  // Open the file
  FILE* fpfile = fopen("inputs.txt", "r");
  // Get the length of the file
  fseek(fpfile, 0L, SEEK_END);
  unsigned long ulfileLength = ftell(fpfile);
  // Put the reader back at the top
  rewind(fpfile);
  // Initialize the array we will be using
  int* ipbuffer = (int*)malloc(ulfileLength*sizeof(int));
  // Read from the file
  int counter = 0;
  while (1) {
    int cpreturn = (int)fgets((char*)(ipbuffer + counter), ulfileLength, fpfile);
    counter += sizeof(int);
    if (cpreturn == 0) {
      break;
    }
  }
  fprintf(stdout, "File is %lu (some unit) in length.\n", ulfileLength);
  fprintf(stdout, "File contents:\n");

  for(int i = 0; i < counter; i+=sizeof(int)) {
    fprintf(stdout, "\t%s\n", (char*)ipbuffer);
  }

  // Close the file and handle errors
  if (fclose(fpfile) == 0) {
    fprintf(stdout, "File close successful.\n");
  } else {
    fprintf(stderr, "File close unsuccessful.\n");
  }
  
  return ipbuffer;
}


int main(void) {
  int* ipbuffer = get_inputs();
  return 0;
}