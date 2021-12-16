#include "mpi_hello_world/hello-world-node.h"
#include <glog/logging.h>
#include <ros/ros.h>

#include <chrono>
#include <thread>

int main(int argc, char **argv) {
  ros::init(argc, argv, "mpi_hello_world");
  google::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();

  ros::NodeHandle nh, nh_private("~");
  mpi::HelloWorldNode hello_world_node(nh, nh_private);
  if (!hello_world_node.run()) {
    LOG(FATAL) << "Failed to start running the packlo node!";
    ros::shutdown();
    return 1;
  }

  const std::atomic<bool> &end_of_days_signal_received =
      hello_world_node.shouldExit();
  while (ros::ok() && !end_of_days_signal_received.load()) {
    VLOG_EVERY_N(1, 10) << "\n" << hello_world_node.updateAndPrintStatistics();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  hello_world_node.shutdown();
  return 0;
}
