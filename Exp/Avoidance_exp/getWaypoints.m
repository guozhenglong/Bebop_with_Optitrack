function [ waypoint ] = getWaypoints(waypoint_pos)
%GETWAYPOINTS Generates a list of waypoints for the ARDrone
% Each waypoint is a column vector that contains the desired position of 
% the drone, desired heading angle, and velocity desired x and y channel. The list of waypoints
% is created combining the column vectors. 
%     t = 0:0.2:4*4*pi;
%     x=2*1*sin(t);
%     y=2*2*sin(t/2);
%     vx=2*1*cos(t);
%     vy=2*1*cos(t/2);
%     plot(x,y,'*r');
%     figure();
%     plot(t,vx,'b');hold on;
%     plot(t,vy,'g')
    h=1.2;  % metric
    yaw=0; % rad
%     disp('nPoints:')
    nPoints=size(waypoint_pos,1);
%     nPoints=size(t,2);
    waypoint = zeros(7,nPoints);
    k_v = 5;
    
    for i=1:nPoints-1
        waypoint(1,i)=i;
        waypoint(2,i)=waypoint_pos(i,1);
        waypoint(3,i)=waypoint_pos(i,2);
        waypoint(4,i)=h;
        waypoint(5,i)=yaw;
%         waypoint(6,i)=k_v*(waypoint_pos(i+1,1)-waypoint_pos(i,1));
%         waypoint(7,i)=k_v*(waypoint_pos(i+1,2)-waypoint_pos(i,2));
        waypoint(6,i)=0;
        waypoint(7,i)=0;
    end
    waypoint(1,nPoints)=nPoints;
    waypoint(2,nPoints)=waypoint_pos(nPoints,1);
    waypoint(3,nPoints)=waypoint_pos(nPoints,2);
    waypoint(4,nPoints)=h;
    waypoint(5,nPoints)=yaw;
    waypoint(6,nPoints)=0;
    waypoint(7,nPoints)=0;
    

   
end

