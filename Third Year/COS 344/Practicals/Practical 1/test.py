import numpy as np

# Assuming you have the normalized axis vector (replace with your actual axis)
axis = np.array([0.46, 0.68, 0.57])

# Project the axis onto the x=0 plane (set x-component to zero)
projected_axis = np.array([0, axis[1], axis[2]])

# Calculate the length (d) of the projected line
d = np.linalg.norm(projected_axis)

# Round d to two decimal places
d = np.round(d, decimals=2)

# Print the length of the projected line
print("Length of projected line (d):", d)
