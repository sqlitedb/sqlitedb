// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/data/NTVDatabaseFileData.h"


@implementation NTVDatabaseFileData

- (nonnull instancetype)initWithName:(nonnull NSString *)name
                            fileSize:(int64_t)fileSize
                            filePath:(nonnull NSString *)filePath
{
    if (self = [super init]) {
        _name = [name copy];
        _fileSize = fileSize;
        _filePath = [filePath copy];
    }
    return self;
}

+ (nonnull instancetype)databaseFileDataWithName:(nonnull NSString *)name
                                        fileSize:(int64_t)fileSize
                                        filePath:(nonnull NSString *)filePath
{
    return [[self alloc] initWithName:name
                             fileSize:fileSize
                             filePath:filePath];
}

#ifndef DJINNI_DISABLE_DESCRIPTION_METHODS
- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p name:%@ fileSize:%@ filePath:%@>", self.class, (void *)self, self.name, @(self.fileSize), self.filePath];
}

#endif
@end