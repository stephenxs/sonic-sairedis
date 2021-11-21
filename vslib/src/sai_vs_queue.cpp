#include "sai_vs.h"

VS_GENERIC_QUAD(QUEUE,queue);
VS_GENERIC_STATS(QUEUE,queue);

VS_BULK_CREATE(QUEUE,queue);
VS_BULK_REMOVE(QUEUE,queue);
VS_BULK_SET(QUEUE,queue);
VS_BULK_GET(QUEUE,queue);

const sai_queue_api_t vs_queue_api = {

    VS_GENERIC_QUAD_API(queue)
    VS_GENERIC_STATS_API(queue)

    vs_bulk_create_queue,
    vs_bulk_remove_queue,
    vs_bulk_set_queue,
    vs_bulk_get_queue
};
