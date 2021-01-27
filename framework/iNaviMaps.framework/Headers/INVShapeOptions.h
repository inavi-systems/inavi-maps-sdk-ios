//
//  INVShapeOptions.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 셰이프의 옵션을 정의한 프로토콜.
*/
@protocol INVShapeOptions

/**
 셰이프의 고유 ID.
 */
@property (nonatomic, readonly) NSString* identifier;

/**
 셰이프에 저장할 사용자 정보.
*/
@property (nonatomic, strong) NSDictionary *userInfo;

/**
 셰이프의 Z 인덱스.
 
 두 셰이프가 겹쳐진 경우, 높은 값일 수록 앞에 표출됩니다.
 */
@property (nonatomic) NSInteger zIndex;

/**
 셰이프의 전역 Z 인덱스.
 */
@property(nonatomic) NSInteger globalZIndex;

/**
 셰이프가 표출되기 위한 최소 줌 레벨.
 
 기본값은 `1`입니다.
 */
@property (nonatomic) double visibleMinZoom;

/**
 셰이프가 표출되기 위한 최대 줌 레벨.
 
 기본값은 `20`입니다.
 */
@property (nonatomic) double visibleMaxZoom;

@end

NS_ASSUME_NONNULL_END
