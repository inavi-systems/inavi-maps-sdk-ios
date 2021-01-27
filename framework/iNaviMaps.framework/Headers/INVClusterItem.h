//
//  INVClusterItem.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"
#import "INVLatLng.h"

NS_ASSUME_NONNULL_BEGIN

/**
 클러스터링 대상이 되는 아이템이 정의된 프로토콜.
 @see `INVClusterManager`
*/
@protocol INVClusterItem <NSObject>

/**
 아이템의 위치 좌표.
 */
@property(nonatomic, readonly) INVLatLng *position;

@end

NS_ASSUME_NONNULL_END
