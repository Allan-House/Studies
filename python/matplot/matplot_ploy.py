import matplotlib.pyplot as plt

x_values = [0, 1, 2, 3, 4, 5]
y_values = [x**2 for x in x_values]

# To use a style, call style.use before calling subplots()
plt.style.use('seaborn-v0_8-notebook')

# subplots(): Create a figure and a set of subplots.
fig, ax = plt.subplots()

# plot(): Plot y versus x as lines and/or markers.
ax.plot(x_values, y_values)

# Set chart title and label axes.
ax.set_title("Square Numbers", fontsize=20)
ax.set_xlabel("Value", fontsize=14)
ax.set_ylabel("Square of Value", fontsize=14)

# tick_params(): Change the appearance of ticks, tick labels, and gridlines.
ax.tick_params(labelsize=14)

# savefig(): Save the current figure as an image or vector graphic to a file.
plt.savefig('squares.png')

# show(): Display the figure window.
plt.show()