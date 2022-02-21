#include "sai_vs.h"

VS_GENERIC_QUAD(NEXT_HOP,next_hop);

VS_BULK_CREATE(NEXT_HOP,next_hop);
VS_BULK_REMOVE(NEXT_HOP,next_hop);
VS_BULK_SET(NEXT_HOP,next_hop);
VS_BULK_GET(NEXT_HOP,next_hop);

const sai_next_hop_api_t vs_next_hop_api = {

    VS_GENERIC_QUAD_API(next_hop)

    vs_bulk_create_next_hop,
    vs_bulk_remove_next_hop,
    vs_bulk_set_next_hop,
    vs_bulk_get_next_hop
};
