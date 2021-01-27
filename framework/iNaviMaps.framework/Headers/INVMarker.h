//
//  INVMarker.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import "INVMarkerOptions.h"

NS_ASSUME_NONNULL_BEGIN

@class INVImage;
@class INVLatLng;
@class INVInfoWindow;

/**
 파란색 기본 마커 아이콘.
 */
FOUNDATION_EXTERN const INVImage *INV_MARKER_IMAGE_BLUE;
/**
 회색 기본 마커 아이콘.
 */
FOUNDATION_EXTERN const INVImage *INV_MARKER_IMAGE_GRAY;
/**
 녹색 기본 마커 아이콘.
 */
FOUNDATION_EXTERN const INVImage *INV_MARKER_IMAGE_GREEN;
/**
 빨간색 기본 마커 아이콘.
 */
FOUNDATION_EXTERN const INVImage *INV_MARKER_IMAGE_RED;
/**
 노란색 기본 마커 아이콘.
 */
FOUNDATION_EXTERN const INVImage *INV_MARKER_IMAGE_YELLOW;

/**
 마커의 기본 전역 Z 인덱스.
 */
const static int INV_MARKER_DEFAULT_GLOBAL_Z_INDEX = 1000;

/**
 지도 위에 아이콘과 타이틀을 이용해 한 지점을 표출하는 셰이프 클래스.
 */
INV_EXPORT
@interface INVMarker : INVShape <INVMarkerOptions>


/**
 사용자가 임의로 지정할 수 있는 태그.
 */
@property (nonatomic) NSUInteger tag;

/**
 마커의 아이콘 이미지.
*/
@property (nonatomic, strong) INVImage *iconImage;

/**
 마커의 아이콘 크기. (배율 단위)
 값을 `3.0`으로 설정하면 `3`배의 크기로 표출됩니다.
 
 기본값은 `1.0`입니다.
 */
@property (nonatomic) CGFloat iconScale;

/**
 타이틀 텍스트.
 
 기본값은 빈 문자열입니다.
 */
@property (nonatomic, strong) NSString *title;

/**
마커의 표출 상태가 변경될 때 애니메이션을 적용할지 여부.

기본값은 `NO`입니다.
*/
@property (nonatomic) BOOL isTransitionEnabled;

/**
 상위 다른 마커와 마커 겹침을 허용할지 여부.
 
 기본값은 `YES`입니다.
 */
@property (nonatomic) BOOL isAllowOverlapMarkers;


/**
 상위 다른 마커와 마커의 타이틀 겹침을 허용할지 여부.
 
 기본값은 `YES`입니다.
 */
@property (nonatomic) BOOL isAllowOverlapTitle;

/**
 마커와 지도상 심볼 겹침을 허용할지 여부를 반환합니다.
 
 기본값은 `NO`입니다.
 */
@property (nonatomic) BOOL isAllowOverlapSymbols;

/**
 마커의 아이콘을 지도에 평평하게 표출할지 여부.
 
 기본값은 `NO`입니다.
 */
@property (nonatomic) BOOL isIconFlat;

/**
 마커의 타이틀을 지도에 평평하게 표출할지 여부.
 
 기본값은 `NO`입니다.
 */
@property (nonatomic) BOOL isTitleFlat;


/**
 마커의 위치 좌표.
 */
@property (nonatomic, strong) INVLatLng *position;

/**
 마커의 투명도. (`0~1` 사잇값)
 
 값을 `0`으로 설정하면 투명, `1`로 설정하면 불투명이 됩니다.<br>
 기본값은 `1`입니다.
 */
@property (nonatomic) CGFloat alpha;

/**
 타이틀의 텍스트 색상.
 
 기본값은 `UIColor.blackColor`입니다.
 */
@property (nonatomic, strong) UIColor *titleColor;

/**
 타이틀의 테두리 색상.
 
 기본값은 `UIColor.whiteColor`입니다.
 */
@property (nonatomic, strong) UIColor *titleHaloColor;

/**
 타이틀의 텍스트 크기. (pt 단위)
 
 기본값은 `12`입니다.
 */
@property(nonatomic) CGFloat titleSize;

/**
 마커의 타이틀 텍스트 한 줄당 최대 너비. (pt 단위)
 
 값을 지정할 경우 타이틀 텍스트의 길이가 최대 너비를 초과할 경우 강제 개행이 됩니다.<br>
 개행은 어절 단위로 이루어지므로, 하나의 어절이 길 경우 최대 너비를 초과할 수 있습니다.<br>
 `0`일 경우 너비를 제한하지 않습니다.
 
 기본값은 `0`입니다.
 */
@property(nonatomic) CGFloat titleMaxWidth;

/**
 아이콘과 타이틀 사이의 여백. (pt 단위)
 
 기본값은 `0`입니다.
 */
@property (nonatomic) CGFloat titleMargin;

/**
 마커 아이콘의 각도. (도 단위)
 값이 `0`이면 북쪽을 의미하며, 시계 방향으로 값이 증가합니다. `360`의 배수마다 다시 북쪽이 됩니다.
 
 기본값은 `0`입니다.
 */
@property (nonatomic) CGFloat angle;

/**
 마커 아이콘의 앵커(기준점).
 
 앵커의 좌표로 설정된 지점이 실제 표출되는 마커의 기준 위치가 되며, 마커 회전 시 해당 좌표를 축으로 회전하게 됩니다.<br>
 앵커의 범위는 `(0.0, 0.0)`~`(1.0, 1.0)`이며, `(0, 0)`일 경우 마커 이미지의 `top-left`,<br>
 `(1, 1)`일 경우 마커 이미지의 `bottom-right`가 기준점이 됩니다.
 
 기본값은 `(0.5, 1)`입니다.
 */
@property (nonatomic) CGPoint anchor;

/**
 마커에 표출되고 있는 `INVInfoWindow` 객체.
 */
@property (nonatomic, strong, readonly, nullable) INVInfoWindow *infoWindow;


/**
 위치 좌표를 이용하여 마커 객체를 생성합니다.
 
 @param position 좌표.
 @return `INVMarker` 객체.
 */
+ (instancetype)markerWithPosition:(INVLatLng *)position;

/**
 아이콘 이미지를 이용하여 마커 객체를 생성합니다.
 
 @param iconImage 아이콘 이미지.
 @return `INVMarker` 객체.
 */
+ (instancetype)markerWithIconImage:(INVImage *)iconImage;

/**
 위치 좌표와 아이콘 이미지를 이용하여 마커 객체를 생성합니다.
 
 @param position 좌표.
 @param iconImage 아이콘 이미지.
 @return `INVMarker` 객체.
 */
+ (instancetype)markerWithPosition:(INVLatLng *)position iconImage:(INVImage *)iconImage;


@end

NS_ASSUME_NONNULL_END
