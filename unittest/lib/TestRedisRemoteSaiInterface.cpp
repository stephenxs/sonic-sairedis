#include "Context.h"
#include "RedisRemoteSaiInterface.h"

#include <gtest/gtest.h>

#include <memory>

using namespace sairedis;

static sai_switch_notifications_t handle_notification(
        _In_ std::shared_ptr<Notification> notification)
{
    SWSS_LOG_ENTER();

    sai_switch_notifications_t ntf;

    memset(&ntf, 0, sizeof(ntf));

    return ntf;
}

TEST(RedisRemoteSaiInterface, notifyCounterGroupOperations)
{
    auto recorder = std::make_shared<Recorder>();
    auto cc = std::make_shared<ContextConfig>(0, "syncd", "ASIC_DB", "COUNTERS_DB","FLEX_DB", "STATE_DB");
    auto rrsi = std::make_shared<RedisRemoteSaiInterface>(cc, handle_notification, recorder);

    sai_attribute_t attr;
    sai_redis_flex_counter_group_parameter_t flexCounterGroupParam;

    flexCounterGroupParam.counter_group_name = "QUEUE_WATERMARK_STAT_COUNTER";
    flexCounterGroupParam.poll_interval = "10000";
    flexCounterGroupParam.plugin_name = "QUEUE_PLUGIN_LIST";
    flexCounterGroupParam.plugins = "";
    flexCounterGroupParam.stats_mode = "STATS_MODE_READ_AND_CLEAR";
    flexCounterGroupParam.operation = nullptr;

    attr.id = SAI_REDIS_SWITCH_ATTR_FLEX_COUNTER_GROUP;
    attr.value.ptr = (void*)&flexCounterGroupParam;

    EXPECT_EQ(SAI_STATUS_SUCCESS, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));
}

TEST(RedisRemoteSaiInterface, notifyCounterOperations)
{
    auto recorder = std::make_shared<Recorder>();
    auto cc = std::make_shared<ContextConfig>(0, "syncd", "ASIC_DB", "COUNTERS_DB","FLEX_DB", "STATE_DB");
    auto rrsi = std::make_shared<RedisRemoteSaiInterface>(cc, handle_notification, recorder);

    sai_attribute_t attr;
    sai_redis_flex_counter_parameter_t flexCounterParam;

    flexCounterParam.counter_key = "oid:0x15000000000001";
    flexCounterParam.counter_ids = "SAI_QUEUE_STAT_SHARED_WATERMARK_BYTES";
    flexCounterParam.counter_field_name = "QUEUE_COUNTER_ID_LIST";

    attr.id = SAI_REDIS_SWITCH_ATTR_FLEX_COUNTER;
    attr.value.ptr = (void*)&flexCounterParam;

    EXPECT_EQ(SAI_STATUS_SUCCESS, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));
}
