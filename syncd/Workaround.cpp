#include "Workaround.h"

#include "meta/sai_serialize.h"

#include "swss/logger.h"

using namespace syncd;

/**
 * @def Maximum port count on port notification
 */
#define MAX_PORT_COUNT (4096)

/**
 * @brief Determines whether attribute is "workaround" attribute for SET API.
 *
 * Some attributes are not supported on SET API on different platforms.
 * For example SAI_SWITCH_ATTR_SRC_MAC_ADDRESS.
 *
 * Some attributes like SAI_HOSTIF_ATTR_QUEUE may not be supported on BRCM
 * platform until vendor will implement them, but it will return success on
 * querySwitchCapability on OA. Support for query switch capability can show up
 * on warm boot when booting new SAI firmware.
 *
 * @param[in] objectType Object type.
 * @param[in] attrId Attribute Id.
 * @param[in] status Status from SET API.
 *
 * @return True if error from SET API can be ignored, false otherwise.
 */
bool Workaround::isSetAttributeWorkaround(
        _In_ sai_object_type_t objectType,
        _In_ sai_attr_id_t attrId,
        _In_ sai_status_t status)
{
    SWSS_LOG_ENTER();

    if (status == SAI_STATUS_SUCCESS)
    {
        return false;
    }

    if (objectType == SAI_OBJECT_TYPE_SWITCH &&
            attrId == SAI_SWITCH_ATTR_SRC_MAC_ADDRESS)
    {
        SWSS_LOG_WARN("setting %s failed: %s, not all platforms support this attribute",
                sai_metadata_get_attr_metadata(objectType, attrId)->attridname,
                sai_serialize_status(status).c_str());

        return true;
    }

    if (objectType == SAI_OBJECT_TYPE_SWITCH &&
            attrId == SAI_SWITCH_ATTR_VXLAN_DEFAULT_ROUTER_MAC)
    {
        SWSS_LOG_WARN("setting %s failed: %s, not all platforms support this attribute",
                sai_metadata_get_attr_metadata(objectType, attrId)->attridname,
                sai_serialize_status(status).c_str());

        return true;
    }

    if (objectType == SAI_OBJECT_TYPE_HOSTIF &&
            attrId == SAI_HOSTIF_ATTR_QUEUE)
    {
        SWSS_LOG_WARN("setting %s failed: %s, not all platforms support this attribute",
                sai_metadata_get_attr_metadata(objectType, attrId)->attridname,
                sai_serialize_status(status).c_str());

        return true;
    }

    return false;
}

std::vector<sai_port_oper_status_notification_t> Workaround::convertPortOperStatusNotification(
        _In_ const uint32_t count,
        _In_ const sai_port_oper_status_notification_t* data,
        _In_ sai_api_version_t version)
{
    SWSS_LOG_ENTER();

    std::vector<sai_port_oper_status_notification_t> ntf;

    if (data == nullptr || count > MAX_PORT_COUNT)
    {
        SWSS_LOG_ERROR("invalid notification parameters: data: %p, count: %d", data, count);

        return ntf;
    }

    if (version > SAI_VERSION(1,14,0))
    {
        // structure is compatible, no need for change

        ntf.assign(data, data + count);

        return ntf;
    }

    SWSS_LOG_INFO("converting sai_port_oper_status_notification_t data from %lu to %u", version, SAI_API_VERSION);

    const sai_port_oper_status_notification_v1_14_0_t* dataold =
        reinterpret_cast<const sai_port_oper_status_notification_v1_14_0_t*>(data);

    for (uint32_t i = 0; i < count; i++)
    {
        sai_port_oper_status_notification_t item{ dataold[i].port_id, dataold[i].port_state, (sai_port_error_status_t)0};

        ntf.push_back(item);
    }

    return ntf;
}
