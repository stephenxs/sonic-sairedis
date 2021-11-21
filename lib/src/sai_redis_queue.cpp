#include "sai_redis.h"

REDIS_GENERIC_QUAD(QUEUE,queue);
REDIS_GENERIC_STATS(QUEUE,queue);

REDIS_BULK_CREATE(QUEUE,queue);
REDIS_BULK_REMOVE(QUEUE,queue);
REDIS_BULK_SET(QUEUE,queue);
REDIS_BULK_GET(QUEUE,queue);

const sai_queue_api_t redis_queue_api = {

    REDIS_GENERIC_QUAD_API(queue)
    REDIS_GENERIC_STATS_API(queue)

    redis_bulk_create_queue,
    redis_bulk_remove_queue,
    redis_bulk_set_queue,
    redis_bulk_get_queue
};
