function [ waypoint ] = getWaypoints_of_square()
%GETWAYPOINTS Generates a list of waypoints for the ARDrone
% Each waypoint is a column vector that contains the desired position of 
% the drone, desired heading angle, and velocity desired x and y channel. The list of waypoints
% is created combining the column vectors. 
k=1.2    
h=1.2;  % metric
    yaw=0; % rad
    nPoints=7;
    waypoint = zeros(7,7);
    for i=1:7
        waypoint(1,i)=i;
        waypoint(4,i)=h;
        waypoint(5,i)=yaw;
        waypoint(6,i)=0;
        waypoint(7,i)=0;
    end
    
    waypoint(2,1)=0;
    waypoint(3,1)=0;
 
    waypoint(2,2)=1*k;
    waypoint(3,2)=1*k;
    
    waypoint(2,3)=1*k;
    waypoint(3,3)=-1*k;
    
    waypoint(2,4)=-1*k;
    waypoint(3,4)=-1*k;
 
    waypoint(2,5)=-1*k;
    waypoint(3,5)=1*k;
    
    waypoint(2,6)=1*k;
    waypoint(3,6)=1*k;
    
    waypoint(2,7)=0;
    waypoint(3,7)=0;
   
end

