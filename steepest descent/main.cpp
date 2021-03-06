
#include <iostream>

#include <Eigen\Eigen>

#include "SteepestDescent.h"



int main()
{
	int dim = 2;
	Eigen::MatrixXd G(dim, dim);
	Eigen::VectorXd b(dim);
	Eigen::VectorXd c(dim);
	Eigen::VectorXd initPt(dim);

	G(0, 0) = 1; G(0, 1) = 0;
	G(1, 0) = 0; G(1, 1) = 9;
	b = Eigen::Vector2d::Zero();
	c = Eigen::Vector2d::Zero();

	initPt(0) = 9; initPt(1) = 1;

	SteepestDescent sd(G, b, c);
	std::cout << sd.computeMin(initPt,1e100,1e-100);

}