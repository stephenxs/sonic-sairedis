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

    std::string group("QUEUE_WATERMARK_STAT_COUNTER");
    std::string poll_interval = "10000";
    std::string plugin_name = "QUEUE_PLUGIN_LIST";
    std::string plugins = "";
    std::string stats_mode = "STATS_MODE_READ_AND_CLEAR";
    std::string operation = "enable";

    flexCounterGroupParam.counter_group_name.list = (int8_t*)const_cast<char *>(group.c_str());
    flexCounterGroupParam.counter_group_name.count = (uint32_t)group.length();
    flexCounterGroupParam.poll_interval.list = (int8_t*)const_cast<char *>(poll_interval.c_str());
    flexCounterGroupParam.poll_interval.count = (uint32_t)poll_interval.length();
    flexCounterGroupParam.plugin_name.list = (int8_t*)const_cast<char *>(plugin_name.c_str());
    flexCounterGroupParam.plugin_name.count = (uint32_t)plugin_name.length();
    flexCounterGroupParam.plugins.list = (int8_t*)const_cast<char *>(plugins.c_str());
    flexCounterGroupParam.plugins.count = (uint32_t)plugins.length();
    flexCounterGroupParam.stats_mode.list = (int8_t*)const_cast<char *>(stats_mode.c_str());
    flexCounterGroupParam.stats_mode.count = (uint32_t)stats_mode.length();
    flexCounterGroupParam.operation.list = (int8_t*)const_cast<char *>(operation.c_str());;
    flexCounterGroupParam.operation.count = (uint32_t)operation.length();

    attr.id = SAI_REDIS_SWITCH_ATTR_FLEX_COUNTER_GROUP;
    attr.value.ptr = (void*)&flexCounterGroupParam;

    EXPECT_EQ(SAI_STATUS_SUCCESS, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));

    flexCounterGroupParam.counter_group_name.count = 100;
    EXPECT_EQ(SAI_STATUS_FAILURE, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));

    flexCounterGroupParam.counter_group_name.list = nullptr;
    EXPECT_EQ(SAI_STATUS_FAILURE, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));

    attr.value.ptr = nullptr;
    EXPECT_EQ(SAI_STATUS_FAILURE, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));
}

TEST(RedisRemoteSaiInterface, notifyCounterOperations)
{
    auto recorder = std::make_shared<Recorder>();
    auto cc = std::make_shared<ContextConfig>(0, "syncd", "ASIC_DB", "COUNTERS_DB","FLEX_DB", "STATE_DB");
    auto rrsi = std::make_shared<RedisRemoteSaiInterface>(cc, handle_notification, recorder);

    sai_attribute_t attr;
    sai_redis_flex_counter_parameter_t flexCounterParam;

    std::string oid = "oid:0x15000000000001";
    std::string counters = "SAI_QUEUE_STAT_SHARED_WATERMARK_BYTES";
    std::string counter_field_name = "QUEUE_COUNTER_ID_LIST";
    std::string mode = "STATS_MODE_READ";

    flexCounterParam.counter_key.list = (int8_t*)const_cast<char *>(oid.c_str());
    flexCounterParam.counter_key.count = (uint32_t)oid.length();
    flexCounterParam.counter_ids.list = (int8_t*)const_cast<char *>(counters.c_str());
    flexCounterParam.counter_ids.count = (uint32_t)counters.length();
    flexCounterParam.counter_field_name.list = (int8_t*)const_cast<char *>(counter_field_name.c_str());
    flexCounterParam.counter_field_name.count = (uint32_t)counter_field_name.length();
    flexCounterParam.stats_mode.list = (int8_t*)const_cast<char *>(mode.c_str());

    attr.id = SAI_REDIS_SWITCH_ATTR_FLEX_COUNTER;
    attr.value.ptr = (void*)&flexCounterParam;

    EXPECT_EQ(SAI_STATUS_SUCCESS, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));

    flexCounterParam.counter_ids.list = nullptr;
    EXPECT_EQ(SAI_STATUS_SUCCESS, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));

    flexCounterParam.counter_field_name.list = nullptr;
    flexCounterParam.counter_ids.list = (int8_t*)const_cast<char *>(counters.c_str());
    EXPECT_EQ(SAI_STATUS_SUCCESS, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));

    flexCounterParam.counter_key.list = nullptr;
    EXPECT_EQ(SAI_STATUS_FAILURE, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));

    attr.value.ptr = nullptr;
    EXPECT_EQ(SAI_STATUS_FAILURE, rrsi->set(SAI_OBJECT_TYPE_SWITCH, SAI_NULL_OBJECT_ID, &attr));
}
