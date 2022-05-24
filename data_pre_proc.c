#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int find_sensor_count(char *filename);
int data_clean(char *filename);
int data_splicing(char *filename, int sensor_count);

int main()
{
	FILE *fp;
	char buff[255];
	
	fp = fopen("ls.txt", "r");
	while(fscanf(fp, "%s", buff)!=EOF)
	{
		printf("Processing [%s]\n", buff );
		int sensor_count = find_sensor_count(buff);
		printf("Sensor count-> %d\n", sensor_count);
		printf("Cleaning Data...\n");
		data_clean(buff);
		printf("Splicing Data...\n");
		data_splicing(buff, sensor_count);
	}
	fclose(fp);
	return 0;	
}

int data_clean(char *filename)
{
	//printf("%s\n", filename);

	FILE *fp;
	FILE *dest;
	char buff[255];
	char line[255];
	//get the address of file to be read
	char address[256];
	strcpy(address, "./data_raw");
	strcat(address, "/");
	strcat(address, filename);
	//printf("%s\n", address);
	//get dest address
	char dest_addr[255];
	strcpy(dest_addr, "./data_cleaned/");
	strcat(dest_addr, filename);
	//open file
	fp = fopen(address, "r");
	//open dest file
	dest = fopen(dest_addr, "w");
	//printf("%s\n", dest_addr);
	
	
	while(fscanf(fp, "%s", buff)!=EOF)
	{
		fscanf(fp, "%s", buff);
		int len=strlen(buff);
		//printf("%s -> ", buff);
		int pos;
		for(int i=0; i<len; i++)
		{
			//find where timestamp ends
			if(buff[i]==','){ pos=i+1; break; }
		}
		for(int i=0; i+pos<len; i++)
		{
			//copy data over
			line[i]=buff[pos+i];
			//remove commas
			if(line[i]==',')
			{
				line[i]=' ';
			}
		}
		line[len-pos]='\0';
		//print to dest file
		fprintf(dest, "%s\n", line);
		//printf("%s\n", line);
		
	}
	fclose(fp);
	fclose(dest);
	
	return 0;
}

int find_sensor_count(char *filename)
{
	FILE *fp;
	char buff[255];
	
	char address[256];
	strcpy(address, "./data_raw");
	strcat(address, "/");
	strcat(address, filename);
	
	fp = fopen(address, "r");
	
	fscanf(fp, "%s", buff);
	fscanf(fp, "%s", buff);
	int length=strlen(buff);
	int sensors=0;
	
	for(int i=0; i<length; i++)
	{
		if(buff[i]==',')
		{
			sensors++;
		}
	}
	fclose(fp);
	
	return sensors;
}

int data_splicing(char *filename, int sensor_count)
{
	FILE *fp;
	FILE *dest[30];
	char buff[255];
	char dirname[256];
	char dest_addr[512];
	char command[512];
	
	strcpy(dirname, filename);
	
	int len=strlen(dirname);
	for(int i=0; i<len; i++)
	{
		if(dirname[i]=='.')
		{
			dirname[i]='\0';
			break;
		}
	}
	strcpy(command, "mkdir ./data_spliced/");
	strcat(command, dirname);
	
	//create directory
	system(command);
	
	//get the address of file to be read
	char address[256];
	strcpy(address, "./data_cleaned/");
	strcat(address, filename);
	//open the file
	fp = fopen(address, "r");
	
	//get dest address
	strcpy(dest_addr, "./data_spliced/");
	strcat(dest_addr, dirname);
	strcat(dest_addr, "/sensor"); 
	char temp[512];
	strcpy(temp, dest_addr);
	
	for(int i=0; i<sensor_count; i++)
	{
		strcpy(dest_addr, temp);
		char s_num[20];
		sprintf(s_num, "%d", i+1);
		strcat(dest_addr, s_num);
		strcat(dest_addr, ".txt");
		dest[i]=fopen(dest_addr, "w");
	}
	
	int counter=0;
	while(fscanf(fp, "%s", buff)!=EOF)
	{
		fprintf(dest[counter%sensor_count], "%s\n", buff);
		counter++;
	}
	fclose(fp);
	for(int i=0; i<sensor_count; i++)
	{
		fclose(dest[i]);
	}
	return 0;
}
