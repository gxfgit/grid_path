#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <Eigen/Eigen>
#include <math.h>
#include <random>

using namespace std;
using namespace Eigen;

ros::Publisher _all_map_pub;

double _x_size, _y_size, _z_size, _init_x, _init_y, _resolution, _sense_rate;
double _x_l, _x_h, _y_l, _y_h, _w_l, _w_h, _h_l, _h_h, _w_c_l, _w_c_h;

bool _has_map  = false;

sensor_msgs::PointCloud2 globalMap_pcd;
pcl::PointCloud<pcl::PointXYZ> cloudMap;

void RandomMapGenerate()
{  
   pcl::PointXYZ pt_random;
   
   for (int i = 0; i < _x_size; i++)
   {
      for (int j = 0; j < _y_size; j++)
      {
         pt_random.x = i;
         pt_random.y = j;
         pt_random.z = 0;
         cloudMap.points.push_back( pt_random );
      }
   }

   cloudMap.width = cloudMap.points.size();
   cloudMap.height = 1;
   cloudMap.is_dense = true;

   _has_map = true;
   pcl::toROSMsg(cloudMap, globalMap_pcd);
   globalMap_pcd.header.frame_id = "world";
}

void pubSensedPoints()
{     
   if( !_has_map ) return;

   _all_map_pub.publish(globalMap_pcd);
}

int main (int argc, char** argv) 
{        
   ros::init (argc, argv, "random_complex");
   ros::NodeHandle n( "~" );

   _all_map_pub   = n.advertise<sensor_msgs::PointCloud2>("global_map", 1);                      


   n.param("map/x_size",  _x_size, 10.0);
   n.param("map/y_size",  _y_size, 10.0);
   n.param("map/z_size",  _z_size, 0.0 );

   n.param("map/resolution", _resolution, 1.0);

   n.param("sensing/rate", _sense_rate, 1.0);

   _x_l = - _x_size / 2.0;
   _x_h = + _x_size / 2.0;

   _y_l = - _y_size / 2.0;
   _y_h = + _y_size / 2.0;

   RandomMapGenerate();
   ros::Rate loop_rate(_sense_rate);
   while (ros::ok())
   {
      pubSensedPoints();
      ros::spinOnce();
      loop_rate.sleep();
   }
}