#pragma once
#include <Eigen/Dense>

class LinearModel {
public:
    LinearModel();

    void fit(const Eigen::MatrixXd& X, const Eigen::VectorXd& y);
    Eigen::VectorXd predict(const Eigen::MatrixXd& X) const;
    const Eigen::VectorXd& coefficients() const { return weights_; }

private:
    Eigen::VectorXd weights_;
    bool fitted_;
};
