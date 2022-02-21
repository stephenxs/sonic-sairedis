#include "sai_redis.h"

REDIS_GENERIC_QUAD(NEXT_HOP,next_hop);

REDIS_BULK_CREATE(NEXT_HOP,next_hop);
REDIS_BULK_REMOVE(NEXT_HOP,next_hop);
REDIS_BULK_SET(NEXT_HOP,next_hop);
REDIS_BULK_GET(NEXT_HOP,next_hop);
const sai_next_hop_api_t redis_next_hop_api = {

    REDIS_GENERIC_QUAD_API(next_hop)
    redis_bulk_create_next_hop,
    redis_bulk_remove_next_hop,
    redis_bulk_set_next_hop,
    redis_bulk_get_next_hop
};
