//
//  INVLocationIcon.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN

@class INVImage;
@class INVLatLng;

/**
 위치 아이콘의 기본 이미지.
 */
FOUNDATION_EXTERN const INVImage* INV_LOCATION_ICON_IMAGE;

/**
 위치 추적 모드가 `INVUserTrackingModeTracking` 상태일 때 위치 아이콘의 기본 이미지.
 */
FOUNDATION_EXTERN const INVImage* INV_LOCATION_ICON_IMAGE_TRACKING;

/**
 위치 추적 모드가 `INVUserTrackingModeTrackingCompass` 상태일 때 위치 아이콘의 기본 이미지.
 */
FOUNDATION_EXTERN const INVImage* INV_LOCATION_ICON_IMAGE_TRACKING_COMPASS;

/**
 위치 아이콘 주변에 그려지는 원의 기본 색상. (투명도가 있는 빨간색)
 */
FOUNDATION_EXTERN const UIColor* INV_LOCATION_ICON_CIRCLE_COLOR;

/**
 현위치 아이콘의 기본 전역 Z 인덱스.
 */
const static int INV_LOCATION_ICON_DEFAULT_GLOBAL_Z_INDEX = 2000;

/**
 지도 위에 현위치를 표출하는 아이콘 클래스.
 
 아이콘의 모양 및 원의 반경 등을 설정하여 다양한 커스텀 위치 아이콘을 만들 수 있습니다.<br>
 `InaviMapView.locationIcon`을 통해서만 인스턴스를 얻을 수 있습니다.
 
 @see `INVUserTrackingMode`
 */
INV_EXPORT
@interface INVLocationIcon : NSObject

/**
 위치 아이콘의 전역 Z 인덱스.
 */
@property(nonatomic) NSInteger globalZIndex;

/**
 위치 아이콘 표출 여부.<br>
 해당 값이 `YES`이더라도 위치 좌표가 설정되지 않으면 위치 아이콘이 표출되지 않습니다.
 
 기본값은 `YES` 입니다.
 */
@property (nonatomic, assign, getter=isVisible) BOOL visible;

/**
 위치 아이콘의 이미지.
 
 기본값은 `INV_LOCATION_ICON_IMAGE`입니다.
 */
@property (nonatomic, strong) INVImage *image;

/**
 위치 추적 모드가 `INVUserTrackingModeTracking` 상태일 때 위치 아이콘의 기본 이미지.
 
 기본값은 `INV_LOCATION_ICON_IMAGE_TRACKING`입니다.
 */
@property (nonatomic, strong) INVImage *imageTracking;

/**
 위치 추적 모드가 `INVUserTrackingModeTrackingCompass` 상태일 때 위치 아이콘의 기본 이미지.
 
 기본값은 `INV_LOCATION_ICON_IMAGE_TRACKING_COMPASS`입니다.
 */
@property (nonatomic, strong) INVImage *imageTrackingCompass;

/**
 위치 아이콘의 크기. (배율 단위)
 
 값을 `3.0`으로 설정하면 `3`배의 크기로 표출됩니다.<br>
 기본값은 `1.0`입니다.
 */
@property (nonatomic) CGFloat scale;

/**
 위치 아이콘의 위치 좌표.
 
 위치 추적 모드 설정에 따라 값이 자동으로 갱신됩니다.
 
 @see `INVUserTrackingMode`
 */
@property (nonatomic, strong) INVLatLng *position;

/**
 위치 아이콘이 지도상에서 바라보는 방향. (도 단위)
 
 위치 추적 모드 설정에 따라 값이 자동으로 갱신됩니다.
 
 값이 `0`이면 북쪽을 의미하며, 시계 방향으로 값이 증가합니다. `360`의 배수마다 다시 북쪽이 됩니다.<br>
 기본값은 `0`입니다.
 
 @see `INVUserTrackingMode`
 */
@property (nonatomic) CGFloat bearing;

/**
 위치 아이콘 주변에 그려지는 원의 반경. (pt 단위)
 
 기본값은 `24`입니다.
 */
@property(nonatomic) double circleRadius;

/**
 위치 아이콘 주변에 그려지는 원의 색상.
 
 기본값은 `INV_LOCATION_ICON_CIRCLE_COLOR`입니다.
 */
@property(nonatomic, strong) UIColor *circleColor;

/**
 위치 아이콘이 터치되었을 때 호출되는 이벤트 블록.
 */
@property (nonatomic, nullable) INVShapeTouchEvent touchEvent;

@end

NS_ASSUME_NONNULL_END
