// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/data/NTVRepositoryColumn.h"
#import "nativium/data/NTVRepositoryInfo.h"
#import "nativium/data/NTVRepositoryRows.h"
#import "nativium/data/NTVRepositoryTable.h"
#import "nativium/data/NTVRepositoryView.h"
#import <Foundation/Foundation.h>
@class NTVRepository;


@interface NTVRepository : NSObject

+ (nullable NTVRepository *)shared;

- (void)open:(nonnull NSString *)path;

- (void)close;

- (void)test;

- (nonnull NTVRepositoryInfo *)getInfo;

- (nonnull NSString *)getSqliteVersion;

- (nonnull NSArray<NTVRepositoryTable *> *)getTableList;

- (nonnull NSArray<NTVRepositoryView *> *)getViewList;

- (nonnull NSArray<NTVRepositoryColumn *> *)getColumns:(nonnull NSString *)name;

- (nonnull NTVRepositoryRows *)getRows:(nonnull NSString *)name
                                sortBy:(nonnull NSString *)sortBy
                            descending:(BOOL)descending
                                  page:(int32_t)page
                           rowsPerPage:(int32_t)rowsPerPage;

@end
