#pragma once
// MESSAGE MODQUAD_CONTROL PACKING

#define MAVLINK_MSG_ID_MODQUAD_CONTROL 388

MAVPACKED(
typedef struct __mavlink_modquad_control_t {
 uint64_t time_usec; /*< [us] Timestamp (micros since boot or Unix epoch)*/
 float modquad_control_coeffs[4]; /*<  The control coefficients for the four rotors once enabling the modquad control*/
 float x; /*< [m] X position in meters (In Structure frame)*/
 float y; /*< [m] Y position in meters (In Structure frame)*/
 uint8_t modquad_control_flag; /*<  The flag indicating the control method in the firmware*/
}) mavlink_modquad_control_t;

#define MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN 33
#define MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN 33
#define MAVLINK_MSG_ID_388_LEN 33
#define MAVLINK_MSG_ID_388_MIN_LEN 33

#define MAVLINK_MSG_ID_MODQUAD_CONTROL_CRC 192
#define MAVLINK_MSG_ID_388_CRC 192

#define MAVLINK_MSG_MODQUAD_CONTROL_FIELD_MODQUAD_CONTROL_COEFFS_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MODQUAD_CONTROL { \
    388, \
    "MODQUAD_CONTROL", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_modquad_control_t, time_usec) }, \
         { "modquad_control_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_modquad_control_t, modquad_control_flag) }, \
         { "modquad_control_coeffs", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_modquad_control_t, modquad_control_coeffs) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_modquad_control_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_modquad_control_t, y) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MODQUAD_CONTROL { \
    "MODQUAD_CONTROL", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_modquad_control_t, time_usec) }, \
         { "modquad_control_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_modquad_control_t, modquad_control_flag) }, \
         { "modquad_control_coeffs", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_modquad_control_t, modquad_control_coeffs) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_modquad_control_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_modquad_control_t, y) }, \
         } \
}
#endif

/**
 * @brief Pack a modquad_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (micros since boot or Unix epoch)
 * @param modquad_control_flag  The flag indicating the control method in the firmware
 * @param modquad_control_coeffs  The control coefficients for the four rotors once enabling the modquad control
 * @param x [m] X position in meters (In Structure frame)
 * @param y [m] Y position in meters (In Structure frame)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_modquad_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t modquad_control_flag, const float *modquad_control_coeffs, float x, float y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_uint8_t(buf, 32, modquad_control_flag);
    _mav_put_float_array(buf, 8, modquad_control_coeffs, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN);
#else
    mavlink_modquad_control_t packet;
    packet.time_usec = time_usec;
    packet.x = x;
    packet.y = y;
    packet.modquad_control_flag = modquad_control_flag;
    mav_array_memcpy(packet.modquad_control_coeffs, modquad_control_coeffs, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MODQUAD_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_CRC);
}

/**
 * @brief Pack a modquad_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (micros since boot or Unix epoch)
 * @param modquad_control_flag  The flag indicating the control method in the firmware
 * @param modquad_control_coeffs  The control coefficients for the four rotors once enabling the modquad control
 * @param x [m] X position in meters (In Structure frame)
 * @param y [m] Y position in meters (In Structure frame)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_modquad_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t modquad_control_flag,const float *modquad_control_coeffs,float x,float y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_uint8_t(buf, 32, modquad_control_flag);
    _mav_put_float_array(buf, 8, modquad_control_coeffs, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN);
#else
    mavlink_modquad_control_t packet;
    packet.time_usec = time_usec;
    packet.x = x;
    packet.y = y;
    packet.modquad_control_flag = modquad_control_flag;
    mav_array_memcpy(packet.modquad_control_coeffs, modquad_control_coeffs, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MODQUAD_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_CRC);
}

/**
 * @brief Encode a modquad_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param modquad_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_modquad_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_modquad_control_t* modquad_control)
{
    return mavlink_msg_modquad_control_pack(system_id, component_id, msg, modquad_control->time_usec, modquad_control->modquad_control_flag, modquad_control->modquad_control_coeffs, modquad_control->x, modquad_control->y);
}

/**
 * @brief Encode a modquad_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param modquad_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_modquad_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_modquad_control_t* modquad_control)
{
    return mavlink_msg_modquad_control_pack_chan(system_id, component_id, chan, msg, modquad_control->time_usec, modquad_control->modquad_control_flag, modquad_control->modquad_control_coeffs, modquad_control->x, modquad_control->y);
}

/**
 * @brief Send a modquad_control message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (micros since boot or Unix epoch)
 * @param modquad_control_flag  The flag indicating the control method in the firmware
 * @param modquad_control_coeffs  The control coefficients for the four rotors once enabling the modquad control
 * @param x [m] X position in meters (In Structure frame)
 * @param y [m] Y position in meters (In Structure frame)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_modquad_control_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t modquad_control_flag, const float *modquad_control_coeffs, float x, float y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_uint8_t(buf, 32, modquad_control_flag);
    _mav_put_float_array(buf, 8, modquad_control_coeffs, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODQUAD_CONTROL, buf, MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_CRC);
#else
    mavlink_modquad_control_t packet;
    packet.time_usec = time_usec;
    packet.x = x;
    packet.y = y;
    packet.modquad_control_flag = modquad_control_flag;
    mav_array_memcpy(packet.modquad_control_coeffs, modquad_control_coeffs, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODQUAD_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_CRC);
#endif
}

/**
 * @brief Send a modquad_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_modquad_control_send_struct(mavlink_channel_t chan, const mavlink_modquad_control_t* modquad_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_modquad_control_send(chan, modquad_control->time_usec, modquad_control->modquad_control_flag, modquad_control->modquad_control_coeffs, modquad_control->x, modquad_control->y);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODQUAD_CONTROL, (const char *)modquad_control, MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_modquad_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t modquad_control_flag, const float *modquad_control_coeffs, float x, float y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_uint8_t(buf, 32, modquad_control_flag);
    _mav_put_float_array(buf, 8, modquad_control_coeffs, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODQUAD_CONTROL, buf, MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_CRC);
#else
    mavlink_modquad_control_t *packet = (mavlink_modquad_control_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->x = x;
    packet->y = y;
    packet->modquad_control_flag = modquad_control_flag;
    mav_array_memcpy(packet->modquad_control_coeffs, modquad_control_coeffs, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODQUAD_CONTROL, (const char *)packet, MAVLINK_MSG_ID_MODQUAD_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN, MAVLINK_MSG_ID_MODQUAD_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE MODQUAD_CONTROL UNPACKING


/**
 * @brief Get field time_usec from modquad_control message
 *
 * @return [us] Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_modquad_control_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field modquad_control_flag from modquad_control message
 *
 * @return  The flag indicating the control method in the firmware
 */
static inline uint8_t mavlink_msg_modquad_control_get_modquad_control_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field modquad_control_coeffs from modquad_control message
 *
 * @return  The control coefficients for the four rotors once enabling the modquad control
 */
static inline uint16_t mavlink_msg_modquad_control_get_modquad_control_coeffs(const mavlink_message_t* msg, float *modquad_control_coeffs)
{
    return _MAV_RETURN_float_array(msg, modquad_control_coeffs, 4,  8);
}

/**
 * @brief Get field x from modquad_control message
 *
 * @return [m] X position in meters (In Structure frame)
 */
static inline float mavlink_msg_modquad_control_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field y from modquad_control message
 *
 * @return [m] Y position in meters (In Structure frame)
 */
static inline float mavlink_msg_modquad_control_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a modquad_control message into a struct
 *
 * @param msg The message to decode
 * @param modquad_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_modquad_control_decode(const mavlink_message_t* msg, mavlink_modquad_control_t* modquad_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    modquad_control->time_usec = mavlink_msg_modquad_control_get_time_usec(msg);
    mavlink_msg_modquad_control_get_modquad_control_coeffs(msg, modquad_control->modquad_control_coeffs);
    modquad_control->x = mavlink_msg_modquad_control_get_x(msg);
    modquad_control->y = mavlink_msg_modquad_control_get_y(msg);
    modquad_control->modquad_control_flag = mavlink_msg_modquad_control_get_modquad_control_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN;
        memset(modquad_control, 0, MAVLINK_MSG_ID_MODQUAD_CONTROL_LEN);
    memcpy(modquad_control, _MAV_PAYLOAD(msg), len);
#endif
}
