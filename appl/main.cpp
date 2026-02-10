#include <iostream>
#include <Eigen/Dense>
#include "linear_model.h"

int main() {
    Eigen::MatrixXd X(4, 2);
    X << 1, 1,
         1, 2,
         1, 3,
         1, 4;
    Eigen::VectorXd y(4);
    y << 6, 5, 7, 10;

    LinearModel model;
    model.fit(X, y);

    Eigen::MatrixXd X_pred(2, 2);
    X_pred << 1, 1.5,
               1, 5.0;

    Eigen::VectorXd predictions = model.predict(X_pred);
    std::cout << "Predictions:\n" << predictions << std::endl;

    return 0;
}
