#ifndef SAMPLES_2_ICARDVIEW_H
#define SAMPLES_2_ICARDVIEW_H

#include <framework.h>

struct WifiSettings {
    char ssid[40];
    char password[40];
};

struct ThingSpeakSettings
{
    char write_api_key[40];
    char channel_id[40];
};

struct AppSettings {
    WifiSettings wifi;
    ThingSpeakSettings thingSpeak;
    bool initFromFile;
};

class ICardView :public ISensorName<ICardView>{
public:
    virtual AppSettings getSettings() = 0;
    ~ICardView() override = default;

    static const char* getSensorName() {
        return "ICardView";
    }
};

#endif //SAMPLES_2_ICARDVIEW_H
