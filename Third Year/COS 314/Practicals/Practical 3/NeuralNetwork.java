import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class NeuralNetwork {

    private int inputSize, hiddenSize, outputSize;
    private double learningRate;
    private double[][] W1, W2;
    private double[] b1, b2;
    private double[] z1, a1, z2, output;

    public NeuralNetwork(int inputSize, int hiddenSize, int outputSize, double learningRate) {
        this.inputSize = inputSize;
        this.hiddenSize = hiddenSize;
        this.outputSize = outputSize;
        this.learningRate = learningRate;
        initializeWeights();
    }

    private void initializeWeights() {
        W1 = new double[hiddenSize][inputSize];
        W2 = new double[outputSize][hiddenSize];
        b1 = new double[hiddenSize];
        b2 = new double[outputSize];
        z1 = new double[hiddenSize];
        a1 = new double[hiddenSize];
        z2 = new double[outputSize];
        output = new double[outputSize];

        Random rand = new Random();
        for (int i = 0; i < hiddenSize; ++i) {
            for (int j = 0; j < inputSize; ++j) {
                W1[i][j] = rand.nextDouble() - 0.8;
            }
        }

        for (int i = 0; i < outputSize; ++i) {
            for (int j = 0; j < hiddenSize; ++j) {
                W2[i][j] = rand.nextDouble() - 0.8;
            }
        }
    }

    private double sigmoid(double x) {
        return 1.0 / (1.0 + Math.exp(-x));
    }

    private double sigmoid_derivative(double x) {
        double s = sigmoid(x);
        return s * (1 - s);
    }

    public double[] forwardPass(double[] input) {
        for (int i = 0; i < hiddenSize; ++i) {
            z1[i] = b1[i];
            for (int j = 0; j < inputSize; ++j) {
                z1[i] += W1[i][j] * input[j];
            }
            a1[i] = sigmoid(z1[i]);
        }

        for (int i = 0; i < outputSize; ++i) {
            z2[i] = b2[i];
            for (int j = 0; j < hiddenSize; ++j) {
                z2[i] += W2[i][j] * a1[j];
            }
            output[i] = sigmoid(z2[i]);
        }

        return output;
    }

    public void backwardPass(double[] input, double[] target) {
        double[] delta2 = new double[outputSize];
        for (int i = 0; i < outputSize; ++i) {
            delta2[i] = (output[i] - target[i]) * sigmoid_derivative(z2[i]);
        }

        double[] delta1 = new double[hiddenSize];
        for (int i = 0; i < hiddenSize; ++i) {
            double error = 0.0;
            for (int j = 0; j < outputSize; ++j) {
                error += delta2[j] * W2[j][i];
            }
            delta1[i] = error * sigmoid_derivative(z1[i]);
        }

        for (int i = 0; i < outputSize; ++i) {
            for (int j = 0; j < hiddenSize; ++j) {
                W2[i][j] -= learningRate * delta2[i] * a1[j];
            }
            b2[i] -= learningRate * delta2[i];
        }

        for (int i = 0; i < hiddenSize; ++i) {
            for (int j = 0; j < inputSize; ++j) {
                W1[i][j] -= learningRate * delta1[i] * input[j];
            }
            b1[i] -= learningRate * delta1[i];
        }
    }

    public void train(List<double[]> inputs, List<double[]> targets, int epochs) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            for (int i = 0; i < inputs.size(); ++i) {
                forwardPass(inputs.get(i));
                backwardPass(inputs.get(i), targets.get(i));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        // Define input data and target values based on the given data
        List<double[]> inputs = new ArrayList<>();
        List<double[]> targets = new ArrayList<>();

        // Load data from text file
        BufferedReader inputFile = new BufferedReader(new FileReader("traindata.txt"));
        String line;
        while ((line = inputFile.readLine()) != null) {
            String[] tokens = line.split(",");
            double[] input = new double[tokens.length - 1];
            for (int i = 0; i < tokens.length - 1; i++) {
                input[i] = Double.parseDouble(tokens[i]);
            }
            inputs.add(input);

            double[] target = {Double.parseDouble(tokens[tokens.length - 1])};
            targets.add(target);
        }
        inputFile.close();

        // Create neural network: 8 inputs, 3 hidden neurons, 1 output, learning rate 0.1
        NeuralNetwork nn = new NeuralNetwork(2, 10, 1, 0.8);

        // Train neural network
        nn.train(inputs, targets, 300);

        // Test neural network
        for (int i = 0; i < inputs.size(); i++) {
            double[] input = inputs.get(i);
            double[] output = nn.forwardPass(input);
            System.out.print("Input: ");
            for (double val : input) {
                System.out.print(val + " ");
            }
            System.out.println(" => Output: " + output[0] + " Expected: " + targets.get(i)[0]);
        }
    }
}
