#include "sai_redis.h"

static sai_status_t redis_clear_port_all_stats(
        _In_ sai_object_id_t port_id)
{
    SWSS_LOG_ENTER();

    return SAI_STATUS_NOT_IMPLEMENTED;
}

REDIS_GENERIC_QUAD(PORT,port);
REDIS_GENERIC_QUAD(PORT_POOL,port_pool);
REDIS_GENERIC_QUAD(PORT_SERDES,port_serdes);
REDIS_GENERIC_QUAD(PORT_CONNECTOR,port_connector);
REDIS_GENERIC_STATS(PORT,port);
REDIS_GENERIC_STATS(PORT_POOL,port_pool);

REDIS_BULK_CREATE(PORT,port);
REDIS_BULK_REMOVE(PORT,port);
REDIS_BULK_SET(PORT,port);
REDIS_BULK_GET_NEW(PORT,port);

const sai_port_api_t redis_port_api = {

    REDIS_GENERIC_QUAD_API(port)
    REDIS_GENERIC_STATS_API(port)

    redis_clear_port_all_stats,

    REDIS_GENERIC_QUAD_API(port_pool)
    REDIS_GENERIC_STATS_API(port_pool)
    REDIS_GENERIC_QUAD_API(port_connector)
    REDIS_GENERIC_QUAD_API(port_serdes)

    redis_bulk_create_port,
    redis_bulk_remove_port,
    redis_bulk_set_port,
    redis_bulk_get_port
};
