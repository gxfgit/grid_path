# grid_path

## Compiles Project

   catkin_make

## Run the Project

   roslaunch grid_path_searcher demo.launch 

## Interface

   rviz 2D Nav Goal set the point to go

   or

  rosservice call /demo_node_1/get_goal "x: 0.0 y: 0.0" 

  rosservice call /demo_node/get_goal "x: 5.0 y: 5.0" 

## Method

   A*

   Create a minimum cost way to the selected(given) point and made the point start point for next path planning

