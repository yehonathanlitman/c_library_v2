/** @file
 *    @brief MAVLink comm protocol testsuite generated from modquad_control.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef MODQUAD_CONTROL_TESTSUITE_H
#define MODQUAD_CONTROL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_modquad_control(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_modquad_control(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_modquad_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MODQUAD_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_modquad_control_t packet_in = {
        93372036854775807ULL,{ 73.0, 74.0, 75.0, 76.0 },185.0,213.0,101
    };
    mavlink_modquad_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.modquad_control_flag = packet_in.modquad_control_flag;
        
        mav_array_memcpy(packet1.modquad_control_coeffs, packet_in.modquad_control_coeffs, sizeof(float)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_modquad_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_modquad_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_modquad_control_pack(system_id, component_id, &msg , packet1.time_usec , packet1.modquad_control_flag , packet1.modquad_control_coeffs , packet1.x , packet1.y );
    mavlink_msg_modquad_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_modquad_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.modquad_control_flag , packet1.modquad_control_coeffs , packet1.x , packet1.y );
    mavlink_msg_modquad_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_modquad_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_modquad_control_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.modquad_control_flag , packet1.modquad_control_coeffs , packet1.x , packet1.y );
    mavlink_msg_modquad_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_modquad_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_modquad_control(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MODQUAD_CONTROL_TESTSUITE_H
