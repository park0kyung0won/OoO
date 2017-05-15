#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "data_structures.h"

int inst_length;

struct CONFIG *read_config(char *configfile);
struct INST *read_instruction(char *tracefile);
