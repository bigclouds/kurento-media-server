/*
 * (C) Copyright 2014 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#include "HttpGetEndpointImpl.hpp"
#include <generated/MediaPipeline.hpp>
#include <generated/MediaProfileSpecType.hpp>
#include <KurentoException.hpp>

#define GST_CAT_DEFAULT kurento_http_get_endpoint_impl
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);
#define GST_DEFAULT_NAME "HttpGetEndpointImpl"

namespace kurento
{
HttpGetEndpointImpl::HttpGetEndpointImpl (
  bool terminateOnEOS, std::shared_ptr<MediaProfileSpecType> mediaProfile,
  int disconnectionTimeout, std::shared_ptr< MediaObjectImpl > mediaPipeline) :
  HttpEndpointImpl (disconnectionTimeout, mediaPipeline)
{
  g_object_set ( G_OBJECT (element), "accept-eos", terminateOnEOS,
                 NULL);

  switch (mediaProfile->getValue() ) {
  case MediaProfileSpecType::WEBM:
    GST_INFO ("Set WEBM profile");
    g_object_set ( G_OBJECT (element), "profile", 0, NULL);
    break;

  case MediaProfileSpecType::MP4:
    GST_INFO ("Set MP4 profile");
    g_object_set ( G_OBJECT (element), "profile", 1, NULL);
    break;
  }

  register_end_point();

  if (!is_registered() ) {
    throw KurentoException ("Cannot register HttpGetEndPoint");
  }
}

MediaObject *
HttpGetEndpoint::Factory::createObject (
  std::shared_ptr<MediaPipeline> mediaPipeline, bool terminateOnEOS,
  std::shared_ptr<MediaProfileSpecType> mediaProfile, int disconnectionTimeout)
{
  return new HttpGetEndpointImpl (terminateOnEOS, mediaProfile,
                                  disconnectionTimeout,
                                  std::dynamic_pointer_cast<MediaObjectImpl> (mediaPipeline) );
}

HttpGetEndpointImpl::StaticConstructor HttpGetEndpointImpl::staticConstructor;

HttpGetEndpointImpl::StaticConstructor::StaticConstructor()
{
  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, GST_DEFAULT_NAME, 0,
                           GST_DEFAULT_NAME);
}

} /* kurento */
