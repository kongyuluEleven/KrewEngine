//
//  IOHIDib.h
//  KrewEngine
//
//  Created by Diego Revilla Rubiera on 18/08/2018.
//  Copyright © 2018 SKG. All rights reserved.
//

#ifndef IOHIDib_h
#define IOHIDib_h

#ifndef _IOKIT_IOHIDLIB_H
#define _IOKIT_IOHIDLIB_H

#include <IOKit/hidsystem/IOHIDShared.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

extern kern_return_t
IOHIDCreateSharedMemory( io_connect_t connect,
                        unsigned int version );

extern kern_return_t
IOHIDSetEventsEnable( io_connect_t connect,
                     boolean_t enable );

extern kern_return_t
IOHIDSetCursorEnable( io_connect_t connect,
                     boolean_t enable );

enum {
    // Options for IOHIDPostEvent()
    kIOHIDSetGlobalEventFlags       = 0x00000001,
    kIOHIDSetCursorPosition         = 0x00000002,
    kIOHIDSetRelativeCursorPosition = 0x00000004,
    kIOHIDPostHIDManagerEvent       = 0x00000008
};

extern kern_return_t
IOHIDPostEvent( io_connect_t        connect,
               UInt32              eventType,
               IOGPoint            location,
               const NXEventData * eventData,
               UInt32              eventDataVersion,
               IOOptionBits        eventFlags,
               IOOptionBits        options );

extern kern_return_t
IOHIDSetMouseLocation( io_connect_t connect,
                      int x, int y);

extern kern_return_t
IOHIDGetButtonEventNum( io_connect_t connect,
                       NXMouseButton button, int * eventNum ) __deprecated;

extern kern_return_t
IOHIDGetScrollAcceleration( io_connect_t handle, double * acceleration ) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_12, __IPHONE_NA, __IPHONE_NA);

extern kern_return_t
IOHIDSetScrollAcceleration( io_connect_t handle, double acceleration ) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_12, __IPHONE_NA, __IPHONE_NA);

extern kern_return_t
IOHIDGetMouseAcceleration( io_connect_t handle, double * acceleration ) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_12, __IPHONE_NA, __IPHONE_NA);

extern kern_return_t
IOHIDSetMouseAcceleration( io_connect_t handle, double acceleration ) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_12, __IPHONE_NA, __IPHONE_NA);

extern kern_return_t
IOHIDGetMouseButtonMode( io_connect_t handle, int * mode );

extern kern_return_t
IOHIDSetMouseButtonMode( io_connect_t handle, int mode ) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_12, __IPHONE_NA, __IPHONE_NA);

extern kern_return_t
IOHIDGetAccelerationWithKey( io_connect_t handle, CFStringRef key, double * acceleration ) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_12, __IPHONE_NA, __IPHONE_NA);

extern kern_return_t
IOHIDSetAccelerationWithKey( io_connect_t handle, CFStringRef key, double acceleration ) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_12, __IPHONE_NA, __IPHONE_NA);

extern kern_return_t
IOHIDGetParameter( io_connect_t handle, CFStringRef key, IOByteCount maxSize,
                  void * bytes, IOByteCount * actualSize ) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_12, __IPHONE_2_0, __IPHONE_10_0);

extern kern_return_t
IOHIDSetParameter( io_connect_t handle, CFStringRef key,
                  const void * bytes, IOByteCount size ) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0, __MAC_10_12, __IPHONE_NA, __IPHONE_NA);

extern kern_return_t
IOHIDCopyCFTypeParameter( io_connect_t handle, CFStringRef key,
                         CFTypeRef * parameter );

extern kern_return_t
IOHIDSetCFTypeParameter( io_connect_t handle, CFStringRef key,
                        CFTypeRef parameter );

// selectors are found in IOHIDParameter.h
extern kern_return_t
IOHIDGetModifierLockState( io_connect_t handle, int selector, bool *state );

extern kern_return_t
IOHIDSetModifierLockState( io_connect_t handle, int selector, bool state );

extern kern_return_t
IOHIDGetStateForSelector( io_connect_t handle, int selector, UInt32 *state );

extern kern_return_t
IOHIDSetStateForSelector( io_connect_t handle, int selector, UInt32 state );

// Used by Window Server only
extern kern_return_t
IOHIDRegisterVirtualDisplay( io_connect_t handle, UInt32 *display_token );

extern kern_return_t
IOHIDUnregisterVirtualDisplay( io_connect_t handle, UInt32 display_token );

extern kern_return_t
IOHIDSetVirtualDisplayBounds( io_connect_t handle, UInt32 display_token, const IOGBounds * bounds );

extern kern_return_t
IOHIDGetActivityState( io_connect_t handle, bool *hidActivityIdle );

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

__END_DECLS

#endif /* ! _IOKIT_IOHIDLIB_H */

#endif /* IOHIDib_h */