// MESSAGE WIFI_NETWORK_INFO support class

#pragma once

namespace mavlink {
namespace development {
namespace msg {

/**
 * @brief WIFI_NETWORK_INFO message
 *
 * Detected WiFi network status information. This message is sent per each WiFi network detected in range with known SSID and general status parameters.
 */
struct WIFI_NETWORK_INFO : mavlink::Message {
    static constexpr msgid_t MSG_ID = 298;
    static constexpr size_t LENGTH = 37;
    static constexpr size_t MIN_LENGTH = 37;
    static constexpr uint8_t CRC_EXTRA = 237;
    static constexpr auto NAME = "WIFI_NETWORK_INFO";


    std::array<char, 32> ssid; /*<  Name of Wi-Fi network (SSID). */
    uint8_t channel_id; /*<  WiFi network operating channel ID. Set to 0 if unknown or unidentified. */
    uint8_t signal_quality; /*< [%] WiFi network signal quality. */
    uint16_t data_rate; /*< [MiB/s] WiFi network data rate. Set to UINT16_MAX if data_rate information is not supplied. */
    uint8_t security; /*<  WiFi network security type. */


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
        ss << "  ssid: \"" << to_string(ssid) << "\"" << std::endl;
        ss << "  channel_id: " << +channel_id << std::endl;
        ss << "  signal_quality: " << +signal_quality << std::endl;
        ss << "  data_rate: " << data_rate << std::endl;
        ss << "  security: " << +security << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << data_rate;                     // offset: 0
        map << ssid;                          // offset: 2
        map << channel_id;                    // offset: 34
        map << signal_quality;                // offset: 35
        map << security;                      // offset: 36
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> data_rate;                     // offset: 0
        map >> ssid;                          // offset: 2
        map >> channel_id;                    // offset: 34
        map >> signal_quality;                // offset: 35
        map >> security;                      // offset: 36
    }
};

} // namespace msg
} // namespace development
} // namespace mavlink
