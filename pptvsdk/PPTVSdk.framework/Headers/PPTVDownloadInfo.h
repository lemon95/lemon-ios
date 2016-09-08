//
//  PPTVDownloadInfo.h
//  PPTVSdkDemo
//
//  Created by Guyue Wang on 15/11/10.
//  Copyright © 2015年 PPTV. All rights reserved.
//

/*!
 @header PPTVDownloadInfo
 @brief 下载信息
 @version 1.00 2015/11/20 Creation
 */

#import <Foundation/Foundation.h>

/**
 *  下载信息
 */
@interface PPTVDownloadInfo : NSObject

/*!
 *  @brief 当前速度
 *  @discussion 单位Byte
 */
@property long long speed;

/*!
 *  @brief 已下载文件大小
 *  @discussion 单位Byte
 */
@property long long downloaded_size;

/*!
 *  @brief 文件大小
 *  @discussion 单位Byte
 */
@property long long file_size;

/*!
 *  @brief 任务唯一标示符
 */
@property (nonatomic, strong) NSString *gid;

@end
