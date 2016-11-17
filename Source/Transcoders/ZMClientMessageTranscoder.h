// 
// Wire
// Copyright (C) 2016 Wire Swiss GmbH
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program. If not, see http://www.gnu.org/licenses/.
// 


@import WireRequestStrategy;

#import "ZMPushMessageHandler.h"
#import "ZMMessageTranscoder.h"

@protocol ClientRegistrationDelegate;
@protocol DeliveryConfirmationDelegate;

@protocol CallingMessageReceptionDelegate

- (void)didReceiveMessageWithContent:(NSString *)content atServerTimestamp:(NSDate *)timestamp inConversation:(ZMConversation *)conversation userID:(NSUUID *)userID clientID:(NSUUID *)clientID;

@end

@interface ZMClientMessageTranscoder : ZMMessageTranscoder

- (instancetype)initWithManagedObjectContext:(NSManagedObjectContext *)moc
                 localNotificationDispatcher:(id<ZMPushMessageHandler>)dispatcher
                    clientRegistrationStatus:(id<ClientRegistrationDelegate>)clientDeletionDelegate
                      apnsConfirmationStatus:(id<DeliveryConfirmationDelegate>)apnsConfirmationStatus
             callingMessageReceptionDelegate:(id<CallingMessageReceptionDelegate>)callingMessageReceptionDelegate;

@property (readonly, weak) id<CallingMessageReceptionDelegate> callingMessageReceptionDelegate;

@end
