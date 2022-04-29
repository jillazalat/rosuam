/** @file
 *	@brief MAVLink comm testsuite protocol generated from development.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "development.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(development, PARAM_ACK_TRANSACTION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::PARAM_ACK_TRANSACTION packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.param_id = to_char_array("GHIJKLMNOPQRSTU");
    packet_in.param_value = 17.0;
    packet_in.param_type = 199;
    packet_in.param_result = 10;

    mavlink::development::msg::PARAM_ACK_TRANSACTION packet1{};
    mavlink::development::msg::PARAM_ACK_TRANSACTION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.param_id, packet2.param_id);
    EXPECT_EQ(packet1.param_value, packet2.param_value);
    EXPECT_EQ(packet1.param_type, packet2.param_type);
    EXPECT_EQ(packet1.param_result, packet2.param_result);
}

#ifdef TEST_INTEROP
TEST(development_interop, PARAM_ACK_TRANSACTION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_param_ack_transaction_t packet_c {
         17.0, 17, 84, "GHIJKLMNOPQRSTU", 199, 10
    };

    mavlink::development::msg::PARAM_ACK_TRANSACTION packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.param_id = to_char_array("GHIJKLMNOPQRSTU");
    packet_in.param_value = 17.0;
    packet_in.param_type = 199;
    packet_in.param_result = 10;

    mavlink::development::msg::PARAM_ACK_TRANSACTION packet2{};

    mavlink_msg_param_ack_transaction_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.param_id, packet2.param_id);
    EXPECT_EQ(packet_in.param_value, packet2.param_value);
    EXPECT_EQ(packet_in.param_type, packet2.param_type);
    EXPECT_EQ(packet_in.param_result, packet2.param_result);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(development, MISSION_CHANGED)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::MISSION_CHANGED packet_in{};
    packet_in.start_index = 17235;
    packet_in.end_index = 17339;
    packet_in.origin_sysid = 17;
    packet_in.origin_compid = 84;
    packet_in.mission_type = 151;

    mavlink::development::msg::MISSION_CHANGED packet1{};
    mavlink::development::msg::MISSION_CHANGED packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.start_index, packet2.start_index);
    EXPECT_EQ(packet1.end_index, packet2.end_index);
    EXPECT_EQ(packet1.origin_sysid, packet2.origin_sysid);
    EXPECT_EQ(packet1.origin_compid, packet2.origin_compid);
    EXPECT_EQ(packet1.mission_type, packet2.mission_type);
}

#ifdef TEST_INTEROP
TEST(development_interop, MISSION_CHANGED)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_mission_changed_t packet_c {
         17235, 17339, 17, 84, 151
    };

    mavlink::development::msg::MISSION_CHANGED packet_in{};
    packet_in.start_index = 17235;
    packet_in.end_index = 17339;
    packet_in.origin_sysid = 17;
    packet_in.origin_compid = 84;
    packet_in.mission_type = 151;

    mavlink::development::msg::MISSION_CHANGED packet2{};

    mavlink_msg_mission_changed_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.start_index, packet2.start_index);
    EXPECT_EQ(packet_in.end_index, packet2.end_index);
    EXPECT_EQ(packet_in.origin_sysid, packet2.origin_sysid);
    EXPECT_EQ(packet_in.origin_compid, packet2.origin_compid);
    EXPECT_EQ(packet_in.mission_type, packet2.mission_type);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(development, MISSION_CHECKSUM)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::MISSION_CHECKSUM packet_in{};
    packet_in.mission_type = 17;
    packet_in.checksum = 963497464;

    mavlink::development::msg::MISSION_CHECKSUM packet1{};
    mavlink::development::msg::MISSION_CHECKSUM packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.mission_type, packet2.mission_type);
    EXPECT_EQ(packet1.checksum, packet2.checksum);
}

#ifdef TEST_INTEROP
TEST(development_interop, MISSION_CHECKSUM)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_mission_checksum_t packet_c {
         963497464, 17
    };

    mavlink::development::msg::MISSION_CHECKSUM packet_in{};
    packet_in.mission_type = 17;
    packet_in.checksum = 963497464;

    mavlink::development::msg::MISSION_CHECKSUM packet2{};

    mavlink_msg_mission_checksum_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.mission_type, packet2.mission_type);
    EXPECT_EQ(packet_in.checksum, packet2.checksum);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(development, AIRSPEED)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::AIRSPEED packet_in{};
    packet_in.id = 187;
    packet_in.airspeed = 17.0;
    packet_in.temperature = 18067;
    packet_in.press_diff = 45.0;
    packet_in.press_static = 73.0;
    packet_in.error = 101.0;
    packet_in.type = 254;

    mavlink::development::msg::AIRSPEED packet1{};
    mavlink::development::msg::AIRSPEED packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.id, packet2.id);
    EXPECT_EQ(packet1.airspeed, packet2.airspeed);
    EXPECT_EQ(packet1.temperature, packet2.temperature);
    EXPECT_EQ(packet1.press_diff, packet2.press_diff);
    EXPECT_EQ(packet1.press_static, packet2.press_static);
    EXPECT_EQ(packet1.error, packet2.error);
    EXPECT_EQ(packet1.type, packet2.type);
}

#ifdef TEST_INTEROP
TEST(development_interop, AIRSPEED)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airspeed_t packet_c {
         17.0, 45.0, 73.0, 101.0, 18067, 187, 254
    };

    mavlink::development::msg::AIRSPEED packet_in{};
    packet_in.id = 187;
    packet_in.airspeed = 17.0;
    packet_in.temperature = 18067;
    packet_in.press_diff = 45.0;
    packet_in.press_static = 73.0;
    packet_in.error = 101.0;
    packet_in.type = 254;

    mavlink::development::msg::AIRSPEED packet2{};

    mavlink_msg_airspeed_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.id, packet2.id);
    EXPECT_EQ(packet_in.airspeed, packet2.airspeed);
    EXPECT_EQ(packet_in.temperature, packet2.temperature);
    EXPECT_EQ(packet_in.press_diff, packet2.press_diff);
    EXPECT_EQ(packet_in.press_static, packet2.press_static);
    EXPECT_EQ(packet_in.error, packet2.error);
    EXPECT_EQ(packet_in.type, packet2.type);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(development, WIFI_NETWORK_INFO)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::WIFI_NETWORK_INFO packet_in{};
    packet_in.ssid = to_char_array("CDEFGHIJKLMNOPQRSTUVWXYZABCDEFG");
    packet_in.channel_id = 235;
    packet_in.signal_quality = 46;
    packet_in.data_rate = 17235;
    packet_in.security = 113;

    mavlink::development::msg::WIFI_NETWORK_INFO packet1{};
    mavlink::development::msg::WIFI_NETWORK_INFO packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.ssid, packet2.ssid);
    EXPECT_EQ(packet1.channel_id, packet2.channel_id);
    EXPECT_EQ(packet1.signal_quality, packet2.signal_quality);
    EXPECT_EQ(packet1.data_rate, packet2.data_rate);
    EXPECT_EQ(packet1.security, packet2.security);
}

#ifdef TEST_INTEROP
TEST(development_interop, WIFI_NETWORK_INFO)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_wifi_network_info_t packet_c {
         17235, "CDEFGHIJKLMNOPQRSTUVWXYZABCDEFG", 235, 46, 113
    };

    mavlink::development::msg::WIFI_NETWORK_INFO packet_in{};
    packet_in.ssid = to_char_array("CDEFGHIJKLMNOPQRSTUVWXYZABCDEFG");
    packet_in.channel_id = 235;
    packet_in.signal_quality = 46;
    packet_in.data_rate = 17235;
    packet_in.security = 113;

    mavlink::development::msg::WIFI_NETWORK_INFO packet2{};

    mavlink_msg_wifi_network_info_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.ssid, packet2.ssid);
    EXPECT_EQ(packet_in.channel_id, packet2.channel_id);
    EXPECT_EQ(packet_in.signal_quality, packet2.signal_quality);
    EXPECT_EQ(packet_in.data_rate, packet2.data_rate);
    EXPECT_EQ(packet_in.security, packet2.security);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(development, COMPONENT_INFORMATION_BASIC)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::COMPONENT_INFORMATION_BASIC packet_in{};
    packet_in.time_boot_ms = 963497880;
    packet_in.vendor_name = {{ 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72 }};
    packet_in.model_name = {{ 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168 }};
    packet_in.software_version = to_char_array("YZABCDEFGHIJKLMNOPQRSTU");
    packet_in.hardware_version = to_char_array("WXYZABCDEFGHIJKLMNOPQRS");
    packet_in.capabilities = 93372036854775807ULL;

    mavlink::development::msg::COMPONENT_INFORMATION_BASIC packet1{};
    mavlink::development::msg::COMPONENT_INFORMATION_BASIC packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.vendor_name, packet2.vendor_name);
    EXPECT_EQ(packet1.model_name, packet2.model_name);
    EXPECT_EQ(packet1.software_version, packet2.software_version);
    EXPECT_EQ(packet1.hardware_version, packet2.hardware_version);
    EXPECT_EQ(packet1.capabilities, packet2.capabilities);
}

#ifdef TEST_INTEROP
TEST(development_interop, COMPONENT_INFORMATION_BASIC)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_component_information_basic_t packet_c {
         93372036854775807ULL, 963497880, { 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72 }, { 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168 }, "YZABCDEFGHIJKLMNOPQRSTU", "WXYZABCDEFGHIJKLMNOPQRS"
    };

    mavlink::development::msg::COMPONENT_INFORMATION_BASIC packet_in{};
    packet_in.time_boot_ms = 963497880;
    packet_in.vendor_name = {{ 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72 }};
    packet_in.model_name = {{ 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168 }};
    packet_in.software_version = to_char_array("YZABCDEFGHIJKLMNOPQRSTU");
    packet_in.hardware_version = to_char_array("WXYZABCDEFGHIJKLMNOPQRS");
    packet_in.capabilities = 93372036854775807ULL;

    mavlink::development::msg::COMPONENT_INFORMATION_BASIC packet2{};

    mavlink_msg_component_information_basic_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.vendor_name, packet2.vendor_name);
    EXPECT_EQ(packet_in.model_name, packet2.model_name);
    EXPECT_EQ(packet_in.software_version, packet2.software_version);
    EXPECT_EQ(packet_in.hardware_version, packet2.hardware_version);
    EXPECT_EQ(packet_in.capabilities, packet2.capabilities);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(development, GROUP_START)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::GROUP_START packet_in{};
    packet_in.group_id = 963497880;
    packet_in.mission_checksum = 963498088;
    packet_in.time_usec = 93372036854775807ULL;

    mavlink::development::msg::GROUP_START packet1{};
    mavlink::development::msg::GROUP_START packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.group_id, packet2.group_id);
    EXPECT_EQ(packet1.mission_checksum, packet2.mission_checksum);
    EXPECT_EQ(packet1.time_usec, packet2.time_usec);
}

#ifdef TEST_INTEROP
TEST(development_interop, GROUP_START)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_group_start_t packet_c {
         93372036854775807ULL, 963497880, 963498088
    };

    mavlink::development::msg::GROUP_START packet_in{};
    packet_in.group_id = 963497880;
    packet_in.mission_checksum = 963498088;
    packet_in.time_usec = 93372036854775807ULL;

    mavlink::development::msg::GROUP_START packet2{};

    mavlink_msg_group_start_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.group_id, packet2.group_id);
    EXPECT_EQ(packet_in.mission_checksum, packet2.mission_checksum);
    EXPECT_EQ(packet_in.time_usec, packet2.time_usec);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(development, GROUP_END)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::GROUP_END packet_in{};
    packet_in.group_id = 963497880;
    packet_in.mission_checksum = 963498088;
    packet_in.time_usec = 93372036854775807ULL;

    mavlink::development::msg::GROUP_END packet1{};
    mavlink::development::msg::GROUP_END packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.group_id, packet2.group_id);
    EXPECT_EQ(packet1.mission_checksum, packet2.mission_checksum);
    EXPECT_EQ(packet1.time_usec, packet2.time_usec);
}

#ifdef TEST_INTEROP
TEST(development_interop, GROUP_END)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_group_end_t packet_c {
         93372036854775807ULL, 963497880, 963498088
    };

    mavlink::development::msg::GROUP_END packet_in{};
    packet_in.group_id = 963497880;
    packet_in.mission_checksum = 963498088;
    packet_in.time_usec = 93372036854775807ULL;

    mavlink::development::msg::GROUP_END packet2{};

    mavlink_msg_group_end_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.group_id, packet2.group_id);
    EXPECT_EQ(packet_in.mission_checksum, packet2.mission_checksum);
    EXPECT_EQ(packet_in.time_usec, packet2.time_usec);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(development, AVAILABLE_MODES)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::AVAILABLE_MODES packet_in{};
    packet_in.number_modes = 17;
    packet_in.mode_index = 84;
    packet_in.standard_mode = 151;
    packet_in.base_mode = 218;
    packet_in.custom_mode = 963497464;
    packet_in.mode_name = to_char_array("IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDE");

    mavlink::development::msg::AVAILABLE_MODES packet1{};
    mavlink::development::msg::AVAILABLE_MODES packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.number_modes, packet2.number_modes);
    EXPECT_EQ(packet1.mode_index, packet2.mode_index);
    EXPECT_EQ(packet1.standard_mode, packet2.standard_mode);
    EXPECT_EQ(packet1.base_mode, packet2.base_mode);
    EXPECT_EQ(packet1.custom_mode, packet2.custom_mode);
    EXPECT_EQ(packet1.mode_name, packet2.mode_name);
}

#ifdef TEST_INTEROP
TEST(development_interop, AVAILABLE_MODES)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_available_modes_t packet_c {
         963497464, 17, 84, 151, 218, "IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDE"
    };

    mavlink::development::msg::AVAILABLE_MODES packet_in{};
    packet_in.number_modes = 17;
    packet_in.mode_index = 84;
    packet_in.standard_mode = 151;
    packet_in.base_mode = 218;
    packet_in.custom_mode = 963497464;
    packet_in.mode_name = to_char_array("IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDE");

    mavlink::development::msg::AVAILABLE_MODES packet2{};

    mavlink_msg_available_modes_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.number_modes, packet2.number_modes);
    EXPECT_EQ(packet_in.mode_index, packet2.mode_index);
    EXPECT_EQ(packet_in.standard_mode, packet2.standard_mode);
    EXPECT_EQ(packet_in.base_mode, packet2.base_mode);
    EXPECT_EQ(packet_in.custom_mode, packet2.custom_mode);
    EXPECT_EQ(packet_in.mode_name, packet2.mode_name);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(development, CURRENT_MODE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::development::msg::CURRENT_MODE packet_in{};
    packet_in.standard_mode = 17;
    packet_in.base_mode = 84;
    packet_in.custom_mode = 963497464;

    mavlink::development::msg::CURRENT_MODE packet1{};
    mavlink::development::msg::CURRENT_MODE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.standard_mode, packet2.standard_mode);
    EXPECT_EQ(packet1.base_mode, packet2.base_mode);
    EXPECT_EQ(packet1.custom_mode, packet2.custom_mode);
}

#ifdef TEST_INTEROP
TEST(development_interop, CURRENT_MODE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_current_mode_t packet_c {
         963497464, 17, 84
    };

    mavlink::development::msg::CURRENT_MODE packet_in{};
    packet_in.standard_mode = 17;
    packet_in.base_mode = 84;
    packet_in.custom_mode = 963497464;

    mavlink::development::msg::CURRENT_MODE packet2{};

    mavlink_msg_current_mode_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.standard_mode, packet2.standard_mode);
    EXPECT_EQ(packet_in.base_mode, packet2.base_mode);
    EXPECT_EQ(packet_in.custom_mode, packet2.custom_mode);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
