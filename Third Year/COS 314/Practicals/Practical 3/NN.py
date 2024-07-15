import tensorflow as tf
import numpy as np

# Load the data
data = np.loadtxt('traindata.txt', delimiter=',')
x = data[:, :-1]  # Input features
y = data[:, -1]   # Expected output

# Define the neural network architecture
model = tf.keras.Sequential([
    tf.keras.layers.Dense(64, activation='relu', input_shape=(x.shape[1],)),
    tf.keras.layers.Dense(64, activation='relu'),
    tf.keras.layers.Dense(1, activation='sigmoid')
])

# Compile the model
model.compile(optimizer='adam',
              loss='binary_crossentropy',
              metrics=['accuracy'])

# Train the model
model.fit(x, y, epochs=3, batch_size=128)

# Evaluate the model

# load test data from testdata.txt
data = np.loadtxt('testdata.txt', delimiter=',')
x = data[:, :-1]  # Input features
y = data[:, -1]   # Expected output

loss, accuracy = model.evaluate(x, y)
print(f"Test loss: {loss}")
print(f"Test accuracy: {accuracy}")