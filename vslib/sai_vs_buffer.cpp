#include "sai_vs.h"

VS_GENERIC_QUAD(BUFFER_POOL,buffer_pool);
VS_GENERIC_QUAD(INGRESS_PRIORITY_GROUP,ingress_priority_group);
VS_GENERIC_QUAD(BUFFER_PROFILE,buffer_profile);
VS_GENERIC_STATS(BUFFER_POOL,buffer_pool);
VS_GENERIC_STATS(INGRESS_PRIORITY_GROUP,ingress_priority_group);

VS_BULK_CREATE(INGRESS_PRIORITY_GROUP,ingress_priority_group);
VS_BULK_REMOVE(INGRESS_PRIORITY_GROUP,ingress_priority_group);
VS_BULK_SET(INGRESS_PRIORITY_GROUP,ingress_priority_group);
VS_BULK_GET(INGRESS_PRIORITY_GROUP,ingress_priority_group);

const sai_buffer_api_t vs_buffer_api = {

    VS_GENERIC_QUAD_API(buffer_pool)
    VS_GENERIC_STATS_API(buffer_pool)
    VS_GENERIC_QUAD_API(ingress_priority_group)
    VS_GENERIC_STATS_API(ingress_priority_group)
    VS_GENERIC_QUAD_API(buffer_profile)

    vs_bulk_create_ingress_priority_group,
    vs_bulk_remove_ingress_priority_group,
    vs_bulk_set_ingress_priority_group,
    vs_bulk_get_ingress_priority_group
};
