//
//  INVPolyline.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVShape.h"

NS_ASSUME_NONNULL_BEGIN

/**
 폴리라인의 기본 전역 Z 인덱스.
 */
const static int INV_POLYLINE_DEFAULT_GLOBAL_Z_INDEX = -1000;

/**
 지도 위에 선형을 표출하는 셰이프 클래스.
 */
INV_EXPORT
@interface INVPolyline : INVShape

/**
 폴리라인의 두께. (pt 단위)
 
 기본값은 `2.5`입니다.
 */
@property (nonatomic) CGFloat width;

/**
 폴리라인의 색상.
 
 기본값은 `UIColor.blackColor`입니다.
 */
@property (nonatomic, copy) UIColor *color;

/**
 폴리라인의 끝 지점 모양.
 
 기본값은 `INVLineCapButt`입니다.
 */
@property (nonatomic) INVLineCap capType;

/**
 폴리라인의 연결점 모양.
 
 기본값은 `INVLineJoinMiter`입니다.
 */
@property (nonatomic) INVLineJoin joinType;

/**
 폴리라인의 점선 패턴. (pt 단위)
 
 배열 내 홀수 index의 값은 실선의 길이, 짝수 index의 값은 공백의 길이를 의미합니다.<br>
 빈 배열일 경우 실선이 됩니다.
 */
@property (nonatomic, strong) NSArray<NSNumber *> *pattern;

/**
 폴리라인의 좌표열.
 
 `coords`의 크기는 `2` 이상이어야 합니다.
 */
@property (nonatomic, copy) NSArray<INVLatLng *> *coords;

/**
 좌표열을 이용하여 폴리라인 객체를 생성합니다.
 
 `coords`의 크기는 `2` 이상이어야 합니다.
 
 @param coords 좌표열.
 @return `INVPolyline` 객체.
 */
+ (instancetype)polylineWithCoords:(NSArray<INVLatLng *> *)coords;

@end

NS_ASSUME_NONNULL_END
