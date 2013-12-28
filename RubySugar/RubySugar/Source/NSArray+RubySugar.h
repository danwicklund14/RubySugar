//
//  NSArray+RubySugar.h
//  RubySugar
//
//  Created by Michal Konturek on 24/12/2013.
//  Copyright (c) 2013 Michal Konturek. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (RubySugar)

/**
 Returns new array by concatenating array with input object.
 
 Every object that responds to description selector is appended.
 */
- (instancetype):(id)object;

/**
 Returns self[@"<from>..<to>"]
 */
- (instancetype):(NSInteger)from :(NSInteger)to;

/**
 Returns self[@"<from>..<to>"] or self[@"<from>...<to>"] if exclusive.
 */
- (instancetype):(NSInteger)from :(NSInteger)to exclusive:(BOOL)exclusive;

/**
 Returns an empty array.
 */
- (instancetype)rs_clear;

/**
 Returns a copy of self with all nil elements removed.
 */
- (instancetype)rs_compact;

/**
 Deletes all items from self that are equal to obj.
 Returns the last deleted item, or nil if no matching item is found.
 */
- (instancetype)rs_delete:(id)object;

/**
 Deletes the element at the specified index, returning new array without 
 element, or self if the index is out of range.
 */
- (instancetype)rs_deleteAt:(NSUInteger)index;

/***/
- (instancetype)rs_deleteIf:(BOOL(^)(id item))block;

/**
 Drops first n elements from ary and returns the rest of the elements in an array.
 If a negative number is given, raises an ArgumentError.
 */
- (instancetype)rs_drop:(NSInteger)count;

/**
 Drops elements up to, but not including, the first element for which the block 
 returns nil or false and returns an array containing the remaining elements.
 
 If no block is given, an Enumerator is returned instead.
 */
- (id)rs_dropWhile:(BOOL(^)(id item))block;

/**
 Mirror: [self objectAtIndex:index];
 */
- (id)rs_fetch:(NSUInteger)index;

/**
 Returns a new array that is a one-dimensional flattening of self (recursively).
 That is, for every element that is an array, extract its elements into the new array.
 */
- (instancetype)rs_flatten;

/**
 Returns a new array that is a one-dimensional flattening of self (recursively).
 That is, for every element that is an array, extract its elements into the new array.
 The optional level argument determines the level of recursion to flatten.
 */
- (instancetype)rs_flatten:(NSInteger)level;

/**
 Mirror: [self containsObject:object];
 */
- (BOOL)rs_includes:(id)object;

/**
 Shorthand ([self count] == 0)
 */
- (BOOL)rs_isEmpty;

/**
 Shorthand [rs_join:nil]
 */
- (NSString *)rs_join;

/**
 Returns a string created by converting each element of the array to a string, 
 separated by the given separator. If the separator is nil, it uses empty string.
 */
- (NSString *)rs_join:(NSString *)separator;

/**
 Returns a new array containing self‘s elements in reverse order.
 */
- (instancetype)rs_reverse;

/**
 Returns a random element from the array or nil in case array is empty.
 */
- (id)rs_sample;

/**
 Returns an array of n random element from the array.
 Returns an empty array in case a target array is empty.
 */
- (instancetype)rs_sample:(NSUInteger)count;

/**
 Returns first n elements from the array.
 If a negative number is given, raises an ArgumentError.
 */
- (instancetype)rs_take:(NSInteger)count;

/**
 Passes elements to the block until the block returns nil or false, 
 then stops iterating and returns an array of all prior elements.
 
 If no block is given, an Enumerator is returned instead.
 */
- (id)rs_takeWhile:(BOOL(^)(id item))block;

/**
 Returns a new array by removing duplicate values in self.
 If a block is given, it will use the return value of the block for comparison.
 */
- (instancetype)rs_uniq;

/**
 Returns a new array by removing duplicate values in self.
 If a block is given, it will use the return value of the block for comparison.
 */
- (instancetype)rs_uniq:(id(^)(id item))block;


- (id)objectForKeyedSubscript:(id<NSCopying>)key;

@end
