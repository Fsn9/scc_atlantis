#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"

class Scc : public rclcpp::Node
{
	public:
		Scc();
		void talk();
		void listen_pointcloud(const sensor_msgs::msg::PointCloud2::SharedPtr msg);
	private:
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
		rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr sub_point_cloud_;
};
