//
//  INVMarkerOptions.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVShape.h"

NS_ASSUME_NONNULL_BEGIN

@class INVImage;
@class INVLatLng;
@class INVInfoWindow;

/**
 마커의 옵션을 정의한 프로토콜.
*/
@protocol INVMarkerOptions <INVShapeOptions>

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
 타이틀의 텍스트 크기. pt 단위.
 
 기본값은 `12`입니다.
 */
@property(nonatomic) CGFloat titleSize;

/**
 마커의 타이틀 텍스트 한 줄당 최대 너비.
 
 값을 지정할 경우 타이틀 텍스트의 길이가 최대 너비를 초과할 경우 강제 개행이 됩니다.<br>
 개행은 어절 단위로 이루어지므로, 하나의 어절이 길 경우 최대 너비를 초과할 수 있습니다.<br>
 `0`일 경우 너비를 제한하지 않습니다.
 
 기본값은 `120`입니다.
 */
@property(nonatomic) CGFloat titleMaxWidth;

/**
 아이콘과 타이틀 사이의 여백.
 
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

@end

NS_ASSUME_NONNULL_END
