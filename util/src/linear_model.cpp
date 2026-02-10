#include "linear_model.h"
#include <stdexcept>

LinearModel::LinearModel() : fitted_(false) {}

void LinearModel::fit(const Eigen::MatrixXd& X, const Eigen::VectorXd& y) {
    if (X.rows() != y.size()) {
        throw std::invalid_argument("Number of rows in X must equal size of y");
    }

    // Normal equation: w = (XᵀX)^(-1) Xᵀy
    weights_ = (X.transpose() * X).ldlt().solve(X.transpose() * y);
    fitted_ = true;
}

Eigen::VectorXd LinearModel::predict(const Eigen::MatrixXd& X) const {
    if (!fitted_) {
        throw std::runtime_error("Model not fitted");
    }
    return X * weights_;
}
