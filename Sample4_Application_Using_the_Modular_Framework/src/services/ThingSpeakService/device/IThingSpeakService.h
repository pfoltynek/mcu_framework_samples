#ifndef SAMPLES_2_ITHINGSPEAKSERVICE_H
#define SAMPLES_2_ITHINGSPEAKSERVICE_H

#include <framework.h>

class IThingSpeakService : public IServiceName<IThingSpeakService> {
    public:
        virtual void init(const char* ssid, const char* password, const char* channel_id,const char* write_api_key) = 0;
        ~IThingSpeakService() override = default;

        static const char* getServiceName() {
            return "ITeamSpeakService";
        }
};

#endif //SAMPLES_2_ITHINGSPEAKSERVICE_H
