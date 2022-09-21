#include "sai_vs.h"

VS_GENERIC_QUAD(SCHEDULER_GROUP,scheduler_group);
VS_BULK_QUAD(SCHEDULER_GROUP,scheduler_groups);

const sai_scheduler_group_api_t vs_scheduler_group_api = {

    VS_GENERIC_QUAD_API(scheduler_group)
    VS_BULK_QUAD_API(scheduler_groups)
};
