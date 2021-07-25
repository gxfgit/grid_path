#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/OccupancyGrid.h>
#include <iostream>

int main(int argc, char * argv[]) {

  ros::init(argc, argv, "gridMap");

  ros::NodeHandle nh;
  ros::NodeHandle nh_private("~");

  ros::Publisher pub = nh.advertise<nav_msgs::OccupancyGrid>("/gridMap", 1);
  nav_msgs::OccupancyGrid map;
  
  map.header.frame_id="grid";
  map.header.stamp = ros::Time::now(); 
  map.info.resolution = 1;         // float32
  map.info.width      = 20;           // uint32
  map.info.height     = 20;           // uint32
  
  int p[map.info.width*map.info.height] = {0};   // [0,100]
//   p[10] = 100;
//   p[1] = 100;
  for (int i =0; i<map.info.width*map.info.height; i++)
  {
      if (i%2 == 0 && i/20%2 == 0)
      {
          p[i] = 100;
      }
    //   else
    //   {
    //       p[i] = -1;
    //   }
      ROS_INFO("%d",p[i]);
  }

  std::vector<signed char> a(p, p+400);
  map.data = a;
  while (ros::ok())
  {
      pub.publish(map);
  }

  ros::shutdown();
  return 0;
}
// #include "ros/ros.h"
// #include "visualization_msgs/Marker.h"


// int main(int argc,char** argv)
//  {
//       ros::init(argc,argv,"basic_shapes");
//       ros::NodeHandle n;
//       ros::Rate r(1);
//       ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker",1);
 
//       uint32_t shape = visualization_msgs::Marker::SPHERE;
 
//      while(ros::ok())
//      {
//          visualization_msgs::Marker marker;
//          marker.header.frame_id = "/my_frame";
//          marker.header.stamp = ros::Time::now();
//          marker.ns = "basic_shapes";
//          marker.id = 0;
//          marker.type = shape;
//          marker.action = visualization_msgs::Marker::ADD;
 
//          marker.pose.position.x = 0;
//          marker.pose.position.y = 0;
//          marker.pose.position.z = 0;
//          marker.pose.orientation.x = 0.0;
//          marker.pose.orientation.y = 0.0;
//          marker.pose.orientation.z = 0.0;
//          marker.pose.orientation.w = 1.0;
 
//          marker.scale.x = 1.0;
//          marker.scale.y = 1.0;
//          marker.scale.z = 1.0;
 
//          marker.color.r = 0.0f;
//          marker.color.g = 1.0f;
//          marker.color.b = 0.0f;
//          marker.color.a = 1.0;
 
//          marker.lifetime = ros::Duration();
 
//          while(marker_pub.getNumSubscribers() < 1)
//          {
//              if(!ros::ok())
//              {
//                  return 0;
//              }
//              ROS_WARN_ONCE("Please create a subscriber to the marker");
//              sleep(1);
//          }
//          marker_pub.publish(marker);
 
//         // switch(shape)
//         //  {
//         //      case visualization_msgs::Marker::CUBE:
//         //         shape = visualization_msgs::Marker::SPHERE;
//         //          break;
//         //      case visualization_msgs::Marker::SPHERE:
//         //          shape = visualization_msgs::Marker::ARROW;
//         //          break;
//         //      case visualization_msgs::Marker::ARROW:
//         //          shape = visualization_msgs::Marker::CYLINDER;
//         //          break;
//         //      case visualization_msgs::Marker::CYLINDER:
//         //          shape = visualization_msgs::Marker::CUBE;
//         //          break;
 
//         //  }
//          r.sleep();
//      }
 
//  }