//
//  INVClusterIconGenerator.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN

@class INVImage;

/**
 클러스터의 아이템 개수에 따라 아이콘 이미지를 생성해주는 역할을 하는 프로토콜.
 */
INV_EXPORT
@protocol INVClusterIconGenerator <NSObject>

/**
 아이템 개수에 따른 아이콘 이미지를 생성합니다.
 @param count 클러스터에 포함된 아이템의 개수.
 @return 아이콘 이미지 객체.
 */
- (INVImage *)iconForCount:(NSUInteger)count;

@end

NS_ASSUME_NONNULL_END
