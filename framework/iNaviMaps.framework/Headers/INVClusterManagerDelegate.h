//
//  INVClusterManagerDelegate.h
//
//  ⓒ 2019-2021. iNavi Systems Corp. All rights reserved.
//

#import "INVFoundation.h"
#import "INVCluster.h"
#import "INVMarkerOptions.h"

NS_ASSUME_NONNULL_BEGIN

@class INVClusterManager;

/**
 클러스터에 대한 콜백 메서드가 정의된 프로토콜.
 */
@protocol INVClusterManagerDelegate <NSObject>

@optional

#pragma mark Responding to Rendering Item or Cluster

/**
 클러스터를 지도 위에 그릴 때 호출되는 콜백.
 
 파라미터로 전달되는 `INVMarkerOptions` 객체를 기반으로 클러스터가 지도 위에 마커 형태로 표출됩니다.
 
 @param clusterManager 클러스터링을 하는데 사용한 `INVClusterManager` 객체.
 @param cluster 클러스터에 대한 정보.
 @param markerOptions 지도 위에 그릴 클러스터의 마커에 대한 옵션.
 */
 - (void)clusterManager:(INVClusterManager *)clusterManager willRenderCluster:(id<INVCluster>)cluster withMarkerOptions:(id<INVMarkerOptions>)markerOptions;

/**
아이템을 지도 위에 그릴 때 호출되는 콜백.

파라미터로 전달되는 `INVMarkerOptions` 객체를 기반으로 아이템이 지도 위에 마커 형태로 표출됩니다.

@param clusterManager 클러스터링을 하는데 사용한 `INVClusterManager` 객체.
@param clusterItem 아이템에 대한 정보.
@param markerOptions 지도 위에 그릴 아이템의 마커에 대한 옵션.
*/
- (void)clusterManager:(INVClusterManager *)clusterManager willRenderClusterItem:(id<INVClusterItem>)clusterItem withMarkerOptions:(id<INVMarkerOptions>)markerOptions;

#pragma mark Responding to Tapping Item or Cluster

/**
 지도에 표출 중인 클러스터를 탭했을 때 호출되는 콜백.

 @param clusterManager 클러스터링을 하는데 사용한 `INVClusterManager` 객체.
 @param cluster 탭한 클러스터에 대한 정보.
 @param markerOptions 탭한 클러스터의 마커에 대한 옵션.
 @return `YES`일 경우 이벤트를 소비합니다. 그렇지 않을 경우 `InaviMapView`까지 이벤트가 전달됩니다.
 */
- (BOOL)clusterManager:(INVClusterManager *)clusterManager didTapCluster:(id<INVCluster>)cluster withMarkerOptions:(id<INVMarkerOptions>)markerOptions;

/**
 지도에 표출 중인 아이템을 탭했을 때 호출되는 콜백.

 @param clusterManager 클러스터링을 하는데 사용한 `INVClusterManager` 객체.
 @param clusterItem 탭한 아이템.
 @param markerOptions 탭한 아이템의 마커에 대한 옵션.
 @return `YES`일 경우 이벤트를 소비합니다. 그렇지 않을 경우 `InaviMapView`까지 이벤트가 전달됩니다.
 */
- (BOOL)clusterManager:(INVClusterManager *)clusterManager didTapClusterItem:(id<INVClusterItem>)clusterItem withMarkerOptions:(id<INVMarkerOptions>)markerOptions;

@end

NS_ASSUME_NONNULL_END
