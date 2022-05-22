#include "scc.h"
using std::placeholders::_1;

Scc::Scc() : Node("scc")
{
	publisher_ = create_publisher<std_msgs::msg::String>("topic", 10);
	sub_point_cloud_ = create_subscription<sensor_msgs::msg::PointCloud2>("/raven/os_cloud_node/points", 10, std::bind(&Scc::listen_pointcloud, this, _1));
}

void Scc::talk()
{
	std_msgs::msg::String msg;
	msg.data = "Hey";
	publisher_->publish(msg);
}

void Scc::listen_pointcloud(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
	printf(">> Received point cloud\n");
}
