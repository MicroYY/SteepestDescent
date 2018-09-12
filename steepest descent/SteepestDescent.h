#pragma once

#include <iostream>
#include <Eigen\Eigen>

class SteepestDescent
{
public:

	SteepestDescent(Eigen::MatrixXd _G, Eigen::VectorXd _b, Eigen::VectorXd _c)
		:G(_G), b(_b), c(_c), dim(_G.rows())
	{
		Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> es(G);
		Eigen::VectorXd ev = es.eigenvalues();
		for (size_t i = 0; i < ev.rows(); i++)
		{
			if (ev[i] <= 0)
				throw std::invalid_argument("·ÇÕý¶¨¾ØÕó");
		}
	}

	Eigen::VectorXd computeMin(Eigen::VectorXd _initPt, int _maxIter = 1000, double epsilon = 1e-10);


private:

	Eigen::MatrixXd G;
	Eigen::VectorXd b;
	Eigen::VectorXd c;

	int dim;
};