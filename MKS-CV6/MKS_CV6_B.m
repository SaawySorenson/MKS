clear all;
close all;

Y = csvread("ntc.csv");



A = zeros(156,2);

ad = zeros(156,1);
t = zeros(156,1);

for i = 1:156
    A(i,1) = Y(i,1);
    A(i,2) = (Y(i,2)/(Y(i,2)+10)) * 1024;
    ad(i) = A(i,2);
    t(i) = A(i,1);
    hold on;
%    plot(ad(i),t(i),'bo');
end

    plot(ad,t,'bo');

%disp(A);


p = polyfit(ad, t, 10);
ad2 = 0:1023;
t2 = round(polyval(p, ad2), 1);
hold on, plot(ad2, t2, 'r');

dlmwrite('data.dlm', t2*10, ',');
