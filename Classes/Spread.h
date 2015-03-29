//
//  Spread.h
//  Spread
//
//  Created by Huy Pham on 3/26/15.
//  Copyright (c) 2015 Katana. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SModel.h"
#import "SPool.h"

@interface Spread : NSObject

/**
 *  Return shared instance of Spread.
 *
 *  @return Spread shared instance.
 */
+ (instancetype)sharedInstance;

+ (void)registerClass:(Class)modelClass
    forPoolIdentifier:(NSString *)identifier;

/**
 *  Register event for multi pool with array of identifiers.
 *
 *  @param event           event identifier.
 *  @param poolIdentifiers array of pools indetifier.
 *  @param action          action handler.
 */
+ (void)registerEvent:(NSString *)event
      poolIdentifiers:(NSArray *)poolIdentifiers
               action:(void (^)(id, SPool *))action;

/**
 *  Remove event of pools.
 *
 *  @param event           event identifier.
 *  @param poolIdentifiers array of pools identiriers.
 */
+ (void)removeEvent:(NSString *)event
    poolIdentifiers:(NSArray *)poolIdentifiers;

/**
 *  Remove event of pools.
 *
 *  @param event event identifier.
 */
+ (void)removeEvent:(NSString *)event;

/**
 *  Remove all event of pools.
 */
+ (void)removeAllEvent;

/**
 *  Get pool istance with identifier.
 *
 *  @param identifier identifier of pool.
 *
 *  @return pool object.
 */
+ (SPool *)getPool:(NSString *)identifier;

/**
 *  Add an object to pool.
 *
 *  @param object     object to add.
 *  @param identifier pool identifier.
 *
 *  @return Spread model.
 */
+ (SModel *)addObject:(NSDictionary *)object
               toPool:(NSString *)identifier;

/**
 *  Remove an object from pool with identifier.
 *
 *  @param object     object to remove.
 *  @param identifier pool identifer.
 */
+ (void)removeObject:(id)object
            fromPool:(NSString *)identifier;

/**
 *  Remove multi object in pool.
 *
 *  @param objects    array of objects.
 *  @param identifier pool identifier.
 */
+ (void)removeObjects:(NSArray *)objects
             fromPool:(NSString *)identifier;

/**
 *  Trigger event and send event to every pool had registed.
 *
 *  @param event event identifier.
 *  @param value value parameters.
 */
+ (void)performEvent:(NSString *)event
               value:(NSDictionary *)value;

@end
