// src/VoiceRecorder.cpp
#include "../include/VoiceRecorder.h"

VoiceRecorder::VoiceRecorder() : currentVolume(0.0f) {
    // Set the channel count to 1 (mono) for simplicity
    setChannelCount(1);
    // You can also add setDevice("your-mic-name") if you want to specify a mic
}

// This function is called by SFML whenever it has a new chunk of audio data
bool VoiceRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount) {
    long long sumOfAmplitudes = 0;
    for (std::size_t i = 0; i < sampleCount; ++i) {
        // We use abs() because sound waves go both positive and negative
        sumOfAmplitudes += std::abs(samples[i]);
    }

    // Calculate the average amplitude and then normalize it to a 0.0 - 1.0 range.
    // An Int16 can go up to 32767.
    float rawVolume = static_cast<float>(sumOfAmplitudes / sampleCount) / 32767.0f;
    
    // Apply amplification for better sensitivity (3x boost)
    float amplifiedVolume = rawVolume * 3.0f;
    
    // REDUCED smoothing for faster response (was 0.7, now 0.3)
    // Lower value = faster response, less smoothing
    const float smoothingFactor = 0.3f;
    currentVolume = (smoothingFactor * currentVolume) + ((1.0f - smoothingFactor) * amplifiedVolume);
    
    // Clamp the volume to prevent it from going above 1.0
    if (currentVolume > 1.0f) {
        currentVolume = 1.0f;
    }
    
    // We return true to tell SFML to continue recording
    return true;
}

// This is the public function we will call from our main program to get the volume
float VoiceRecorder::getVolume() const {
    return currentVolume;
}

bool VoiceRecorder::setDevice(const std::string& deviceName) {
    return sf::SoundRecorder::setDevice(deviceName);
}

std::vector<std::string> VoiceRecorder::getAvailableDevices() const {
    return sf::SoundRecorder::getAvailableDevices();
}