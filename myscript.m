% Create an impulse signal (delta function)
n = -5:5;               % Define the range of n (from -5 to 5)
impulse_signal = (n == 0);  % Generate the impulse signal, 1 at n=0, 0 elsewhere

% Plot the impulse signal
stem(n, impulse_signal, 'filled');  % Use 'stem' to plot discrete signals
xlabel('n');
ylabel('Amplitude');
title('Impulse Signal');
grid on;  % Turn on the grid for better visualization
