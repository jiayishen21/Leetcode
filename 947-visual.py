import matplotlib.pyplot as plt

# Coordinates
coordinates = [
    [5, 9], [9, 0], [0, 0], [7, 0], [4, 3], [8, 5], [5, 8],
    [1, 1], [0, 6], [7, 5], [1, 6], [1, 9], [9, 4], [2, 8],
    [1, 3], [4, 2], [2, 5], [4, 1], [0, 2], [6, 5]
]

print(len(coordinates))

# Split coordinates into x and y lists
x, y = zip(*coordinates)

# Create a scatter plot
plt.figure(figsize=(8, 6))
plt.scatter(x, y, c='blue', marker='o', label='Points')
plt.title('Scatter Plot of Coordinates')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.grid(True)
plt.legend()
plt.show()
