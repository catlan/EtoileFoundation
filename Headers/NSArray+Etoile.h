/**
	Copyright (C) 2007 Quentin Mathe
 
	Author:  Quentin Mathe <quentin.mathe@gmail.com>
	Date:  September 2007
	License: Modified BSD (see COPYING)
 */

#import <Foundation/Foundation.h> 

/** 
 * @group Collection Additions
 * @abstract Additions to NSArray. 
 */
@interface NSArray (Etoile)

- (id) firstObject;
- (NSArray *) arrayByRemovingObject: (id)anObject;
- (NSArray *) arrayByRemovingObjectsInArray: (NSArray *)anArray;
- (NSArray *) filteredArrayUsingPredicate: (NSPredicate *)aPredicate
                          ignoringObjects: (NSSet *)ignoredObjects;

/** @taskunit Deprecated */

- (NSArray *) objectsMatchingValue: (id)value forKey: (NSString *)key;
- (id) firstObjectMatchingValue: (id)value forKey: (NSString *)key;

@end

/** 
 * @group Collection Additions
 * @abstract Additions to NSMutableArray. 
 */
@interface NSMutableArray (Etoile)
/**
 * Removes the objects located between anIndex and the end of the array.
 *
 * The object located at anIndex is included in the removed objects.
 */
- (void) removeObjectsFromIndex: (NSUInteger)anIndex;
@end

