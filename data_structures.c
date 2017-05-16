#include "data_structures.h"

void ca_cnt_push(struct CA_status *status)
{
	(*status).occupied++;
}

void ca_cnt_pop(struct CA_status *status)
{
	(*status).head = ((*status).head + 1) % (*status).size;
	(*status).occupied--;
}

int ca_next_pos(struct CA_status *status)
{
	return ((*status).head + (*status).occupied) % (*status).size;
}
