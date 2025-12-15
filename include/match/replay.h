#pragma once
#include <vector>
#include "input/game_input.h"

namespace match {

class Replay {
public:
    void clear() { frames.clear(); cursor = 0; recording = false; playing = false; }

    void startRecording() { clear(); recording = true; }
    void stopRecording() { recording = false; }

    void startPlayback() { playing = true; recording = false; cursor = 0; }
    void stopPlayback() { playing = false; cursor = 0; }

    bool isRecording() const { return recording; }
    bool isPlaying() const { return playing; }

    void push(const input::GameInputFrame& f) {
        if (recording) frames.push_back(f);
    }

    // Returns false if playback ended
    bool next(input::GameInputFrame& out) {
        if (!playing) return false;
        if (cursor >= frames.size()) { stopPlayback(); return false; }
        out = frames[cursor++];
        return true;
    }

    std::size_t size() const { return frames.size(); }
    std::size_t position() const { return cursor; }

private:
    std::vector<input::GameInputFrame> frames;
    std::size_t cursor = 0;
    bool recording = false;
    bool playing = false;
};

} // namespace match
