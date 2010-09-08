// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PPAPI_C_PPB_CORE_H_
#define PPAPI_C_PPB_CORE_H_

#include "ppapi/c/pp_resource.h"
#include "ppapi/c/pp_stdint.h"
#include "ppapi/c/pp_time.h"
#include "ppapi/c/pp_var.h"

struct PP_CompletionCallback;

#define PPB_CORE_INTERFACE "PPB_Core;1"

/**
 * @file
 * Defines the API ...
 *
 * @addtogroup PPB
 * @{
 */

/** {PENDING: describe PPB_CORE} */
struct PPB_Core {
  /** Same as AddRefVar for Resources. */
  void (*AddRefResource)(PP_Resource resource);

  /** Same as ReleaseVar for Resources. */
  void (*ReleaseResource)(PP_Resource resource);

  /**
   * Allocate memory. 
   *
   * @return NULL If the allocation fails.
   */
  void* (*MemAlloc)(size_t num_bytes);

  /** Free memory; it's safe to pass NULL. */
  void (*MemFree)(void* ptr);

  /**
   * Returns the "wall clock time" according to the browser.  This clock is
   * used by the browser when passing time values to the plugin (e.g., via the
   * PP_Event::time_stamp_seconds field).
   */
  PP_Time (*GetTime)();

  /**
   * Schedules work to be executed on the main plugin thread after the
   * specified delay. The delay may be 0 to specify a call back as soon as
   * possible.
   *
   * The |result| parameter will just be passed as the second argument as the
   * callback. Many applications won't need this, but it allows a plugin to
   * emulate calls of some callbacks which do use this value.
   *
   * NOTE: If the browser is shutting down or if the plugin has no instances,
   * then the callback function may not be called.
   */
  void (*CallOnMainThread)(int32_t delay_in_milliseconds,
                           struct PP_CompletionCallback callback,
                           int32_t result);

  /**
   * Returns true if the current thread is the main pepper thread.
   *
   * This is useful for implementing sanity checks, and deciding if dispatching
   * via CallOnMainThread() is required.
   */
  bool (*IsMainThread)();
};

/**
 * @}
 * End addtogroup PPB
 */
#endif  // PPAPI_C_DEV_PPB_CORE_DEV_H_
