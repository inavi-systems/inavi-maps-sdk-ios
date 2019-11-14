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

@end

NS_ASSUME_NONNULL_END
