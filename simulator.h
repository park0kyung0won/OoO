#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data_structures.h"

extern int inst_length;

void dump_1();
void dump_2();
void fetch(struct CONFIG *config, struct FQ *fetch_queue, struct CA_status *fq_status, struct INST *arr_inst);
void decode(struct CONFIG *config, struct FQ *fetch_queue, struct CA_status *fq_status,struct RS *rs_ele, struct RAT *rat, struct ROB *rob, struct CA_status *rob_status);
void issue(struct CONFIG *config, struct RS *rs_ele, struct RS *issuewait_list, struct ROB *rob, bool *is_completed_this_cycle, int *issuewait_reference, int i);
void execute(struct CONFIG *config, struct RS *rs_ele, bool *is_issued_this_cycle, int i);
void wait(void);
void rs_retire(struct RS *rs_ele, struct ROB *rob);
void commit(struct CONFIG *config, struct ROB *rob, struct CA_status *rob_status, struct RAT *rat);
struct REPORT *core_simulator(struct CONFIG *config, struct INST *arr_inst);
