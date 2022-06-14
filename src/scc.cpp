#include "scc.h"
using std::placeholders::_1;

Scc::Scc() : Node("scc")
{
	publisher_ = create_publisher<std_msgs::msg::String>("topic", 10);
	crow_pcl_sub_ = create_subscription<sensor_msgs::msg::PointCloud2>("/crow/os_cloud_node/points", 10, std::bind(&Scc::crow_pcl_cb, this, _1));
	crow_state_sub_ = create_subscription<mavros_msgs::msg::State>("/crow/mavros/state", 10, std::bind(&Scc::crow_state_cb, this, _1));
}

void Scc::rtl_srv_cb(const std::shared_ptr<scc_atlantis::srv::RTL::Request> request,
	std::shared_ptr<scc_atlantis::srv::RTL::Response> response)
{

}

void Scc::crow_state_cb(const mavros_msgs::msg::State::SharedPtr msg)
{
	std::cout << "Crow state: " << msg->mode << "\n";
}

void Scc::crow_pcl_cb(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
	std::cout << "msg width: " << msg->width;
}

void Scc::talk()
{
	std_msgs::msg::String msg;
	msg.data = "Hey";
	publisher_->publish(msg);
}

