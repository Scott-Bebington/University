import numpy as np

camera_position = np.array([2, 0, 8])
view_volume_width = 9

# Assuming calculated right vector (u)
right_vector = np.array([0.67, 0.92, -0.18])

right_side_offset = view_volume_width / 2 * right_vector
right_side = camera_position + right_side_offset

print(f"Right Side of View Volume:\n{right_side}")
