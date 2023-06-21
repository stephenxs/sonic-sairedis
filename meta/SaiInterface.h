#pragma once

extern "C" {
#include "sai.h"
#include "saimetadata.h"
}

#define SAIREDIS_DECLARE_EVERY_ENTRY(_X)    \
    _X(FDB_ENTRY,fdb_entry);                \
    _X(INSEG_ENTRY,inseg_entry);            \
    _X(IPMC_ENTRY,ipmc_entry);              \
    _X(L2MC_ENTRY,l2mc_entry);              \
    _X(MCAST_FDB_ENTRY,mcast_fdb_entry);    \
    _X(NEIGHBOR_ENTRY,neighbor_entry);      \
    _X(ROUTE_ENTRY,route_entry);            \
    _X(NAT_ENTRY,nat_entry);                \
    _X(MY_SID_ENTRY,my_sid_entry);          \

#define SAIREDIS_DECLARE_EVERY_BULK_ENTRY(_X)   \
    _X(FDB_ENTRY,fdb_entry);                    \
    _X(INSEG_ENTRY,inseg_entry);                \
    _X(NAT_ENTRY,nat_entry);                    \
    _X(ROUTE_ENTRY,route_entry);                \
    _X(MY_SID_ENTRY,my_sid_entry);              \
    _X(NEIGHBOR_ENTRY,neighbor_entry);          \

#define SAIREDIS_SAIINTERFACE_DECLARE_QUAD_ENTRY_VIRTUAL(OT,ot)     \
    virtual sai_status_t create(                                    \
            _In_ const sai_ ## ot ## _t* ot,                        \
            _In_ uint32_t attr_count,                               \
            _In_ const sai_attribute_t *attr_list) = 0;             \
    virtual sai_status_t remove(                                    \
            _In_ const sai_ ## ot ## _t* ot) = 0;                   \
    virtual sai_status_t set(                                       \
            _In_ const sai_ ## ot ## _t* ot,                        \
            _In_ const sai_attribute_t *attr) = 0;                  \
    virtual sai_status_t get(                                       \
            _In_ const sai_ ## ot ## _t* ot,                        \
            _In_ uint32_t attr_count,                               \
            _Out_ sai_attribute_t *attr_list) = 0;                  \

#define SAIREDIS_SAIINTERFACE_DECLARE_QUAD_ENTRY_OVERRIDE(OT,ot)    \
    virtual sai_status_t create(                                    \
            _In_ const sai_ ## ot ## _t* ot,                        \
            _In_ uint32_t attr_count,                               \
            _In_ const sai_attribute_t *attr_list) override;        \
    virtual sai_status_t remove(                                    \
            _In_ const sai_ ## ot ## _t* ot) override;              \
    virtual sai_status_t set(                                       \
            _In_ const sai_ ## ot ## _t* ot,                        \
            _In_ const sai_attribute_t *attr) override;             \
    virtual sai_status_t get(                                       \
            _In_ const sai_ ## ot ## _t* ot,                        \
            _In_ uint32_t attr_count,                               \
            _Out_ sai_attribute_t *attr_list) override;             \

#define SAIREDIS_SAIINTERFACE_DECLARE_BULK_ENTRY_VIRTUAL(OT,ot)     \
    virtual sai_status_t bulkCreate(                                \
            _In_ uint32_t object_count,                             \
            _In_ const sai_ ## ot ## _t *ot,                        \
            _In_ const uint32_t *attr_count,                        \
            _In_ const sai_attribute_t **attr_list,                 \
            _In_ sai_bulk_op_error_mode_t mode,                     \
            _Out_ sai_status_t *object_statuses) = 0;               \
    virtual sai_status_t bulkRemove(                                \
            _In_ uint32_t object_count,                             \
            _In_ const sai_ ## ot ## _t *ot,                        \
            _In_ sai_bulk_op_error_mode_t mode,                     \
            _Out_ sai_status_t *object_statuses) = 0;               \
    virtual sai_status_t bulkSet(                                   \
            _In_ uint32_t object_count,                             \
            _In_ const sai_ ## ot ## _t *ot,                        \
            _In_ const sai_attribute_t *attr_list,                  \
            _In_ sai_bulk_op_error_mode_t mode,                     \
            _Out_ sai_status_t *object_statuses) = 0;               \

#define SAIREDIS_SAIINTERFACE_DECLARE_BULK_ENTRY_OVERRIDE(OT,ot)    \
    virtual sai_status_t bulkCreate(                                \
            _In_ uint32_t object_count,                             \
            _In_ const sai_ ## ot ## _t *ot,                        \
            _In_ const uint32_t *attr_count,                        \
            _In_ const sai_attribute_t **attr_list,                 \
            _In_ sai_bulk_op_error_mode_t mode,                     \
            _Out_ sai_status_t *object_statuses) override;          \
    virtual sai_status_t bulkRemove(                                \
            _In_ uint32_t object_count,                             \
            _In_ const sai_ ## ot ## _t *ot,                        \
            _In_ sai_bulk_op_error_mode_t mode,                     \
            _Out_ sai_status_t *object_statuses) override;          \
    virtual sai_status_t bulkSet(                                   \
            _In_ uint32_t object_count,                             \
            _In_ const sai_ ## ot ## _t *ot,                        \
            _In_ const sai_attribute_t *attr_list,                  \
            _In_ sai_bulk_op_error_mode_t mode,                     \
            _Out_ sai_status_t *object_statuses) override;          \

namespace sairedis
{
    class SaiInterface
    {
        public:

            SaiInterface() = default;

            virtual ~SaiInterface() = default;

        public:

            virtual sai_status_t initialize(
                    _In_ uint64_t flags,
                    _In_ const sai_service_method_table_t *service_method_table) = 0;

            virtual sai_status_t uninitialize(void) = 0;

        public: // QUAD oid

            virtual sai_status_t create(
                    _In_ sai_object_type_t objectType,
                    _Out_ sai_object_id_t* objectId,
                    _In_ sai_object_id_t switchId,
                    _In_ uint32_t attr_count,
                    _In_ const sai_attribute_t *attr_list) = 0;

            virtual sai_status_t remove(
                    _In_ sai_object_type_t objectType,
                    _In_ sai_object_id_t objectId) = 0;

            virtual sai_status_t set(
                    _In_ sai_object_type_t objectType,
                    _In_ sai_object_id_t objectId,
                    _In_ const sai_attribute_t *attr) = 0;

            virtual sai_status_t get(
                    _In_ sai_object_type_t objectType,
                    _In_ sai_object_id_t objectId,
                    _In_ uint32_t attr_count,
                    _Inout_ sai_attribute_t *attr_list) = 0;

        public: // QUAD ENTRY and BULK QUAD ENTRY

            SAIREDIS_DECLARE_EVERY_ENTRY(SAIREDIS_SAIINTERFACE_DECLARE_QUAD_ENTRY_VIRTUAL);
            SAIREDIS_DECLARE_EVERY_BULK_ENTRY(SAIREDIS_SAIINTERFACE_DECLARE_BULK_ENTRY_VIRTUAL);

        public: // bulk QUAD oid

            virtual sai_status_t bulkCreate(
                    _In_ sai_object_type_t object_type,
                    _In_ sai_object_id_t switch_id,
                    _In_ uint32_t object_count,
                    _In_ const uint32_t *attr_count,
                    _In_ const sai_attribute_t **attr_list,
                    _In_ sai_bulk_op_error_mode_t mode,
                    _Out_ sai_object_id_t *object_id,
                    _Out_ sai_status_t *object_statuses) = 0;

            virtual sai_status_t bulkRemove(
                    _In_ sai_object_type_t object_type,
                    _In_ uint32_t object_count,
                    _In_ const sai_object_id_t *object_id,
                    _In_ sai_bulk_op_error_mode_t mode,
                    _Out_ sai_status_t *object_statuses) = 0;

            virtual sai_status_t bulkSet(
                    _In_ sai_object_type_t object_type,
                    _In_ uint32_t object_count,
                    _In_ const sai_object_id_t *object_id,
                    _In_ const sai_attribute_t *attr_list,
                    _In_ sai_bulk_op_error_mode_t mode,
                    _Out_ sai_status_t *object_statuses) = 0;

        public: // QUAD meta key

            virtual sai_status_t create(
                    _Inout_ sai_object_meta_key_t& metaKey,
                    _In_ sai_object_id_t switch_id,
                    _In_ uint32_t attr_count,
                    _In_ const sai_attribute_t *attr_list);

            virtual sai_status_t remove(
                    _In_ const sai_object_meta_key_t& metaKey);

            virtual sai_status_t set(
                    _In_ const sai_object_meta_key_t& metaKey,
                    _In_ const sai_attribute_t *attr);

            virtual sai_status_t get(
                    _In_ const sai_object_meta_key_t& metaKey,
                    _In_ uint32_t attr_count,
                    _Inout_ sai_attribute_t *attr_list);

        public: // stats API

            virtual sai_status_t getStats(
                    _In_ sai_object_type_t object_type,
                    _In_ sai_object_id_t object_id,
                    _In_ uint32_t number_of_counters,
                    _In_ const sai_stat_id_t *counter_ids,
                    _Out_ uint64_t *counters) = 0;

            virtual sai_status_t queryStatsCapability(
                    _In_ sai_object_id_t switch_id,
                    _In_ sai_object_type_t object_type,
                    _Inout_ sai_stat_capability_list_t *stats_capability) = 0;

            virtual sai_status_t getStatsExt(
                    _In_ sai_object_type_t object_type,
                    _In_ sai_object_id_t object_id,
                    _In_ uint32_t number_of_counters,
                    _In_ const sai_stat_id_t *counter_ids,
                    _In_ sai_stats_mode_t mode,
                    _Out_ uint64_t *counters) = 0;

            virtual sai_status_t clearStats(
                    _In_ sai_object_type_t object_type,
                    _In_ sai_object_id_t object_id,
                    _In_ uint32_t number_of_counters,
                    _In_ const sai_stat_id_t *counter_ids) = 0;

            virtual sai_status_t bulkGetStats(
                    _In_ sai_object_id_t switchId,
                    _In_ sai_object_type_t object_type,
                    _In_ uint32_t object_count,
                    _In_ const sai_object_key_t *object_key,
                    _In_ uint32_t number_of_counters,
                    _In_ const sai_stat_id_t *counter_ids,
                    _In_ sai_stats_mode_t mode,
                    _Inout_ sai_status_t *object_statuses,
                    _Out_ uint64_t *counters) = 0;

            virtual sai_status_t bulkClearStats(
                    _In_ sai_object_id_t switchId,
                    _In_ sai_object_type_t object_type,
                    _In_ uint32_t object_count,
                    _In_ const sai_object_key_t *object_key,
                    _In_ uint32_t number_of_counters,
                    _In_ const sai_stat_id_t *counter_ids,
                    _In_ sai_stats_mode_t mode,
                    _Inout_ sai_status_t *object_statuses) = 0;

        public: // non QUAD API

            virtual sai_status_t flushFdbEntries(
                    _In_ sai_object_id_t switchId,
                    _In_ uint32_t attrCount,
                    _In_ const sai_attribute_t *attrList) = 0;

            virtual sai_status_t switchMdioRead(
                    _In_ sai_object_id_t switch_id,
                    _In_ uint32_t device_addr,
                    _In_ uint32_t start_reg_addr,
                    _In_ uint32_t number_of_registers,
                    _Out_ uint32_t *reg_val);

            virtual sai_status_t switchMdioWrite(
                    _In_ sai_object_id_t switch_id,
                    _In_ uint32_t device_addr,
                    _In_ uint32_t start_reg_addr,
                    _In_ uint32_t number_of_registers,
                    _In_ const uint32_t *reg_val);

            virtual sai_status_t switchMdioCl22Read(
                    _In_ sai_object_id_t switch_id,
                    _In_ uint32_t device_addr,
                    _In_ uint32_t start_reg_addr,
                    _In_ uint32_t number_of_registers,
                    _Out_ uint32_t *reg_val);

            virtual sai_status_t switchMdioCl22Write(
                    _In_ sai_object_id_t switch_id,
                    _In_ uint32_t device_addr,
                    _In_ uint32_t start_reg_addr,
                    _In_ uint32_t number_of_registers,
                    _In_ const uint32_t *reg_val);

        public: // SAI API

            virtual sai_status_t objectTypeGetAvailability(
                    _In_ sai_object_id_t switchId,
                    _In_ sai_object_type_t objectType,
                    _In_ uint32_t attrCount,
                    _In_ const sai_attribute_t *attrList,
                    _Out_ uint64_t *count) = 0;

            virtual sai_status_t queryAttributeCapability(
                    _In_ sai_object_id_t switch_id,
                    _In_ sai_object_type_t object_type,
                    _In_ sai_attr_id_t attr_id,
                    _Out_ sai_attr_capability_t *capability) = 0;

            virtual sai_status_t queryAattributeEnumValuesCapability(
                    _In_ sai_object_id_t switch_id,
                    _In_ sai_object_type_t object_type,
                    _In_ sai_attr_id_t attr_id,
                    _Inout_ sai_s32_list_t *enum_values_capability) = 0;

            virtual sai_object_type_t objectTypeQuery(
                    _In_ sai_object_id_t objectId) = 0;

            virtual sai_object_id_t switchIdQuery(
                    _In_ sai_object_id_t objectId) = 0;

            virtual sai_status_t logSet(
                    _In_ sai_api_t api,
                    _In_ sai_log_level_t log_level) = 0;

    public:
        virtual sai_status_t sai_bulk_get_attribute(
            _In_ sai_object_id_t switch_id,
            _In_ sai_object_type_t object_type,
            _In_ uint32_t object_count,
            _In_ const sai_object_key_t *object_key,
            _Inout_ uint32_t *attr_count,
            _Inout_ sai_attribute_t **attr_list,
            _Inout_ sai_status_t *object_statuses) = 0;

    };
}
