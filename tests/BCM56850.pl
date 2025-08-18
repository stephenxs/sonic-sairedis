#!/usr/bin/perl

BEGIN { push @INC,'.'; }

use strict;
use warnings;
use diagnostics;

use utils;

sub test_brcm_start_empty
{
    fresh_start;

    play "empty_sw.rec";
}

sub test_brcm_start_empty_to_empty
{
    fresh_start;

    play "empty_sw.rec";
    play "empty_sw.rec";
}

sub test_brcm_full
{
    fresh_start;

    play "full.rec";
}

sub test_brcm_full_to_empty
{
    fresh_start;

    play "full.rec";
    play "empty_sw.rec";
}

sub test_brcm_empty_to_full
{
    fresh_start;

    play "empty_sw.rec";
    play "full.rec";
}

sub test_brcm_empty_restart_to_full
{
    fresh_start;

    play "empty_sw.rec";

    kill_syncd;
    start_syncd;

    play "full.rec";
}

sub test_brcm_empty_to_full_to_empty_to_full_to_full
{
    fresh_start;

    play "empty_sw.rec";
    play "full.rec";
    play "empty_sw.rec";
    play "full_second.rec";
    play "full_second.rec";
}

sub test_brcm_full_to_full
{
    fresh_start;

    play "full.rec";
    play "full_second.rec";
}

sub test_brcm_full_to_full_no_bridge
{
    fresh_start;

    play "full.rec";
    play "full_second_no_bridge.rec";
}

sub test_brcm_full_to_full_no_bridge_restart
{
    fresh_start;

    play "full.rec";
    play "full_second_no_bridge.rec";

    kill_syncd;
    start_syncd;

    play "full_second_no_bridge.rec";
}

sub test_brcm_empty_to_full_to_empty
{
    fresh_start;

    play "empty_sw.rec";
    play "full.rec";
    play "empty_sw.rec";
}

sub test_brcm_empty_to_full_nhg_bug
{
    fresh_start;

    play "empty_sw.rec";
    play "full_nhg_bug.rec";
}

sub test_brcm_empty_to_full_prio_flow_bug
{
    fresh_start;

    play "empty_sw.rec";
    play "full_nhg_bug_prio_flow_bug.rec";
}

sub test_brcm_empty_to_full_trap_group_bug
{
    fresh_start;

    play "empty_sw.rec";
    play "full_nhg_bug_trap_group_create_fail.rec";
}

sub test_brcm_queue_bug_null_buffer_profile
{
    fresh_start;

    play "full_queue_bug_null_buffer_profile.rec";
    play "empty_sw.rec";
}

sub test_brcm_full_to_empty_no_queue
{
    fresh_start;

    play "full_no_queue.rec";
    play "empty_sw.rec";
}

sub test_brcm_full_to_empty_no_queue_no_ipg
{
    fresh_start;

    play "full_no_queue_no_ipg.rec";
    play "empty_sw.rec";
}

sub test_brcm_full_to_empty_hostif_remove_segfault
{
    fresh_start;

    play "full_hostif_remove_segfault.rec";
    play "empty_sw.rec";
}

sub test_brcm_full_to_empty_no_queue_no_ipg_no_buffer_profile
{
    fresh_start;

    play "full_no_queue_no_ipg_no_buffer_pfofile.rec";
    play "empty_sw.rec";
}

sub test_brcm_speed_init_apply
{
    fresh_start;

    play "speed_init.rec";
    play "speed_apply.rec";
}

sub test_brcm_lag_comparison_logic
{
    fresh_start;

    # we expect no asic operations on this test
    # even do lags looks the same, but are matched
    # using lag member and port

    play "lag_comparison_logic.rec";
    play "lag_comparison_logic.rec", 0;
}

sub test_brcm_nhg_comparison_logic
{
    fresh_start;

    # we expect no asic operations on this test
    # even do next hop groups looks the same, but are
    # matched using route destination prefix

    play "nhg_comparison_logic.rec";
    play "nhg_comparison_logic.rec", 0;
    play "nhg_comparison_logic.rec", 0;
}

sub test_brcm_remove_next_hop
{
    fresh_start;

    # we expect this will succeed, test checks
    # whether coparison logis on REMOVE operation
    # is working correctly and reference count will
    # be correct for each obejct when performing REMOVE

    play "remove_next_hop.rec";
    play "remove_next_hop.rec";
    play "remove_next_hop.rec";
    play "remove_next_hop.rec";
    play "remove_next_hop.rec";
}

sub test_brcm_hostif
{
    fresh_start;

    # we expect no asic operation on policer, hostif trap group, router interface

    play "hostif.rec";
    play "hostif.rec", 0;
    play "hostif.rec", 0;
}

sub test_brcm_full_testbed_config
{
    fresh_start;

    # we expect no asic operation on policer, hostif trap group, router interface

    play "full_testbed_config.rec";
    play "full_testbed_config.rec", 0;
    play "full_testbed_config.rec", 0;
}

sub test_brcm_rif_loopback
{
    fresh_start;

    # we expect no asic operation on router interface

    play "rif_loopback.rec";
    play "rif_loopback.rec", 0;
    play "rif_loopback.rec", 0;
    play "rif_loopback.rec", 0;
    play "rif_loopback.rec", 0;
    play "rif_loopback.rec", 0;
}

sub test_brcm_lag_no_members
{
    fresh_start;

    # we expect no asic operation on lag's that has no members

    play "lag_no_members.rec";
    play "lag_no_members.rec", 0;
    play "lag_no_members.rec", 0;
    play "lag_no_members.rec", 0;
    play "lag_no_members.rec", 0;
    play "lag_no_members.rec", 0;
}

sub test_brcm_qos_map_order
{
    fresh_start;

    # we expect no asic operation on qos maps that are the same but different order

    play "qos_map_order.rec", 0;
}

sub test_brcm_acl_tables
{
    fresh_start;

    # we expect no asic operation on lag's that has no members

    play "acl_tables.rec";
    play "acl_tables.rec", 0;
    play "acl_tables.rec", 0;
    play "acl_tables.rec", 0;
    play "acl_tables.rec", 0;
    play "acl_tables.rec", 0;
}

sub test_brcm_buffer_pool
{
    fresh_start;

    # we expect no operations on asic, and all buffer pools will be matched correctly

    play "full_buffer.rec";
    play "full_buffer_second.rec",0;
}

sub test_brcm_warm_boot_full
{
    fresh_start;

    play "full.rec";

    request_warm_shutdown;
    start_syncd_warm;

    play "full_second.rec";

    request_warm_shutdown;
}

sub test_brcm_warm_boot_empty
{
    fresh_start;

    play "empty_sw.rec";

    request_warm_shutdown;
    start_syncd_warm;

    play "empty_sw.rec", 0;

    request_warm_shutdown;
}

sub test_brcm_warm_boot_small_buffer
{
    fresh_start;

    play "small_buffer.rec";

    request_warm_shutdown;
    start_syncd_warm;

    play "small_buffer.rec", 0;

    request_warm_shutdown;
}

sub test_brcm_warm_boot_full_empty
{
    fresh_start;

    play "full.rec";

    request_warm_shutdown;
    start_syncd_warm;

    play "empty_sw.rec";
    play "empty_sw.rec", 0;
    play "full_second.rec";
    play "empty_sw.rec";

    request_warm_shutdown;
}

sub test_brcm_config_acl
{
    fresh_start;

    play "config_acl.rec";
    play "config_acl.rec", 0;

    fresh_start;

    play "config_acl2.rec";
    play "config_acl2.rec", 0;
}

sub test_brcm_warm_wred_queue
{
    fresh_start;

    play "wred_queue.rec";
    play "wred_queue.rec", 0;
    play "wred_queue.rec", 0;
    play "wred_queue.rec", 0;
    play "wred_queue.rec", 0;
    play "wred_queue.rec", 0;
    play "wred_queue.rec", 0;

    fresh_start;

    play "wred_queue.rec";

    request_warm_shutdown;
    start_syncd_warm;

    play "wred_queue.rec", 0;

    request_warm_shutdown;

    start_syncd_warm;

    play "wred_queue.rec", 0;
}

sub test_empty_lag_buffer_acl
{
    fresh_start;

    play "empty_lag_buffer_acl.rec";

    for (1..8) { play "empty_lag_buffer_acl.rec", 0; }
}

sub test_acl_mask
{
    fresh_start;

    play "acl_mask.rec";

    for (1..8) { play "acl_mask.rec", 0; }
}

sub test_ntf
{
    fresh_start;

    play "ntf1.rec";
    play "ntf2.rec", 1;
    play "ntf2.rec", 0;
    play "ntf1.rec", 1;
    play "ntf1.rec", 0;
}

sub test_bridge_create
{
    fresh_start;

    play "bridge_create_1.rec";
    play "bridge_create_2.rec", 0;
}

sub test_tunnel_map
{
    fresh_start;

    play "tunnel_map.rec";
    play "tunnel_map.rec", 0;
    play "tunnel_map.rec", 0;
    play "tunnel_map.rec", 0;
    play "tunnel_map.rec", 0;
    play "tunnel_map.rec", 0;
}

sub test_acl_counter
{
    fresh_start;

    play "acl_counter.rec";
    play "acl_counter.rec", 0;
    play "acl_counter.rec", 0;
    play "acl_counter.rec", 0;
    play "acl_counter.rec", 0;
    play "acl_counter.rec", 0;
}

sub test_remove_port
{
    fresh_start;

    play "remove_port.rec";
}

sub test_remove_create_port
{
    fresh_start;

    play "remove_create_port.rec";
}

sub test_acl_counter2
{
    fresh_start;

    play "acl_counter2.rec";
    play "acl_counter2.rec", 0;
    play "acl_counter2.rec", 0;
    play "acl_counter2.rec", 0;
    play "acl_counter2.rec", 0;
    play "acl_counter2.rec", 0;
}

sub test_brcm_warm_boot_port_remove
{
    fresh_start;

    play "wb_port_remove_a.rec";

    request_warm_shutdown;
    start_syncd_warm;

    play "wb_port_remove_b.rec";

    request_warm_shutdown;
}

sub test_sync_brcm_warm_boot_port_remove
{
    sync_fresh_start;

    sync_play "wb_port_remove_a.rec";

    request_warm_shutdown;
    sync_start_syncd_warm;

    sync_play "wb_port_remove_b.rec";

    request_warm_shutdown;
}

sub test_brcm_warm_boot_port_create
{
    fresh_start;

    play "wb_port_create_a.rec";

    request_warm_shutdown;
    start_syncd_warm;

    play "wb_port_create_b.rec";

    request_warm_shutdown;
}

sub test_brcm_query_attr_enum_values_capability
{
    fresh_start;

    play "query_attr_enum_values_capability.rec";
}

sub test_brcm_query_object_type_get_availability
{
    fresh_start;

    play "query_object_type_get_availability.rec";
}

sub test_brcm_acl_limit
{
    fresh_start("-b", "$utils::DIR/bbm.ini", "-p", "$utils::DIR/vsprofile_acl_limit.ini");

    play "acl_limit.rec";
}

sub test_brcm_buffer_pool_zmq
{
    fresh_start("-p", "$utils::DIR/vsprofile_ctx_zmq.ini", "-s", "-g", "0", "-x", "$utils::DIR/ctx_zmq.json");

    # we expect no operations on asic, and all buffer pools will be matched correctly

    play("-p", "$utils::DIR/vsprofile_ctx_zmq.ini", "full_buffer.rec");
    play("-p", "$utils::DIR/vsprofile_ctx_zmq.ini", "full_buffer_second.rec",0);
}

sub test_brcm_buffer_pool_zmq_sync_flag
{
    fresh_start("-p", "$utils::DIR/vsprofile.ini", "-g", "0", "-z", "zmq_sync");

    # we expect no operations on asic, and all buffer pools will be matched correctly

    play("-p", "$utils::DIR/vsprofile.ini", "-z", "zmq_sync", "full_buffer.rec");
    play("-p", "$utils::DIR/vsprofile.ini", "-z", "zmq_sync", "full_buffer_second.rec",0);
}

sub test_bulk_route
{
    fresh_start;

    play "bulk_route.rec"
}

sub test_bulk_neighbor
{
    fresh_start;

    play "bulk_neighbor.rec"
}

sub test_bulk_fdb
{
    fresh_start;

    play "bulk_fdb.rec"
}

sub test_emulated_bulk_object
{
    fresh_start;

    play "bulk_object.rec"
}

sub test_bulk_object
{
    fresh_start_bulk;

    play "bulk_object.rec"
}

sub test_depreacated_enums
{
    fresh_start;

    play "depreacated.rec";

    request_warm_shutdown;

    `perl -i.bak -pe 's/SAI_NEXT_HOP_GROUP_TYPE_DYNAMIC_UNORDERED_ECMP/SAI_NEXT_HOP_GROUP_TYPE_ECMP/' sai_warmboot.bin`;

    my $key = `redis-cli -n 1 "keys" "*"|grep SAI_OBJECT_TYPE_NEXT_HOP_GROUP`;

    chomp $key;

    `redis-cli -n 1 hset "$key" "SAI_NEXT_HOP_GROUP_ATTR_TYPE" "SAI_NEXT_HOP_GROUP_TYPE_ECMP"`;

    start_syncd_warm;

    play "non_depreacated.rec", 0;
}

sub test_bulk_set_multiple
{
    fresh_start;

    play "test_bulk_set_multiple_A.rec";
    play "test_bulk_set_multiple_B.rec", 0;
}

sub test_lag_label
{
    fresh_start;

    play "lag_label_A.rec";
    play "lag_label_B.rec";

    open (my $H, "<", "applyview.log") or die "failed to open applyview.log $!";

    my $line = <$H>;

    close ($H);

    chomp$line;

    if (not $line =~ /ASIC_OPERATIONS: (\d+)/ or $1 != 8)
    {
        print color('red') . "expected 8 ASIC_OPERATIONS count on first line, but got: '$line'" . color('reset') . "\n";
        exit 1;
    }
}

sub test_no_lag_label
{
    fresh_start;

    play "no_lag_label_A.rec";
    play "no_lag_label_B.rec", 2;
}

sub test_macsec_p2p_establishment
{
    fresh_start;

    play "test_macsec_p2p_establishment.rec";
}

sub test_sairedis_client
{
    fresh_start;

    # saiplayer here is acting as OA

    system("../saiplayer/saiplayer -u $utils::DIR/client_switch.rec &");

    sleep 1;

    `./testclient`;

    my $exit = $?;

    `killall -9 saiplayer`;

    if ($exit != 0)
    {
        print color('red') . "test client failed" . color('reset') . "\n";
        exit 1;
    }
}

sub test_ignore_attributes
{
    fresh_start;

    play "ignore_attributes.rec";
}

sub test_multi_switch_key
{
    fresh_start("-p", "$utils::DIR/vsprofile_ctx_multi.ini", "-g", "0", "-x", "$utils::DIR/ctx_multi.json");

    play("-p", "$utils::DIR/vsprofile_ctx_multi.ini", "multi_switch_key.rec");
}

sub test_buffer_profile_get
{
    fresh_start;

    play "buffer_profile_get_A.rec";
    play "buffer_profile_get_B.rec";
}

sub test_brcm_warm_new_object_port_serdes
{
    fresh_start;

    # use buffer profile and pool objects since they
    # are not default created on the switch
    # so asic operations should still be zero

    play "buffer_profile_get_A.rec";

    print "port serdes objects in ASIC_DB: ";
    print `redis-cli -n 1 keys "*_SERDES*" | wc -l`;

    request_warm_shutdown;

    # remove port serdes from asic db to simulate
    # previous boot didn't contained serdes objects

    print "port serdes entries (objects and attributes) in sai_warmboot.bin: ";
    print `cat sai_warmboot.bin | grep _SERDES_| wc -l`;

    print "removed port serdes objects from ASIC_DB: ";
    print `redis-cli -n 1 --scan --pattern '*SERDES*' |xargs redis-cli -n 1 DEL`;

    # need to handle rid2vid map

    print "removed port serdes from VIDTORID map: ";
    print `redis-cli -n 1 HKEYS VIDTORID |grep oid:0x5700 | xargs redis-cli -n 1 HDEL VIDTORID`;
    print "removed remove serdes from RIDTOVID map: ";
    print `redis-cli -n 1 HKEYS RIDTOVID |grep oid:0x5700 | xargs redis-cli -n 1 HDEL RIDTOVID`;

    start_syncd_warm;

    play "buffer_profile_get_A.rec", 0;

    print "check ASIC_DB for serdes\n";
    print "RIDTOVID: ", `redis-cli -n 1 HKEYS RIDTOVID |grep oid:0x5700 |wc -l`;
    print "VIDTORID: ", `redis-cli -n 1 HKEYS VIDTORID |grep oid:0x5700 |wc -l`;
    print "ASIC_DB: ", `redis-cli -n 1 keys "*_SERDES*"| wc -l`;
}

sub test_remove_port_serdes
{
    fresh_start;

    play "test_remove_port_serdes.rec";
}

sub test_lag_member
{
    fresh_start;

    play "test_lag_member.rec";
    play "test_lag_member.rec", 1;
    play "test_lag_member.rec", 1;
    play "test_lag_member.rec", 1;
    play "test_lag_member.rec", 1;
    play "test_lag_member.rec", 1;
}

sub test_neighbor_lag
{
    fresh_start;

    play "test_neighbor_lag.rec";
    play "test_neighbor_lag.rec", 3;
    play "test_neighbor_lag.rec", 3;
    play "test_neighbor_lag.rec", 3;
    play "test_neighbor_lag.rec", 3;
    play "test_neighbor_lag.rec", 3;
    play "test_neighbor_lag.rec", 3;
}

sub test_voq_switch_create
{
    fresh_start("-z", "redis_sync");

    play("-z", "redis_sync", "voq_switch_create.rec")
}

sub test_acl_counter_match
{
    # this will test scenario where we have 1 acl entry with counter and after
    # warm boot 2 acl entries and 2 counters the same which could end up
    # matching wrong acl counter and causing fail "object exist" on broadcom
    # acl entry set, which will require improve pre match logic for acl entry

    fresh_start;

    play "acl_counter_match.rec";

    open (my $H, "<", "applyview.log") or die "failed to open applyview.log $!";

    my $line = <$H>;

    close ($H);

    chomp$line;

    if (not $line =~ /ASIC_OPERATIONS: (\d+)/ or $1 != 2)
    {
        print color('red') . "expected 2 ASIC_OPERATIONS count on first line, but got: '$line'" . color('reset') . "\n";
        exit 1;
    }
}

sub test_relaxed
{
    fresh_start;

    play "relaxed.rec";
    play "relaxed.rec", 0;
}

sub test_acl_pre_match_999
{
    fresh_start;

    play "acl_pre_match_999.rec";

    for (1..8) { play "acl_pre_match_999.rec", 0; }
}

sub test_neighbor_next_hop
{
    fresh_start;

    play "neighbor_next_hop.rec";

    open (my $H, "<", "applyview.log") or die "failed to open applyview.log $!";

    my @lines = <$H>;

    close ($H);

    my $order = "";

    for(@lines)
    {
        $order .= "E" if /create.+NEIGHBOR_ENTRY:/;
        $order .= "N" if /create.+NEXT_HOP:/;
    }

    if (not $order =~ /^E+N+$/)
    {
        print color('red') . "Invalid order, expected neighbor created first, then next hop" . color('reset') . "\n";
        exit 1;
    }
}

sub test_port_bulk_get
{
    fresh_start;

    play "port_bulk_get.rec";
}

sub test_vxlan_default_router_mac
{
    fresh_start;

    play "vxlan_default_router_mac.rec";
}

# RUN TESTS

test_port_bulk_get
test_vxlan_default_router_mac;
test_neighbor_next_hop;
test_acl_pre_match_999;
test_relaxed;
test_acl_counter_match;
test_neighbor_lag;
test_lag_member;
test_remove_port_serdes;
test_brcm_warm_new_object_port_serdes;
test_buffer_profile_get;
test_multi_switch_key;
test_ignore_attributes;
test_sairedis_client;
test_macsec_p2p_establishment;
test_no_lag_label;
test_lag_label;
test_bulk_set_multiple;
test_depreacated_enums;
test_brcm_buffer_pool_zmq_sync_flag;
test_brcm_buffer_pool_zmq;
test_brcm_acl_limit;
test_sync_brcm_warm_boot_port_remove;
test_brcm_warm_boot_port_remove;
test_brcm_warm_boot_port_create;
test_remove_port;
test_remove_create_port;
test_acl_counter2;
test_acl_counter;
test_tunnel_map;
test_bridge_create;
test_ntf;
test_acl_mask;
test_empty_lag_buffer_acl;
test_bulk_route;
test_bulk_neighbor;
test_bulk_fdb;
test_emulated_bulk_object;
test_bulk_object;
test_brcm_config_acl;
test_brcm_warm_wred_queue;
test_brcm_warm_boot_full_empty;
test_brcm_warm_boot_small_buffer;
test_brcm_warm_boot_empty;
test_brcm_warm_boot_full;

test_brcm_buffer_pool;
test_brcm_acl_tables;
test_brcm_qos_map_order;
test_brcm_lag_no_members;
test_brcm_rif_loopback;
test_brcm_hostif;
test_brcm_full_testbed_config;
test_brcm_remove_next_hop;
test_brcm_nhg_comparison_logic;
test_brcm_lag_comparison_logic;
test_brcm_speed_init_apply;
test_brcm_start_empty;
test_brcm_start_empty_to_empty;
test_brcm_full;
test_brcm_full_to_empty;
test_brcm_empty_to_full;
test_brcm_empty_restart_to_full;
test_brcm_empty_to_full_to_empty_to_full_to_full;
test_brcm_full_to_full;
test_brcm_full_to_full_no_bridge;
test_brcm_full_to_full_no_bridge_restart;
test_brcm_empty_to_full_to_empty;
test_brcm_empty_to_full_nhg_bug;
test_brcm_empty_to_full_prio_flow_bug;
test_brcm_empty_to_full_trap_group_bug;
test_brcm_queue_bug_null_buffer_profile;
test_brcm_full_to_empty_no_queue;
test_brcm_full_to_empty_no_queue_no_ipg;
test_brcm_full_to_empty_hostif_remove_segfault;
test_brcm_full_to_empty_no_queue_no_ipg_no_buffer_profile;
test_brcm_query_attr_enum_values_capability;
test_brcm_query_object_type_get_availability;
test_voq_switch_create;

kill_syncd;
