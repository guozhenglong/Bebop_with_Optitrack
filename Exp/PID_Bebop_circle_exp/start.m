%%%%%%%%%%%%%%%%%%%%%%%%
%  cleaning workspace
clear;
close all;
clc;
A_v=1.0;
A_p=1.0;
delta_p = 0.2;
Is_sim = 0; % simulation gazebo
sampleTime = 0.01; 
k_p_xy = 0.6;
k_d_xy = 0.9;
k_i_xy = 0.005;
k_p_z = 0.6;
k_d_z = 0.3;
if Is_sim == 1
    k_p_yaw = -0.5;
    k_sign = 1;
else
    k_p_yaw = 0.5;
    k_sign = -1;
end
limit_cmd_xy = 10;
%%%%%%%%%%%%%%%%%%%%%%%%
try
% 	setenv('ROS_MASTER_URI','http://192.168.0.2:11311') % the IP of server 
% 	setenv('ROS_IP','192.168.0.3') % the IP of client
% 	rosinit('http://192.168.0.2:11311')
rosinit;
end
uav_cmd;
% SingleARDroneCtrl; 
waypoints1=getWaypoints(0,A_p,A_v);
% waypoints2=getWaypoints(-pi,A_p,A_v);
r2017bSingleARDroneCtrl