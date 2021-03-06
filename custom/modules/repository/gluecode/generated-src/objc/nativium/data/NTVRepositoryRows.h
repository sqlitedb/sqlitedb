// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/data/NTVRepositoryRow.h"
#import <Foundation/Foundation.h>

@interface NTVRepositoryRows : NSObject
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
- (nonnull instancetype)initWithList:(nonnull NSArray<NTVRepositoryRow *> *)list
                              amount:(int32_t)amount NS_DESIGNATED_INITIALIZER;
+ (nonnull instancetype)repositoryRowsWithList:(nonnull NSArray<NTVRepositoryRow *> *)list
                                        amount:(int32_t)amount;

@property (nonatomic, readonly, nonnull) NSArray<NTVRepositoryRow *> * list;

@property (nonatomic, readonly) int32_t amount;

@end
