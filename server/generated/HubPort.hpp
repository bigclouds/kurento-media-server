/* Autogenerated with Kurento Idl */

#ifndef __HUB_PORT_HPP__
#define __HUB_PORT_HPP__

#include <jsoncpp/json/json.h>
#include <JsonRpcException.hpp>
#include <ObjectRegistrar.hpp>
#include <memory>
#include <vector>
#include "MediaElement.hpp"

namespace kurento {

class Hub;

class HubPort : public virtual MediaElement {

public:

  HubPort () {};
  virtual ~HubPort () {};

  virtual std::string connect(const std::string &eventType, std::shared_ptr<EventHandler> handler);

  class Factory : public virtual kurento::Factory
  {
  public:
    Factory () {};

    virtual std::string getName () {
      return "HubPort";
    };

  private:

    virtual MediaObject * createObjectPointer (const Json::Value &params);

    MediaObject * createObject (std::shared_ptr<Hub> hub);

    class StaticConstructor
    {
    public:
      StaticConstructor();
    };

    static StaticConstructor staticConstructor;

  };

  class Invoker : public virtual MediaElement::Invoker
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

#endif /*  __HUB_PORT_HPP__ */
