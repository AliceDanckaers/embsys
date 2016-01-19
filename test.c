#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void encryptDecrypt(char *input, char *output) {
	char key[] = {'K', 'C', 'Q'}; //Can be any chars, and any size array

	int i;
	for(i = 0; i < strlen(input); i++) {
		output[i] = input[i] ^ key[i % (sizeof(key)/sizeof(char))];

	}
}


int encryptFile(char* input,char* output){

	// Creation of the files
	FILE *FileIn;
	FILE *FileOut;

	// initialization
	char *lineIn = NULL;
	char *lineOut;
	size_t len = 0;
	ssize_t read;

	// open file input and output
	FileIn = fopen(input,"r+");
	if(FileIn == NULL)
	{
        	exit(EXIT_FAILURE);
	} 
	FileOut = fopen(output,"w+");
	if(FileOut == NULL)
	{
        	exit(EXIT_FAILURE);
	} 

	// read each line of the input and store it in the output
	while ((read = getline(&lineIn, &len, FileIn)) != -1) 
	{
		char lineOut[strlen(lineIn)];
		encryptDecrypt(lineIn, lineOut);
		fwrite (lineOut , sizeof(char), sizeof(lineOut), FileOut);
	}

	fclose(FileIn);
	fclose(FileOut);

	if (lineIn)
	{
		free(lineIn);
	}

       	exit(EXIT_SUCCESS);


}

int main (int argc, char *argv[]) {

	int rep = encryptFile("testin.txt","testout.txt");
	return rep;
	
}
