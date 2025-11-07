# navviz-qt (ROS 2 + Qt5 Navigation Visualization)

navviz-qt is a Qt5 GUI for visualizing navigation data in ROS 2. It renders the map, global/local costmaps, LaserScan points, and planned paths, and allows setting 2D Pose and 2D Goal from the UI.

## Features
- Map (OccupancyGrid) rendering with correct origin and Y-flip
- Global and local costmap overlays with color mapping
- Laser scan point cloud rendering
- Global and local path visualization
- Set 2D Pose (`initialpose`) and 2D Goal (`goal_pose`) publishing
- Multi-threaded ROS 2 executor integrated with Qt event loop

## Requirements
- ROS 2 (Foxy/Humble or later)
- C++14 toolchain
- Qt 5 (Widgets)

## Build Options

This project is a standard ROS 2 ament_cmake package and can be compiled directly by ROS 2 (colcon). You can also build and run it from Qt Creator as a CMake project.

### Option A: Build with ROS 2 (colcon)
1) Create or use an existing ROS 2 workspace and place this repo under `src/`:

```
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
# clone your repo here
# git clone https://github.com/<you>/navviz-qt.git
```

2) Build and source:

```
cd ~/ros2_ws
colcon build
source install/setup.bash
```

### Option B: Build with Qt Creator
Two ways to ensure the runtime finds ROS 2 libraries:
- Recommended: start Qt Creator from a terminal where ROS 2 (and the workspace, if any) is sourced, then open this folder as a CMake project and Build & Run.
- Or: configure Run Environment in Qt Creator to include the same environment as a sourced terminal.

## Run
```
ros2 run navviz_qt navviz_qt
```

This node expects common navigation topics to be available:
- Subscriptions:
  - `/map` (nav_msgs/OccupancyGrid)
  - `/global_costmap/costmap` (nav_msgs/OccupancyGrid)
  - `/local_costmap/costmap` (nav_msgs/OccupancyGrid)
  - `/scan` (sensor_msgs/LaserScan)
  - `/plan` (nav_msgs/Path)
  - `/local_plan` (nav_msgs/Path)
- Publications:
  - `initialpose` (geometry_msgs/PoseWithCovarianceStamped)
  - `goal_pose` (geometry_msgs/PoseStamped)

## Repository vs Package Naming
- Repository name: `navviz-qt`
- ROS 2 package name: `navviz_qt`
- CMake project name: `navviz_qt`
- Node name: `navviz_qt`

## License
MIT. See `LICENSE`.

## Notes
- Images under `resource/images/` should be ensured to be redistributable. Replace with your own or open-source assets if unsure.
- IDE local files and build outputs are ignored (see `.gitignore`).
 - To visualize data, make sure your navigation stack (e.g., Nav2) is running and publishing the listed topics.
