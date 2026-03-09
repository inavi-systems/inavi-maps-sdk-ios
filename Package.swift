// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "iNaviMaps",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "iNaviMaps",
            targets: ["iNaviMaps"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "iNaviMaps",
            path: "framework/iNaviMaps.xcframework"
        ),
    ]
)
