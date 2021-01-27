//
//  INVCircle.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVShape.h"

NS_ASSUME_NONNULL_BEGIN

/**
 원의 기본 전역 Z 인덱스.
 */
const static int INV_CIRCLE_DEFAULT_GLOBAL_Z_INDEX = -1000;

/**
 지도 위에 원을 표출하는 셰이프 클래스.
 */
INV_EXPORT
@interface INVCircle : INVShape

/**
 원의 중심점 좌표.
 */
@property(nonatomic) INVLatLng *center;

/**
 원의 반경. (미터 단위)
 
 기본값은 `1000`입니다.
 */
@property(nonatomic) double radius;

/**
 원의 채우기 색상.
 
 기본값은 `UIColor.whiteColor`입니다.
 */
@property(nonatomic, copy) UIColor *fillColor;

/**
 원의 테두리 두께. (pt 단위)
 
 기본값은 `0`입니다.
 */
@property(nonatomic) double strokeWidth;

/**
 원의 테두리 색상.
 
 기본값은 `UIColor.blackColor`입니다.
 */
@property(nonatomic, copy) UIColor *strokeColor;

/**
 중심점과 반경을 이용하여 원 객체를 생성합니다.
 
 @param center 중심점.
 @param radius 원의 반경. (미터 단위)
 @return `INVCircle` 객체.
 */
+ (instancetype)circleWithCenter:(INVLatLng *)center radius:(double)radius;

/**
 중심점, 반경, 채우기 색상을 이용하여 원 객체를 생성합니다.
 
 @param center 중심점.
 @param radius 반경. (미터 단위)
 @param fillColor 채우기 색상.
 @return `INVCircle` 객체.
 */
+ (instancetype)circleWithCenter:(INVLatLng *)center
                       radius:(double)radius
                    fillColor:(UIColor *)fillColor;

@end

NS_ASSUME_NONNULL_END
