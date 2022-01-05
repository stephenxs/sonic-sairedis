#include "sai_redis.h"

REDIS_GENERIC_QUAD(SCHEDULER_GROUP,scheduler_group);

REDIS_BULK_CREATE(SCHEDULER_GROUP,scheduler_group);
REDIS_BULK_REMOVE(SCHEDULER_GROUP,scheduler_group);
REDIS_BULK_SET(SCHEDULER_GROUP,scheduler_group);
REDIS_BULK_GET_NEW(SCHEDULER_GROUP,scheduler_group);

const sai_scheduler_group_api_t redis_scheduler_group_api = {

    REDIS_GENERIC_QUAD_API(scheduler_group)

    redis_bulk_create_scheduler_group,
    redis_bulk_remove_scheduler_group,
    redis_bulk_set_scheduler_group,
    redis_bulk_get_scheduler_group
};
