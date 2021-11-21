#include "sai_vs.h"

VS_GENERIC_QUAD(SCHEDULER_GROUP,scheduler_group);

VS_BULK_CREATE(SCHEDULER_GROUP,scheduler_group);
VS_BULK_REMOVE(SCHEDULER_GROUP,scheduler_group);
VS_BULK_SET(SCHEDULER_GROUP,scheduler_group);
VS_BULK_GET(SCHEDULER_GROUP,scheduler_group);

const sai_scheduler_group_api_t vs_scheduler_group_api = {

    VS_GENERIC_QUAD_API(scheduler_group)

    vs_bulk_create_scheduler_group,
    vs_bulk_remove_scheduler_group,
    vs_bulk_set_scheduler_group,
    vs_bulk_get_scheduler_group
};
