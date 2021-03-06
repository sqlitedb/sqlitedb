// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/data/NTVDatabaseFileData.h"
#import "nativium/data/NTVRepositoryTable.h"
#import "nativium/data/NTVRepositoryView.h"
#import <Foundation/Foundation.h>

@interface NTVRepositoryInfo : NSObject
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
- (nonnull instancetype)initWithSqliteVersion:(nonnull NSString *)sqliteVersion
                                     fileData:(nonnull NTVDatabaseFileData *)fileData
                                       tables:(nonnull NSArray<NTVRepositoryTable *> *)tables
                                        views:(nonnull NSArray<NTVRepositoryView *> *)views NS_DESIGNATED_INITIALIZER;
+ (nonnull instancetype)repositoryInfoWithSqliteVersion:(nonnull NSString *)sqliteVersion
                                               fileData:(nonnull NTVDatabaseFileData *)fileData
                                                 tables:(nonnull NSArray<NTVRepositoryTable *> *)tables
                                                  views:(nonnull NSArray<NTVRepositoryView *> *)views;

@property (nonatomic, readonly, nonnull) NSString * sqliteVersion;

@property (nonatomic, readonly, nonnull) NTVDatabaseFileData * fileData;

@property (nonatomic, readonly, nonnull) NSArray<NTVRepositoryTable *> * tables;

@property (nonatomic, readonly, nonnull) NSArray<NTVRepositoryView *> * views;

@end
