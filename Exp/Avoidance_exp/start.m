%%%%%%%%%%%%%%%%%%%%%%%%
%  cleaning workspace
clear;
close all;
clc;
% initial map is 20x20m;
% factor_shrink = 0.1;% exp flight
factor_shrink = 0.2;
cd Astar;
waypoint_pos=A_Star1(factor_shrink);
cd ..

sampleTime = 0.01; 
k_p_xy = 0.6;
k_d_xy = 0.3;
k_p_z = 0.6;
k_d_z = 0.3;
k_p_yaw = 0.5;
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
waypoints=getWaypoints(waypoint_pos);
r2017bSingleARDroneCtrl_opti;
figure()
plot(waypoints(2,:),waypoints(3,:),'r*');
