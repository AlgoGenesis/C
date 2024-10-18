#include <stdio.h>
#include <stdlib.h>

// Struct to hold data points
typedef struct {
    double *features;
    int label;
} Point;

// Struct to hold the SVM model (weights and bias)
typedef struct {
    double *weights;
    double bias;
} SVMModel;

// Dot product of two vectors
double dot_product(double *vec1, double *vec2, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) sum += vec1[i] * vec2[i];
    return sum;
}

// Train SVM
SVMModel* train_svm(Point *data, int data_count, int feature_count, double lr, int epochs, double C) {
    SVMModel *model = malloc(sizeof(SVMModel));
    model->weights = calloc(feature_count, sizeof(double));
    model->bias = 0;

    for (int epoch = 0; epoch < epochs; epoch++) {
        for (int i = 0; i < data_count; i++) {
            double output = dot_product(model->weights, data[i].features, feature_count) + model->bias;
            if (data[i].label * output < 1) {
                for (int j = 0; j < feature_count; j++)
                    model->weights[j] += lr * (data[i].label * data[i].features[j] - 2 * C * model->weights[j]);
                model->bias += lr * data[i].label;
            }
        }
    }
    return model;
}

// Classify new data
int classify(SVMModel *model, double *features, int feature_count) {
    double output = dot_product(model->weights, features, feature_count) + model->bias;
    return (output >= 0) ? 1 : -1;
}

int main() {
    int data_count = 4, feature_count = 2, epochs = 1000;
    double lr = 0.01, C = 0.1;

    Point data[4] = {
        {(double[]){2.0, 3.0}, 1},
        {(double[]){1.0, 1.0}, -1},
        {(double[]){2.0, 1.0}, 1},
        {(double[]){0.0, 2.0}, -1}
    };

    SVMModel *model = train_svm(data, data_count, feature_count, lr, epochs, C);

    double test_features[2] = {1.5, 2.0};
    printf("Predicted class: %d\n", classify(model, test_features, feature_count));

    free(model->weights);
    free(model);
    return 0;
}
