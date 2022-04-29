// MESSAGE AVAILABLE_MODES support class

#pragma once

namespace mavlink {
namespace development {
namespace msg {

/**
 * @brief AVAILABLE_MODES message
 *
 * Get information about a particular flight modes.
        The message can be enumerated or requested for a particular mode using MAV_CMD_REQUEST_MESSAGE.
        Specify 0 in param2 to request that the message is emitted for all available modes or the specific index for just one mode.
        The modes must be available/settable for the current vehicle/frame type.
        Each modes should only be emitted once (even if it is both standard and custom).
      
 */
struct AVAILABLE_MODES : mavlink::Message {
    static constexpr msgid_t MSG_ID = 435;
    static constexpr size_t LENGTH = 58;
    static constexpr size_t MIN_LENGTH = 58;
    static constexpr uint8_t CRC_EXTRA = 94;
    static constexpr auto NAME = "AVAILABLE_MODES";


    uint8_t number_modes; /*<  The total number of available modes for the current vehicle type. */
    uint8_t mode_index; /*<  The current mode index within number_modes, indexed from 1. */
    uint8_t standard_mode; /*<  Standard mode. */
    uint8_t base_mode; /*<  System mode bitmap. */
    uint32_t custom_mode; /*<  A bitfield for use for autopilot-specific flags */
    std::array<char, 50> mode_name; /*<  Name of custom mode, with null termination character. Should be omitted for standard modes. */


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
        ss << "  number_modes: " << +number_modes << std::endl;
        ss << "  mode_index: " << +mode_index << std::endl;
        ss << "  standard_mode: " << +standard_mode << std::endl;
        ss << "  base_mode: " << +base_mode << std::endl;
        ss << "  custom_mode: " << custom_mode << std::endl;
        ss << "  mode_name: \"" << to_string(mode_name) << "\"" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << custom_mode;                   // offset: 0
        map << number_modes;                  // offset: 4
        map << mode_index;                    // offset: 5
        map << standard_mode;                 // offset: 6
        map << base_mode;                     // offset: 7
        map << mode_name;                     // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> custom_mode;                   // offset: 0
        map >> number_modes;                  // offset: 4
        map >> mode_index;                    // offset: 5
        map >> standard_mode;                 // offset: 6
        map >> base_mode;                     // offset: 7
        map >> mode_name;                     // offset: 8
    }
};

} // namespace msg
} // namespace development
} // namespace mavlink
