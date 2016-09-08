//
//  PPTVPlayerSdk.h
//  PPTVSdkDemo
//
//  Created by chunhaixu on 15/11/30.
//  Copyright © 2015年 PPTV. All rights reserved.
//

/*!
 @header PPTVPlayerSdk
 @brief 实现视频播放相关操作
 @version 1.00 2015/11/30 Creation
 */

#import <Foundation/Foundation.h>

@class PPTVDownloadInfo;

/*! 视频填充模式 */

typedef NS_ENUM(NSUInteger, PPTVVideoFillModel) {
    /*!  视频宽度和高度全部填充满 */
    VideoFillModelBothFill,
    
    /*!  视频宽度填充满 */
    VideoFillModelWidthFill,
    
    /*!  视频高度填充满 */
    VideoFillModelHeightFill,
    
    /*!  原始视频填充模式 */
    VideoFillModelOriginalFill,
};


/**
 *  广告的回调
 */
@protocol PPTVADViewDelegate <NSObject>
@optional

/*!
 @brief 广告开始播放
 */
- (void)adViewStartPlay;

/*!
 @brief 广告播放完成
 */
- (void)adViewPlayFinished;


@end


/**
 *  播放串的回调
 */
@protocol PPTVStreamDelegate <NSObject>
@optional

/*!
 @brief 获取播放串成功
 */
- (void)loadPlayStreamSuccess;

/*!
 @brief 获取播放串失败
 */
- (void)loadPlayStreamFailed:(NSError *)error;

@end


/**
 *  自有播放器播放的回调
 */
@protocol PPTVMediaPlayerDelegate <NSObject>
@optional
/*!
 @brief 播放器加载播放串失败
 @param error 错误信息
 */
- (void)playerLoadPlaylinkFailed:(NSError *)error;

/*!
 @brief 播放器视频加载失败
 @param error 错误信息
 */
- (void)playerLoadFailedWithError:(NSError *)error;

/*!
 @brief 加载完成
 @discussion  表示节目开始播放了
 */
- (void)playerLoadFinished;

/*!
 @brief 缓冲中
 @discussion  每一次卡顿,缓冲
 */
- (void)playerBuffering;

/*!
 @brief 缓冲完成
 @discussion  每一次卡顿,缓冲完成
 */
- (void)playerBufferFinished;

/*!
 @brief 播放结束
 */
- (void)playBackDidFinished;

/*!
 @brief 节目总时间
 @discussion  只有点播才能获取节目总时间
 @param duration 节目总时间(单位秒)
 */
- (void)playerDurationAvailable:(NSTimeInterval)duration;

/*!
 @brief 播放状态
 @param isPlaying 当前视频是否正在播放中
 */
- (void)playBackStateChanged:(BOOL)isPlaying;

/*!
 @brief airPlay状态
 @discussion  根据isActive的值, 来判断当前时候是AirPlay状态
 @param isActive 是否是airPlay状态
 */
- (void)playerShowOnAirPlay:(BOOL)isActive;
@end


/**
 *  实现基本播放功能
 */
@interface PPTVPlayerSdk : NSObject

/*!
 @brief 使用内置播放器时, 设置Player回调函数
 */
@property(nonatomic, weak) id<PPTVMediaPlayerDelegate> playerDelegate;

/*!
 @brief 不使用内置播放器时, 设置获取播放串的回调函数
 */
@property(nonatomic, weak) id<PPTVStreamDelegate> streamDelegate;

/*!
 @brief 使用内置播放器时, 设置广告回调函数
 */
@property(nonatomic, weak) id<PPTVADViewDelegate> ADViewDelegate;

/*!
 @brief 播放页面视图, 主要是为了处理播放器的UI部分
 */
@property(nonatomic, readonly) UIView       *playerView;

/*!
 @brief 播放串
 @discussion 不使用内置播放器才有值
 */
@property (nonatomic, readonly) NSString    *curPlayLink;

/*!
 @brief 所有支持的码流列表
 */
@property(nonatomic, readonly) NSArray      *ftList;

/*!
 @brief 当前的码流数据 
 */
@property(nonatomic, readonly) NSString     *currentFt;

/*!
 @brief 是否正在播放 
 */
@property(nonatomic, readonly) BOOL isPlaying;

/*!
 @brief 是否准备完成
 */
@property(nonatomic, readonly) BOOL isPreparedToPlay;

/*!
 @brief 网络缓存到的位置（单位：秒）
 */
@property(nonatomic, readonly) NSTimeInterval bufferedSecondsPosition;

/*!
 @brief 播放总时长（单位：秒）
 */
@property(nonatomic, readonly) NSTimeInterval duration;

/*!
 @brief 当前播放时间（单位：秒）
 */
@property(nonatomic, readonly) NSTimeInterval currentPlaybackTime;

/*!
 @brief 初始化播放器SDK
 @param controller 播放器依赖的视图控制器
 @return instancetype
 */
- (instancetype)initWithPlayerViewController:(UIViewController *)controller;

/*!
 @brief 设置播放信息, 准备播放
 @discussion 注意params的格式以及参数, 
    其中playerType为PLAYER_TYPE_VOD/PLAYER_TYPE_LIVE时正常初始化,
    playerType为PLAYER_TYPE_LOCAL为本地播放，可播放下载的视频
 @param params 例如 param: encodeurl=%@&ft=%@&playerType=%@&ppType=%@
 */
- (void)prepareToPlayWithInfo:(NSString *)params;

/**
 *  @brief 重新请求播放
 *  @discussion 当网络状态变化, 比如3G/wifi切换时, 或者是进入后台1分钟以上, 开始播放正片后才可以调用
 */
- (void)reReadyPlay;

/*!
 @brief 开始播放
 */
- (void)play;

/*!
 @brief 暂停播放
 */
- (void)pause;

/*!
 @brief 停止播放
 */
- (void)stop;

/*!
 @brief 清空播放相关
 @discussion 退出播放页面或者释放播放器时调用
 */
- (void)clearPlayer;

/*!
 @brief 跳过广告
 @discussion 播放前贴视频广告时, 可以根据需求, 是否跳过广告
 */
- (void)skipADView;

/*!
 @brief 按时间点检索
 @discussion 设置视频进度
 @param position 时间点s
 */
- (void)seekToPosition:(float)position;

/*!
 @brief 切换码流
 @discussion 当前视频有多个码流的时候, 可以直接调用此接口切换码流播放
 @param ft 码流
 */
- (void)changeStreamWithFt:(NSString *)ft;

/*!
 @brief 修改视频屏幕填充模式 PPTVVideoFillModel
 @param model 视频页面填充模式
 */
- (void)changeVideoFillModel:(PPTVVideoFillModel)model;

/*!
 @brief 根据下载任务信息播放
 @param showInfo PPTVDownloadInfo:已有的PPTVDownloadInfo对象
 */
- (void)prepareToPlayWithDownloadInfo:(PPTVDownloadInfo *)showInfo;

@end
