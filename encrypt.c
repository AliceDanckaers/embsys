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
	char fileIn[1024];
	strcpy(fileIn,"");
	size_t len = 0;
	size_t lentot=0;
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

	// read each line of the input and store it in fileIn
	while ((read = getline(&lineIn, &len, FileIn)) != -1 && lentot<1025) 
	{
		strcat(fileIn,lineIn);
		lentot+=sizeof(lineIn);
	}
	
	char txtOut[strlen(fileIn)];
	encryptDecrypt(fileIn, txtOut);
	fwrite (txtOut , sizeof(char), sizeof(txtOut), FileOut);

	fclose(FileIn);
	fclose(FileOut);

	if (lineIn)
	{
		free(lineIn);
	}

       	exit(EXIT_SUCCESS);


}

int main (int argc, char *argv[]) {

	int rep = encryptFile("/mnt/sda1/tocrypt.txt","/mnt/sda1/encrypted.txt");
	return rep;
	
}
