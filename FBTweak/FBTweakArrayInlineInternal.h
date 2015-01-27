/**
 Copyright (c) 2014-present, Facebook, Inc.
 All rights reserved.
 
 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */


#if !FB_TWEAK_ENABLED

#define _FBArrayTweakValue(categoryName_, collectionName_, tweakName_, array_, default_) default_
#define _FBArrayTweak(categoryName_, collectionName_, tweakName_, array_, default_) nil \

#else

#define _FBArrayTweak(categoryName_, collectionName_, tweakName_, array_, default_) \
((^{ \
FBTweakStore *store = [FBTweakStore sharedInstance];  \
FBTweakCategory *cat = [store tweakCategoryWithName:categoryName_];  \
if (!cat) { \
cat = [[FBTweakCategory alloc] initWithName:categoryName_]; \
[store addTweakCategory:cat]; \
} \
FBTweakCollection *collection = [cat tweakCollectionWithName:collectionName_]; \
if (!collection) { \
collection = [[FBTweakCollection alloc] initWithName:collectionName_]; \
[cat addTweakCollection:collection]; \
} \
FBTweak *tweak = [collection tweakWithIdentifier:tweakName_]; \
if (!tweak) { \
tweak = [[FBTweak alloc] initWithIdentifier:tweakName_]; \
tweak.name = tweakName_; \
tweak.arrayValue = array_; \
tweak.defaultValue = default_; \
[collection addTweak:tweak]; \
} \
return tweak; \
})())

#define _FBArrayTweakValue(categoryName_, collectionName_, tweakName_, array_, default_) \
((^{ \
FBTweak *tweak = FBArrayTweak(categoryName_, collectionName_, tweakName_, array_, default_); \
return tweak.currentValue ?: tweak.defaultValue; \
})())

#endif
