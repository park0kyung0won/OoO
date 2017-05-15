#include <stdbool.h>

enum oprd_state {Q = 0, V = 1};
enum instruction {IntAlu = 0, MemRead = 1, MemWrite = 2};
enum is_complete {P = 0, C = 1};

struct CONFIG;     // Config file
struct REPORT;     // Report file
struct INST;       // Single Instruction
struct FQ;         // Single element in Fetch Queue
struct RAT;        // Single element in Register Address Table
struct RS;         // Single element in Reservation Station
struct ROB;        // Single element in ReOrder Buffer
struct CA_status;  // Status of cyclic array

void ca_cnt_push(struct CA_status *status);
void ca_cnt_pop(struct CA_status *status);
int ca_next_pos(struct CA_status *status);

struct CONFIG
{
	int Dump;
	int Width;
	int ROB_size;
	int RS_size;
};

struct REPORT
{
	int Cycles;
	double IPC;
	int Total_Insts;
	int IntAlu;
	int MemRead;
	int MemWrite;
};

struct CA_status
{
	int size;
	int head;
	int occupied;
};

struct INST // Instruction
{
	enum instruction opcode;
	int dest;
	int oprd_1;
	int oprd_2;
};

struct FQ
{
	enum instruction opcode;
	int dest;
	int oprd_1;
	int oprd_2;	
};

struct RAT
{
	bool RF_valid;
	int q;
};

struct RS
{
	int time_decoded;
	int rob_dest;
	bool is_valid;
	enum instruction opcode;
	int time_left;
	struct
	{
		enum oprd_state state;
		union
		{
			int v;
			int q;
		} data;
	} oprd_1;

	struct
	{
		enum oprd_state state;
		union
		{
			int v;
			int q;
		} data;
	} oprd_2;
};

struct ROB
{
	enum instruction opcode;
	int dest;
	enum is_complete status;
};
