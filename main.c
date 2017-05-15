#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data_structures.h"
#include "reader.h"
#include "simulator.h"

int main(int argc, char *argv[])
{
	// Initializing ...
	struct CONFIG *ptr_config;
	struct INST *arr_inst;
       	ptr_config = read_config(argv[1]);
	arr_inst = read_instruction(argv[2]);
	struct REPORT *ptr_report;
	ptr_report = core_simulator(ptr_config, arr_inst);
	// TODO list
	// reader.c 파일이 제대로 동작할지 모르겠다 확인해달라
	// simulator.c 안에 Dump 하는 부분, dump_1이랑 dump_2 만들어야함
	// ptr_report로 출력하는 부분 작성하기
	
	return 0;
}
