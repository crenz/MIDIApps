//
// Copyright 2001-2002 Kurt Revis. All rights reserved.
//

#import <SnoizeMIDI/SMPortOrVirtualStream.h>
#import <SnoizeMIDI/SMMessageDestinationProtocol.h>

@class SMSysExSendRequest;


@interface SMPortOrVirtualOutputStream : SMPortOrVirtualStream <SMMessageDestination>
{
    struct {
        unsigned int ignoresTimeStamps:1;
        unsigned int sendsSysExAsynchronously:1;
    } flags;
}

- (BOOL)ignoresTimeStamps;
- (void)setIgnoresTimeStamps:(BOOL)value;
    // If YES, then ignore the timestamps in the messages we receive, and send immediately instead

- (BOOL)sendsSysExAsynchronously;
- (void)setSendsSysExAsynchronously:(BOOL)value;
    // If YES, then use MIDISendSysex() to send sysex messages. Otherwise, use plain old MIDI packets.
    // (This can only work on port streams, not virtual ones.)
- (BOOL)canSendSysExAsynchronously;

- (void)cancelPendingSysExSendRequests;
- (SMSysExSendRequest *)currentSysExSendRequest;
    // More methods which are passed on the port stream if possible.

@end

// Notifications
// This class will repost SMPortOutputStreamWillStartSysExSendNotification and SMPortOutputStreamFinishedSysExSendNotification, if it receives them from its port stream.
