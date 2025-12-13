#pragma once
#include <vector>
#include <functional>

#include "core/screen_request.h"

namespace core
{

class EventBus {
public:
  using ScreenRequestListener = std::function<void(const ScreenRequest&)>;

  void subscribeScreenRequests(ScreenRequestListener listener) {
    screenRequestListeners.push_back(std::move(listener));
  }

  void emit(const ScreenRequest& req) {
    for (auto& l : screenRequestListeners) {
      l(req);
    }
  }

private:
  std::vector<ScreenRequestListener> screenRequestListeners;

};

} // namespace core
