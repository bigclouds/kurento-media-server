/* Autogenerated with Kurento Idl */

#ifndef __GSTREAMER_FILTER_HPP__
#define __GSTREAMER_FILTER_HPP__

#include <jsoncpp/json/json.h>
#include <JsonRpcException.hpp>
#include <ObjectRegistrar.hpp>
#include <memory>
#include <vector>
#include "Filter.hpp"

namespace kurento {

class MediaPipeline;

class GStreamerFilter : public virtual Filter {

public:

  GStreamerFilter () {};
  virtual ~GStreamerFilter () {};

  virtual std::string connect(const std::string &eventType, std::shared_ptr<EventHandler> handler);

  class Factory : public virtual kurento::Factory
  {
  public:
    Factory () {};

    virtual std::string getName () {
      return "GStreamerFilter";
    };

  private:

    virtual MediaObject * createObjectPointer (const Json::Value &params);

    MediaObject * createObject (std::shared_ptr<MediaPipeline> mediaPipeline, const std::string& command);

    class StaticConstructor
    {
    public:
      StaticConstructor();
    };

    static StaticConstructor staticConstructor;

  };

  class Invoker : public virtual Filter::Invoker
  {
  public:
    Invoker() {};
    virtual void invoke (std::shared_ptr<MediaObject> obj,
        const std::string &methodName, const Json::Value &params,
        Json::Value &response);
  };

  virtual MediaObject::Invoker &getInvoker() {
    return invoker;
  }

  private:
    Invoker invoker;

};

} /* kurento */

#endif /*  __GSTREAMER_FILTER_HPP__ */
