// MESSAGE CURRENT_MODE support class

#pragma once

namespace mavlink {
namespace development {
namespace msg {

/**
 * @brief CURRENT_MODE message
 *
 * Get the current mode.
        This should be emitted on any mode change, and broadcast at low rate (nominally 0.5 Hz).
        It may be requested using MAV_CMD_REQUEST_MESSAGE.
      
 */
struct CURRENT_MODE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 436;
    static constexpr size_t LENGTH = 6;
    static constexpr size_t MIN_LENGTH = 6;
    static constexpr uint8_t CRC_EXTRA = 151;
    static constexpr auto NAME = "CURRENT_MODE";


    uint8_t standard_mode; /*<  Standard mode. */
    uint8_t base_mode; /*<  System mode bitmap. */
    uint32_t custom_mode; /*<  A bitfield for use for autopilot-specific flags */


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
        ss << "  standard_mode: " << +standard_mode << std::endl;
        ss << "  base_mode: " << +base_mode << std::endl;
        ss << "  custom_mode: " << custom_mode << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << custom_mode;                   // offset: 0
        map << standard_mode;                 // offset: 4
        map << base_mode;                     // offset: 5
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> custom_mode;                   // offset: 0
        map >> standard_mode;                 // offset: 4
        map >> base_mode;                     // offset: 5
    }
};

} // namespace msg
} // namespace development
} // namespace mavlink
