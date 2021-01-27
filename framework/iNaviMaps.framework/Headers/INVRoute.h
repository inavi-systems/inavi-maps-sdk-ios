//
//  INVRoute.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVShape.h"

@class INVRouteLink;
@class INVMarker;
@class INVImage;
@protocol INVRouteDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 경로의 기본 전역 Z 인덱스.
 */
const static int INV_ROUTE_DEFAULT_GLOBAL_Z_INDEX = -1000;

/**
 지도 위에 다중 선형으로 경로를 표출하는 셰이프 클래스.
 */
INV_EXPORT
@interface INVRoute : INVShape

/**
 `INVRoute`의 Delegate.
 */
@property (nonatomic, weak, nullable) id <INVRouteDelegate> delegate;

/**
 경로를 구성하는 링크 배열.
 */
@property (nonatomic, copy) NSArray<INVRouteLink *> *links;

/**
 경로의 두께. (pt 단위)
 
 기본값은 `5`입니다.
 */
@property (nonatomic) CGFloat lineWidth;

/**
 경로의 테두리 두께. (pt 단위)
 
 기본값은 `1`입니다.
 */
@property (nonatomic) CGFloat strokeWidth;

/**
 경로의 진행률.
 
 진행률의 범위는 `0.0~1.0` 입니다. <br>
 기본값은 `0.0`입니다.
 */
@property (nonatomic) CGFloat passRatio;

/**
 경로의 진행 색상.
 
 기본값은 `UIColor.clearColor`입니다.
 */
@property (nonatomic, strong) UIColor* passLineColor;

/**
 경로의 진행 테두리 색상.
 
 기본값은 `UIColor.clearColor`입니다.
 */
@property (nonatomic, strong) UIColor* passStrokeColor;

/**
 경로의 진행된 길이. (미터 단위)
 */
@property (nonatomic, readonly) double passDistance;

/**
 경로의 진행된 위치.
 */
@property (nonatomic, readonly) INVLatLng* passPosition;

/**
 경로가 진행되는 각도. (도 단위)
 */
@property (nonatomic, readonly) double passAngle;

/**
 경로의 전체 길이. (미터 단위)
 */
@property (nonatomic, readonly) double routeDistance;


/**
 패턴 이미지.
 
 패턴의 크기는 경로의 두께로 리사이징되며  `patternScale`로 변경 가능합니다.
 
 기본값은 `nil` 입니다.
 */
@property (nonatomic, strong, nullable) INVImage *patternImage;

/**
 경로의 두께 대비 패턴 크기의 배율.
 
 값이 `1.0`이면 경로와 동일한 크기로 표출됩니다.

 기본값은 `1.0`입니다.

 */
@property (nonatomic) CGFloat patternScale;

/**
 패턴의 간격. (pt 단위)
 
 패턴 이미지간 간격을 설정할 수 있습니다.
 
 기본값은 `0`입니다.
 */
@property (nonatomic) CGFloat patternMargin;

/**
 링크 배열을 이용하여 경로 객체를 생성합니다.
 
 @param links 링크 배열.
 @return `INVRouteLink` 객체.
 */
+ (instancetype)routeWithLinks:(NSArray<INVRouteLink *> *)links;

@end


/**
 경로의 진행률 변화의 결과를 알려주는 함수가 정의된 프로토콜.
 
 @see `INVRoute`
 */
@protocol INVRouteDelegate<NSObject>
@optional

/**
 경로의 진행률이 변경되면 호출되는 콜백 메서드.
 
 @param position 진행된 위치.
 @param angle 진행되는 각도.
 @param distance 진행된 거리.
 */
- (void)route:(INVRoute *)route didChangePassPosition:(INVLatLng*)position passAngle:(double)angle passDistance:(double)distance;

@end
NS_ASSUME_NONNULL_END
