function [ waypoint ] = getWaypoints()
%GETWAYPOINTS Generates a list of waypoints for the ARDrone
% Each waypoint is a column vector that contains the desired position of 
% the drone, desired heading angle, and velocity desired x and y channel. The list of waypoints
% is created combining the column vectors. 
    A_p=1.0;
    A_v=1.3;
    t = 0:0.2:4*4*pi;
    x=A_p*1*sin(t);
    y=A_p*2*sin(t/2);
    vx=A_v*1*cos(t);
    vy=A_v*1*cos(t/2);
    plot(x,y,'*r');
    figure();
    plot(t,vx,'b');hold on;
    plot(t,vy,'g')
    h=1.2;  % metric
    yaw=0; % rad
    nPoints=size(t,2);
    waypoint = zeros(7,nPoints+1);
    for i=1:nPoints
        waypoint(1,i)=i;
        waypoint(2,i)=x(i);
        waypoint(3,i)=y(i);
        waypoint(4,i)=h;
        waypoint(5,i)=yaw;
        waypoint(6,i)=vx(i);
        waypoint(7,i)=vy(i);
    end
    waypoint(1,nPoints+1)=nPoints+1;
    waypoint(2,nPoints+1)=0;
    waypoint(3,nPoints+1)=0;
    waypoint(4,nPoints+1)=h;
    waypoint(5,nPoints+1)=yaw;
    waypoint(6,nPoints+1)=0;
    waypoint(7,nPoints+1)=0;
    
%     waypoint(1,1)=1;
%     waypoint(2,1)=-1;
%     waypoint(3,1)=-1;
%     waypoint(4,1)=h;
%     waypoint(5,1)=yaw;
%     waypoint(6,1)=0;
%     waypoint(7,1)=0;
   
end

