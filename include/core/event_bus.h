#pragma once
#include <vector>
#include <functional>

/** Event types: GameModeChanged, KeyPressed, etc */
enum class EventType {
  // When we change game modes: MainMenu -> Playing.
  GameModeChanged
};

/** Event struct */
struct Event {
  EventType type;
};

// Handle event listener.
class EventBus {
public:
  using Listener = std::function<void(const Event&)>;

  void subscribe(Listener listener) {
    listeners.push_back(std::move(listener));
  }

  void emit(const Event& e) {
    for (auto& l : listeners) {
      l(e);
    }
  }
private:
  std::vector<Listener> listeners;
};
