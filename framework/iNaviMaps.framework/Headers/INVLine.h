//
//  INVLine.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INVFoundation.h"

@class INVLatLng;

NS_ASSUME_NONNULL_BEGIN

/**
 다중 선형에서 사용하는 선형의 좌표열과 색상 속성을 정의한 클래스.
 */
INV_EXPORT
INV_DEPRECATED_WITH_TEXT("`INVRouteLink`로 대체됩니다.")
@interface INVLine : NSObject

/**
 라인의 색상.
 
 기본값은 `UIColor.blackColor`입니다.
 */
@property (nonatomic, copy) UIColor *color;

/**
 라인의 좌표열.
 
 `coords`의 크기는 `2` 이상이어야 합니다.
 */
@property (nonatomic, copy) NSArray<INVLatLng *> *coords;

/**
 좌표열을 이용하여 라인 객체를 생성합니다.
 
 `coords`의 크기는 `2` 이상이어야 합니다.
 
 @param coords 좌표열.
 @return `INVLine` 객체.
 */
+ (instancetype)lineWithCoords:(NSArray<INVLatLng *> *)coords;

/**
 좌표열과 색상을 이용하여 라인 객체를를 생성합니다.
 
 `coords`의 크기는 `2` 이상이어야 합니다.
 
 @param coords 좌표열.
 @param color 색상.
 @return `INVLine` 객체.
 */
+ (instancetype)lineWithCoords:(NSArray<INVLatLng *> *)coords color:(UIColor*)color;

@end

NS_ASSUME_NONNULL_END
