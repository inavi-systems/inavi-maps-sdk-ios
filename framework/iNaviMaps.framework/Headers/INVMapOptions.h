#import <UIKit/UIKit.h>

#import "INVFoundation.h"

@class INVCameraPosition;

NS_ASSUME_NONNULL_BEGIN

/**
 지도 객체 생성 시 기본 옵션을 설정하는 클래스.
 */
INV_EXPORT
@interface INVMapOptions : NSObject

/**
 지도의 초기 카메라 위치.
 */
@property (nonatomic) INVCameraPosition* camera;

/**
 축척 바 표출 여부.
 
 기본값은 `YES`입니다.
 */
@property (nonatomic, assign) BOOL showScaleBar;

/**
 나침반 표출 여부.
 
 기본값은 `YES`입니다.
 */
@property(nonatomic, assign) BOOL showCompass;

/**
 줌 컨트롤 표출 여부.
 
 기본값은 `NO`입니다.
 */
@property (nonatomic) BOOL showZoomControl;

/**
 현위치 버튼 표출 여부.
 
 기본값은 `NO`입니다.
 */
@property (nonatomic) BOOL showLocationButton;


/**
 지도의 최소 줌 레벨.
 
 기본값은 `1`입니다.
 */
@property (nonatomic) double minimumZoomLevel;

/**
 지도의 최대 줌 레벨.
 
 기본값은 `20`입니다.
 */
@property (nonatomic) double maximumZoomLevel;


/**
 지도의 최소 기울기 각도. (도 단위)
 
 기본값은 `0`입니다.
 */
@property (nonatomic) double minimumTilt;

/**
 지도의 최대 기울기 각도. (도 단위)
 
 기본값은 `60`입니다.
 */
@property (nonatomic) double maximumTilt;

/**
 지도 심벌의 크기. (배율 단위)
 `0.0` ~ `2.0` 값을 지원하며 `1.5`으로 설정하면 지도 심벌이 `1.5`배의 크기로 표출됩니다.
 
 기본값은 `1.0`입니다.
 */
@property (nonatomic) double symbolScale;

/**
 지도 줌 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `YES`입니다.
 */
@property(nonatomic, getter=isZoomGesturesEnabled) BOOL zoomGesturesEnabled;

/**
 지도 스크롤 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `YES`입니다.
 */
@property(nonatomic, getter=isScrollGesturesEnabled) BOOL scrollGesturesEnabled;

/**
 지도 회전 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `YES`입니다.
 */
@property(nonatomic, getter=isRotateGesturesEnabled) BOOL rotateGesturesEnabled;

/**
 지도 기울기 제스처 사용 여부를 나타내는 속성.
 
 기본값은 `YES`입니다.
 */
@property(nonatomic, getter=isTiltGesturesEnabled) BOOL tiltGesturesEnabled;

/**
 줌 또는 회전 제스처 시 기준점을 지도 중심으로 할지 여부를 나타내는 속성.
 
 값이 `YES`이면 지도 중심을 기준으로, `NO`이면 제스처 하는 위치를 기준으로 줌 또는 회전이 됩니다.<br>
 기본값은 `NO` 입니다.
 */
@property(nonatomic, getter=isFocalPointCenter) BOOL focalPointCenter;


/**
 로고 클릭 시 SDK 정보 팝업 표출 여부를 나타내는 속성.
 
 비활성화 시 별도의 페이지에 아이나비 지도 SDK의 오픈 소스 라이선스와 법적 고지를 제공해야 합니다.<br>
 기본값은 `YES`입니다.
 
 @see `+[INVMapSdk presentLicenseViewController]`<br>`+[INVMapSdk presentLegalNoticeViewController]`
 */
@property(nonatomic, getter=isLogoClickEnabled) BOOL logoClickEnabled;



/**
 지도에 적용할 커스텀 지도 스타일.

 적용하려는 지도 스타일이 `INVMapSdk.savedCustomMapStyles`에 존재하지 않거나 `nil`로 설정할 경우 기본 지도 스타일이 적용됩니다.

 기본값은 `nil`입니다.
 */
@property (nonatomic, nullable) INVMapStyle* customMapStyle;


@end

NS_ASSUME_NONNULL_END
