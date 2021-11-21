#include "sai_redis.h"

REDIS_GENERIC_QUAD(BUFFER_POOL,buffer_pool);
REDIS_GENERIC_QUAD(INGRESS_PRIORITY_GROUP,ingress_priority_group);
REDIS_GENERIC_QUAD(BUFFER_PROFILE,buffer_profile);
REDIS_GENERIC_STATS(BUFFER_POOL,buffer_pool);
REDIS_GENERIC_STATS(INGRESS_PRIORITY_GROUP,ingress_priority_group);

REDIS_BULK_CREATE(INGRESS_PRIORITY_GROUP,ingress_priority_group);
REDIS_BULK_REMOVE(INGRESS_PRIORITY_GROUP,ingress_priority_group);
REDIS_BULK_SET(INGRESS_PRIORITY_GROUP,ingress_priority_group);
REDIS_BULK_GET(INGRESS_PRIORITY_GROUP,ingress_priority_group);

const sai_buffer_api_t redis_buffer_api = {

    REDIS_GENERIC_QUAD_API(buffer_pool)
    REDIS_GENERIC_STATS_API(buffer_pool)
    REDIS_GENERIC_QUAD_API(ingress_priority_group)
    REDIS_GENERIC_STATS_API(ingress_priority_group)
    REDIS_GENERIC_QUAD_API(buffer_profile)

    redis_bulk_create_ingress_priority_group,
    redis_bulk_remove_ingress_priority_group,
    redis_bulk_set_ingress_priority_group,
    redis_bulk_get_ingress_priority_group
};
