/**
 Copyright (c) 2014-present, Facebook, Inc.
 All rights reserved.
 
 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#import "FBTweak+Array.h"

@implementation FBTweak (Array)

- (BOOL)isArray
{
  return (self.arrayValue != nil);
}

- (NSArray *)arrayValue
{
  if ([self.stepValue isKindOfClass:[NSArray class]]) {
    return self.stepValue;
  }
  return nil;
}

- (void)setArrayValue:(NSArray *)arrayValue
{
  self.stepValue = arrayValue;
}

@end
