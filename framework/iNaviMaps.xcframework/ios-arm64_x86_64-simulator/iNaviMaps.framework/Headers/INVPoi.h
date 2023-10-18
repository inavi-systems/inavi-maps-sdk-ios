//
//  INVPoi.h
//
//  ⓒ 2019-2023. iNavi Systems Corp. All rights reserved.
//


#import "INVFoundation.h"

NS_ASSUME_NONNULL_BEGIN

@class INVLatLng;

INV_EXPORT
/**
 지도 POI의 기본 정보를 나타내는 클래스.
 */
@interface INVPoi : NSObject

/**
 POI의 명칭.
 */
@property (nonatomic, readonly, strong) NSString *name;

/**
 POI의 Id.
 */
@property (nonatomic, readonly) int64_t poiId;

/**
 POI의 위치 좌표.
*/
@property (nonatomic, readonly, strong) INVLatLng *position;
@end

NS_ASSUME_NONNULL_END
