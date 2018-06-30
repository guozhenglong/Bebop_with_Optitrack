%%%%%%%%%%%%%%%%%%%%%%%%
%  cleaning workspace
clear;
close all;
clc;

sampleTime = 0.01; 
k_p_xy = 0.5;
k_d_xy = 0.3;
k_p_z = 0.6;
k_d_z = 0;
k_p_yaw = 1.0;
limit_cmd_xy = 1;
%%%%%%%%%%%%%%%%%%%%%%%%
try
	setenv('ROS_MASTER_URI','http://192.168.0.2:11311') % the IP of server 
	setenv('ROS_IP','192.168.0.3') % the IP of client
	rosinit('http://192.168.0.2:11311')
end
uav_cmd;
% SingleARDroneCtrl; 
waypoints=getWaypoints();
r2016bSingleARDroneCtrl