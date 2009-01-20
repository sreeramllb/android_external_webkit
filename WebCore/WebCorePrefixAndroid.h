/*
 * Copyright 2007, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// This prefix file is for Android only. It should contain only:
//    - the special trick to catch us using new or delete without including "config.h"
// Things that need to be defined globally should go into "config.h".

#include <limits.h>
#include <math.h>   // !!! is this allowed as a standard include?
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

// Both JavaScriptCore and WebCore include config.h in almost every file.
// Unfortunately only one gets picked up if we compile all the files in one
// library. Since they can operate together, include it here so it is always
// pulled in.
#include <kjs/config.h>

#ifdef __cplusplus
#define PREFIX_FOR_WEBCORE 1
#define EXPORT __attribute__((visibility("default")))

#include <algorithm>
#include "stl_iterator_base.h"
#include "heap.h"
#include <memory>
#include <new>

#endif

#ifdef __cplusplus
#define new ("if you use new/delete make sure to include config.h at the top of the file"()) 
#define delete ("if you use new/delete make sure to include config.h at the top of the file"()) 
#endif

typedef short int   flex_int16_t;
typedef int     flex_int32_t;
typedef signed char     flex_int8_t;
typedef unsigned short int  flex_uint16_t;
typedef unsigned int    flex_uint32_t;
typedef unsigned char   flex_uint8_t;

#define FLATTEN_FRAMESET
#define FLATTEN_IFRAME

#define ANDROID_EXPOSE_COLUMN_GAP

#define ANDROID_LAYOUT

// Allows us to select all of the text in a <textarea> in onfocus
#define ANDROID_SELECT_TEXT_AREAS

#define ANDROID_FIX
// note: if uncomment ANDROID_INSTRUMENT here, you must also 
// uncomment it on line 31 of JavaScriptCore/kjs/config.h
// #define ANDROID_INSTRUMENT

// Fix for issue 878095.  Only call onBlur on an element if it has an
// onBlur event.
#define ANDROID_IGNORE_BLUR

// Passes the webkit-originated changes of a focused textfield to our UI thread
#define ANDROID_ACCEPT_CHANGES_TO_FOCUSED_TEXTFIELDS

// Fix for an issue where WebKit was scrolling a focused element onscreen.
// Unnecessary for us, since we handle scrolling outside of WebKit.
#define ANDROID_SCROLL_FIX

#define ANDROID_META_SUPPORT

// Give public access to a private method in HTMLSelectElement so that
// we can use information from the java UI to deselect items of the element.
#define ANDROID_DESELECT_SELECT

// Converts ListBoxes to dropdown popup lists.
#define ANDROID_LISTBOX_USES_MENU_LIST

#define ANDROID_ALLOW_TRANSPARENT_BACKGROUNDS
#define ANDROID_HISTORY_CLIENT
#define ANDROID_MULTIPLE_WINDOWS
#define ANDROID_CSS_TAP_HIGHLIGHT_COLOR

// Hack to make File Upload buttons draw disabled.
// Will be removed if/when we get file uploads working.
#define ANDROID_DISABLE_UPLOAD

#define ANDROID_BLOCK_NETWORK_IMAGE

// Changes needed to support native plugins (npapi.h). If the change is generic,
// it may be under a different #define (see: PLUGIN_PLATFORM_SETVALUE,
// PLUGIN_SCHEDULE_TIMER)
#define ANDROID_PLUGINS

// Prevent Webkit from drawing the selection in textfields/textareas, since we 
// draw it ourselves in the UI thread.
#define ANDROID_DO_NOT_DRAW_TEXTFIELD_SELECTION

// This should possibly be patched back to WebKit since they seem to lose the
// user gesture hint. If we do decide to patch this back, the user gesture flag
// should probably be passed in the NavigationAction rather than the
// ResourceRequest.
#define ANDROID_USER_GESTURE

// Add support for the orientation window property
#define ANDROID_ORIENTATION_SUPPORT

// This enables a portable implementation of NPN_[Un]ScheduleTimer
// Will submit this as a patch to apple
#define PLUGIN_SCHEDULE_TIMER

// This adds platformInit() and platformSetValue() to pluginview
// Will submit this as a patch to apple
#define PLUGIN_PLATFORM_SETVALUE

// This enables logging the DOM tree, Render tree even for the release build
#define ANDROID_DOM_LOGGING

// Notify WebViewCore when a clipped out rectangle is drawn,
// so that all invals are captured by the display tree.  
#define ANDROID_CAPTURE_OFFSCREEN_PAINTS

// This disables the css position:fixed to the Browser window. Instead the fixed
// element will be always fixed to the top page.
#define ANDROID_DISABLE_POSITION_FIXED

// Fix exceptions not surfacing through NPAPI bindings to the
// JavaScriptCore execution context.
#define ANDROID_NPN_SETEXCEPTION 1

// Enable dumping the display tree to a file (triggered in WebView.java)
#define ANDROID_DUMP_DISPLAY_TREE
