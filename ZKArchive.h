//
//  ZKArchive.h
//  ZipKit
//
//  Created by Karl Moskowski on 08/05/09.
//

#import <Foundation/Foundation.h>

@class ZKCDTrailer;

@interface ZKArchive : NSObject {
@protected
	// cached respondsToSelector: checks
	BOOL drtsDelegateWantsSizes;
	BOOL drtsDidBeginZip;
	BOOL drtsDidBeginUnzip;
	BOOL drtsWillZipPath;
	BOOL drtsWillUnzipPath;
	BOOL drtsDidEndZip;
	BOOL drtsDidEndUnzip;
	BOOL drtsDidCancel;
	BOOL drtsDidFail;
	BOOL drtsDidUpdateTotalSize;
	BOOL drtsDidUpdateTotalCount;
	BOOL drtsDidUpdateBytesWritten;
	
	BOOL irtsIsCancelled;
}

+ (BOOL) validArchiveAtPath:(NSString *) path;
+ (NSString *) uniquify:(NSString *) path;
- (void) calculateSizeAndItemCount:(NSDictionary *) userInfo;
- (NSString *) uniqueExpansionDirectoryIn:(NSString *) enclosingFolder;
- (void) cleanUpExpansionDirectory:(NSString *) expansionDirectory;

- (BOOL) delegateWantsSizes;

- (void) didBeginZip;
- (void) didBeginUnzip;
- (void) willZipPath:(NSString *)path;
- (void) willUnzipPath:(NSString *)path;
- (void) didEndZip;
- (void) didEndUnzip;
- (void) didCancel;
- (void) didFail;
- (void) didUpdateTotalSize:(NSNumber *) size;
- (void) didUpdateTotalCount:(NSNumber *) count;
- (void) didUpdateBytesWritten:(NSNumber *) byteCount;

/** invoker should be an NSOperation or NSThread; if [invoker isCancelled], inflation or deflation will be aborted. */
@property (weak, nonatomic) id invoker;
@property (weak, nonatomic) id delegate;
@property (copy) NSString *archivePath;
@property (strong) NSMutableArray *centralDirectory;
@property (strong) NSFileManager *fileManager;
@property (strong) ZKCDTrailer *cdTrailer;
@property (assign) NSTimeInterval throttleThreadSleepTime;
@property (copy) NSString *comment;

@end