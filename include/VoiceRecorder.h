// src/VoiceRecorder.h
#ifndef VOICERECORDER_H
#define VOICERECORDER_H

#include <SFML/Audio.hpp>
#include <vector>
#include <cmath>
#include <algorithm>

class VoiceRecorder : public sf::SoundRecorder {
public:
    VoiceRecorder();
    float getVolume() const;
    bool setDevice(const std::string& deviceName);
    std::vector<std::string> getAvailableDevices() const;

private:
    virtual bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
    float currentVolume;
};

#endif // VOICERECORDER_H