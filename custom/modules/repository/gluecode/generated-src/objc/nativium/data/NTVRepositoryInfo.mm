// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/data/NTVRepositoryInfo.h"


@implementation NTVRepositoryInfo

- (nonnull instancetype)initWithSqliteVersion:(nonnull NSString *)sqliteVersion
                                     fileData:(nonnull NTVDatabaseFileData *)fileData
                                       tables:(nonnull NSArray<NTVRepositoryTable *> *)tables
                                        views:(nonnull NSArray<NTVRepositoryView *> *)views
{
    if (self = [super init]) {
        _sqliteVersion = [sqliteVersion copy];
        _fileData = fileData;
        _tables = [tables copy];
        _views = [views copy];
    }
    return self;
}

+ (nonnull instancetype)repositoryInfoWithSqliteVersion:(nonnull NSString *)sqliteVersion
                                               fileData:(nonnull NTVDatabaseFileData *)fileData
                                                 tables:(nonnull NSArray<NTVRepositoryTable *> *)tables
                                                  views:(nonnull NSArray<NTVRepositoryView *> *)views
{
    return [[self alloc] initWithSqliteVersion:sqliteVersion
                                      fileData:fileData
                                        tables:tables
                                         views:views];
}

#ifndef DJINNI_DISABLE_DESCRIPTION_METHODS
- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p sqliteVersion:%@ fileData:%@ tables:%@ views:%@>", self.class, (void *)self, self.sqliteVersion, self.fileData, self.tables, self.views];
}

#endif
@end
