/**
    Copyright (C) 2007 Quentin Mathe

    Date:  December 2007
    License:  Modified BSD (see COPYING)
 */

#import <Foundation/Foundation.h>

/** @group Viewpoints
@abstract The base viewpoint protocol.

A viewpoint is an adaptor that exposes a value derived from a represented object 
and handles reading and writing the properties of this value through 
-valueForProperty: and -setValue:forProperty:.

The derived value object can be read and write through -value and -setValue:. */
@protocol ETViewpoint // FIXME: <NSCopying>
/** Returns the adapted object. */
- (id) representedObject;
/** Sets the adapted object. */
- (void) setRepresentedObject: (id)object;
/** Returns the object value resulting from the viewpoint. */
- (id) value;
/** Sets the object value resulting from the viewpoint. */
- (void) setValue: (id)objectValue;
/** Returns the property names exposed through by the viewpoint for -value. */
- (NSArray *) propertyNames;
/** Returns a value bound to a property of the object -value. */
- (id) valueForProperty: (NSString *)key;
/** Sets the value bound to a property of the object -value. */
- (BOOL) setValue: (id)value forProperty: (NSString *)key;
@optional
- (BOOL) isMutableValue;
- (void) applyMutableViewpointTraitForValue: (id)aValue;
- (void) unapplyMutableViewpointTraitForValue: (id)aValue;
@end

/** @group Viewpoints
@abstract A viewpoint protocol to represent an object property.

A property viewpoint is an adaptor that represents an object property and 
handles reading and writing the property value through -value and -setValue. */
@protocol ETPropertyViewpoint <ETViewpoint> 
/** Returns a new autoreleased property viewpoint that represents the property
identified by the given name in object. */
+ (id) viewpointWithName: (NSString *)key representedObject: (id)object;
/** Returns the name used to declare the property in the represented object. */
- (NSString *) name;
@end

/** @group Viewpoints
@abstract Protocol to provide a viewpoint that simulates mutability for 
immutable objects.

For each immutable object class, a distinct ETMutableObjectViewpoint subclass 
must exist. 

Immutable object class that wants to support editing or mutation through a 
ETMutableObjectViewpoint must implement this protocol. */
@protocol ETViewpointMutation
/** Returns the ETMutableObjectViewpoint subclass used to mutate the receiver 
instances.

Must not return Nil. */
+ (Class) mutableViewpointClass;
@end

/** @group Viewpoints
@abstract A basic and reusable ETViewpoint protocol implementation.

If you implement a class that conforms to ETViewpoint, the core implementation 
of the protocol is usually the same. You can adopt this trait to get all the 
basic viewpoint behavior without writing code, and just implement or 
reimplement the parts that matter.

For example, ETMutableObjectViewpoint uses this trait. */
@interface ETViewpointTrait : NSObject <ETViewpoint>
{
    
}

/** Returns YES. */
- (BOOL) isViewpoint;

/** @taskunit Mutability Trait */

- (BOOL) isMutableValue;
- (void) applyMutableViewpointTraitForValue: (id)aValue;
- (void) unapplyMutableViewpointTraitForValue: (id)aValue;

@end

/** @group Viewpoints
@abstract A mechanism to access a represented collection when a viewpoint 
content is another viewpoint.

This is an unstable API (will probably be removed or changed later). */
@interface NSObject (ETViewpointAdditions)
/** Returns NO. */
- (BOOL) isViewpoint;
- (id) valueForContentKey: (NSString *)key;
- (void) setValue: (id)aValue forContentKey: (NSString *)key;
- (id) valueForContentKeyPath: (NSString *)aKeyPath;
- (void) setValue: (id)aValue forContentKeyPath: (NSString *)aKeyPath;
@end
