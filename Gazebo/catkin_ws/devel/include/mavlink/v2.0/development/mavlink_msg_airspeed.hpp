// MESSAGE AIRSPEED support class

#pragma once

namespace mavlink {
namespace development {
namespace msg {

/**
 * @brief AIRSPEED message
 *
 * Airspeed information from a sensor.
 */
struct AIRSPEED : mavlink::Message {
    static constexpr msgid_t MSG_ID = 295;
    static constexpr size_t LENGTH = 20;
    static constexpr size_t MIN_LENGTH = 20;
    static constexpr uint8_t CRC_EXTRA = 41;
    static constexpr auto NAME = "AIRSPEED";


    uint8_t id; /*<  Sensor ID. */
    float airspeed; /*< [m/s] Calibrated airspeed (CAS) if available, otherwise indicated airspeed (IAS). */
    int16_t temperature; /*< [cdegC] Temperature. INT16_MAX for value unknown/not supplied. */
    float press_diff; /*< [hPa] Differential pressure. NaN for value unknown/not supplied. */
    float press_static; /*< [hPa] Static pressure. NaN for value unknown/not supplied. */
    float error; /*< [m/s] Error/accuracy. NaN for value unknown/not supplied. */
    uint8_t type; /*<  Airspeed sensor type. NaN for value unknown/not supplied. Used to estimate accuracy (i.e. as an alternative to using the error field). */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  id: " << +id << std::endl;
        ss << "  airspeed: " << airspeed << std::endl;
        ss << "  temperature: " << temperature << std::endl;
        ss << "  press_diff: " << press_diff << std::endl;
        ss << "  press_static: " << press_static << std::endl;
        ss << "  error: " << error << std::endl;
        ss << "  type: " << +type << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << airspeed;                      // offset: 0
        map << press_diff;                    // offset: 4
        map << press_static;                  // offset: 8
        map << error;                         // offset: 12
        map << temperature;                   // offset: 16
        map << id;                            // offset: 18
        map << type;                          // offset: 19
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> airspeed;                      // offset: 0
        map >> press_diff;                    // offset: 4
        map >> press_static;                  // offset: 8
        map >> error;                         // offset: 12
        map >> temperature;                   // offset: 16
        map >> id;                            // offset: 18
        map >> type;                          // offset: 19
    }
};

} // namespace msg
} // namespace development
} // namespace mavlink
