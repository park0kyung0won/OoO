#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data_structures.h"

extern int inst_length;

struct CONFIG *read_config(char *configfile)
{
	char buffer[5];
	FILE *fp;
	struct CONFIG *ptr_config = malloc(sizeof(struct CONFIG));
	if ((fp = fopen(configfile, "r")) == NULL) 
	{
		printf("Failed to read config file\n");
		return NULL;
	}

	for (int idx = 0; idx < 4; idx++)
	{
		fgets(buffer, 5, fp);
		switch (idx)
		{
			case 0:
				(*ptr_config).Dump = atoi(buffer);
				break;
			case 1:
				(*ptr_config).Width = atoi(buffer);
				break;
			case 2:
				(*ptr_config).ROB_size = atoi(buffer);
				break;
			case 3:
				(*ptr_config).RS_size = atoi(buffer);
				break;
			default:
				printf("Something wrong while reading config!!\n");
		}
	}
	fclose(fp);

	return ptr_config;
}

struct INST *read_instruction(char *tracefile)
{
	int line_length = 0;
	FILE *fp;

	if ((fp = fopen(tracefile, "r")) == NULL)
	{
		printf("Failed to read trace file\n");
		return NULL;
	}
	
	int counter;

	while ((counter = fgetc(fp)) != EOF)
	{
		if (counter == '\n')
		{
			line_length++;
		}
	}
	inst_length = line_length;
	fclose(fp);

	struct INST *arr_inst = malloc(sizeof(struct INST) * line_length);
	char buffer[100];
	char *opcode;
	fp = fopen(tracefile, "r");
	int i;
	int oprd;

	for (i = 0; i < line_length; i++)
	{
		fgets(buffer, 100, fp);
		opcode = strsep(&buffer, " ");
		if (strcmp(opcode, "IntAlu") == 0) // IntAlu
		{
			arr_inst[i].opcode = IntAlu;
			arr_inst[i].dest = atoi(strsep(&buffer, " "));
			arr_inst[i].oprd_1 = atoi(strsep(&buffer, " "));
			arr_inst[i].oprd_2 = atoi(strsep(&buffer, " "));
		}
		else if (strcmp(opcode, "MemRead") == 0) // MemRead
		{
			arr_inst[i].opcode = MemRead;
			arr_inst[i].dest = atoi(strsep(&buffer, " "));
			arr_inst[i].oprd_1 = atoi(strsep(&buffer, " "));
			arr_inst[i].oprd_2 = atoi(strsep(&buffer, " "));
		}
		else if (strcmp(opcode, "MemWrite") == 0)
		{
			arr_inst[i].opcode = MemWrite;
			arr_inst[i].dest = atoi(strsep(&buffer, " "));
			arr_inst[i].oprd_1 = atoi(strsep(&buffer, " "));
			arr_inst[i].oprs_2 = atoi(strsep(&buffer, " "));
		}
		else // Exeption
		{
			printf("Warning : illegal instruction\n");
		}
	}
	
	fclose(fp);
	return arr_inst;
}








