t = (1:50000)*1e-4
r0 = 4e-3;

figure
subplot(311)
h1 = plot(t,rx11/r0,'Color',[1 0 0])
hold on
h2 = plot(t,rx12/r0,'Color',[1 0.38 0])
hold on
h3 = plot(t,rx13/r0,'Color',[0.13 0.55 0.13])
ylim([-1 1])
set(gca,'child',[h1 h3 h2])
subplot(312)
% plot(t,rx21/r0,'Color',[1 0 0])
% hold on
h4 = plot(t,rx22/r0,'Color',[1 0.38 0])
hold on
h5 = plot(t,rx23/r0,'Color',[0.13 0.55 0.13])
set(gca,'child',[h4 h5])
subplot(313)
% plot(t,rx31/r0,'Color',[1 0 0])
% hold on
% plot(t,rx32/r0,'Color',[1 0.38 0])
% hold on
plot(t(1:102444),rx33(1:102444)/r0,'Color',[0.13 0.55 0.13])

mat = [rx1' rx2' rx3' rx4']./4e-3;
mat = [t' mat];
save figS.txt -ascii mat