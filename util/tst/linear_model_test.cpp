#include "linear_model.h"
#include <gtest/gtest.h>

TEST(LinearModelTest, FitPredictWorks) {
    Eigen::MatrixXd X(3, 2);
    X << 1, 1,
         1, 2,
         1, 3;
    Eigen::VectorXd y(3);
    y << 1, 2, 3;

    LinearModel model;
    model.fit(X, y);

    Eigen::MatrixXd X_test(1, 2);
    X_test << 1, 4;
    Eigen::VectorXd y_pred = model.predict(X_test);

    EXPECT_NEAR(y_pred(0), 4.0, 1e-6);
}
