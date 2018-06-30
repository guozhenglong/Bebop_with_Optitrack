% plot_trajectory.m
figure()
% hold on;
plot(waypoints(2,:),waypoints(3,:),'r*');
hold on;
plot(r1_pos.x.Data,r1_pos.y.Data,'b-');
set(gca,'XMinorGrid','on','YMinorGrid','on')
grid on;