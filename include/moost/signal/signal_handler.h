/* vim:set ts=3 sw=3 sts=3 et: */
/**
 * Copyright © 2008-2013 Last.fm Limited
 *
 * This file is part of libmoost.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MOOST_SIGNAL_SIGNAL_HANDLER_H__
#define MOOST_SIGNAL_SIGNAL_HANDLER_H__

#include <csignal>

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

namespace moost { namespace signal {

/** Intercepts SIGHUP, SIGTERM, and SIGINT signals and passes them
* to the provided callback function.
*/
class signal_handler : public boost::noncopyable
{
private:

  class impl;

  boost::shared_ptr<impl> m_pimpl;

public:

  /** Constructs a signal_handler
  * @param callback the function to call when a signal is intercepted
  *
  * callback is void(int) and takes the signal recieved, or -1 if there was an error waiting for a signal
  */
  signal_handler(const boost::function<void(int)> & callback);

};

}} // moost::signal

#endif // MOOST_SIGNAL_SIGNAL_HANDLER_H__
