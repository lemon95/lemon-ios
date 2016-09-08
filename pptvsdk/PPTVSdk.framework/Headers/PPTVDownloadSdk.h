//
//  PPTVDownloadSdk.h
//  PPTVSdkDemo
//
//  Created by Guyue Wang on 15/11/29.
//  Copyright © 2015年 PPTV. All rights reserved.
//

/*!
 @header PPTVDownloadInfo
 @brief 实现下载相关操作
 @version 1.00 2015/11/29 Creation
 */

#import <Foundation/Foundation.h>

@class PPTVDownloadInfo;


/*! 下载失败原因 */
typedef NS_ENUM(NSUInteger, PPTVDownloadFailedReason)
{
    /*!   获取播放串失败 */
    DownloadFailedWithStreamingFailed = 100,
    
    /*!   网络问题 */
    DownloadFailedWithNetwork = 200,
    
    /*!  空间不够 */
    DownloadFailedWithSpaceNotEnough = 300,
    
    /*!  当前节目被屏蔽, 不允许下载*/
    DownloadForbiden = 400,
    
    /*!  下载目录未设置*/
    DownloadPathUndefine = 500
};

/*!
 @brief 下载信息的回调
 @discussion 获取下载信息的回调
 */
@protocol PPTVDownloadDelegate <NSObject>
@optional

/*!
 @brief 下载任务开始
 @param info 节目信息 PPTVDownloadInfo
 */
- (void)downloadBeganWithShowInfo:(PPTVDownloadInfo *)info;

/*!
 @brief 下载完毕
 @param info 节目信息 PPTVDownloadInfo
 */
- (void)downloadFinishedWithShowInfo:(PPTVDownloadInfo *)info;

/*!
 @brief 下载失败
 @param info 节目信息 PPTVDownloadInfo
 @param reason 失败原因 PPTVDownloadFailedReason
 */
- (void)downloadFailedWithShowInfo:(PPTVDownloadInfo *)info andReasonType:(PPTVDownloadFailedReason)reason;

/*!
 @brief 下载状态实时更新（每秒更新）
 @param info 节目信息 PPTVDownloadInfo
 */
- (void)downloadUpdateWithShowInfo:(PPTVDownloadInfo *)info;

/*!
 @brief 下载数据刷新回调
 */
- (void)reloadDownloadData;

@end

/**
 *  下载功能
 */
@interface PPTVDownloadSdk : NSObject

#pragma mark - download module
/*
 *暂时设计为下载信息分两份保存，使用pptvsdk自有播放器形式
 */
/////////////////////////////////////////////////////////////////////////////////////
/*!
 @brief 设置downloadDelegate回调
 */
@property (nonatomic, weak) id<PPTVDownloadDelegate> downloadDelegate;

/*!
 @brief 下载队列添加新的下载任务
 @param downloadDirectory 下载目录
 */
- (void)setDownloadDirectory:(NSString *)downloadDirectory;

/*!
 @brief 下载队列添加新的下载任务
 @param paramsStr 下载节目信息
 */
- (BOOL)addNewDownloadTaskWithParams:(NSString *)paramsStr;

/*!
 @brief 根据已保存PPTVDownloadInfo对象继续下载任务
 @param showInfo PPTVDownloadInfo:已有的PPTVDownloadInfo对象
 @param downloadDelegate 下载代理对象 PPTVDownloadDelegate
 */
- (void)resumeDownloadWithDownloadInfo:(PPTVDownloadInfo *)showInfo andDownloadDelegate:(id<PPTVDownloadDelegate>)downloadDelegate;

/*!
 @brief 暂停任务
 @param showInfo PPTVDownloadInfo:已有的PPTVDownloadInfo对象
 */
- (void)pauseDownloadTask:(PPTVDownloadInfo *)showInfo;

/*!
 @brief 删除单个任务
 @param showInfo PPTVDownloadInfo: 已有的PPTVDownloadInfo对象
 */
- (void)deleteDownloadTask:(PPTVDownloadInfo *)showInfo;

/*!
 @brief 删除所有当前正在下载任务务
 */
- (void)deleteAllDownloadingTask;

/*!
 @brief 删除所有已下载完成文件
 */
- (void)deleteAllDownloadedTask;

/*!
 @brief 清理下载造成的多余内存
 */
- (void)deleteDownloadCache;

@end
