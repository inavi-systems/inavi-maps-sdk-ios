#import <Foundation/Foundation.h>

@class InaviMapView;

NS_ASSUME_NONNULL_BEGIN

@interface InaviMapView (IBAdditions)

@property (nonatomic) IBInspectable double latitude;
@property (nonatomic) IBInspectable double longitude;
@property (nonatomic) IBInspectable double zoomLevel;

@end

NS_ASSUME_NONNULL_END
