#include "sai_redis.h"

REDIS_GENERIC_QUAD(SCHEDULER_GROUP,scheduler_group);
REDIS_BULK_QUAD(SCHEDULER_GROUP,scheduler_groups);

const sai_scheduler_group_api_t redis_scheduler_group_api = {

    REDIS_GENERIC_QUAD_API(scheduler_group)
    REDIS_BULK_QUAD_API(scheduler_groups)
};
